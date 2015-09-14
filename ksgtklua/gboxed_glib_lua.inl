// gboxed_glib_lua.inl

#include "gobject_lua.h"

static GValue* gboxedvalue_check(lua_State* L, int idx, GType tp) {
	GValue* v = lua_gboxedvalue_check(L, 1);
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

static luaL_Reg strv_methods[] =
	{ {"get",		strv_get}
	, {"set",		strv_set}
	, {NULL, NULL}
	};

static int gstring_get(lua_State* L) {
	GValue* v = gboxedvalue_check(L, 1, G_TYPE_STRING);
	const GString* s = (const GString*)g_value_get_boxed(v);
	lua_pushlstring(L, s->str, s->len);
	return 1;
}

static int gstring_set(lua_State* L) {
	GValue* v = gboxedvalue_check(L, 1, G_TYPE_STRING);
	GString* gstr = (GString*)g_value_get_boxed(v);
	size_t len = 0;
	const char* str = luaL_checklstring(L, 2, &len);
	g_value_set_boxed(v, g_string_new_len(str, (gssize)len));
	return 0;
}

static luaL_Reg gstring_methods[] =
	{ {"get",		gstring_get}
	, {"set",		gstring_set}
	, {NULL, NULL}
	};

