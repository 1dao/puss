// script_system.c

const char script_system_default_script[] = "-- __builtins__/__script_system__.lua : skip some lines for alignment with C code!\n\n\n"
	"__script_system__ = {}\n"
	"\n"
	"__script_system__.__system_script_dofile = function(script, env, ...)\n"
	"	-- ks.log_debug('load script: '..script)\n"
	"	local vfs = __script_system__.__root_vfs__\n"
	"	local cxt = vfs:load_utf8(script)\n"
	"	if cxt==nil then error('load scirpt('..script..') failed!') end\n"
	"	local f, err = load( cxt, script, 'bt', env or _ENV )\n"
	"	if f==nil then error(err) end\n"
	"	return f(...)\n"
	"end\n"
	"\n"
	"__script_system__.dofile = __script_system__.__system_script_dofile\n"
	"\n"
	"-- debug console & debugger core functions\n"
	"-- \n"
	"__script_system__.__debug_console_command = function(cmd)\n"
	"	if cmd=='debug' and type(ks.__debugger__)=='table' then\n"
	"		if os.getenv('os')=='Windows_NT' then\n"
	"			ks.__debugger__.show(ks.daemon_work_path() .. '/ksluadbg_gtk.dll', ks.daemon_work_path() .. '/../scripts')\n"
	"		else\n"
	"			ks.__debugger__.show(ks.daemon_work_path() .. '/ksluadbg_gtk.so', ks.daemon_work_path() .. '/../scripts')\n"
	"		end\n"
	"	else\n"
	"		error('NOTICE : replace __script_system__.__debug_console_command if you need more functions!')\n"
	"	end\n"
	"end\n"
	"\n"
	"__script_system__.__debug_console_update = function()\n"
	"	local cmd = ks.debug_console_cmd_pop()\n"
	"	if cmd==nil then\n"
	"		-- continue\n"
	"	elseif cmd:sub(1,1)=='/' then\n"
	"		__script_system__.__debug_console_command(cmd:sub(2))\n"
	"	else\n"
	"		local chunk, err = load(cmd, '__debug_command__')\n"
	"		if chunk==nil then error(err) end\n"
	"		local ret = chunk()\n"
	"		if ret~=nil then print(ret) end\n"
	"	end\n"
	"end\n"
	"\n"
	"if type(ks)=='table' and type(ks.__debugger__)=='table' then\n"
	"	ks.__debugger__.list_scripts = function()\n"
	"		return ks.__debugger__.fill_files( ks.__debugger__.list_builtins({}), __script_system__.__root_vfs__:list('scripts') )\n"
	"	end\n"
	"	ks.__debugger__.load_script = function(filename)\n"
	"		return ks.__debugger__.fetch_builtin(filename) or __script_system__.__root_vfs__:load_utf8(filename)\n"
	"	end\n"
	"end\n"
	"\n"
	"-- callbacks declare\n"
	"__script_system__.activate = function(puss) end\n"
	"__script_system__.open = function(puss, files, hint) end\n"
	"\n"
	;
	
#include "puss.h"

#ifdef _WIN32
	#define WIN32_LEAN_AND_MEAN
	#include <Windows.h>
#endif

#include <stdlib.h>
#include <glib.h>
#include <gtk/gtk.h>

#include "puss_interface.h"

#include "ks/daemon.h"
#include "ks/vfs/vdisk_fs.h"

#include "kslua/ks_lua.h"
#include "kslua/vfs_lua.h"
#include "kslua/debug_core.h"
#include "kslua/debug_console_lua.h"
#include "kslua/ffi_lua.h"
#include "kslua/ffi_lua.inl"

#include "source_editor.h"

#include "ksgtklua/gobject_lua_ffi.h"
#include "ksgtklua/gboxed_glib_lua.inl"
#include "ksgtklua/gobject_lua_extra_gtk.inl"

