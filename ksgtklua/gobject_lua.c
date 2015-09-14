// gobject_lua.c
// 

#include "gobject_lua.h"

#include <assert.h>
#include <memory.h>
#include <string.h>

static const char*	GOBJECT_LUA_NAME = "__GOBJECT__";
static const char*	GBOXEDVALUE_LUA_NAME = "__GBOXEDVALUE__";
static const char*	GPARAMSPEC_LUA_NAME = "__GPARAMSPEC__";
static const char*	GSIGNAL_HANDLE_LUA_NAME = "__GSIGNAL_HANDLE__";

typedef struct _GObjectLua {
	GObject*	obj;
	gboolean	weak_ref;
} GObjectLua;

static GObject* _gobject_check(lua_State* L, int idx) {
	GObjectLua* ud = (GObjectLua*)luaL_checkudata(L, idx, GOBJECT_LUA_NAME);
	if( !(ud->obj) )
		luaL_argerror(L, idx, "gobject not exist");
	return ud->obj;
}

static GObject* _gobject_test(lua_State* L, int idx) {
	GObjectLua* ud = (GObjectLua*)luaL_testudata(L, idx, GOBJECT_LUA_NAME);
	return ud ? ud->obj : NULL;
}

typedef struct _GParamSpecLua {
	GParamSpec*	spec;
} GParamSpecLua;

typedef struct _SingalHandleLua {
	lua_State*	L;
	int			ref;
	gpointer	obj;
	gulong		signal_handle_id;
} SingalHandleLua;

typedef struct _MarshalLuaCallEnv {
	GValue*			return_value;
	guint			n_param_values;
	const GValue*	param_values;
} MarshalLuaCallEnv;

GValue* lua_gboxedvalue_check(lua_State* L, int idx) {
	return luaL_checkudata(L, 1, GBOXEDVALUE_LUA_NAME);
}

GValue* lua_gboxedvalue_test(lua_State* L, int idx) {
	return luaL_testudata(L, 1, GBOXEDVALUE_LUA_NAME);
}

static int lua_gboxedvalue_unset(lua_State* L) {
	GValue* v = lua_gboxedvalue_check(L, 1);
	g_value_unset(v);
	return 0;
}

static int lua_gboxedvalue_tostring(lua_State* L) {
	GValue* v = lua_gboxedvalue_check(L, 1);
	lua_pushfstring(L, "%s(%s):%p", GBOXEDVALUE_LUA_NAME, G_VALUE_TYPE_NAME(v), v);
	return 1;
}

static int lua_gboxedvalue_index(lua_State* L) {
	GValue* v = lua_gboxedvalue_check(L, 1);
	luaL_checkany(L, 2);

	lua_getuservalue(L, 1);		// search cache
	if( lua_isnil(L, -1) ) {
		lua_getmetatable(L, 1);
		lua_rawgeti(L, -1, 1);	// extra table
		lua_getfield(L, -1, G_VALUE_TYPE_NAME(v));	// find MT
		if( lua_isnil(L, -1) ) {
			lua_pop(L, 2);
			lua_rawgeti(L, -1, 2);	// not find, use empty MT
		}
		lua_pushvalue(L, -1);	// cache MT
		lua_setuservalue(L, 1);
	}

	if( lua_isfunction(L, -1) ) {
		lua_pushvalue(L, 1);
		lua_pushvalue(L, 2);
		lua_call(L, 2, 1);
	} else {
		lua_pushvalue(L, 2);
		lua_gettable(L, -2);
	}
	return 1;
}

static luaL_Reg gboxedvalue_methods[] =
	{ {"__gc",			lua_gboxedvalue_unset}
	, {"__tostring",	lua_gboxedvalue_tostring}
	, {"__index",		lua_gboxedvalue_index}
	, {NULL, NULL}
	};

static int _lua_gvalue_empty_metatable(lua_State* L) {
	return 0;
}

