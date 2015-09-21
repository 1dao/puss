// glua.c
// 

#include "glua.h"

#include <assert.h>
#include <memory.h>
#include <string.h>

static const char*	GOBJECT_MASTER_TABLE_NAME  = "__gobject_master__";
static const char*	GOBJECT_TYPES_TABLE_NAME   = "__gobject_types__";
static const char*	GOBJECT_G_TYPES_TABLE_NAME = "__gobject_gtypes__";

static const char*	GOBJECT_LUA_NAME = "__GOBJECT__";
static const char*	GERROR_LUA_NAME = "__GERROR__";
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

static void _fundamental_types_register(lua_State* L);

static void _lua_push_types_table(lua_State* L) {
	// types = { GTypeName : TypeMethods }	-- ONLY type methods, not include parents or interfaces methods
	if( lua_getfield(L, LUA_REGISTRYINDEX, GOBJECT_TYPES_TABLE_NAME)!=LUA_TTABLE ) {
		lua_pop(L, 1);
		lua_newtable(L);

		lua_pushvalue(L, -1);
		lua_setfield(L, LUA_REGISTRYINDEX, GOBJECT_TYPES_TABLE_NAME);

		_fundamental_types_register(L);
	}
}

static void _lua_push_g_types_table(lua_State* L) {
	// __gtypes__ = { GType : AllMethods }	-- all type methods, INCLUDE parents and interfaces methods
	if( lua_getfield(L, LUA_REGISTRYINDEX, GOBJECT_G_TYPES_TABLE_NAME)!=LUA_TTABLE ) {
		lua_pop(L, 1);
		lua_newtable(L);
		lua_pushvalue(L, -1);
		lua_setfield(L, LUA_REGISTRYINDEX, GOBJECT_G_TYPES_TABLE_NAME);
	}
}

static void _lua_hash_table_copy_top_table_into_target_table(lua_State* L, int target) {
	assert( target > 0 );
	assert( lua_type(L, target)==LUA_TTABLE );
	assert( lua_type(L, -1)==LUA_TTABLE );

	lua_pushnil(L);
	while( lua_next(L, -2) ) {
		// assert( lua_type(L, -1)==LUA_TFUNCTION );

		lua_pushvalue(L, -2);	// k,v ==> k,k,v
		lua_insert(L, -2);
		// assert( lua_type(L, -1)==LUA_TFUNCTION );

		//const char* x = luaL_tolstring(L, -1, NULL);
		//fprintf(stderr, "		fetch : %s - %s\n", lua_tostring(L, -3), x );
		//lua_pop(L, 1);

		lua_rawset(L, target);	// set to all methods table

		// lua_pushvalue(L, -1);	// push k
		// assert( lua_rawget(L, -5)==LUA_TFUNCTION );
		// lua_pop(L, 1);
	}
}

static void _lua_fetch_g_type_all_methods_table(lua_State* L, GType tp) {
	int top = lua_gettop(L);
	_lua_push_g_types_table(L);
	if( lua_rawgeti(L, -1, (lua_Integer)tp)!=LUA_TTABLE ) {
		lua_pop(L, 1);

		lua_newtable(L);			// gtype all methods table
		int gtype_table_index = lua_gettop(L);

		lua_pushvalue(L, -1);		// set all methods table to gtypes table
		lua_rawseti(L, -3, (lua_Integer)tp);

		// copy parent type methods
		GType parent = g_type_parent(tp);
		if( parent != G_TYPE_INVALID ) {
			_lua_fetch_g_type_all_methods_table(L, parent);
			assert( lua_istable(L, -1) );
			_lua_hash_table_copy_top_table_into_target_table(L, gtype_table_index);
			lua_pop(L, 1);
		}

		// iterator all interfaces
		GType* interfaces = g_type_interfaces(tp, NULL);
		if( interfaces ) {
			GType* p;
			for( p=interfaces; *p; ++p ) {
				// fetch type methods from types table & copy to all methods table
				_lua_fetch_g_type_all_methods_table(L, parent);
				assert( lua_istable(L, -1) );
				_lua_hash_table_copy_top_table_into_target_table(L, gtype_table_index);
				lua_pop(L, 1);
			}
			g_free(interfaces);
		}

		// copy self type methods
		// fprintf(stderr, "fetch type : %s\n", g_type_name(tp));
		_lua_push_types_table(L);	// types table
		if( lua_getfield(L, -1, g_type_name(tp))==LUA_TTABLE )	// type table
			_lua_hash_table_copy_top_table_into_target_table(L, gtype_table_index);
		lua_pop(L, 2);			// pop type table & types table

		assert( lua_gettop(L)==gtype_table_index );
	}

	lua_remove(L, -2);			// remove gtypes table
	assert( lua_gettop(L)==(top+1) );
}

