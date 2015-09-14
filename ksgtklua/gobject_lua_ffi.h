// gobject_lua_ffi.h
//

#ifndef __PUSS_INC_GOBJECT_LUA_FFI_H__
#define __PUSS_INC_GOBJECT_LUA_FFI_H__

#include "gobject_lua.h"

#define GVALUE_FFI_TYPE_CHAR	'V'
#define GOBJECT_FFI_TYPE_CHAR	'G'

#ifdef __cplusplus
extern "C" {
#endif

void	gobject_ffi_type_register(lua_State* L);

void	gobject_ffi_type_register_start(lua_State* L, GType type);
void	gobject_ffi_type_register_method(lua_State* L, const char* name, const void* func, char rtype, const char* atypes);
void	gobject_ffi_type_register_end(lua_State* L);

#ifdef __cplusplus
}
#endif

#endif//__PUSS_INC_GOBJECT_LUA_FFI_H__

