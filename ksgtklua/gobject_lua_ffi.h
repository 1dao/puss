// gobject_lua_ffi.h
//

#ifndef __PUSS_INC_GOBJECT_LUA_FFI_H__
#define __PUSS_INC_GOBJECT_LUA_FFI_H__

#include "gobject_lua.h"

#define GERROR_FFI_TYPE_CHAR	'E'
#define GVALUE_FFI_TYPE_CHAR	'V'
#define GOBJECT_FFI_TYPE_CHAR	'G'

#ifdef __cplusplus
extern "C" {
#endif

// basic types format: 
//	[fmt]	[in]						[out]/[in-out]/[pcall return type]
//----------------------------------------------------------------------------------------
//	-		void(only used when no return)
//	O		KSFFICustom*				KSFFICustom*
//	b		BOOL						BOOL*
//	l		int32_t						int32_t*
//	L		uint32_t					uint32_t*
//	q		int64_t						int64_t*
//	Q		uint64_t					uint64_t*
//	f		float						float*
//	d		double						double*
//	s		const char*					const char**
//	p		void*						void**
//
//	i		gint						gint*
//	L		guint						guint*
//	z		gssize						gssize*
//	Z		gsize						gsize*
//
//	E		GError*						GError**
//	V		GValue*						GValue**
//	G		GObject*					GObject**
// 
void	gobject_ffi_type_register(lua_State* L);

void	gobject_ffi_type_register_start(lua_State* L, GType type);
void	gobject_ffi_type_register_method(lua_State* L, const char* name, const void* func, char rtype, const char* atypes);
void	gobject_ffi_type_register_end(lua_State* L);

#ifdef __cplusplus
}
#endif

#endif//__PUSS_INC_GOBJECT_LUA_FFI_H__