#ifdef _WIN32
	#ifdef _DEBUG
		#define MODULE_SUFFIX	"_d.dll"
	#else
		#define MODULE_SUFFIX	".dll"
	#endif
#else
	#ifdef _DEBUG
		#define MODULE_SUFFIX	"_d.so"
	#else
		#define MODULE_SUFFIX	".so"
	#endif
#endif

static SourceEditor* lua_source_editor_check(lua_State* L, int idx) {
	GObject* obj = lua_gobject_check(L, idx);
	SourceEditor* editor = obj ? SOURCE_EDITOR(obj) : NULL;
	if( !editor )
		luaL_error(L, "check SourceEditor type error!\n");
	return editor;
}

#define PUSS_MODULE_NAME		"__PUSS_MODULE__"

typedef struct _PussModule {
	gchar*			name;
	GModule*		dll;
	int				ref;
} PussModule;

typedef struct {
	GtkApplication	parent;

	lua_State*		L;
	PussModule*		main_module;
	KSVFS*			root_vfs;

	GtkBuilder*		main_builder;

	// get pointer from "builder"
	// 
	GtkWindow*		main_window;
	GtkNotebook*	doc_panel;
	GtkNotebook*	left_panel;
	GtkNotebook*	right_panel;
	GtkNotebook*	bottom_panel;
} Puss;

typedef GtkApplicationClass PussClass;

G_DEFINE_TYPE(Puss, puss, GTK_TYPE_APPLICATION)

static BOOL puss_script_invoke(const char* function_path, const char* fmt, ...) {
	Puss* app = (Puss*)g_application_get_default();
	lua_State* L = app->L;
	int res;
	va_list args;

	kslua_rawget_ex(L, function_path);

	va_start(args, fmt);
	res = kslua_ffi_va_pcallv(L, -1, fmt, args);
	va_end(args);

	if( res ) {
		g_warning("puss_script_invoke(%s) failed : %s\n", function_path, lua_tostring(L, -1));
		lua_pop(L, 1);
		return FALSE;
	}
	return TRUE;
}

static void puss_module_reg_ffi(lua_State* L, const char* method, const void* func, char rtype, const char* atypes) {
	assert( L && lua_type(L, -1)==LUA_TTABLE );

	KSFFIFunction* f = kslua_ffi_va_function_create(L, method, func, rtype, atypes);
	if( f )
		lua_setfield(L, -2, method);
}

static BOOL puss_module_script_invoke(PussModule* pm, const char* method, const char* fmt, ...) {
	Puss* app = (Puss*)g_application_get_default();
	lua_State* L = app->L;
	int res;
	va_list args;

	if( pm->ref==0 || pm->name==NULL ) {
		g_warning("module(%s).script_invoke(%s) failed : %s\n", pm->name, method, "module already freed!");
		return FALSE;
	}

	lua_rawgeti(L, LUA_REGISTRYINDEX, pm->ref);
	if( lua_getuservalue(L, -1) != LUA_TTABLE ) {
		g_warning("module(%s).script_invoke(%s) failed : %s\n", pm->name, method, "uservalue not table!");
		lua_pop(L, 2);
		return FALSE;
	}
	lua_remove(L, -2);

	if( lua_getfield(L, -1, method)!=LUA_TFUNCTION ) {
		g_warning("module(%s).script_invoke(%s) failed : %s\n", pm->name, method, "method not found or not function!");
		lua_pop(L, 2);
		return FALSE;
	}
	lua_remove(L, -2);

	va_start(args, fmt);
	res = kslua_ffi_va_pcallv(L, -1, fmt, args);
	va_end(args);

	if( res ) {
		g_warning("module(%s).script_invoke(%s) failed : %s\n", pm->name, method, lua_tostring(L, -1));
		lua_pop(L, 1);
		return FALSE;
	}

	return TRUE;
}

static IPuss _puss_iface =
	{ puss_module_script_invoke
	};

