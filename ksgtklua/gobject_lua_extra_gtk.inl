// gobject_lua_extra_gtk.inl

#include "gobject_lua_ffi.h"

#include <gtk/gtk.h>

static void _gtk_builder_connect_wrapper(GtkBuilder* builder, GObject* object, const gchar* signal_name, const gchar* handler_name, GObject* connect_object, GConnectFlags flags, gpointer user_data) {
	lua_State* L = (lua_State*)user_data;
	if( lua_istable(L, 2) ) {
		lua_pushcfunction(L, lua_gobject_signal_connect);
		lua_gobject_push(L, object, TRUE);
		lua_pushstring(L, signal_name);
		lua_getfield(L, 2, handler_name);
		lua_pushboolean(L, ((flags&G_CONNECT_AFTER) != 0));
		lua_call(L, 4, 0);
	} else {
		assert( lua_isfunction(L, 2) );
		lua_pushvalue(L, 2);
		lua_gobject_push(L, object, TRUE);
		lua_pushstring(L, signal_name);
		lua_pushstring(L, handler_name);
		lua_pushboolean(L, ((flags&G_CONNECT_AFTER) != 0));
		lua_call(L, 4, 0);
	}
}

static int lua_gtk_builder_connect(lua_State* L) {
	GObject* obj = lua_gobject_check(L, 1);
	GtkBuilder* builder = GTK_BUILDER(obj);
	if( !builder )
		return luaL_argerror(L, 1, "need GtkBuilder");
	if( !(lua_istable(L, 2) || lua_isfunction(L, 2)) )
		return luaL_argerror(L, 2, "need table or function");
	gtk_builder_connect_signals_full(builder, _gtk_builder_connect_wrapper, L);
	return 0;
}

static void gobject_extra_gtk_register(lua_State* L) {

	gobject_ffi_type_register_start(L, GTK_TYPE_BUILDER);
	{
		#define	_reg(f, rtype, atypes)	gobject_ffi_type_register_method(L, #f, gtk_builder_##f, rtype, atypes)
		_reg(new,				'G', "");
		_reg(add_from_file,		'I', "Gs>E");
		_reg(add_from_string,	'I', "GsZ>E");
		_reg(get_object,		'G', "Gs");
		_reg(get_object,		'G', "Gs");
		#undef _reg

		lua_pushcfunction(L, lua_gtk_builder_connect);	lua_setfield(L, -2, "connect_signals");
	}
	gobject_ffi_type_register_end(L);

	gobject_ffi_type_register_start(L, GTK_TYPE_WIDGET);
	{
		#define	_reg(f, rtype, atypes)	gobject_ffi_type_register_method(L, #f, gtk_widget_##f, rtype, atypes)
		_reg(destroy,		'-', "G");
		_reg(unparent,		'-', "G");
		_reg(show,			'-', "G");
		_reg(hide,			'-', "G");
		_reg(show_all,		'-', "G");
		_reg(queue_draw,	'-', "G");
		_reg(queue_resize,	'-', "G");
		_reg(activate,		'b', "G");
		_reg(reparent,		'-', "G");

		_reg(grab_focus,	'-', "G");
		_reg(grab_default,	'-', "G");

		_reg(grab_default,	'-', "G");
		_reg(grab_default,	'-', "G");

		_reg(get_pointer,	'-', "G>i>i");
		#undef _reg
	}
	gobject_ffi_type_register_end(L);

	gobject_ffi_type_register_start(L, GTK_TYPE_CONTAINER);
	{
		#define	_reg(f, rtype, atypes)	gobject_ffi_type_register_method(L, #f, gtk_container_##f, rtype, atypes)
		_reg(add,				'-', "GG");
		_reg(remove,			'-', "GG");
		_reg(set_focus_child,	'-', "GG");
		_reg(get_focus_child,	'G', "G");
		#undef _reg
	}
	gobject_ffi_type_register_end(L);

	gobject_ffi_type_register_start(L, GTK_TYPE_NOTEBOOK);
	{
		#define	_reg(f, rtype, atypes)	gobject_ffi_type_register_method(L, #f, gtk_notebook_##f, rtype, atypes)
		_reg(append_page,		'i', "GGG");
		_reg(prepend_page,		'i', "GGG");
		_reg(insert_page,		'i', "GGGi");
		_reg(remove_page,		'i', "Gi");
		_reg(get_current_page,	'i', "G");
		_reg(get_nth_page,		'G', "Gi");
		_reg(get_n_pages,		'i', "G");
		_reg(page_num,			'i', "GG");
		_reg(set_current_page,	'-', "Gi");
		_reg(get_tab_label,		'G', "GG");
		_reg(set_tab_label,		'-', "GGG");
		_reg(set_tab_label_text,'-', "GGs");
		_reg(get_tab_label_text,'s', "GG");
		_reg(reorder_child,		'-', "GGi");
		#undef _reg
	}
	gobject_ffi_type_register_end(L);

}

