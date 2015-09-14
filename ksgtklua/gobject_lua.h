// gobject_lua.h
//

#ifndef __PUSS_INC_GOBJECT_LUA_H__
#define __PUSS_INC_GOBJECT_LUA_H__

#include <glib-object.h>

#ifdef __cplusplus
extern "C" {
#endif

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

void		lua_gobject_open(lua_State* L);

int			lua_gtype_register_metatable_index(lua_State* L);	// [-2,+0,e] reg(GType, methods_table_or_index_function)
void		lua_gtype_register_index_table(lua_State* L, GType type, luaL_Reg* methods);
void		lua_gtype_register_index_function(lua_State* L, GType type, lua_CFunction func);

void		lua_gboxedvalue_push(lua_State* L, const GValue* v);
GValue*		lua_gboxedvalue_check(lua_State* L, int idx);
GValue*		lua_gboxedvalue_test(lua_State* L, int idx);

void		lua_gobject_push(lua_State* L, GObject* obj, gboolean weak_ref);	// [-0,+1,e] ref_sink or weak_ref obj
GObject*	lua_gobject_check(lua_State* L, int idx);
GObject*	lua_gobject_test(lua_State* L, int idx);

#ifdef __cplusplus
}
#endif

#endif//__PUSS_INC_GOBJECT_LUA_H__