static PussModule* puss_module_check(lua_State* L, int idx) {
	PussModule* pm = (PussModule*)luaL_checkudata(L, 1, PUSS_MODULE_NAME);
	if( pm->ref==0 )
		luaL_argerror(L, idx, "puss module already freed!");
	return pm;
}

static PussModule* puss_module_test(lua_State* L, int idx) {
	PussModule* pm = (PussModule*)luaL_testudata(L, 1, PUSS_MODULE_NAME);
	return (pm && pm->ref) ? pm : NULL;
}

static void puss_module_push(lua_State* L, PussModule* module) {
	if( module && module->ref ) {
		lua_rawgeti(L, LUA_REGISTRYINDEX, module->ref);
	} else {
		lua_pushnil(L);
	}
}

static int puss_module_destroy(lua_State* L) {
	PussModule* pm = (PussModule*)luaL_testudata(L, 1, PUSS_MODULE_NAME);
	if( pm->dll ) {
		PussModuleUninit uninit = NULL;
		if( g_module_symbol(pm->dll, PUSS_MODULE_SYMBOL_INIT, (gpointer*)(&uninit)) )
			uninit();
		g_module_close(pm->dll);
		pm->dll = NULL;
	}
	if( pm->name ) {
		g_free(pm->name);
		pm->name = NULL;
	}
	if( pm->ref ) {
		luaL_unref(L, LUA_REGISTRYINDEX, pm->ref);
		pm->ref = 0;
	}
	return 0;
}

static int puss_module_tostring(lua_State* L) {
	PussModule* pm = (PussModule*)luaL_checkudata(L, 1, PUSS_MODULE_NAME);
	lua_pushfstring(L, "PussModuel(%s)", pm->name ? pm->name : "<NULL>");
	return 1;
}

static int puss_module_index(lua_State* L) {
	PussModule* pm = puss_module_check(L, 1);
	luaL_checkany(L, 2);
	lua_getuservalue(L, 1);
	lua_pushvalue(L, 2);
	lua_gettable(L, -2);
	return 1;
}

static luaL_Reg puss_module_methods[] =
	{ {"__gc",			puss_module_destroy}
	, {"__tostring",	puss_module_tostring}
	, {"__index",		puss_module_index}
	, {NULL,			NULL}
	};

static PussModule* puss_module_new(lua_State* L, const gchar* name) {
	PussModule* pm = lua_newuserdata(L, sizeof(PussModule));
	luaL_setmetatable(L, PUSS_MODULE_NAME);
	pm->name = g_strdup(name);
	pm->dll = NULL;
	lua_pushvalue(L, -1);
	pm->ref = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_newtable(L);
	lua_setuservalue(L, -2);
	return pm;
}

static int puss_module_create(lua_State* L) {
	const gchar* name = luaL_checkstring(L, 1);
	const gchar* modname = luaL_checkstring(L, 2);

	gchar* dllfname = g_strconcat(ks_daemon_work_path(), "/", modname, MODULE_SUFFIX, NULL);
	GModule* dll = g_module_open(dllfname, (GModuleFlags)0);
	g_free(dllfname);

	if( !dll )
		return luaL_error(L, "load dll module failed: %s", modname);
	

	PussModuleInit init = NULL;
	if( !g_module_symbol(dll, PUSS_MODULE_SYMBOL_INIT, (gpointer*)(&init)) ) {
		g_module_close(dll);
		return luaL_error(L, "load dll module not find symbol: %s", PUSS_MODULE_SYMBOL_INIT);
	}

	PussModule* pm = puss_module_new(L, name);
	lua_getuservalue(L, -1);
	init(&_puss_iface, L, puss_module_reg_ffi);
	lua_pop(L, 1);
	return 1;
}

static void lua_ffi_check_puss_module(lua_State* L, int idx, void* pval, const void* pdef) {
	*((PussModule**)pval) = (pdef==NULL) ? puss_module_check(L, idx) : puss_module_test(L, idx);
}

