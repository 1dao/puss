// puss_interface.h
//
#ifndef __PUSS_INC_PUSS_INTERFACE_H__
#define __PUSS_INC_PUSS_INTERFACE_H__

#include "ks/types.h"

KS_DECLS_BEGIN

// puss interface
// 
// FFI types format: 
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

//	E		SourceEditor*				SourceEditor**
//	$		PussModule*					PussModule**

typedef struct lua_State	lua_State;

typedef struct _PussModule	PussModule;

typedef struct _IPuss {
	BOOL	(*script_invoke)(PussModule* module, const char* method, const char* fmt, ...);
} IPuss;

typedef void (*PussModuleRegFFI)(lua_State* L, const char* method, const void* func, char rtype, const char* atypes);

typedef void (*PussModuleInit)(IPuss* iface, lua_State* L, PussModuleRegFFI puss_module_reg_ffi);
typedef void (*PussModuleUninit)(void);

#define	PUSS_MODULE_SYMBOL_INIT		"puss_module_init"
#define	PUSS_MODULE_SYMBOL_UNINIT	"puss_module_uninit"

#define	PUSS_MODULE_REG(func, rtype, atypes)	puss_module_reg_ffi(L, #func, func, rtype, atypes)

KS_DECLS_END

#endif//__PUSS_INC_PUSS_INTERFACE_H__