static void _gvalue_metatable_new(lua_State* L) {
	if( luaL_newmetatable(L, GBOXEDVALUE_LUA_NAME) ) {
		luaL_setfuncs(L, gboxedvalue_methods, 0);

		// metatable[1] = { __extra_types__[gtypename:mt] }
		lua_newtable(L);
		lua_rawseti(L, -2, 1);

		// metatable[2] = function() end	-- empty MT
		lua_pushcfunction(L, _lua_gvalue_empty_metatable);
		lua_rawseti(L, -2, 2);
	}
}

void lua_gboxedvalue_push(lua_State* L, const GValue* v) {
	GValue* ud = lua_newuserdata(L, sizeof(GValue));
	memset(ud, 0, sizeof(GValue));
	g_value_init(ud, G_VALUE_TYPE(v));
	g_value_copy(v, ud);
	if( luaL_newmetatable(L, GBOXEDVALUE_LUA_NAME) )
		luaL_setfuncs(L, gboxedvalue_methods, 0);
	lua_setmetatable(L, -2);
}

static int lua_param_sepc_unref(lua_State* L) {
	GParamSpecLua* ud = luaL_checkudata(L, 1, GPARAMSPEC_LUA_NAME);
	if( ud->spec ) {
		g_param_spec_unref(ud->spec);
		ud->spec = NULL;
	}
	return 0;
}

static int lua_param_sepc_tostring(lua_State* L) {
	GParamSpecLua* ud = luaL_checkudata(L, 1, GPARAMSPEC_LUA_NAME);
	lua_pushfstring(L, "%s:%p {valuetype='%s', name='%s', nick='%s', blurb='%s'}"
		, GPARAMSPEC_LUA_NAME
		, ud->spec
		, g_type_name(G_PARAM_SPEC_VALUE_TYPE(ud->spec))
		, g_param_spec_get_name(ud->spec)
		, g_param_spec_get_nick(ud->spec)
		, g_param_spec_get_blurb(ud->spec)
		);
	return 1;
}

static GParamSpec* lua_param_check(lua_State* L, int idx) {
	GParamSpecLua* ud = luaL_checkudata(L, 1, GPARAMSPEC_LUA_NAME);
	if( ud->spec==NULL )
		luaL_argerror(L, idx, "GParamSpec already free");
	return ud->spec;
}

static int lua_param_sepc_name(lua_State* L) {
	GParamSpec* spec = lua_param_check(L, 1);
	lua_pushfstring(L, "%s", g_param_spec_get_name(spec));
	return 1;
}

static int lua_param_sepc_nick(lua_State* L) {
	GParamSpec* spec = lua_param_check(L, 1);
	lua_pushfstring(L, "%s", g_param_spec_get_nick(spec));
	return 1;
}

static int lua_param_sepc_blurb(lua_State* L) {
	GParamSpec* spec = lua_param_check(L, 1);
	lua_pushfstring(L, "%s", g_param_spec_get_blurb(spec));
	return 1;
}

static luaL_Reg param_spec_methods[] =
	{ {"__gc",			lua_param_sepc_unref}
	, {"__tostring",	lua_param_sepc_tostring}
	, {"name",			lua_param_sepc_name}
	, {"nick",			lua_param_sepc_nick}
	, {"blurb",			lua_param_sepc_blurb}
	, {NULL, NULL}
	};

static void lua_gparamspec_push(lua_State* L, GParamSpec* spec) {
	GParamSpecLua* ud = lua_newuserdata(L, sizeof(GParamSpecLua));
	if( luaL_newmetatable(L, GPARAMSPEC_LUA_NAME) ) {
		luaL_setfuncs(L, param_spec_methods, 0);
		lua_pushvalue(L, -1);
		lua_setfield(L, -2, "__index");
	}
	lua_setmetatable(L, -2);
	ud->spec = g_param_spec_ref_sink(spec);
}

static GParamSpec* lua_gparamspec_test(lua_State* L, int idx) {
	GParamSpecLua* ud = luaL_testudata(L, 1, GPARAMSPEC_LUA_NAME);
	return ud ? ud->spec : NULL;
}

static void lua_param_gvalue_push(lua_State* L, const GValue* v) {
	lua_gparamspec_push(L, g_value_get_param(v));
}

