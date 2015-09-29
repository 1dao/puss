// main.c

#ifdef _WIN32
	#define _CRT_SECURE_NO_WARNINGS
	#include <Windows.h>
	#include <conio.h>

	#ifdef _MSC_VER
		#define inline	__inline
	#endif
#endif

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>

#include "glua/gffireg.h"
#include "glua/gtypes_glib.inl"
#include "glua/gtypes_gtk3.inl"
#include "glua/gtypes_scintilla.inl"

#ifdef G_OS_WIN32
	static gchar* find_root_filepath(const char* argv0) {
		gchar buf[4096];
		int len = GetModuleFileNameA(0, buf, 4096);
		return g_locale_to_utf8(buf, len, NULL, NULL, NULL);
	}

	G_MODULE_EXPORT int main(int argc, char* argv[]);

#else
	static gchar* find_root_filepath(const char* argv0) {
		gchar* pwd;
		gchar* prj;
		gchar* realpath;
		gchar* filepath = g_find_program_in_path(argv0);

		if( !filepath ) {
			g_printerr(_("ERROR : can not find puss in $PATH\n"));
			return 0;
		}

		if( !g_path_is_absolute(filepath) ) {
			pwd = g_get_current_dir();
			prj = g_build_filename(pwd, filepath, NULL);
			g_free(pwd);
			g_free(filepath);
			filepath = prj;
		}

		if( g_file_test(filepath, G_FILE_TEST_IS_SYMLINK) ) {
			realpath = g_file_read_link(filepath, 0);
			g_free(filepath);
			filepath = realpath;
		}

		if( !g_file_test(filepath, G_FILE_TEST_EXISTS) ) {
			g_printerr(_("ERROR : can not find puss directory!\n"));
			g_printerr(_("        can not use indirect search path in $PATH!\n"));
			g_free(filepath);
			return 0;
		}

		return filepath;
	}

#endif

static int debug_traceback(lua_State* L) {
	const char *msg = lua_tostring(L, 1);
	if (msg)
		luaL_traceback(L, L, msg, 1);
	else if (!lua_isnoneornil(L, 1)) {  /* is there an error object? */
		if (!luaL_callmeta(L, 1, "__tostring"))  /* try its 'tostring' metamethod */
			lua_pushliteral(L, "(no error message)");
	}
	return 1;
}

static int lua_pcall_stacktrace(lua_State* L, int narg, int nres) {
	int status;
	int base = lua_gettop(L) - narg;  /* function index */
	lua_pushcfunction(L, debug_traceback);  /* push traceback function */
	lua_insert(L, base);  /* put it under chunk and args */
	status = lua_pcall(L, narg, nres, base);
	lua_remove(L, base);  /* remove traceback function */
	return status;
}

static int lua_load_main_script(lua_State* L, const char* arg0) {
	int res = 0;
	gsize len = 0;
	gchar* cxt = NULL;
	GError* err = NULL;
	gchar* main_script = NULL;
	gchar* root_path = find_root_filepath(arg0);
	size_t i = strlen(root_path);
	for( --i; i>0; --i ) {
		if( root_path[i]=='\\' || root_path[i]=='/' ) {
			root_path[i] = '\0';
			break;
		}
	}

	main_script = g_build_filename(root_path, "modules", "puss", "puss.lua", NULL);
	if( g_file_get_contents_utf8(main_script, &cxt, &len, &err) ) {
		res = luaL_loadbuffer(L, cxt, len, "puss");
		if( res==LUA_OK ) {
			lua_pushstring(L, root_path);
		}

	} else {
		lua_pushfstring(L, "load main script error : %s\n", err->message);
		g_error_free(err);
		res = 1;
	}

	g_free(cxt);
	g_free(main_script);
	g_free(root_path);
	return res;
}

int main(int argc, char* argv[]) {
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);

	gffi_init();
		gtypes_glib_register(L);
		gtypes_gtk_register(L);
		gtypes_scintilla_register(L);
	glua_enum_types_register(L);

	glua_push_master_table(L);
	lua_setglobal(L, "__glua__");

	// load main_script
	// push root_path as first argument
	// 
	if( lua_load_main_script(L, argv[0]) ) {
		g_error("load script error : %s", lua_tostring(L, -1));
		lua_pop(L, 1);

	} else {
		// push argv as strv
		{
			gchar** v = g_new0(gchar*, argc+1);
			int i = 0;
			for( ; i<argc; ++i ) {
				v[i] = g_strdup(argv[i]);
			}
			glua_boxed_push(L, G_TYPE_STRV, v);
			g_strfreev(v);
		}

		if( lua_pcall_stacktrace(L, 2, 0) ) {
			g_error("pcall error : %s", lua_tostring(L, -1));
			lua_pop(L, 1);
		}
	}

	lua_close(L);

#ifdef _WIN32
	if( getenv("PUSS_DEBUG") ) {
		fprintf(stderr, "press any key to exit...\n");
		_getch();
	}
#endif
	return 0;
}

