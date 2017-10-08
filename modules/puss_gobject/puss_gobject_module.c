// puss_gobject_module.c

#include "puss_gobject_module.h"

#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include "gffi.h"
#include <gio/gio.h>

#include "puss_gobject_ffi_reg.h"

#include "luaproxy_import.inl"

static PussGObjectRegIface reg_iface =
	{ gffi_function_va_create
	, glua_push_gtype_index_table
	, glua_push_c_struct0_boxed_type_new_method
	, glua_reg_gtype
	};
 
static int reg_wrapper(lua_State* L) {
	PussGObjectReg f = (PussGObjectReg)lua_touserdata(L, 1);
	lua_settop(L, 0);
	glua_push_master_table(L);
	assert( lua_gettop(L)==1 );
	f(L, &reg_iface, 1);
	lua_settop(L, 0);
	return 0;
}

static void puss_gobject_module_reg(lua_State* L, PussGObjectReg f) {
	lua_pushcfunction(L, reg_wrapper);
	lua_pushlightuserdata(L, f);
	lua_call(L, 1, 0);
}

static PussGObjectInterface puss_gobject_interface =
	{ glua_push_master_table
	, puss_gobject_module_reg
	, glua_value_check
	, glua_value_test
	, glua_value_check_type
	, glua_value_new
	, glua_value_push
	, glua_value_push_boxed
	, glua_value_from_lua
	, glua_object_push
	, glua_object_check
	, glua_object_test
	, glua_object_check_type
	, glua_signal_connect
	};

// gobject & gio module register

static int strv_get(lua_State* L) {
	GValue* v = glua_value_check_type(L, 1, G_TYPE_STRV);
	const GStrv gstrv = (const GStrv)g_value_get_boxed(v);
	int n = (int)g_strv_length(gstrv);
	int i;
	lua_createtable(L, n, 0);
	for( i=0; i<n; ++i ) {
		lua_pushstring(L, gstrv[i]);
		lua_rawseti(L, -2, i+1);
	}
	return 1;
}

static int strv_set(lua_State* L) {
	GValue* v = glua_value_check_type(L, 1, G_TYPE_STRV);
	GStrv strv = NULL;
	if( lua_istable(L, 2) ) {
		int n = (int)lua_rawlen(L, 1);
		int i;
		strv = g_new0(gchar*, (n+1));
		for( i=0; i<n; ++i ) {
			lua_rawgeti(L, 2, i+1);
			if( lua_isstring(L, -1) ) {
				size_t len = 0;
				const char* str = lua_tolstring(L, -1, &len);
				strv[i] = g_strndup(str, len);
			} else {
				strv[i] = g_strdup(lua_tostring(L, -1));
			}
			lua_pop(L, 1);
		}

	} else if( !lua_isnoneornil(L, 2) ) {
		luaL_error(L, "convert to G_TYPE_STRV failed, only support nil or table!");
	}
	g_value_set_boxed(v, strv);
	return 0;
}

static int strv_new(lua_State* L) {
	glua_value_new(L, G_TYPE_STRV);
	lua_pushvalue(L, 1);
	lua_insert(L, 0);
	if( lua_istable(L, 2) )
		strv_set(L);
	lua_settop(L, 1);
	return 1;
}

static int strv_len(lua_State* L) {
	GValue* v = glua_value_check_type(L, 1, G_TYPE_STRV);
	const GStrv gstrv = (const GStrv)g_value_get_boxed(v);
	lua_pushinteger(L, (lua_Integer)g_strv_length(gstrv));
	return 1;
}

static luaL_Reg strv_methods[] =
	{ {"new",		strv_new}
	, {"get",		strv_get}
	, {"set",		strv_set}
	, {"len",		strv_len}
	, {NULL, NULL}
	};

