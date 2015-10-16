// glua.h
//

#ifndef __PUSS_INC_GOBJECT_LUA_H__
#define __PUSS_INC_GOBJECT_LUA_H__

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

#ifdef _MSC_VER
	#define inline	__inline
#endif

#include <glib.h>
#include <glib-object.h>

void		glua_push_master_table(lua_State* L);	// [-0,+1,-]

void		glua_enum_types_register(lua_State* L);	// NOTICE : must invoke after all other gtypes register finished

void		glua_new_gtype_index_table(lua_State* L, GType type);
void		glua_reg_gtype_index_table(lua_State* L, GType type, luaL_Reg* methods);

GValue*		glua_boxed_check(lua_State* L, int idx);
GValue*		glua_boxed_test(lua_State* L, int idx);
GValue*		glua_boxed_push(lua_State* L, GType tp, gconstpointer ptr, gboolean isnew);

GValue*		glua_value_new(lua_State* L, GType init_type);
void		glua_value_push(lua_State* L, const GValue* v);
void		glua_value_from_lua(lua_State* L, int idx, GValue* v);

void		glua_object_push(lua_State* L, GObject* obj);	// [-0,+1,e]
GObject*	glua_object_check(lua_State* L, int idx);
GObject*	glua_object_test(lua_State* L, int idx);

gpointer	glua_object_check_type(lua_State* L, int idx, GType type);

int			glua_signal_connect(lua_State* L);	// [-3|4,+1,e]	connect(GObject* obj, const char* detailed_signal, function, gboolean after)

int			glua_pcall(lua_State* L, int narg, int nres);

#endif//__PUSS_INC_GOBJECT_LUA_H__

