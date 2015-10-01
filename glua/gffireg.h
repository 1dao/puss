// gffireg.h
//
#include "gffi.h"

// GType register methods utils

#define out		GFFI_PESUDO_TYPE_OUT_ARG,
#define inout	GFFI_PESUDO_TYPE_INOUT_ARG,
#define opt		GFFI_PESUDO_TYPE_OPT_ARG,

#define gtype_reg_env_declare() \
	size_t __gtype_reg_prefix_len = 0

#define gtype_reg_start(gtype, remove_method_prefix) \
	glua_new_gtype_index_table(L, gtype); \
	__gtype_reg_prefix_len = sizeof(#remove_method_prefix)

#define gtype_reg_end() lua_pop(L, 1)

#define gtype_reg_lua(name, func) \
	lua_pushcfunction(L, func); \
	lua_setfield(L, -2, name)

#define gtype_reg_ffi(rtype, func, ...) \
	gffi_function_va_create(L, #func, rtype, func, __VA_ARGS__, G_TYPE_INVALID); \
	lua_setfield(L, -2, ((const char*)#func) + __gtype_reg_prefix_len)

#define gtype_reg_ffi_rename(name, rtype, func, ...) \
	gffi_function_va_create(L, #func, rtype, func, __VA_ARGS__, G_TYPE_INVALID); \
	lua_setfield(L, -2, name)

#define gtype_reg_ffi_rnew(rtype, func, ...) \
	gffi_function_va_create(L, "*" #func, rtype, func, __VA_ARGS__, G_TYPE_INVALID); \
	lua_setfield(L, -2, ((const char*)#func) + __gtype_reg_prefix_len)