GValue* glua_boxed_check(lua_State* L, int idx) {
	return luaL_checkudata(L, idx, GBOXEDVALUE_LUA_NAME);
}

GValue* glua_boxed_test(lua_State* L, int idx) {
	return luaL_testudata(L, idx, GBOXEDVALUE_LUA_NAME);
}

static int lua_gboxed_unset(lua_State* L) {
	GValue* v = glua_boxed_check(L, 1);
	g_value_unset(v);
	return 0;
}

static int lua_gboxed_tostring(lua_State* L) {
	GValue* v = glua_boxed_check(L, 1);
	lua_pushfstring(L, "%s(%s):%p", GBOXEDVALUE_LUA_NAME, G_VALUE_TYPE_NAME(v), v);
	return 1;
}

static int lua_gboxed_index(lua_State* L) {
	GValue* v = glua_boxed_check(L, 1);
	luaL_checkany(L, 2);

	if( lua_getuservalue(L, 1)!=LUA_TTABLE ) {	// search cache
		lua_pop(L, 1);
		_lua_fetch_g_type_all_methods_table(L, G_VALUE_TYPE(v));
		lua_pushvalue(L, -1);
		lua_setuservalue(L, 1);
	}

	lua_pushvalue(L, 2);
	lua_gettable(L, -2);
	return 1;
}

static luaL_Reg gboxed_methods[] =
	{ {"__gc",			lua_gboxed_unset}
	, {"__tostring",	lua_gboxed_tostring}
	, {"__index",		lua_gboxed_index}
	, {NULL, NULL}
	};

void lua_gboxed_push(lua_State* L, const GValue* v) {
	GValue* ud = lua_newuserdata(L, sizeof(GValue));
	memset(ud, 0, sizeof(GValue));
	g_value_init(ud, G_VALUE_TYPE(v));
	g_value_copy(v, ud);
	if( luaL_newmetatable(L, GBOXEDVALUE_LUA_NAME) )
		luaL_setfuncs(L, gboxed_methods, 0);
	lua_setmetatable(L, -2);
}

static int lua_param_sepc_unref(lua_State* L) {
	GParamSpec** ud = luaL_checkudata(L, 1, GPARAMSPEC_LUA_NAME);
	if( *ud ) {
		g_param_spec_unref(*ud);
		*ud = NULL;
	}
	return 0;
}

static int lua_param_sepc_tostring(lua_State* L) {
	GParamSpec** ud = luaL_checkudata(L, 1, GPARAMSPEC_LUA_NAME);
	const char* vtype = g_type_name(G_PARAM_SPEC_VALUE_TYPE(*ud));
	const char* name = g_param_spec_get_name(*ud);
	const char* nick = g_param_spec_get_nick(*ud);
	const char* blurb = g_param_spec_get_blurb(*ud);
	char buf[4096];
	sprintf(buf, "%s:%p {valuetype=%s name=%s nick=%s blurb=%s}"
		, GPARAMSPEC_LUA_NAME
		, *ud
		, vtype
		, name
		, nick
		, blurb);
	lua_pushstring(L, buf);
	return 1;
}

static GParamSpec* lua_param_check(lua_State* L, int idx) {
	GParamSpec** ud = luaL_checkudata(L, 1, GPARAMSPEC_LUA_NAME);
	if( *ud==NULL )
		luaL_argerror(L, idx, "GParamSpec already free");
	return *ud;
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
	GParamSpec** ud = lua_newuserdata(L, sizeof(GParamSpec*));
	if( luaL_newmetatable(L, GPARAMSPEC_LUA_NAME) ) {
		luaL_setfuncs(L, param_spec_methods, 0);
		lua_pushvalue(L, -1);
		lua_setfield(L, -2, "__index");
	}
	lua_setmetatable(L, -2);
	*ud = g_param_spec_ref_sink(spec);
}

static GParamSpec* lua_gparamspec_test(lua_State* L, int idx) {
	GParamSpec** ud = luaL_testudata(L, 1, GPARAMSPEC_LUA_NAME);
	return ud ? *ud : NULL;
}

static void lua_param_gvalue_push(lua_State* L, const GValue* v) {
	lua_gparamspec_push(L, g_value_get_param(v));
}

