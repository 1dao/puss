// NOTICE : generate by luaproxy_gen.lua

#include "luaproxy.h"
static LuaProxy* __lua_proxy_export__(void) {
	static LuaProxy _proxy = {0};
	if( _proxy.__lua_proxy_inited__==0 ) {
		_proxy.__lua_proxy_inited__ = 1;

		#ifndef LUA_COMPAT_MODULE
			#define luaL_pushmodule	NULL
			#define luaL_openlib	NULL
		#endif
			_proxy._lua_newstate = lua_newstate;
		_proxy._lua_close = lua_close;
		_proxy._lua_newthread = lua_newthread;
		_proxy._lua_atpanic = lua_atpanic;
		_proxy._lua_version = lua_version;
		_proxy._lua_absindex = lua_absindex;
		_proxy._lua_gettop = lua_gettop;
		_proxy._lua_settop = lua_settop;
		_proxy._lua_pushvalue = lua_pushvalue;
		_proxy._lua_rotate = lua_rotate;
		_proxy._lua_copy = lua_copy;
		_proxy._lua_checkstack = lua_checkstack;
		_proxy._lua_xmove = lua_xmove;
		_proxy._lua_isnumber = lua_isnumber;
		_proxy._lua_isstring = lua_isstring;
		_proxy._lua_iscfunction = lua_iscfunction;
		_proxy._lua_isinteger = lua_isinteger;
		_proxy._lua_isuserdata = lua_isuserdata;
		_proxy._lua_type = lua_type;
		_proxy._lua_typename = lua_typename;
		_proxy._lua_tonumberx = lua_tonumberx;
		_proxy._lua_tointegerx = lua_tointegerx;
		_proxy._lua_toboolean = lua_toboolean;
		_proxy._lua_tolstring = lua_tolstring;
		_proxy._lua_rawlen = lua_rawlen;
		_proxy._lua_tocfunction = lua_tocfunction;
		_proxy._lua_touserdata = lua_touserdata;
		_proxy._lua_tothread = lua_tothread;
		_proxy._lua_topointer = lua_topointer;
		_proxy._lua_arith = lua_arith;
		_proxy._lua_rawequal = lua_rawequal;
		_proxy._lua_compare = lua_compare;
		_proxy._lua_pushnil = lua_pushnil;
		_proxy._lua_pushnumber = lua_pushnumber;
		_proxy._lua_pushinteger = lua_pushinteger;
		_proxy._lua_pushlstring = lua_pushlstring;
		_proxy._lua_pushstring = lua_pushstring;
		_proxy._lua_pushvfstring = lua_pushvfstring;
		_proxy._lua_pushfstring = lua_pushfstring;
		_proxy._lua_pushcclosure = lua_pushcclosure;
		_proxy._lua_pushboolean = lua_pushboolean;
		_proxy._lua_pushlightuserdata = lua_pushlightuserdata;
		_proxy._lua_pushthread = lua_pushthread;
		_proxy._lua_getglobal = lua_getglobal;
		_proxy._lua_gettable = lua_gettable;
		_proxy._lua_getfield = lua_getfield;
		_proxy._lua_geti = lua_geti;
		_proxy._lua_rawget = lua_rawget;
		_proxy._lua_rawgeti = lua_rawgeti;
		_proxy._lua_rawgetp = lua_rawgetp;
		_proxy._lua_createtable = lua_createtable;
		_proxy._lua_newuserdata = lua_newuserdata;
		_proxy._lua_getmetatable = lua_getmetatable;
		_proxy._lua_getuservalue = lua_getuservalue;
		_proxy._lua_setglobal = lua_setglobal;
		_proxy._lua_settable = lua_settable;
		_proxy._lua_setfield = lua_setfield;
		_proxy._lua_seti = lua_seti;
		_proxy._lua_rawset = lua_rawset;
		_proxy._lua_rawseti = lua_rawseti;
		_proxy._lua_rawsetp = lua_rawsetp;
		_proxy._lua_setmetatable = lua_setmetatable;
		_proxy._lua_setuservalue = lua_setuservalue;
		_proxy._lua_callk = lua_callk;
		_proxy._lua_pcallk = lua_pcallk;
		_proxy._lua_load = lua_load;
		_proxy._lua_dump = lua_dump;
		_proxy._lua_yieldk = lua_yieldk;
		_proxy._lua_resume = lua_resume;
		_proxy._lua_status = lua_status;
		_proxy._lua_isyieldable = lua_isyieldable;
		_proxy._lua_gc = lua_gc;
		_proxy._lua_error = lua_error;
		_proxy._lua_next = lua_next;
		_proxy._lua_concat = lua_concat;
		_proxy._lua_len = lua_len;
		_proxy._lua_stringtonumber = lua_stringtonumber;
		_proxy._lua_getallocf = lua_getallocf;
		_proxy._lua_setallocf = lua_setallocf;
		_proxy._lua_getstack = lua_getstack;
		_proxy._lua_getinfo = lua_getinfo;
		_proxy._lua_getlocal = lua_getlocal;
		_proxy._lua_setlocal = lua_setlocal;
		_proxy._lua_getupvalue = lua_getupvalue;
		_proxy._lua_setupvalue = lua_setupvalue;
		_proxy._lua_upvalueid = lua_upvalueid;
		_proxy._lua_upvaluejoin = lua_upvaluejoin;
		_proxy._lua_sethook = lua_sethook;
		_proxy._lua_gethook = lua_gethook;
		_proxy._lua_gethookmask = lua_gethookmask;
		_proxy._lua_gethookcount = lua_gethookcount;
		_proxy._luaL_checkversion_ = luaL_checkversion_;
		_proxy._luaL_getmetafield = luaL_getmetafield;
		_proxy._luaL_callmeta = luaL_callmeta;
		_proxy._luaL_tolstring = luaL_tolstring;
		_proxy._luaL_argerror = luaL_argerror;
		_proxy._luaL_checklstring = luaL_checklstring;
		_proxy._luaL_optlstring = luaL_optlstring;
		_proxy._luaL_checknumber = luaL_checknumber;
		_proxy._luaL_optnumber = luaL_optnumber;
		_proxy._luaL_checkinteger = luaL_checkinteger;
		_proxy._luaL_optinteger = luaL_optinteger;
		_proxy._luaL_checkstack = luaL_checkstack;
		_proxy._luaL_checktype = luaL_checktype;
		_proxy._luaL_checkany = luaL_checkany;
		_proxy._luaL_newmetatable = luaL_newmetatable;
		_proxy._luaL_setmetatable = luaL_setmetatable;
		_proxy._luaL_testudata = luaL_testudata;
		_proxy._luaL_checkudata = luaL_checkudata;
		_proxy._luaL_where = luaL_where;
		_proxy._luaL_error = luaL_error;
		_proxy._luaL_checkoption = luaL_checkoption;
		_proxy._luaL_fileresult = luaL_fileresult;
		_proxy._luaL_execresult = luaL_execresult;
		_proxy._luaL_ref = luaL_ref;
		_proxy._luaL_unref = luaL_unref;
		_proxy._luaL_loadfilex = luaL_loadfilex;
		_proxy._luaL_loadbufferx = luaL_loadbufferx;
		_proxy._luaL_loadstring = luaL_loadstring;
		_proxy._luaL_newstate = luaL_newstate;
		_proxy._luaL_len = luaL_len;
		_proxy._luaL_gsub = luaL_gsub;
		_proxy._luaL_setfuncs = luaL_setfuncs;
		_proxy._luaL_getsubtable = luaL_getsubtable;
		_proxy._luaL_traceback = luaL_traceback;
		_proxy._luaL_requiref = luaL_requiref;
		_proxy._luaL_buffinit = luaL_buffinit;
		_proxy._luaL_prepbuffsize = luaL_prepbuffsize;
		_proxy._luaL_addlstring = luaL_addlstring;
		_proxy._luaL_addstring = luaL_addstring;
		_proxy._luaL_addvalue = luaL_addvalue;
		_proxy._luaL_pushresult = luaL_pushresult;
		_proxy._luaL_pushresultsize = luaL_pushresultsize;
		_proxy._luaL_buffinitsize = luaL_buffinitsize;
		_proxy._luaL_pushmodule = luaL_pushmodule;
		_proxy._luaL_openlib = luaL_openlib;
		_proxy._luaopen_base = luaopen_base;
		_proxy._luaopen_coroutine = luaopen_coroutine;
		_proxy._luaopen_table = luaopen_table;
		_proxy._luaopen_io = luaopen_io;
		_proxy._luaopen_os = luaopen_os;
		_proxy._luaopen_string = luaopen_string;
		_proxy._luaopen_utf8 = luaopen_utf8;
		_proxy._luaopen_bit32 = luaopen_bit32;
		_proxy._luaopen_math = luaopen_math;
		_proxy._luaopen_debug = luaopen_debug;
		_proxy._luaopen_package = luaopen_package;
		_proxy._luaL_openlibs = luaL_openlibs;
	}
	return &_proxy;
}
