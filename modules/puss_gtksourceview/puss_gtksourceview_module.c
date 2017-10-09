// puss_gtk_module.c

#include "puss_gobject_module.h"

#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include <gtk/gtk.h>
#include <gtksourceview/gtksource.h>

#include "puss_gobject_ffi_reg.h"

#include "luaproxy_import.inl"


static PussGObjectInterface* gobject_iface = NULL;

static int _lua_gtk_source_buffer_get_source_marks_at_line(lua_State* L) {
	GObject* obj = gobject_iface->gobject_check(L, 1);
	gint line = (gint)luaL_checkinteger(L, 2);
	const gchararray category = (const gchararray)luaL_optstring(L, 3, NULL);
	GtkSourceBuffer* buffer = GTK_SOURCE_BUFFER(obj);
	GSList* masks = NULL;
	if( !buffer )
		return luaL_argerror(L, 1, "need GtkSourceBuffer");
	masks = gtk_source_buffer_get_source_marks_at_line(buffer, line, category);
	if( !masks ) {
		lua_pushnil(L);
	} else {
		GSList* p;
		lua_Integer n = 0;
		lua_newtable(L);
		for( p=masks; p; p=p->next ) {
			GtkSourceMark* mark = (GtkSourceMark*)(p->data);
			gobject_iface->gobject_push(L, G_OBJECT(mark));
			lua_rawseti(L, -2, ++n);
		}
		g_slist_free(masks);
	}
	return 1;
}