static void _glua_value_push(lua_State* L, GType fundamental_type, const GValue* v) {
	switch( fundamental_type ) {
	case G_TYPE_INVALID:	lua_pushnil(L);		break;
	case G_TYPE_NONE:		lua_pushnil(L);		break;
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
	case G_TYPE_BOXED:		lua_gboxed_push(L, v);				break;
	case G_TYPE_PARAM:		lua_param_gvalue_push(L, v);				break;	// derived
	case G_TYPE_INTERFACE:
	case G_TYPE_OBJECT:		glua_object_push(L, (GObject*)g_value_get_object(v), TRUE);	break;
	// case G_TYPE_VARIANT:	break;	// TODO if need
	default:
		fprintf(stderr, "glua_value_push push nil for not support type(%s) now", G_VALUE_TYPE_NAME(v));
		lua_pushnil(L);
		break;
	}
}

GValue* glua_boxed_push(lua_State* L, GType tp, gconstpointer ptr) {
	GValue* v = lua_newuserdata(L, sizeof(GValue));
	memset(v, 0, sizeof(GValue));
	g_value_init(v, tp);
	if( ptr )
		g_value_set_boxed(v, ptr);
	if( luaL_newmetatable(L, GBOXEDVALUE_LUA_NAME) )
		luaL_setfuncs(L, gboxed_methods, 0);
	lua_setmetatable(L, -2);
	return v;
}

void glua_value_push(lua_State* L, const GValue* v) {
	GType tp = G_VALUE_TYPE(v);
	_glua_value_push(L, G_TYPE_IS_FUNDAMENTAL(tp) ? tp : g_type_fundamental(tp), v);
}

static void _glua_value_from_lua(lua_State* L, int idx, GType fundamental_type, GValue* v) {
	switch( fundamental_type ) {
	case G_TYPE_INVALID:	break;
	case G_TYPE_NONE:		break;
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
	case G_TYPE_BOXED:		g_value_set_boxed(v, g_value_dup_boxed(glua_boxed_test(L, idx)));	break;
	case G_TYPE_PARAM:		g_value_set_param(v, lua_gparamspec_test(L, idx));		break;	// derived
	case G_TYPE_INTERFACE:
	case G_TYPE_OBJECT:
		{
			GObject* obj = glua_object_test(L, idx);
			g_value_set_object(v, obj ? g_object_ref(obj) : NULL);
		}
		break;
	// case G_TYPE_VARIANT:	break;	// TODO if need
	default:
		fprintf(stderr, "glua_value_from_lua not support type(%s) now!", G_VALUE_TYPE_NAME(v));
		lua_pushnil(L);
		break;
	}
}

void glua_value_from_lua(lua_State* L, int idx, GValue* v) {
	GType tp = G_VALUE_TYPE(v);
	_glua_value_from_lua(L, idx, G_TYPE_IS_FUNDAMENTAL(tp) ? tp : g_type_fundamental(tp), v);
}

static int _lua_gclosure_marshal_wrapper(lua_State* L) {
	MarshalLuaCallEnv* env = (MarshalLuaCallEnv*)(*((void**)lua_getextraspace(L)));
	assert( lua_gettop(L)==1 && lua_isfunction(L, -1) );

	guint i;
	for( i=0; i<env->n_param_values; ++i )
		glua_value_push(L, env->param_values + i);

	lua_call(L, lua_gettop(L)-1, env->return_value ? 1 : 0);

	if( env->return_value )
		glua_value_from_lua(L, 1, env->return_value);

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
		fprintf(stderr, "lua_gclosure_marshal error : %s", lua_tostring(L, -1));
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

	if( lua_getuservalue(L, 1)!=LUA_TTABLE ) {	// search cache
		lua_pop(L, 1);
		_lua_fetch_g_type_all_methods_table(L, G_OBJECT_TYPE(obj));
		lua_pushvalue(L, -1);
		lua_setuservalue(L, 1);
	}

	lua_pushvalue(L, 2);
	lua_gettable(L, -2);
	return 1;
}

static luaL_Reg _gobject_methods[] =
	{ {"__gc",				_lua_gobject_gc}
	, {"__eq",				_lua_gobject_eq}
	, {"__tostring",		_lua_gobject_tostring}
	, {"__index",			_lua_gobject_index}
	, {NULL, NULL}
	};

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

static int lua_gtype_from_instance(lua_State* L) {
	GType tp = G_TYPE_INVALID;
	if( lua_isuserdata(L, 1) ) {
		GObject* o = glua_object_test(L, 1);
		if( o ) {
			tp = G_OBJECT_TYPE(o);
		} else {
			GValue* v = glua_boxed_test(L, 1);
			if( v ) {
				tp = G_VALUE_TYPE(v);
			}
		}
	}

	if( tp==G_TYPE_INVALID )
		return 0;
	lua_pushinteger(L, tp);
	return 1;
}

static int lua_gtype_from_name(lua_State* L) {
	const char* gtypename = luaL_checkstring(L, 1);
	GType tp = g_type_from_name(gtypename);
	if( tp==G_TYPE_INVALID )
		return 0;
	lua_pushinteger(L, tp);
	return 1;
}

