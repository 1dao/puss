// gffireg.h
//
#include "gffi.h"

// GType register methods utils

#define out		GFFI_PESUDO_TYPE_OUT_ARG,
#define inout	GFFI_PESUDO_TYPE_INOUT_ARG,
#define opt		GFFI_PESUDO_TYPE_OPT_ARG,

#define gtype_reg_env_declare() \
	size_t __gtype_reg_prefix_len = 0

#define gtype_reg_start(gtype, prefix) \
	glua_push_capis_table(L); \
	glua_new_gtype_index_table(L, gtype, #prefix); \
	__gtype_reg_prefix_len = sizeof(#prefix)

#define gtype_reg_end() lua_pop(L, 2)

#define _gtype_reg_setfield(func) do {\
		lua_pushvalue(L, -1); \
		lua_setfield(L, -3, ((const char*)#func) + __gtype_reg_prefix_len); \
		lua_setfield(L, -3, (const char*)#func); \
	} while(0)

#define gtype_reg_lua(func) \
	lua_pushcfunction(L, _lua_##func); \
	_gtype_reg_setfield(func)

#define gtype_reg_ffi(rtype, func, ...) \
	gffi_function_va_create(L, #func, rtype, func, __VA_ARGS__, G_TYPE_INVALID); \
	_gtype_reg_setfield(func)

#define gtype_reg_ffi_rename(rtype, func, ...) \
	gffi_function_va_create(L, #func, rtype, _rename_##func, __VA_ARGS__, G_TYPE_INVALID); \
	_gtype_reg_setfield(func)

#define gtype_reg_ffi_rnew(rtype, func, ...) \
	gffi_function_va_create(L, "*" #func, rtype, func, __VA_ARGS__, G_TYPE_INVALID); \
	_gtype_reg_setfield(func)

#define gtype_reg_boxed_new_use_c_struct0(gtype, func, ctype) \
	glua_reg_c_struct0_boxed_type_new_method(L, gtype, sizeof(ctype)); \
	_gtype_reg_setfield(func)

