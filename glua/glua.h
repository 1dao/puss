// glua.h
//

#ifndef __PUSS_INC_GOBJECT_LUA_H__
#define __PUSS_INC_GOBJECT_LUA_H__

#ifdef _MSC_VER
	#define inline __inline
#endif

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

#include <glib.h>
#include <glib-object.h>

#ifdef __cplusplus
	extern "C" {
#endif

void		glua_push_master_table(lua_State* L);	// [-0,+1,-]
void		glua_push_capis_table(lua_State* L);	// [-0,+1,-]

void		glua_enum_types_register(lua_State* L);	// NOTICE : must invoke after all other gtypes register finished

void		glua_new_gtype_index_table(lua_State* L, GType type, const char* prefix);
void		glua_reg_gtype_index_table(lua_State* L, GType type, const char* prefix, const luaL_Reg* methods);
void		glua_reg_c_struct0_boxed_type_new_method(lua_State* L, GType type, gsize struct_size);

GValue*		glua_value_check(lua_State* L, int idx);
GValue*		glua_value_test(lua_State* L, int idx);
GValue*		glua_value_check_type(lua_State* L, int idx, GType type);
GValue*		glua_value_new(lua_State* L, GType init_type);
void		glua_value_push(lua_State* L, const GValue* v);
GValue*		glua_value_push_boxed(lua_State* L, GType tp, gconstpointer ptr, gboolean take);	// take==FALSE means need copy
void		glua_value_from_lua(lua_State* L, int idx, GValue* v);

void		glua_object_push(lua_State* L, GObject* obj);	// [-0,+1,e]
GObject*	glua_object_check(lua_State* L, int idx);
GObject*	glua_object_test(lua_State* L, int idx);

gpointer	glua_object_check_type(lua_State* L, int idx, GType type);

int			glua_signal_connect(lua_State* L);	// [-3|4,+1,e]	connect(GObject* obj, const char* detailed_signal, function, gboolean after)

int			glua_pcall(lua_State* L, int narg, int nres);

#ifdef __cplusplus
	}
#endif

#endif//__PUSS_INC_GOBJECT_LUA_H__