static int lua_ffi_push_puss_module(lua_State* L, const void* pval) {
	puss_module_push(L, *(PussModule**)pval);
	return 1;
}

static void kslua_ffi_return_puss_module(lua_State* L, int idx, void* pval) {
	*((PussModule**)pval) = puss_module_test(L, idx);
}

KSLUA_FFI_TYPEDEF(puss_module, PussModule*, FFI_TYPE_POINTER, KS_FFI_VA_ARG_POINTER);

static void puss_panel_page_add(GtkWidget* widget, const gchar* label, const char* default_panel) {
	Puss* app = (Puss*)g_application_get_default();
	const char* panel_name = NULL;
	if( !puss_script_invoke("__script_system__.panel_fetch_position", "$s>s", label, default_panel, &panel_name) )
		panel_name = default_panel;

	GtkNotebook* panel = GTK_NOTEBOOK(gtk_builder_get_object(app->main_builder, panel_name));
	if( !panel ) {
		panel = app->bottom_panel;
		panel_name = "bottom_panel";
	}

	g_object_set_data_full(G_OBJECT(widget), "__puss_page_id__", g_strdup(label), (GDestroyNotify)g_free);

	// puss_script_invoke("__script_system__.panel_save_position", "...", ...) )
}

static void puss_panel_page_remove(GtkWidget* widget) {
	GtkNotebook* panel = GTK_NOTEBOOK(gtk_widget_get_parent(widget));
	g_return_if_fail( panel != NULL );

	const gchar* label = g_object_get_data(G_OBJECT(widget), "__puss_page_id__");
	g_return_if_fail( label != NULL );

	gint page_num = gtk_notebook_page_num(panel, widget);
	g_return_if_fail( page_num >= 0 );

	gtk_notebook_remove_page(panel, page_num);
}

static gboolean load_ui(Puss* app, const gchar* filename ) {
	GError* err = 0;
	gchar* filepath = g_build_filename(ks_daemon_work_path(), "modules/puss", filename, NULL);
	if( !filepath ) {
		g_printerr("ERROR(puss) : build ui filepath failed!\n");
		return FALSE;
	}

	gtk_builder_add_from_file(app->main_builder, filepath, &err);
	g_free(filepath);

	if( err ) {
		g_printerr("ERROR(puss): %s\n", err->message);
		g_error_free(err);
		return FALSE;
	}

	return TRUE;
}

static gboolean _debugger_update(gpointer tag) {
	// Puss* app = (Puss*)tag;
	kslua_debugger_update();
	puss_script_invoke("__script_system__.__debug_console_update", "");
	return TRUE;
}

static void main_window_on_destroy(GtkWidget* w, Puss* app) {
	g_source_remove_by_user_data(app);
	kslua_debug_console_stop();
}

static void puss_main_window_create(GApplication* application) {
	Puss* app =(Puss*)application;
	if( app->main_builder )
		return;

	{
		const gchar* new_accels[] = { "<Primary>n", "<Primary>t", NULL };
		gtk_application_set_accels_for_action(GTK_APPLICATION(application), "app.new", new_accels);
	}

	//gtk_application_set_menubar(GTK_APPLICATION(application), G_MENU_MODEL(gtk_builder_get_object(builder, "app-menu")));
	{
		GtkBuilder* builder = gtk_builder_new();
		app->main_builder = builder;

		if( !load_ui(app, "puss_main_window.ui") )
			g_error("load puss_main_window.ui failed!");

		app->main_window = GTK_WINDOW(gtk_builder_get_object(builder, "main_window"));
		gtk_window_set_application(app->main_window, GTK_APPLICATION(application));

		// g_action_map_add_action_entries(G_ACTION_MAP(window), win_entries, G_N_ELEMENTS(win_entries), window);
		app->doc_panel    = GTK_NOTEBOOK(gtk_builder_get_object(app->main_builder, "doc_panel"));
		app->left_panel   = GTK_NOTEBOOK(gtk_builder_get_object(app->main_builder, "left_panel"));
		app->right_panel  = GTK_NOTEBOOK(gtk_builder_get_object(app->main_builder, "right_panel"));
		app->bottom_panel = GTK_NOTEBOOK(gtk_builder_get_object(app->main_builder, "bottom_panel"));
	}

	gtk_widget_show_all(GTK_WIDGET(app->main_window));

#ifdef _WIN32
	// windows release version, show window twice when use SW_HIDE
	gdk_window_show( gtk_widget_get_window(GTK_WIDGET(app->main_window)) );
#endif

	g_signal_connect(app->main_window, "destroy", G_CALLBACK(main_window_on_destroy), app);
}