static void _lua_gvalue_push(lua_State* L, GType fundamental_type, const GValue* v) {
	switch( fundamental_type ) {
	case G_TYPE_NONE:		lua_pushnil(L);		break;
	case G_TYPE_INVALID:	lua_pushnil(L);		break;
	case G_TYPE_CHAR:		{ gchar ch = g_value_get_schar(v); lua_pushlstring(L, &ch, 1); }	break;
	case G_TYPE_UCHAR:		lua_pushinteger(L, g_value_get_uchar(v));	break;
	case G_TYPE_BOOLEAN:	lua_pushboolean(L, g_value_get_boolean(v));	break;
	case G_TYPE_INT:		lua_pushinteger(L, g_value_get_int(v));		break;
	case G_TYPE_UINT:		lua_pushinteger(L, g_value_get_uint(v));	break;
	case G_TYPE_LONG:		lua_pushinteger(L, g_value_get_long(v));	break;
	case G_TYPE_ULONG:		lua_pushinteger(L, g_value_get_ulong(v));	break;
	case G_TYPE_INT64:		lua_pushinteger(L, g_value_get_int64(v));	break;
	case G_TYPE_UINT64:		lua_pushinteger(L, g_value_get_uint64(v));	break;
	case G_TYPE_ENUM:		lua_pushinteger(L, g_value_get_enum(v));	break;	// derived
	case G_TYPE_FLAGS:		lua_pushinteger(L, g_value_get_flags(v));	break;	// derived
	case G_TYPE_FLOAT:		lua_pushnumber(L, g_value_get_float(v));	break;
	case G_TYPE_DOUBLE:		lua_pushnumber(L, g_value_get_double(v));	break;
	case G_TYPE_STRING:		lua_pushstring(L, g_value_get_string(v));	break;
	case G_TYPE_POINTER:	lua_pushlightuserdata(L, g_value_get_pointer(v));	break;
	case G_TYPE_BOXED:		lua_gboxedvalue_push(L, v);				break;
	case G_TYPE_PARAM:		lua_param_gvalue_push(L, v);				break;	// derived
	case G_TYPE_OBJECT:		lua_gobject_push(L, (GObject*)g_value_get_object(v), TRUE);	break;
	// case G_TYPE_VARIANT:	break;	// TODO if need
	default:
		g_warning("lua_gvalue_push push nil for not support type(%s) now", G_VALUE_TYPE_NAME(v));
		lua_pushnil(L);
		break;
	}
}

static void lua_gvalue_push(lua_State* L, const GValue* v) {
	GType tp = G_VALUE_TYPE(v);
	_lua_gvalue_push(L, G_TYPE_IS_FUNDAMENTAL(tp) ? tp : g_type_fundamental(tp), v);
}

