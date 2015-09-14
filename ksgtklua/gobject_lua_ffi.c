// gobject_lua_ffi.c
//

#include "gobject_lua_ffi.h"

#include "kslua/ffi_lua_reg.h"

static void lua_ffi_check_gvalue(lua_State* L, int idx, void* pval, const void* pdef) {
	*((GValue**)pval) = (pdef==NULL) ? lua_gboxedvalue_check(L, idx) : lua_gboxedvalue_test(L, idx);
}

static int lua_ffi_push_gvalue(lua_State* L, const void* pval) {
	lua_gboxedvalue_push(L, *(GValue**)pval);
	return 1;
}

static void kslua_ffi_return_gvalue(lua_State* L, int idx, void* pval) {
	*((GValue**)pval) = lua_gboxedvalue_test(L, idx);
}

KSLUA_FFI_TYPEDEF(gvalue, GValue*, FFI_TYPE_POINTER, KS_FFI_VA_ARG_POINTER);

static void lua_ffi_check_gobject(lua_State* L, int idx, void* pval, const void* pdef) {
	*((GObject**)pval) = (pdef==NULL) ? lua_gobject_check(L, idx) : lua_gobject_test(L, idx);
}

static int lua_ffi_push_gobject(lua_State* L, const void* pval) {
	lua_gobject_push(L, G_OBJECT(*(GObject**)pval), TRUE);
	return 1;
}

static void kslua_ffi_return_gobject(lua_State* L, int idx, void* pval) {
	*((GObject**)pval) = lua_gobject_test(L, idx);
}

KSLUA_FFI_TYPEDEF(gobject, GObject*, FFI_TYPE_POINTER, KS_FFI_VA_ARG_POINTER);

void gobject_ffi_type_register(lua_State* L) {
	kslua_ffi_va_type_register(GVALUE_FFI_TYPE_CHAR, &_kslua_ffi_type_gvalue);
	kslua_ffi_va_type_register(GOBJECT_FFI_TYPE_CHAR, &_kslua_ffi_type_gobject);
}

void gobject_ffi_type_register_start(lua_State* L, GType type) {
	lua_pushcfunction(L, lua_gtype_register_metatable_index);
	lua_pushinteger(L, (lua_Integer)type);
	lua_newtable(L);
}

void gobject_ffi_type_register_method(lua_State* L, const char* name, const void* func, char rtype, const char* atypes) {
	KSFFIFunction* f = kslua_ffi_va_function_create(L, name, func, rtype, atypes);
	if( f )
		lua_setfield(L, -2, name);
	else
		g_warning("register method(%s) failed!", name);
}

void gobject_ffi_type_register_end(lua_State* L) {
	lua_call(L, 2, 0);
}