static SourceEditor* source_editor_page_new(const char* label) {
	Puss* app = (Puss*)g_application_get_default();
	lua_State* L = app->L;
	SourceEditor* editor = source_editor_new();
	GtkWidget* sw = gtk_scrolled_window_new(NULL, NULL);
	gtk_container_add(GTK_CONTAINER(sw), GTK_WIDGET(editor));
	gtk_widget_show(sw);
	gtk_notebook_prepend_page(app->doc_panel, sw, gtk_label_new(label));
	return editor;
}

static void puss_activate(GApplication* application) {
	Puss* app = (Puss*)application;
	puss_main_window_create(application);
	puss_script_invoke("__script_system__.activate", "");
}

typedef struct _FilesTag {
	GFile**			files;
	gint			n_files;
} FilesTag;

static int _files_push(lua_State* L, const void* pval) {
	const FilesTag* tag = (const FilesTag*)pval;
	gint i;

	lua_createtable(L, tag->n_files, 0);
	for(i = 0; i < tag->n_files; i++) {
		gchar* pth = g_file_get_path(tag->files[i]);
		lua_pushstring(L, pth);
		g_free(pth);
		lua_rawseti(L, -2, (i+1));
	}
	return 1;
}

static void puss_open(GApplication* application, GFile** files, gint n_files, const gchar* hint){
	Puss* app = (Puss*)application;
	lua_State* L = app->L;

	puss_main_window_create(application);

	FilesTag tag = { files, n_files };
	KSFFICustom ofiles = { NULL, _files_push, NULL, &tag };

	puss_script_invoke("__script_system__.open", "Os", &ofiles, hint);
}

static void puss_startup(GApplication* application) {
	G_APPLICATION_CLASS(puss_parent_class)->startup(application);
}

static void puss_shutdown(GApplication* application) {
	G_APPLICATION_CLASS(puss_parent_class)->shutdown(application);
}

static int _source_editor_format_diskfile_filename(lua_State* L) {
	gchar* res = source_editor_format_diskfile_filename(luaL_checkstring(L, 1));
	if( res ) {
		lua_pushstring(L, res);
		g_free(res);
	} else {
		lua_pushvalue(L, 1);
	}
	return 1;
}

static PussModule* _puss_main_module_create(lua_State* L) {
	PussModule* pm = puss_module_new(L, "puss");
	lua_getuservalue(L, -1);

	lua_pushcfunction(L, puss_module_create);
	lua_setfield(L, -2, "module_create");

	lua_pushcfunction(L, _source_editor_format_diskfile_filename);
	lua_setfield(L, -2, "source_editor_format_diskfile_filename");

	PUSS_MODULE_REG(source_editor_page_new, 'G', "s");

	lua_pop(L, 1);
	return pm;
}