static void _lua_gvalue_test(lua_State* L, int idx, GType fundamental_type, GValue* v) {
	switch( fundamental_type ) {
	case G_TYPE_NONE:		break;
	case G_TYPE_INVALID:	break;
	case G_TYPE_CHAR:
		{
			size_t len = 0;
			const char* str = lua_tolstring(L, idx, &len);
			if( len != 1 )
				luaL_error(L, "check G_TYPE_CHAR not string or length not 1");
			g_value_set_schar(v, str[0]);
		}
		break;
	case G_TYPE_UCHAR:		g_value_set_uchar(v, (guchar)lua_tointeger(L, idx));	break;
	case G_TYPE_BOOLEAN:	g_value_set_boolean(v, (gboolean)lua_toboolean(L, idx));break;
	case G_TYPE_INT:		g_value_set_int(v, (gint)lua_tointeger(L, idx));		break;
	case G_TYPE_UINT:		g_value_set_uint(v, (guint)lua_tointeger(L, idx));		break;
	case G_TYPE_LONG:		g_value_set_long(v, (glong)lua_tointeger(L, idx));		break;
	case G_TYPE_ULONG:		g_value_set_ulong(v, (gulong)lua_tointeger(L, idx));	break;
	case G_TYPE_INT64:		g_value_set_int64(v, (gint64)lua_tointeger(L, idx));	break;
	case G_TYPE_UINT64:		g_value_set_uint64(v, (guint64)lua_tointeger(L, idx));	break;
	case G_TYPE_ENUM:		g_value_set_enum(v, (gint)lua_tointeger(L, idx));		break;	// derived
	case G_TYPE_FLAGS:		g_value_set_flags(v, (guint)lua_tointeger(L, idx));		break;	// derived
	case G_TYPE_FLOAT:		g_value_set_float(v, (gfloat)lua_tonumber(L, idx));		break;
	case G_TYPE_DOUBLE:		g_value_set_double(v, (gdouble)lua_tonumber(L, idx));	break;
	case G_TYPE_STRING:		g_value_set_string(v, lua_tostring(L, idx));			break;
	case G_TYPE_POINTER:	g_value_set_pointer(v, (gpointer)lua_topointer(L, idx));break;
	case G_TYPE_BOXED:		g_value_set_boxed(v, g_value_dup_boxed(lua_gboxedvalue_test(L, idx)));	break;
	case G_TYPE_PARAM:		g_value_set_param(v, lua_gparamspec_test(L, idx));		break;	// derived
	case G_TYPE_OBJECT:
		{
			GObject* obj = lua_gobject_test(L, idx);
			g_value_set_object(v, obj ? g_object_ref(obj) : NULL);
		}
		break;
	// case G_TYPE_VARIANT:	break;	// TODO if need
	default:
		g_warning("lua_gvalue_test not support type(%s) now!", G_VALUE_TYPE_NAME(v));
		lua_pushnil(L);
		break;
	}
}

static void lua_gvalue_test(lua_State* L, int idx, GValue* v) {
	GType tp = G_VALUE_TYPE(v);
	_lua_gvalue_test(L, idx, G_TYPE_IS_FUNDAMENTAL(tp) ? tp : g_type_fundamental(tp), v);
}

static int _lua_gclosure_marshal_wrapper(lua_State* L) {
	MarshalLuaCallEnv* env = (MarshalLuaCallEnv*)(*((void**)lua_getextraspace(L)));
	assert( lua_gettop(L)==1 && lua_isfunction(L, -1) );

	guint i;
	for( i=0; i<env->n_param_values; ++i )
		lua_gvalue_push(L, env->param_values + i);

	lua_call(L, lua_gettop(L)-1, env->return_value ? 1 : 0);

	if( env->return_value )
		lua_gvalue_test(L, 1, env->return_value);

	return 0;
}

static void lua_gclosure_marshal(GClosure* closure
	, GValue *return_value
	, guint n_param_values
	, const GValue *param_values
	, gpointer invocation_hint
	, gpointer marshal_data)
{
	SingalHandleLua* h = (SingalHandleLua*)(closure->data);
	g_return_if_fail( (h && h->L) );
	MarshalLuaCallEnv env = { return_value, n_param_values, param_values };
	lua_State* L = h->L;
	*((void**)lua_getextraspace(L)) = (void*)(&env);

	lua_pushcfunction(L, _lua_gclosure_marshal_wrapper);
	lua_rawgeti(L, LUA_REGISTRYINDEX, h->ref);
	lua_getuservalue(L, -1);
	lua_remove(L, -2);
	if( lua_pcall(L, 1, 0, 0) ) {
		g_warning("lua_gclosure_marshal error : %s", lua_tostring(L, -1));
		lua_pop(L, 1);
	}
}

static int lua_signal_handle_tostring(lua_State* L) {
	lua_pushfstring(L, "%s:%p", GSIGNAL_HANDLE_LUA_NAME, lua_touserdata(L, 1));
	return 1;
}

static int lua_signal_handle_disconnect(lua_State* L) {
	SingalHandleLua* h = (SingalHandleLua*)luaL_checkudata(L, 1, GSIGNAL_HANDLE_LUA_NAME);

	if( h->L ) {
		luaL_unref(h->L, LUA_REGISTRYINDEX, h->ref);
		h->L = NULL;
		h->ref = LUA_NOREF;
	}

	if( h->signal_handle_id ) {
		g_signal_handler_disconnect(h->obj, h->signal_handle_id);
		h->obj = NULL;
		h->signal_handle_id = 0;
	}

	return 0;
}

