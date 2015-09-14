// gobject_lua_extra_gtk.inl

#include "gobject_lua_ffi.h"

#include <gtk/gtk.h>

static void gobject_extra_gtk_register(lua_State* L) {

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

		_reg(get_pointer,	'-', "G>l>l");
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
		_reg(append_page,		'l', "GGG");
		_reg(prepend_page,		'l', "GGG");
		_reg(insert_page,		'l', "GGGl");
		_reg(remove_page,		'l', "Gl");
		_reg(get_current_page,	'l', "G");
		_reg(get_nth_page,		'G', "Gl");
		_reg(get_n_pages,		'l', "G");
		_reg(page_num,			'l', "GG");
		_reg(set_current_page,	'-', "Gl");
		_reg(get_tab_label,		'G', "GG");
		_reg(set_tab_label,		'-', "GGG");
		_reg(set_tab_label_text,'-', "GGs");
		_reg(get_tab_label_text,'s', "GG");
		_reg(reorder_child,		'-', "GGl");
		#undef _reg
	}
	gobject_ffi_type_register_end(L);
}