static int _do_puss_init_lua(lua_State* L) {
	Puss* app = (Puss*)KSLUA_PCALL_CFUNCTION_WRAPPER_FETCH_TAG(L);

	lua_gtype_register_index_table(L, G_TYPE_STRV, strv_methods);
	lua_gtype_register_index_table(L, G_TYPE_STRING, gstring_methods);
	assert( lua_gettop(L)==0 );

	gobject_extra_gtk_register(L);
	assert( lua_gettop(L)==0 );

	lua_source_editor_open(L, lua_source_editor_check);
	luaL_dostring(L, "__gobject__.gtype_register_metatable_index(__sci__.__SOURCE_EDITOR_TYPE__, __sci__)");

	if( luaL_newmetatable(L, PUSS_MODULE_NAME) ) {
		luaL_setfuncs(L, puss_module_methods, 0);
		lua_pop(L, 1);
	}

	if( luaL_loadbuffer(L, script_system_default_script, sizeof(script_system_default_script)-1, "__builtins__/__script_system__.lua") )
		luaL_error(L, "create __script_system__ load failed : %s\n", lua_tostring(L, -1));
	lua_call(L, 0, 0);

	lua_getglobal(L, "__script_system__");

	kslua_push_vfs_can_not_destroy(L, app->root_vfs);
	lua_setfield(L, -2, "__root_vfs__");

	app->main_module = _puss_main_module_create(L);
	lua_setfield(L, -2, "__puss__");

	lua_pop(L, 1);	// __script_system__
	return 0;
}

static void puss_init(Puss* app) {
	KSVFS* vfs = ks_vdisk_fs_create("", ks_daemon_work_path());
	app->root_vfs = vfs;

	const char* puss_debug = getenv("PUSS_DEBUG");
	int debug = puss_debug ? atoi(puss_debug) : 0;
	lua_State* L = debug ? kslua_debugger_newstate() : luaL_newstate();
	app->L = L;

	luaL_openlibs(L);
	kslua_open_vfs(L);
	assert( lua_gettop(L)==0 );

	lua_gobject_open(L);
	assert( lua_gettop(L)==0 );

	gobject_ffi_type_register(L);
	kslua_ffi_va_type_register('$', &_kslua_ffi_type_puss_module);

	KSLUA_PCALL_CFUNCTION_WRAPPER_PUSH_CLOSURE(L, _do_puss_init_lua, app);
	if( kslua_pcall_stacktrace(L, 0, 0) ) {
		g_error("init lua failed: %s", lua_tostring(L, -1));
		lua_pop(L, 1);
	}

	if( debug ) {
		kslua_rawget_ex(L, "ks.__debugger__.__builtins__");
		if( lua_istable(L, -1) ) {
			lua_pushlstring(L, script_system_default_script, sizeof(script_system_default_script)-1);
			lua_setfield(L, -2, "__script_system__.lua");
			lua_pop(L, 1);
		}

#ifdef G_OS_WIN32
		// use HIDE window, need show twice
		ShowWindow(GetConsoleWindow(), SW_SHOW);
		ShowWindow(GetConsoleWindow(), SW_SHOW);
#endif

		kslua_debug_console_start(L);
		g_timeout_add(10, (GSourceFunc)_debugger_update, app);
	}
}

static void puss_finalize(GObject* object) {
	Puss* app = (Puss*)object;
	G_OBJECT_CLASS(puss_parent_class)->finalize(object);

	ks_vfs_destroy(app->root_vfs);
	lua_close(app->L);

	source_editor_release_resources();
}

static void puss_class_init(PussClass* class) {
	GApplicationClass* application_class = G_APPLICATION_CLASS(class);
	GObjectClass* object_class = G_OBJECT_CLASS(class);

	application_class->startup = puss_startup;
	application_class->shutdown = puss_shutdown;
	application_class->activate = puss_activate;
	application_class->open = puss_open;

	object_class->finalize = puss_finalize;
}

GApplication* puss_application_create(void) {
	g_set_application_name("Puss");

	Puss* app = (Puss*)g_object_new( puss_get_type()
					, "application-id", "org.puss"
					, "flags", G_APPLICATION_HANDLES_OPEN
					, NULL );
	g_application_set_default(G_APPLICATION(app));

	puss_script_invoke("__script_system__.dofile", "s", "modules/puss/puss.lua");
	return G_APPLICATION(app);
}