static luaL_Reg _signal_handle_methods[] = 
	{ {"__gc",			lua_signal_handle_disconnect}
	, {"__tostring",	lua_signal_handle_tostring}
	, {"disconnect",	lua_signal_handle_disconnect}
	, {NULL, NULL}
	};

static void lua_singal_handle_finalize_notifier(gpointer ud, GClosure* closure) {
	// closure->data
	SingalHandleLua* h = (SingalHandleLua*)ud;
	h->obj = NULL;
	h->signal_handle_id = 0;

	if( h->L ) {
		SingalHandleLua t = *h;
		h->L = NULL;
		h->ref = LUA_NOREF;
		luaL_unref(t.L, LUA_REGISTRYINDEX, t.ref);
	}
}

static int _lua_gobject_gc(lua_State* L) {
	GObjectLua* ud = (GObjectLua*)luaL_checkudata(L, 1, GOBJECT_LUA_NAME);
	if( ud->obj ) {
		if( ud->weak_ref )
			g_object_remove_weak_pointer(ud->obj, &(ud->obj));
		else
			g_object_unref(ud->obj);
		ud->obj = NULL;
	}
	return 0;
}

static int _lua_gobject_eq(lua_State* L) {
	GObjectLua* a = (GObjectLua*)luaL_checkudata(L, 1, GOBJECT_LUA_NAME);
	GObjectLua* b = (GObjectLua*)luaL_testudata(L, 1, GOBJECT_LUA_NAME);
	lua_pushboolean(L, b ? (a->obj==b->obj) : (a->obj==NULL));
	return 1;
}

static int _lua_gobject_tostring(lua_State* L) {
	GObjectLua* ud = (GObjectLua*)luaL_checkudata(L, 1, GOBJECT_LUA_NAME);
	if( ud->obj ) {
		lua_pushfstring(L, "%s(%s:%p)", G_OBJECT_TYPE_NAME(ud->obj), ud->weak_ref?"weakref":"ref", ud->obj);
	} else {
		lua_pushliteral(L, "GObject(null)");
	}
	return 1;
}

static int _lua_gobject_index(lua_State* L) {
	GObject* obj = _gobject_check(L, 1);
	luaL_checkany(L, 2);

	lua_getuservalue(L, 1);		// search cache
	if( lua_isnil(L, -1) ) {
		lua_getmetatable(L, 1);
		lua_rawgeti(L, -1, 1);	// extra table
		lua_getfield(L, -1, G_OBJECT_TYPE_NAME(obj));	// find MT
		if( lua_isnil(L, -1) ) {
			lua_pop(L, 2);
			lua_rawgeti(L, -1, 2);	// not find, use empty MT
		}
		lua_pushvalue(L, -1);	// cache MT
		lua_setuservalue(L, 1);
	}

	if( lua_isfunction(L, -1) ) {
		lua_pushvalue(L, 1);
		lua_pushvalue(L, 2);
		lua_call(L, 2, 1);
	} else {
		lua_pushvalue(L, 2);
		lua_gettable(L, -2);
	}
	return 1;
}

static luaL_Reg _gobject_methods[] =
	{ {"__gc",				_lua_gobject_gc}
	, {"__eq",				_lua_gobject_eq}
	, {"__tostring",		_lua_gobject_tostring}
	, {"__index",			_lua_gobject_index}
	, {NULL, NULL}
	};

static int _lua_gobject_empty_metatable(lua_State* L) {
	return 0;
}

static void _gobject_metatable_new(lua_State* L) {
	if( luaL_newmetatable(L, GOBJECT_LUA_NAME) ) {
		luaL_setfuncs(L, _gobject_methods, 0);

		// metatable[1] = { __extra_types__[gtypename:mt] }
		lua_newtable(L);
		lua_rawseti(L, -2, 1);

		// metatable[2] = function() end	-- empty MT
		lua_pushcfunction(L, _lua_gobject_empty_metatable);
		lua_rawseti(L, -2, 2);
	}
}