static void glua_glib_register(lua_State* L, PussGObjectRegIface* reg_iface, int glua_env_index) {
	// glib boxed
	reg_iface->reg_gtype(L, glua_env_index, G_TYPE_STRV, "g_strv", strv_methods);

	// gio
	gtype_reg_start(G_TYPE_FILE, g_file);
		gtype_reg_ffi(G_TYPE_FILE, g_file_new_for_path, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_FILE, g_file_new_for_uri, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_FILE, g_file_new_for_commandline_arg, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_FILE, g_file_new_for_commandline_arg_and_cwd, G_TYPE_STRING, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_FILE, g_file_parse_name, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_FILE, g_file_dup, G_TYPE_FILE);
		gtype_reg_ffi(G_TYPE_BOOLEAN, g_file_equal, G_TYPE_FILE, G_TYPE_FILE);
		gtype_reg_ffi(G_TYPE_STRING, g_file_get_basename, G_TYPE_FILE);
		gtype_reg_ffi(G_TYPE_STRING, g_file_get_path, G_TYPE_FILE);
		gtype_reg_ffi(G_TYPE_STRING, g_file_get_uri, G_TYPE_FILE);
		gtype_reg_ffi(G_TYPE_STRING, g_file_get_parse_name, G_TYPE_FILE);
		gtype_reg_ffi(G_TYPE_FILE, g_file_get_parent, G_TYPE_FILE);
		gtype_reg_ffi(G_TYPE_BOOLEAN, g_file_has_parent, G_TYPE_FILE, G_TYPE_FILE);
		gtype_reg_ffi(G_TYPE_FILE, g_file_get_child, G_TYPE_FILE, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_FILE, g_file_get_child_for_display_name, G_TYPE_FILE, G_TYPE_STRING, out G_TYPE_ERROR);
		gtype_reg_ffi(G_TYPE_BOOLEAN, g_file_has_prefix, G_TYPE_FILE, G_TYPE_FILE);
		gtype_reg_ffi(G_TYPE_STRING, g_file_get_relative_path, G_TYPE_FILE, G_TYPE_FILE);
		gtype_reg_ffi(G_TYPE_FILE, g_file_resolve_relative_path, G_TYPE_FILE, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_BOOLEAN, g_file_is_native, G_TYPE_FILE);
		gtype_reg_ffi(G_TYPE_BOOLEAN, g_file_has_uri_scheme, G_TYPE_FILE, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_STRING, g_file_get_uri_scheme, G_TYPE_FILE);
	gtype_reg_end();

	gtype_reg_start(G_TYPE_FILE_ICON, g_file_icon);
		gtype_reg_ffi(G_TYPE_FILE_ICON, g_file_icon_new, G_TYPE_FILE);
	gtype_reg_end();

	gtype_reg_start(G_TYPE_FILE_INFO, g_file_info); gtype_reg_end();

	gtype_reg_start(G_TYPE_APPLICATION, g_application);
		gtype_reg_ffi(G_TYPE_BOOLEAN, g_application_id_is_valid, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_APPLICATION, g_application_new, G_TYPE_STRING, G_TYPE_APPLICATION_FLAGS);
		gtype_reg_ffi(G_TYPE_BOOLEAN, g_application_get_is_registered, G_TYPE_APPLICATION);
		gtype_reg_ffi(G_TYPE_BOOLEAN, g_application_get_is_remote, G_TYPE_APPLICATION);
		gtype_reg_ffi(G_TYPE_NONE, g_application_hold, G_TYPE_APPLICATION);
		gtype_reg_ffi(G_TYPE_NONE, g_application_release, G_TYPE_APPLICATION);
		gtype_reg_ffi(G_TYPE_NONE, g_application_activate, G_TYPE_APPLICATION);
		gtype_reg_ffi(G_TYPE_NONE, g_application_quit, G_TYPE_APPLICATION);
		gtype_reg_ffi(G_TYPE_APPLICATION, g_application_get_default, G_TYPE_INVALID);
		gtype_reg_ffi(G_TYPE_NONE, g_application_set_default, G_TYPE_APPLICATION);
		gtype_reg_ffi(G_TYPE_INT, g_application_run, G_TYPE_APPLICATION, G_TYPE_UINT, G_TYPE_STRV);
	gtype_reg_end();

	gtype_reg_start(G_TYPE_MOUNT_OPERATION, g_mount_operation); gtype_reg_end();
}


static gboolean __glua_inited__ = FALSE;
/*
static int __glua_gtk_argc = 1;
static char __glua_gtk_arg0[32] = { '.', '/', 'a', 'p', 'p', 0 };
static char* __glua_gtk_args[2] = { __glua_gtk_arg0, NULL };
static char** __glua_gtk_argv = __glua_gtk_args;
		guint64 now = (guint64)g_get_real_time();
		sprintf(__glua_gtk_arg0, "glua_%u_%u", (unsigned)(now>>32), (unsigned)(now));
*/

PUSS_MODULE_EXPORT void* __puss_module_init__(lua_State* L, PussInterface* puss, void* ud) {
	if( !__glua_inited__ ) {
		__glua_inited__ = TRUE;
		__lua_proxy_import__(puss->luaproxy());
		gffi_init();
	}

	puss_gobject_interface.module_reg(L, glua_glib_register);

	return &puss_gobject_interface;
}