static void glua_gtksourceview_register(lua_State* L, PussGObjectRegIface* reg_iface, int glua_env_index) {
	(void)GTK_SOURCE_TYPE_COMPLETION_ACTIVATION;
	(void)GTK_SOURCE_TYPE_COMPLETION_ERROR;
	(void)GTK_SOURCE_TYPE_VIEW_GUTTER_POSITION;
	(void)GTK_SOURCE_TYPE_SMART_HOME_END_TYPE;
	(void)GTK_SOURCE_TYPE_DRAW_SPACES_FLAGS;

	gtype_reg_start(GTK_SOURCE_TYPE_BUFFER, gtk_source_buffer);
		gtype_reg_ffi(GTK_SOURCE_TYPE_BUFFER, gtk_source_buffer_new_with_language, GTK_SOURCE_TYPE_LANGUAGE);
		gtype_reg_ffi(G_TYPE_NONE, gtk_source_buffer_ensure_highlight, GTK_SOURCE_TYPE_BUFFER, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_source_buffer_redo, GTK_SOURCE_TYPE_BUFFER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_source_buffer_undo, GTK_SOURCE_TYPE_BUFFER);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_source_buffer_can_redo, GTK_SOURCE_TYPE_BUFFER);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_source_buffer_can_undo, GTK_SOURCE_TYPE_BUFFER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_source_buffer_begin_not_undoable_action, GTK_SOURCE_TYPE_BUFFER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_source_buffer_end_not_undoable_action, GTK_SOURCE_TYPE_BUFFER);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_source_buffer_iter_has_context_class, GTK_SOURCE_TYPE_BUFFER, GTK_TYPE_TEXT_ITER, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_source_buffer_iter_forward_to_context_class_toggle, GTK_SOURCE_TYPE_BUFFER, GTK_TYPE_TEXT_ITER, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_source_buffer_iter_backward_to_context_class_toggle, GTK_SOURCE_TYPE_BUFFER, GTK_TYPE_TEXT_ITER, G_TYPE_STRING);
		gtype_reg_ffi(GTK_SOURCE_TYPE_MARK, gtk_source_buffer_create_source_mark, GTK_SOURCE_TYPE_BUFFER, opt G_TYPE_STRING, G_TYPE_STRING, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_source_buffer_forward_iter_to_source_mark, GTK_SOURCE_TYPE_BUFFER, GTK_TYPE_TEXT_ITER, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_source_buffer_backward_iter_to_source_mark, GTK_SOURCE_TYPE_BUFFER, GTK_TYPE_TEXT_ITER, G_TYPE_STRING);
		gtype_reg_lua(gtk_source_buffer_get_source_marks_at_line);
		gtype_reg_ffi(G_TYPE_NONE, gtk_source_buffer_remove_source_marks, GTK_SOURCE_TYPE_BUFFER, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER, opt G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_NONE, gtk_source_buffer_change_case, GTK_SOURCE_TYPE_BUFFER, GTK_SOURCE_TYPE_CHANGE_CASE_TYPE, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_source_buffer_join_lines, GTK_SOURCE_TYPE_BUFFER, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_source_buffer_sort_lines, GTK_SOURCE_TYPE_BUFFER, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER, GTK_SOURCE_TYPE_SORT_FLAGS, G_TYPE_INT);
	gtype_reg_end();

	gtype_reg_start(GTK_SOURCE_TYPE_VIEW, gtk_source_view);
		gtype_reg_ffi(GTK_TYPE_WIDGET, gtk_source_view_new_with_buffer, GTK_SOURCE_TYPE_BUFFER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_source_view_indent_lines, GTK_SOURCE_TYPE_VIEW, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_source_view_unindent_lines, GTK_SOURCE_TYPE_VIEW, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_UINT, gtk_source_view_get_visual_column, GTK_SOURCE_TYPE_VIEW, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_source_view_set_mark_attributes, GTK_SOURCE_TYPE_VIEW, G_TYPE_STRING, GTK_SOURCE_TYPE_MARK_ATTRIBUTES, G_TYPE_INT);
		gtype_reg_ffi(GTK_SOURCE_TYPE_MARK_ATTRIBUTES, gtk_source_view_get_mark_attributes, GTK_SOURCE_TYPE_VIEW, G_TYPE_STRING, out G_TYPE_INT);
	gtype_reg_end();

	gtype_reg_start(GTK_SOURCE_TYPE_LANGUAGE, gtk_source_language);	gtype_reg_end();

	gtype_reg_start(GTK_SOURCE_TYPE_LANGUAGE_MANAGER, gtk_source_language_manager);
		gtype_reg_ffi(GTK_SOURCE_TYPE_LANGUAGE_MANAGER, gtk_source_language_manager_get_default, G_TYPE_INVALID);
		gtype_reg_ffi(GTK_SOURCE_TYPE_LANGUAGE, gtk_source_language_manager_get_language, GTK_SOURCE_TYPE_LANGUAGE_MANAGER, G_TYPE_STRING);
		gtype_reg_ffi(GTK_SOURCE_TYPE_LANGUAGE, gtk_source_language_manager_guess_language, GTK_SOURCE_TYPE_LANGUAGE_MANAGER, G_TYPE_STRING, G_TYPE_STRING);
	gtype_reg_end();

	gtype_reg_start(GTK_SOURCE_TYPE_MARK, gtk_source_mark);	gtype_reg_end();

	gtype_reg_start(GTK_SOURCE_TYPE_MARK_ATTRIBUTES, gtk_source_mark_attributes);
		gtype_reg_ffi(GDK_TYPE_PIXBUF, gtk_source_mark_attributes_render_icon, GTK_SOURCE_TYPE_MARK_ATTRIBUTES, GTK_TYPE_WIDGET, G_TYPE_INT);
		gtype_reg_ffi_rnew(G_TYPE_STRING, gtk_source_mark_attributes_get_tooltip_text, GTK_SOURCE_TYPE_MARK_ATTRIBUTES, GTK_SOURCE_TYPE_MARK);
		gtype_reg_ffi_rnew(G_TYPE_STRING, gtk_source_mark_attributes_get_tooltip_markup, GTK_SOURCE_TYPE_MARK_ATTRIBUTES, GTK_SOURCE_TYPE_MARK);
	gtype_reg_end();

	gtype_reg_start(GTK_SOURCE_TYPE_UNDO_MANAGER, gtk_source_undo_manager);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_source_undo_manager_can_undo, GTK_SOURCE_TYPE_UNDO_MANAGER);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_source_undo_manager_can_redo, GTK_SOURCE_TYPE_UNDO_MANAGER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_source_undo_manager_undo, GTK_SOURCE_TYPE_UNDO_MANAGER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_source_undo_manager_redo, GTK_SOURCE_TYPE_UNDO_MANAGER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_source_undo_manager_begin_not_undoable_action, GTK_SOURCE_TYPE_UNDO_MANAGER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_source_undo_manager_end_not_undoable_action, GTK_SOURCE_TYPE_UNDO_MANAGER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_source_undo_manager_can_undo_changed, GTK_SOURCE_TYPE_UNDO_MANAGER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_source_undo_manager_can_redo_changed, GTK_SOURCE_TYPE_UNDO_MANAGER);
	gtype_reg_end();
}

PUSS_MODULE_EXPORT void* __puss_module_init__(lua_State* L, PussInterface* puss, void* ud) {
	if( !gobject_iface ) {
		__lua_proxy_import__(puss->luaproxy());
		gobject_iface = puss->require(L, "puss_gobject", ud);
		if( !gobject_iface ) {
			luaL_error(L, "require puss_gobject failed!");
			return NULL;
		}
	}

	gobject_iface->module_reg(L, glua_gtksourceview_register);
	return NULL;
}