static int lua_gtype_get_metatables(lua_State* L) {
	_gobject_metatable_new(L);
	lua_rawgeti(L, -1, 1);
	return 1;
}

static int lua_gtype_list_properties(lua_State* L) {
	GType tp = g_type_from_name(luaL_checkstring(L, 1));
	if( !G_TYPE_IS_CLASSED(tp) )
		return 0;
	GObjectClass* klass = g_type_class_peek(tp);
	if( !klass )
		return 0;
	guint i, n;
	GParamSpec** props = g_object_class_list_properties(klass, &n);
	lua_createtable(L, n, 0);
	for( i=0; i<n; ++i ) {
		lua_gparamspec_push(L, props[i]);
		lua_rawseti(L, -2, i+1);
	}
	return 1;
}

static int lua_gtype_from_name(lua_State* L) {
	const char* gtypename = luaL_checkstring(L, 1);
	lua_pushinteger(L, (lua_Integer)g_type_from_name(gtypename));
	return 1;
}

static int lua_gtype_name(lua_State* L) {
	GType type = (GType)luaL_checkinteger(L, 1);
	const char* gtypename = g_type_name(type);
	lua_pushstring(L, gtypename);
	return 1;
}

static int lua_gobject_new(lua_State* L) {
	const char* gtypename = luaL_checkstring(L, 1);
	GType gtype = g_type_from_name(gtypename);
	if( gtype==G_TYPE_INVALID )
		return luaL_error(L, "not find GType(%s)", gtypename);
	GObject* obj = g_object_new(gtype, NULL);
	if( !obj )
		return 0;
	lua_gobject_push(L, obj, FALSE);
	return 1;
}

static int lua_gobject_get(lua_State* L) {
	GObject* obj = _gobject_check(L, 1);
	gpointer klass = G_OBJECT_GET_CLASS(obj);
	int top = lua_gettop(L);
	int i;
	for( i=2; i<=top; ++i ) {
		const char* prop = luaL_checkstring(L, i);
		GParamSpec* spec = g_object_class_find_property(klass, prop);
		if( !spec )
			luaL_error(L, "gobject prop(%s) not found!", prop);

		GValue v = G_VALUE_INIT;
		g_value_init(&v, G_PARAM_SPEC_VALUE_TYPE(spec));
		g_object_get_property(obj, prop, &v);
		lua_gvalue_push(L, &v);
		lua_replace(L, i);
		g_value_unset(&v);
	}
	return top - 1;
}

static int lua_gobject_set(lua_State* L) {
	GObject* obj = _gobject_check(L, 1);
	gpointer klass = G_OBJECT_GET_CLASS(obj);
	int top = lua_gettop(L);
	int i;
	for( i=2; i<=top; i+=2 ) {
		const char* prop = luaL_checkstring(L, i);
		GParamSpec* spec = g_object_class_find_property(klass, prop);
		if( !spec )
			luaL_error(L, "gobject prop(%s) not found!", prop);

		GValue v = G_VALUE_INIT;
		g_value_init(&v, G_PARAM_SPEC_VALUE_TYPE(spec));
		lua_gvalue_test(L, i+1, &v);
		g_object_set_property(obj, prop, &v);
		g_value_unset(&v);
	}
	return 0;
}

static int lua_gobject_signal_connect(lua_State* L) {
	GObject* obj = _gobject_check(L, 1);
	const char* detailed_signal = luaL_checkstring(L, 2);
	luaL_checktype(L, 3, LUA_TFUNCTION);
	gboolean after = lua_toboolean(L, 4);

	lua_rawgeti(L, LUA_REGISTRYINDEX, LUA_RIDX_MAINTHREAD);
	lua_State* mainL = lua_tothread(L, -1);
	lua_pop(L, 1);

	SingalHandleLua* h = (SingalHandleLua*)lua_newuserdata(L, sizeof(SingalHandleLua));
	if( luaL_newmetatable(L, GSIGNAL_HANDLE_LUA_NAME) ) {
		luaL_setfuncs(L, _signal_handle_methods, 0);
		lua_pushvalue(L, -1);
		lua_setfield(L, -2, "__index");
	}
	lua_setmetatable(L, -2);
	lua_pushvalue(L, 3);
	lua_setuservalue(L, -2);

	GClosure* closure = g_closure_new_simple(sizeof(GClosure), h);
	g_closure_set_marshal(closure, lua_gclosure_marshal);
	g_closure_add_finalize_notifier(closure, h, lua_singal_handle_finalize_notifier);
	h->obj = obj;
	h->signal_handle_id = g_signal_connect_closure(obj, detailed_signal, closure, after);
	h->L = mainL;
	lua_pushvalue(L, -1);
	h->ref = luaL_ref(L, LUA_REGISTRYINDEX);
	return 1;
}

