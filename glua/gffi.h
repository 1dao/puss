// gffi.h
//

#ifndef __PUSS_INC_GOBJECT_LUA_FFI_H__
#define __PUSS_INC_GOBJECT_LUA_FFI_H__

#include <stdlib.h>
#include <stdarg.h>

#include "glua.h"

typedef struct _GFFIType		GFFIType;
typedef struct _GFFIFunction	GFFIFunction;

typedef void (*GFFILuaCheck)(lua_State* L, int idx, gpointer pval, gboolean opt, GFFIType* tp);	// FFI C function argument
typedef int  (*GFFILuaPush)(lua_State* L, gconstpointer pval, GFFIType* tp, gboolean isnew);	// FFI C Function return

void	gffi_init(void);

// void	gtype_ffi_type_reg(GType tp);

#define GFFI_PESUDO_TYPE_OUT_ARG		G_TYPE_MAKE_FUNDAMENTAL(G_TYPE_RESERVED_USER_FIRST + 1)
#define GFFI_PESUDO_TYPE_INOUT_ARG		G_TYPE_MAKE_FUNDAMENTAL(G_TYPE_RESERVED_USER_FIRST + 2)
#define GFFI_PESUDO_TYPE_OPT_ARG		G_TYPE_MAKE_FUNDAMENTAL(G_TYPE_RESERVED_USER_FIRST + 3)

// create lua C function & push to L
// atypes :
//	1 ends with G_TYPE_INVALID
//	2 can use GFFI_PESUDO_TYPE_OUT_ARG for out argument
//	3 can use GFFI_PESUDO_TYPE_INOUT_ARG for in-out argument
//	4 can use GFFI_PESUDO_TYPE_OPT_ARG for opt input argument(can be null)
//	5 if use pesudo type, MUST use it before real GType.
//	6 name[0]=='*' means return value need free
// 
// for example : void add(gint* result, gint a, gint b);
//		GType atypes[] = { GFFI_PESUDO_TYPE_OUT_ARG, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_INVALID };
//		gffi_function_create(L, "add", G_TYPE_NONE, add, atypes);
// 
// or use va_args:
//		gffi_function_va_create(L, "add", G_TYPE_NONE, add, GFFI_PESUDO_TYPE_OUT_ARG, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_INVALID)
// 
// if return value need free, name[0] used for mark it: gchar* foo(void) { return g_strdup("some str"); }
//		gffi_function_va_create(L, "*foo", G_TYPE_STRING, foo);
// 
GFFIFunction*	gffi_function_create(lua_State* L, const char* name, GType rtype, const void* addr, GType* atypes);

GFFIFunction*	gffi_function_va_create(lua_State* L, const char* name, GType rtype, const void* addr, ... /*GType atype ... */ );

#endif//__PUSS_INC_GOBJECT_LUA_FFI_H__