static int lua_gtype_name_from_instance(lua_State* L) {
	GType tp = G_TYPE_INVALID;
	if( lua_isuserdata(L, 1) ) {
		GObject* o = glua_object_test(L, 1);
		if( o ) {
			tp = G_OBJECT_TYPE(o);
		} else {
			GValue* v = glua_boxed_test(L, 1);
			if( v ) {
				tp = G_VALUE_TYPE(v);
			}
		}
	}

	if( tp==G_TYPE_INVALID )
		return 0;

	lua_pushstring(L, g_type_name(tp));
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
	glua_object_push(L, obj, FALSE);
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
		glua_value_push(L, &v);
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
		glua_value_from_lua(L, i+1, &v);
		g_object_set_property(obj, prop, &v);
		g_value_unset(&v);
	}
	return 0;
}

int glua_singal_connect(lua_State* L) {
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

static luaL_Reg _gobject_module_methods[] = 
	{ {"gtype_list_properties",			lua_gtype_list_properties}
	, {"gtype_from_instance",			lua_gtype_from_instance}
	, {"gtype_from_name",				lua_gtype_from_name}
	, {"gtype_name_from_instance",		lua_gtype_name_from_instance}
	, {"new",							lua_gobject_new}
	, {NULL, NULL}
	};

static luaL_Reg _gobject_metatable_methods[] = 
	{ {"get",							lua_gobject_get}
	, {"set",							lua_gobject_set}
	, {"signal_connect",				glua_singal_connect}
	, {"signal_handle_disconnect",		lua_signal_handle_disconnect}
	, {NULL, NULL}
	};

static void _fundamental_types_register(lua_State* L) {
	glua_reg_gtype_index_table(L, G_TYPE_OBJECT, _gobject_metatable_methods);
	glua_reg_gtype_index_table(L, G_TYPE_INITIALLY_UNOWNED, NULL);
}

static int _lua_gobject_empty_metatable(lua_State* L) {
	return 0;
}

void glua_push_master_table(lua_State* L) {
	if( lua_getfield(L, LUA_REGISTRYINDEX, GOBJECT_MASTER_TABLE_NAME)!=LUA_TTABLE ) {
		lua_pop(L, 1);

		// new master table & set to register
		lua_newtable(L);
		lua_pushvalue(L, -1);
		lua_setfield(L, LUA_REGISTRYINDEX, GOBJECT_MASTER_TABLE_NAME);

		luaL_setfuncs(L, _gobject_module_methods, 0);

		// master.types = { GTypeName : TypeMethods }	-- ONLY type methods, not include parents or interfaces methods
		_lua_push_types_table(L);
		lua_setfield(L, -2, "types");

		// master.__gtypes__ = { GType : AllMethods }	-- all type methods, INCLUDE parents and interfaces methods
		_lua_push_g_types_table(L);
		lua_setfield(L, -2, "__gtypes__");
	}
}

void glua_object_push(lua_State* L, GObject* obj, gboolean weak_ref) {
	GObjectLua* ud;
	if( !obj ) {
		lua_pushnil(L);
		return;
	}

	ud = (GObjectLua*)lua_newuserdata(L, sizeof(GObjectLua));
	ud->obj = NULL;
	ud->weak_ref = weak_ref;
	if( luaL_newmetatable(L, GOBJECT_LUA_NAME) )
		luaL_setfuncs(L, _gobject_methods, 0);
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

GObject* glua_object_check(lua_State* L, int idx) {
	return _gobject_check(L, idx);
}

GObject* glua_object_test(lua_State* L, int idx) {
	return _gobject_test(L, idx);
}

gpointer glua_object_check_type(lua_State* L, int idx, GType type) {
	GObject* obj = _gobject_check(L, idx);
	GType vtp = G_OBJECT_TYPE(obj);
	if( !g_type_is_a(vtp, type) ) {
		char err[512];
		sprintf(err, "glua_object_check_type need(%s) but got(%s)", g_type_name(type), g_type_name(vtp));
		luaL_argerror(L, idx, err);
	}
	return obj;
}

void glua_new_gtype_index_table(lua_State* L, GType type) {
	lua_newtable(L);
	_lua_push_types_table(L);
	lua_pushvalue(L, -2);
	lua_setfield(L, -2, g_type_name(type));
	lua_pop(L, 1);
}

void glua_reg_gtype_index_table(lua_State* L, GType type, luaL_Reg* methods) {
	glua_new_gtype_index_table(L, type);
	if( methods )
		luaL_setfuncs(L, methods, 0);
	lua_pop(L, 1);
}