int lua_gtype_register_metatable_index(lua_State* L) {
	GType tp = (GType)luaL_checkinteger(L, 1);
	switch( lua_type(L,2) ) {
	case LUA_TFUNCTION:
	case LUA_TTABLE:
		break;
	default:
		luaL_argerror(L, 2, "need table or function!");
		break;
	}

	if( G_TYPE_IS_OBJECT(tp) ) {
		_gobject_metatable_new(L);
	} else if( G_TYPE_IS_VALUE(tp) ) {
		_gvalue_metatable_new(L);
	} else {
		luaL_error(L, "(%s) not need register, only support G_TYPE_BOXED & G_TYPE_OBJECT!", g_type_name(tp));
	}

	lua_rawgeti(L, -1, 1);				// extra table
	lua_pushstring(L, g_type_name(tp));	// name
	lua_pushvalue(L, 2);				// MT or index
	lua_settable(L, -3);
	return 0;
}

static luaL_Reg _gobject_module_methods[] = 
	{ {"gtype_get_metatables",			lua_gtype_get_metatables}
	, {"gtype_list_properties",			lua_gtype_list_properties}
	, {"gtype_from_name",				lua_gtype_from_name}
	, {"gtype_name",					lua_gtype_name}

	, {"new",							lua_gobject_new}
	, {"get",							lua_gobject_get}
	, {"set",							lua_gobject_set}
	, {"signal_connect",				lua_gobject_signal_connect}
	, {"signal_handle_disconnect",		lua_signal_handle_disconnect}

	, {NULL, NULL}
	};

void lua_gobject_open(lua_State* L) {
	lua_newtable(L);
	luaL_setfuncs(L, _gobject_module_methods, 0);
	lua_setglobal(L, "__gobject__");
}

void lua_gobject_push(lua_State* L, GObject* obj, gboolean weak_ref) {
	GObjectLua* ud;
	if( !obj ) {
		lua_pushnil(L);
		return;
	}

	ud = (GObjectLua*)lua_newuserdata(L, sizeof(GObjectLua));
	ud->obj = NULL;
	ud->weak_ref = weak_ref;
	_gobject_metatable_new(L);
	lua_setmetatable(L, -2);

	if( weak_ref ) {
		ud->obj = obj;
		g_object_add_weak_pointer(obj, &(ud->obj));
	} else {
		ud->obj = g_object_ref_sink(obj);
		//ud->obj = g_object_is_floating(obj) ? g_object_ref_sink(obj) : g_object_ref(obj);
		//ud->obj = g_object_ref(obj);
	}
}

GObject* lua_gobject_check(lua_State* L, int idx) {
	return _gobject_check(L, idx);
}

GObject* lua_gobject_test(lua_State* L, int idx) {
	return _gobject_test(L, idx);
}

void lua_gtype_register_index_table(lua_State* L, GType type, luaL_Reg* methods) {
	lua_pushcfunction(L, lua_gtype_register_metatable_index);
	lua_pushinteger(L, (lua_Integer)type);
	lua_newtable(L);
	luaL_setfuncs(L, methods, 0);
	lua_call(L, 2, 0);
}

void lua_gtype_register_index_function(lua_State* L, GType type, lua_CFunction func) {
	lua_pushcfunction(L, lua_gtype_register_metatable_index);
	lua_pushinteger(L, (lua_Integer)type);
	lua_pushcfunction(L, func);
	lua_call(L, 2, 0);
}

