// gtypes_glib.inl

// #include "gffireg.h"

static GValue* gboxedvalue_check(lua_State* L, int idx, GType tp) {
	GValue* v = glua_boxed_check(L, 1);
	if( G_VALUE_TYPE(v) != tp )
		luaL_error(L, "type(%s) not matched!", g_type_name(tp));
	return v;
}

static int strv_get(lua_State* L) {
	GValue* v = gboxedvalue_check(L, 1, G_TYPE_STRV);
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
	GValue* v = gboxedvalue_check(L, 1, G_TYPE_STRV);
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
	GValue v = G_VALUE_INIT;
	g_value_init(&v, G_TYPE_STRV);
	glua_value_push(L, &v);
	lua_pushvalue(L, 1);
	lua_insert(L, 0);
	if( lua_istable(L, 2) )
		strv_set(L);
	lua_settop(L, 1);
	return 1;
}

static luaL_Reg strv_methods[] =
	{ {"new",		strv_new}
	, {"get",		strv_get}
	, {"set",		strv_set}
	, {NULL, NULL}
	};

static void gtypes_glib_register(lua_State* L) {
	gtype_reg_env_declare();

	// glib boxed
	glua_reg_gtype_index_table(L, G_TYPE_STRV, strv_methods);

	// gobjects
	gtype_reg_start(G_TYPE_APPLICATION, g_application);
		gtype_reg_ffi(G_TYPE_NONE, g_application_id_is_valid, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_APPLICATION, g_application_new, G_TYPE_STRING, G_TYPE_UINT);
		gtype_reg_ffi(G_TYPE_BOOLEAN, g_application_get_is_registered, G_TYPE_APPLICATION);
		gtype_reg_ffi(G_TYPE_BOOLEAN, g_application_get_is_remote, G_TYPE_APPLICATION);
		gtype_reg_ffi(G_TYPE_NONE, g_application_hold, G_TYPE_APPLICATION);
		gtype_reg_ffi(G_TYPE_NONE, g_application_release, G_TYPE_APPLICATION);
		gtype_reg_ffi(G_TYPE_NONE, g_application_activate, G_TYPE_APPLICATION);
		gtype_reg_ffi(G_TYPE_NONE, g_application_quit, G_TYPE_APPLICATION);
		gtype_reg_ffi(G_TYPE_APPLICATION, g_application_get_default);
		gtype_reg_ffi(G_TYPE_NONE, g_application_set_default, G_TYPE_APPLICATION);
		gtype_reg_ffi(G_TYPE_INT, g_application_run, G_TYPE_APPLICATION, G_TYPE_UINT, G_TYPE_STRV);
	gtype_reg_end();
}

