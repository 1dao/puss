// glualib.h
//

#ifndef __PUSS_INC_GTK_LUA_H__
#define __PUSS_INC_GTK_LUA_H__

#define GTK_DISABLE_DEPRECATED
#include <gtk/gtk.h>

#include "glua.h"

void gffi_init(void);
void gtypes_glib_register(lua_State* L);
void gtypes_gtk_register(lua_State* L);

// usage : 
//	1 gffi_init();
//	2 gtypes register
//		2.1 gtypes_glib_register()
//		2.2 gtypes_gtk_register()
//		2.x ... other gtypes register
//	3 glua_enum_types_register() MUST after gtypes register
//	4 push glua to lua global : glua_push_master_table(L); lua_setglobal(L, "glua");
//	
//	======================================================
//	void demo() {
//		lua_State* L = luaL_newstate();
//		luaL_openlibs(L);
//	
//		gffi_init();
//			gtypes_glib_register(L);
//			gtypes_gtk_register(L);
//			// gtypes_scintilla_register(L);
//		glua_enum_types_register(L);
//	
//		glua_push_master_table(L);
//		lua_setglobal(L, "glua");
//	}
//	======================================================
//

#endif//__PUSS_INC_GTK_LUA_H__

