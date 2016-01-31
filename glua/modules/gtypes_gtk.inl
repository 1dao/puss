// gtypes_gtk.inl

#include "../gffireg.h"

#include <assert.h>
#include <gtk/gtk.h>

static void gtk_globals_register(lua_State* L) {
	glua_push_capis_table(L);
	{
		lua_pushinteger(L, GTK_MAJOR_VERSION);	lua_setfield(L, -2, "GTK_MAJOR_VERSION");
		lua_pushinteger(L, GTK_MINOR_VERSION);	lua_setfield(L, -2, "GTK_MINOR_VERSION");
		lua_pushinteger(L, GTK_MICRO_VERSION);	lua_setfield(L, -2, "GTK_MICRO_VERSION");
	}
	#define _reg_ffi(rtype, func, ...) \
		gffi_function_va_create(L, #func, rtype, func, __VA_ARGS__, G_TYPE_INVALID); \
		lua_setfield(L, -2, #func)

	{
		_reg_ffi(G_TYPE_STRING, gtk_check_version, G_TYPE_UINT, G_TYPE_UINT, G_TYPE_UINT);
		_reg_ffi(G_TYPE_NONE, gtk_disable_setlocale, G_TYPE_INVALID);
		_reg_ffi(PANGO_TYPE_LANGUAGE, gtk_get_default_language, G_TYPE_INVALID);
#if GTK_CHECK_VERSION(3,12,0)
		_reg_ffi(GTK_TYPE_TEXT_DIRECTION, gtk_get_locale_direction, G_TYPE_INVALID);
#endif
		_reg_ffi(G_TYPE_NONE, gtk_main_do_event, GDK_TYPE_EVENT);
		_reg_ffi(G_TYPE_NONE, gtk_main, G_TYPE_INVALID);
		_reg_ffi(G_TYPE_UINT, gtk_main_level, G_TYPE_INVALID);
		_reg_ffi(G_TYPE_NONE, gtk_main_quit, G_TYPE_INVALID);
		_reg_ffi(G_TYPE_BOOLEAN, gtk_main_iteration, G_TYPE_INVALID);
		_reg_ffi(G_TYPE_BOOLEAN, gtk_main_iteration_do, G_TYPE_BOOLEAN);
		_reg_ffi(G_TYPE_BOOLEAN, gtk_true, G_TYPE_INVALID);
		_reg_ffi(G_TYPE_BOOLEAN, gtk_false, G_TYPE_INVALID);
		_reg_ffi(G_TYPE_NONE, gtk_grab_add, GTK_TYPE_WIDGET);
		_reg_ffi(GTK_TYPE_WIDGET, gtk_grab_get_current, G_TYPE_INVALID);
		_reg_ffi(G_TYPE_NONE, gtk_grab_remove, GTK_TYPE_WIDGET);
	}

	#undef _reg_ffi

	lua_pop(L, 1);
}

#if GTK_CHECK_VERSION(3,2,0)
	static gboolean _rename_gdk_event_get_keycode(const GdkEvent *event, guint *keycode) {
		guint16 code = 0;
		gboolean res = gdk_event_get_keycode(event, &code);
		*keycode = code;
		return res;
	}
#endif

static void gtk_boxed_register(lua_State* L) {
	gtype_reg_env_declare();

	gtype_reg_start(GDK_TYPE_EVENT, gdk_event);
		gtype_reg_ffi(G_TYPE_UINT, gdk_event_get_time, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gdk_event_get_state, GTYPE_SELF, out GDK_TYPE_MODIFIER_TYPE);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gdk_event_get_coords, GTYPE_SELF, out G_TYPE_DOUBLE, out G_TYPE_DOUBLE);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gdk_event_get_root_coords, GTYPE_SELF, out G_TYPE_DOUBLE, out G_TYPE_DOUBLE);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gdk_event_get_axis, GTYPE_SELF, GDK_TYPE_AXIS_USE, out G_TYPE_DOUBLE);
		gtype_reg_ffi(G_TYPE_NONE, gdk_event_set_screen, GTYPE_SELF, GDK_TYPE_SCREEN);
		gtype_reg_ffi(GDK_TYPE_SCREEN, gdk_event_get_screen, GTYPE_SELF);
#if GTK_CHECK_VERSION(3,0,0)
		gtype_reg_ffi(GDK_TYPE_WINDOW, gdk_event_get_window, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gdk_event_get_button, GTYPE_SELF, out G_TYPE_UINT);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gdk_event_get_click_count, GTYPE_SELF, out G_TYPE_UINT);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gdk_event_get_keyval, GTYPE_SELF, out G_TYPE_UINT);
		gtype_reg_ffi_rename(G_TYPE_BOOLEAN, gdk_event_get_keycode, GTYPE_SELF, out G_TYPE_UINT);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gdk_event_get_scroll_direction, GTYPE_SELF, out GDK_TYPE_SCROLL_DIRECTION);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gdk_event_get_scroll_deltas, GTYPE_SELF, out G_TYPE_DOUBLE, out G_TYPE_DOUBLE);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gdk_event_get_axis, GTYPE_SELF, GDK_TYPE_AXIS_USE, out G_TYPE_DOUBLE);
		gtype_reg_ffi(G_TYPE_NONE, gdk_event_set_device, GTYPE_SELF, GDK_TYPE_DEVICE);
		gtype_reg_ffi(GDK_TYPE_DEVICE, gdk_event_get_device, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE, gdk_event_set_source_device, GTYPE_SELF, GDK_TYPE_DEVICE);
		gtype_reg_ffi(GDK_TYPE_DEVICE, gdk_event_get_source_device, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gdk_event_triggers_context_menu, GTYPE_SELF);
		gtype_reg_ffi(GDK_TYPE_EVENT_TYPE, gdk_event_get_event_type, GTYPE_SELF);
#endif
	gtype_reg_end();

	gtype_reg_start(GTK_TYPE_PAPER_SIZE, gtk_paper_size); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_TEXT_ITER, gtk_text_iter);
		gtype_reg_boxed_new_use_c_struct0(GTYPE_SELF, gtk_text_iter_new, GtkTextIter);
		gtype_reg_ffi(G_TYPE_INT , gtk_text_iter_get_offset, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_INT , gtk_text_iter_get_line, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_INT , gtk_text_iter_get_line_offset, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_INT , gtk_text_iter_get_line_index, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_INT , gtk_text_iter_get_visible_line_offset, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_INT , gtk_text_iter_get_visible_line_index, GTYPE_SELF);
		gtype_reg_ffi_rnew(G_TYPE_STRING, gtk_text_iter_get_slice, GTYPE_SELF, GTYPE_SELF);
		gtype_reg_ffi_rnew(G_TYPE_STRING, gtk_text_iter_get_text, GTYPE_SELF, GTYPE_SELF);
		gtype_reg_ffi_rnew(G_TYPE_STRING, gtk_text_iter_get_visible_slice, GTYPE_SELF, GTYPE_SELF);
		gtype_reg_ffi_rnew(G_TYPE_STRING, gtk_text_iter_get_visible_text, GTYPE_SELF, GTYPE_SELF);
		gtype_reg_ffi(GDK_TYPE_PIXBUF, gtk_text_iter_get_pixbuf, GTYPE_SELF);
		gtype_reg_ffi(GTK_TYPE_TEXT_CHILD_ANCHOR, gtk_text_iter_get_child_anchor, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_begins_tag, GTYPE_SELF, GTK_TYPE_TEXT_TAG);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_ends_tag, GTYPE_SELF, GTK_TYPE_TEXT_TAG);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_toggles_tag, GTYPE_SELF, GTK_TYPE_TEXT_TAG);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_has_tag, GTYPE_SELF, GTK_TYPE_TEXT_TAG);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_editable, GTYPE_SELF, G_TYPE_BOOLEAN);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_can_insert, GTYPE_SELF, G_TYPE_BOOLEAN);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_starts_word, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_ends_word, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_inside_word, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_starts_sentence, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_ends_sentence, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_inside_sentence, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_starts_line, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_ends_line, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_is_cursor_position, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_INT , gtk_text_iter_get_chars_in_line, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_INT , gtk_text_iter_get_bytes_in_line, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_get_attributes, GTYPE_SELF, GTK_TYPE_TEXT_ATTRIBUTES);
		gtype_reg_ffi(PANGO_TYPE_LANGUAGE, gtk_text_iter_get_language, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_is_end, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_is_start, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_forward_char, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_backward_char, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_forward_chars, GTYPE_SELF, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_backward_chars, GTYPE_SELF, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_forward_line, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_backward_line, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_forward_lines, GTYPE_SELF, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_backward_lines, GTYPE_SELF, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_forward_word_end, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_backward_word_start, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_forward_word_ends, GTYPE_SELF, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_backward_word_starts, GTYPE_SELF, G_TYPE_INT);
		gtype_reg_ffi( G_TYPE_BOOLEAN , gtk_text_iter_forward_visible_line, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_backward_visible_line, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_forward_visible_lines, GTYPE_SELF, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_backward_visible_lines, GTYPE_SELF, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_forward_visible_word_end, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_backward_visible_word_start, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_forward_visible_word_ends, GTYPE_SELF, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_backward_visible_word_starts, GTYPE_SELF, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_forward_sentence_end, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_backward_sentence_start, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_forward_sentence_ends, GTYPE_SELF, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_backward_sentence_starts, GTYPE_SELF, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_forward_cursor_position, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_backward_cursor_position, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_forward_cursor_positions, GTYPE_SELF, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_backward_cursor_positions, GTYPE_SELF, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_forward_visible_cursor_position, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_backward_visible_cursor_position, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_forward_visible_cursor_positions, GTYPE_SELF, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_backward_visible_cursor_positions, GTYPE_SELF, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_NONE , gtk_text_iter_set_offset, GTYPE_SELF, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_NONE , gtk_text_iter_set_line, GTYPE_SELF, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_NONE , gtk_text_iter_set_line_offset, GTYPE_SELF, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_NONE , gtk_text_iter_set_line_index, GTYPE_SELF, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_NONE , gtk_text_iter_forward_to_end, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_forward_to_line_end, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE , gtk_text_iter_set_visible_line_offset, GTYPE_SELF, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_NONE , gtk_text_iter_set_visible_line_index, GTYPE_SELF, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_forward_to_tag_toggle, GTYPE_SELF, GTK_TYPE_TEXT_TAG);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_backward_to_tag_toggle, GTYPE_SELF, GTK_TYPE_TEXT_TAG);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_forward_search, GTYPE_SELF, G_TYPE_STRING, GTK_TYPE_TEXT_SEARCH_FLAGS, GTYPE_SELF, GTYPE_SELF, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_backward_search, GTYPE_SELF, G_TYPE_STRING, GTK_TYPE_TEXT_SEARCH_FLAGS, GTYPE_SELF, GTYPE_SELF, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_equal, GTYPE_SELF, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_INT , gtk_text_iter_compare, GTYPE_SELF, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_in_range, GTYPE_SELF, GTYPE_SELF, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE , gtk_text_iter_order, GTYPE_SELF, GTYPE_SELF);
	gtype_reg_end();

	gtype_reg_start(GTK_TYPE_REQUISITION, gtk_requisition); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_SELECTION_DATA, gtk_selection_data); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_BORDER, gtk_border); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_TREE_ITER, gtk_tree_iter);
		gtype_reg_boxed_new_use_c_struct0(GTYPE_SELF, gtk_tree_iter_new, GtkTreeIter);
		gtype_reg_ffi_rnew(GTYPE_SELF, gtk_tree_iter_copy, GTYPE_SELF);
	gtype_reg_end();

	gtype_reg_start(GTK_TYPE_TREE_PATH, gtk_tree_path); gtype_reg_end();

#ifdef GTK_TYPE_ICON_SET
	gtype_reg_start(GTK_TYPE_ICON_SET, gtk_icon_set); gtype_reg_end();
#endif

	gtype_reg_start(GTK_TYPE_TARGET_LIST, gtk_target_list); gtype_reg_end();
}

static void gtk_interface_register(lua_State* L) {
	gtype_reg_env_declare();

	gtype_reg_start(GTK_TYPE_BUILDABLE, gtk_buildable); gtype_reg_end();

#ifdef GTK_TYPE_ACTIVATABLE
	gtype_reg_start(GTK_TYPE_ACTIVATABLE, gtk_activatable); gtype_reg_end();
#endif

	gtype_reg_start(GTK_TYPE_ORIENTABLE, gtk_orientable); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_CELL_EDITABLE, gtk_cell_editable); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_CELL_LAYOUT, gtk_cell_layout); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_EDITABLE, gtk_editable); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_FILE_CHOOSER, gtk_file_chooser); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_TREE_MODEL, gtk_tree_model);
		gtype_reg_ffi(GTK_TYPE_TREE_MODEL_FLAGS, gtk_tree_model_get_flags, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_UINT, gtk_tree_model_get_n_columns, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_UINT, gtk_tree_model_get_column_type, GTYPE_SELF, G_TYPE_INT);

		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_tree_model_get_iter, GTYPE_SELF, GTK_TYPE_TREE_ITER, GTK_TYPE_TREE_PATH);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_tree_model_get_iter_from_string, GTYPE_SELF, GTK_TYPE_TREE_ITER, G_TYPE_STRING);
		gtype_reg_ffi_rnew(G_TYPE_STRING, gtk_tree_model_get_string_from_iter, GTYPE_SELF, GTK_TYPE_TREE_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_tree_model_get_iter_first, GTYPE_SELF, GTK_TYPE_TREE_ITER);
		gtype_reg_ffi_rnew(GTK_TYPE_TREE_PATH, gtk_tree_model_get_path, GTYPE_SELF, GTK_TYPE_TREE_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_model_get_value, GTYPE_SELF, GTK_TYPE_TREE_ITER, G_TYPE_INT, G_TYPE_VALUE);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_tree_model_iter_next, GTYPE_SELF, GTK_TYPE_TREE_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_tree_model_iter_children, GTYPE_SELF, GTK_TYPE_TREE_ITER, GTK_TYPE_TREE_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_tree_model_iter_has_child, GTYPE_SELF, GTK_TYPE_TREE_ITER);
		gtype_reg_ffi(G_TYPE_INT, gtk_tree_model_iter_n_children, GTYPE_SELF, GTK_TYPE_TREE_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_tree_model_iter_nth_child, GTYPE_SELF, GTK_TYPE_TREE_ITER, GTK_TYPE_TREE_ITER, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_tree_model_iter_parent, GTYPE_SELF, GTK_TYPE_TREE_ITER, GTK_TYPE_TREE_ITER);
	gtype_reg_end();

	gtype_reg_start(GTK_TYPE_TREE_DRAG_SOURCE, gtk_tree_drag_source); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_TREE_DRAG_DEST, gtk_tree_drag_dest); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_TREE_SORTABLE, gtk_tree_sortable); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_PRINT_OPERATION_PREVIEW, gtk_print_operation_preview); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_RECENT_CHOOSER, gtk_recent_chooser); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_TOOL_SHELL, gtk_tool_shell); gtype_reg_end();
}

static void gtk_object_register(lua_State* L) {
	gtype_reg_env_declare();
	
	gtype_reg_start(GDK_TYPE_WINDOW, gdk_window);
		gtype_reg_ffi(G_TYPE_NONE, gdk_window_raise, GTYPE_SELF);
	gtype_reg_end();
	
#ifdef GTK_TYPE_OBJECT
	gtype_reg_start(GTK_TYPE_OBJECT, gtk_object); gtype_reg_end();
#endif

	gtype_reg_start(GTK_TYPE_WIDGET, gtk_widget);
		gtype_reg_ffi(GTYPE_SELF, gtk_widget_destroy, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE, gtk_widget_destroyed, GTYPE_SELF, out GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE, gtk_widget_unparent, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE, gtk_widget_show, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE, gtk_widget_hide, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE, gtk_widget_show_now, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE, gtk_widget_show_all, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE, gtk_widget_map, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE, gtk_widget_unmap, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE, gtk_widget_realize, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE, gtk_widget_unrealize, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE, gtk_widget_queue_draw, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE, gtk_widget_queue_draw_area, GTYPE_SELF, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_NONE, gtk_widget_queue_resize, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE, gtk_widget_queue_resize_no_redraw, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_widget_activate, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE, gtk_widget_reparent, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE, gtk_widget_grab_focus, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE, gtk_widget_grab_default, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE, gtk_widget_grab_default, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE, gtk_widget_grab_default, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE, gtk_widget_get_pointer, GTYPE_SELF, out G_TYPE_INT, out G_TYPE_INT);
	gtype_reg_end();

	gtype_reg_start(GTK_TYPE_CONTAINER, gtk_container);
		gtype_reg_ffi(G_TYPE_NONE, gtk_container_add, GTYPE_SELF, GTK_TYPE_WIDGET);
		gtype_reg_ffi(G_TYPE_NONE, gtk_container_remove, GTYPE_SELF, GTK_TYPE_WIDGET);
		gtype_reg_ffi(G_TYPE_NONE, gtk_container_set_focus_child, GTYPE_SELF, GTK_TYPE_WIDGET);
		gtype_reg_ffi(GTK_TYPE_WIDGET, gtk_container_get_focus_child, GTYPE_SELF);
	gtype_reg_end();

	gtype_reg_start(GTK_TYPE_BIN, gtk_bin);
		gtype_reg_ffi(GTK_TYPE_WIDGET, gtk_bin_get_child, GTYPE_SELF);
		gtype_reg_ffi(GTK_TYPE_WIDGET, gtk_bin_get_child, GTYPE_SELF);
	gtype_reg_end();

	gtype_reg_start(GTK_TYPE_WINDOW, gtk_window);
		gtype_reg_ffi(G_TYPE_NONE, gtk_window_add_accel_group, GTYPE_SELF, GTK_TYPE_ACCEL_GROUP);
		gtype_reg_ffi(G_TYPE_NONE, gtk_window_remove_accel_group, GTYPE_SELF, GTK_TYPE_ACCEL_GROUP);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_window_activate_focus, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_window_activate_default, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE, gtk_window_set_modal, GTYPE_SELF, G_TYPE_BOOLEAN);
		gtype_reg_ffi(G_TYPE_NONE, gtk_window_set_default_size, GTYPE_SELF, G_TYPE_INT, G_TYPE_INT);
		gtype_reg_ffi(GDK_TYPE_WINDOW, gtk_widget_get_window, GTYPE_SELF);
#if GTK_CHECK_VERSION(3,0,0)
		gtype_reg_ffi(G_TYPE_NONE, gtk_window_set_default_geometry, GTYPE_SELF, G_TYPE_INT, G_TYPE_INT);
#endif
	gtype_reg_end();

	gtype_reg_start(GTK_TYPE_DIALOG, gtk_dialog); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_ABOUT_DIALOG, gtk_about_dialog); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_FILE_CHOOSER_DIALOG, gtk_file_chooser_dialog); gtype_reg_end();

#ifdef GTK_TYPE_INPUT_DIALOG
	gtype_reg_start(GTK_TYPE_INPUT_DIALOG, gtk_input_dialog); gtype_reg_end();
#endif

#ifdef GTK_TYPE_COLOR_SELECTION_DIALOG
	gtype_reg_start(GTK_TYPE_COLOR_SELECTION_DIALOG, gtk_color_selection_dialog); gtype_reg_end();
#endif

#ifdef GTK_TYPE_FONT_SELECTION_DIALOG
	gtype_reg_start(GTK_TYPE_FONT_SELECTION_DIALOG, gtk_font_selection_dialog); gtype_reg_end();
#endif

	gtype_reg_start(GTK_TYPE_MESSAGE_DIALOG, gtk_message_dialog); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_RECENT_CHOOSER_DIALOG, gtk_recent_chooser_dialog); gtype_reg_end();

#ifdef GTK_TYPE_APPLICATION_WINDOW
	gtype_reg_start(GTK_TYPE_APPLICATION_WINDOW, gtk_application_window);
		gtype_reg_ffi(G_TYPE_NONE, gtk_application_window_set_show_menubar, GTYPE_SELF, G_TYPE_BOOLEAN);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_application_window_get_show_menubar, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_UINT, gtk_application_window_get_id, GTYPE_SELF);
	gtype_reg_end();
#endif

	gtype_reg_start(GTK_TYPE_ASSISTANT, gtk_assistant); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_OFFSCREEN_WINDOW, gtk_offscreen_window); gtype_reg_end();
	
#ifdef GTK_TYPE_ALIGNMENT
	gtype_reg_start(GTK_TYPE_ALIGNMENT, gtk_alignment); gtype_reg_end();
#endif

	gtype_reg_start(GTK_TYPE_FRAME, gtk_frame); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_ASPECT_FRAME, gtk_aspect_frame); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_BUTTON, gtk_button); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_TOGGLE_BUTTON, gtk_toggle_button); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_CHECK_BUTTON, gtk_check_button); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_RADIO_BUTTON, gtk_radio_button); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_COLOR_BUTTON, gtk_color_button); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_FONT_BUTTON, gtk_font_button); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_LINK_BUTTON, gtk_link_button); gtype_reg_end();

#ifdef GTK_TYPE_OPTION_MENU
	gtype_reg_start(GTK_TYPE_OPTION_MENU, gtk_option_menu); gtype_reg_end();
#endif

	gtype_reg_start(GTK_TYPE_SCALE_BUTTON, gtk_scale_button); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_VOLUME_BUTTON, gtk_volume_button); gtype_reg_end();

#ifdef GTK_TYPE_ITEM
	gtype_reg_start(GTK_TYPE_ITEM, gtk_item); gtype_reg_end();
#endif

	gtype_reg_start(GTK_TYPE_MENU_ITEM, gtk_menu_item); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_CHECK_MENU_ITEM, gtk_check_menu_item); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_RADIO_MENU_ITEM, gtk_radio_menu_item); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_SEPARATOR_MENU_ITEM, gtk_separator_menu_item); gtype_reg_end();

#ifdef GTK_TYPE_LIST_ITEM
	gtype_reg_start(GTK_TYPE_LIST_ITEM, gtk_list_item); gtype_reg_end();
#endif

#ifdef GTK_TYPE_IMAGE_MENU_ITEM
	gtype_reg_start(GTK_TYPE_IMAGE_MENU_ITEM, gtk_image_menu_item); gtype_reg_end();
#endif

#ifdef GTK_TYPE_TEAROFF_MENU_ITEM
	gtype_reg_start(GTK_TYPE_TEAROFF_MENU_ITEM, gtk_tearoff_menu_item); gtype_reg_end();
#endif

	gtype_reg_start(GTK_TYPE_COMBO_BOX, gtk_combo_box); gtype_reg_end();

#ifdef GTK_TYPE_COMBO_BOX_ENTRY
	gtype_reg_start(GTK_TYPE_COMBO_BOX_ENTRY, gtk_combo_box_entry); gtype_reg_end();
#endif

	gtype_reg_start(GTK_TYPE_COMBO_BOX_TEXT, gtk_combo_box_text); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_EVENT_BOX, gtk_event_box); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_EXPANDER, gtk_expander); gtype_reg_end();

#ifdef GTK_TYPE_HANDLE_BOX
	gtype_reg_start(GTK_TYPE_HANDLE_BOX, gtk_handle_box); gtype_reg_end();
#endif

	gtype_reg_start(GTK_TYPE_TOOL_ITEM, gtk_tool_item); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_TOOL_BUTTON, gtk_tool_button); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_MENU_TOOL_BUTTON, gtk_menu_tool_button); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_TOGGLE_TOOL_BUTTON, gtk_toggle_tool_button); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_RADIO_TOOL_BUTTON, gtk_radio_tool_button); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_SEPARATOR_TOOL_ITEM, gtk_separator_tool_item); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_SCROLLED_WINDOW, gtk_scrolled_window); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_VIEWPORT, gtk_viewport); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_BOX, gtk_box); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_BUTTON_BOX, gtk_button_box); gtype_reg_end();

#ifdef GTK_TYPE_VBOX
	gtype_reg_start(GTK_TYPE_VBOX, gtk_vbox); gtype_reg_end();
#endif

#ifdef GTK_TYPE_HBOX
	gtype_reg_start(GTK_TYPE_HBOX, gtk_hbox); gtype_reg_end();
#endif

#ifdef GTK_TYPE_CLIST
	gtype_reg_start(GTK_TYPE_CLIST, gtk_clist); gtype_reg_end();
#endif

	gtype_reg_start(GTK_TYPE_FIXED, gtk_fixed); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_PANED, gtk_paned); gtype_reg_end();

#ifdef GTK_TYPE_VPANED
	gtype_reg_start(GTK_TYPE_VPANED, gtk_vpaned); gtype_reg_end();
#endif

#ifdef GTK_TYPE_HPANED
	gtype_reg_start(GTK_TYPE_HPANED, gtk_hpaned); gtype_reg_end();
#endif

	gtype_reg_start(GTK_TYPE_ICON_VIEW, gtk_icon_view); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_LAYOUT, gtk_layout); gtype_reg_end();

#ifdef GTK_TYPE_LIST
	gtype_reg_start(GTK_TYPE_LIST, gtk_list); gtype_reg_end();
#endif

	gtype_reg_start(GTK_TYPE_MENU_SHELL, gtk_menu_shell); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_NOTEBOOK, gtk_notebook);
		gtype_reg_ffi(G_TYPE_INT, gtk_notebook_append_page, GTYPE_SELF, GTK_TYPE_WIDGET, GTK_TYPE_WIDGET);
		gtype_reg_ffi(G_TYPE_INT, gtk_notebook_prepend_page, GTYPE_SELF, GTK_TYPE_WIDGET, GTK_TYPE_WIDGET);
		gtype_reg_ffi(G_TYPE_INT, gtk_notebook_insert_page, GTYPE_SELF, GTK_TYPE_WIDGET, GTK_TYPE_WIDGET, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_INT, gtk_notebook_remove_page, GTYPE_SELF, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_INT, gtk_notebook_get_current_page, GTYPE_SELF);
		gtype_reg_ffi(GTK_TYPE_WIDGET, gtk_notebook_get_nth_page, GTYPE_SELF, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_INT, gtk_notebook_get_n_pages, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_INT, gtk_notebook_page_num, GTYPE_SELF, GTK_TYPE_WIDGET);
		gtype_reg_ffi(G_TYPE_NONE, gtk_notebook_set_current_page, GTYPE_SELF, G_TYPE_INT);
		gtype_reg_ffi(GTK_TYPE_WIDGET, gtk_notebook_get_tab_label, GTYPE_SELF, GTK_TYPE_WIDGET);
		gtype_reg_ffi(G_TYPE_NONE, gtk_notebook_set_tab_label, GTYPE_SELF, GTK_TYPE_WIDGET, GTK_TYPE_WIDGET);
		gtype_reg_ffi(G_TYPE_NONE, gtk_notebook_set_tab_label_text, GTYPE_SELF, GTK_TYPE_WIDGET, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_STRING, gtk_notebook_get_tab_label_text, GTYPE_SELF, GTK_TYPE_WIDGET);
		gtype_reg_ffi(G_TYPE_NONE, gtk_notebook_reorder_child, GTYPE_SELF, GTK_TYPE_WIDGET, G_TYPE_INT);
	gtype_reg_end();

	gtype_reg_start(GTK_TYPE_TREE_VIEW, gtk_tree_view);
		gtype_reg_ffi(GTK_TYPE_WIDGET, gtk_tree_view_new, G_TYPE_INVALID);
		gtype_reg_ffi(GTK_TYPE_WIDGET, gtk_tree_view_new_with_model, GTK_TYPE_TREE_MODEL);
		gtype_reg_ffi(GTK_TYPE_TREE_SELECTION, gtk_tree_view_get_selection, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_view_columns_autosize, GTYPE_SELF);

		gtype_reg_ffi(G_TYPE_INT, gtk_tree_view_append_column, GTYPE_SELF, GTK_TYPE_TREE_VIEW_COLUMN);
		gtype_reg_ffi(G_TYPE_INT, gtk_tree_view_remove_column, GTYPE_SELF, GTK_TYPE_TREE_VIEW_COLUMN);
		gtype_reg_ffi(G_TYPE_INT, gtk_tree_view_insert_column, GTYPE_SELF, GTK_TYPE_TREE_VIEW_COLUMN, G_TYPE_INT);
		gtype_reg_ffi(GTK_TYPE_TREE_VIEW_COLUMN, gtk_tree_view_get_column, GTYPE_SELF, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_view_move_column_after, GTYPE_SELF, GTK_TYPE_TREE_VIEW_COLUMN, GTK_TYPE_TREE_VIEW_COLUMN);

		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_view_scroll_to_point, GTYPE_SELF, G_TYPE_INT, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_view_scroll_to_cell, GTYPE_SELF, GTK_TYPE_TREE_PATH, GTK_TYPE_TREE_VIEW_COLUMN, G_TYPE_BOOLEAN, G_TYPE_FLOAT, G_TYPE_FLOAT);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_view_row_activated, GTYPE_SELF, GTK_TYPE_TREE_PATH, GTK_TYPE_TREE_VIEW_COLUMN);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_view_expand_all, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_view_collapse_all, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_view_expand_to_path, GTYPE_SELF, GTK_TYPE_TREE_PATH);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_view_expand_row, GTYPE_SELF, GTK_TYPE_TREE_PATH, G_TYPE_BOOLEAN);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_tree_view_collapse_row, GTYPE_SELF, GTK_TYPE_TREE_PATH);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_tree_view_row_expanded, GTYPE_SELF, GTK_TYPE_TREE_PATH);

		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_view_set_cursor, GTYPE_SELF, GTK_TYPE_TREE_PATH, GTK_TYPE_TREE_VIEW_COLUMN, G_TYPE_BOOLEAN);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_view_set_cursor_on_cell, GTYPE_SELF, GTK_TYPE_TREE_PATH, GTK_TYPE_TREE_VIEW_COLUMN, GTK_TYPE_CELL_RENDERER, G_TYPE_BOOLEAN);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_view_get_cursor, GTYPE_SELF, GTK_TYPE_TREE_PATH, out GTK_TYPE_TREE_VIEW_COLUMN);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_tree_view_get_path_at_pos, GTYPE_SELF, G_TYPE_INT, G_TYPE_INT, out GTK_TYPE_TREE_PATH, out GTK_TYPE_TREE_VIEW_COLUMN, out G_TYPE_INT, out G_TYPE_INT);

#if GTK_CHECK_VERSION(3,4,0)
		gtype_reg_ffi(G_TYPE_UINT, gtk_tree_view_get_n_columns, GTYPE_SELF);
#endif
	gtype_reg_end();

	gtype_reg_start(GTK_TYPE_TEXT_VIEW, gtk_text_view);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_text_view_scroll_to_iter, GTYPE_SELF, GTK_TYPE_TEXT_ITER, G_TYPE_DOUBLE, G_TYPE_BOOLEAN, G_TYPE_DOUBLE, G_TYPE_DOUBLE);
	gtype_reg_end();

#ifdef GTK_TYPE_TABLE
	gtype_reg_start(GTK_TYPE_TABLE, gtk_table); gtype_reg_end();
#endif

	gtype_reg_start(GTK_TYPE_TOOLBAR, gtk_toolbar); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_TOOL_ITEM_GROUP, gtk_tool_item_group); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_MISC, gtk_misc); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_LABEL, gtk_label); gtype_reg_end();

#ifdef GTK_TYPE_ARROW
	gtype_reg_start(GTK_TYPE_ARROW, gtk_arrow); gtype_reg_end();
#endif

	gtype_reg_start(GTK_TYPE_IMAGE, gtk_image); gtype_reg_end();

#ifdef GTK_TYPE_PIXMAP
	gtype_reg_start(GTK_TYPE_PIXMAP, gtk_pixmap); gtype_reg_end();
#endif

	gtype_reg_start(GTK_TYPE_CALENDAR, gtk_calendar); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_CELL_VIEW, gtk_cell_view); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_DRAWING_AREA, gtk_drawing_area); gtype_reg_end();

#ifdef GTK_TYPE_CURVE
	gtype_reg_start(GTK_TYPE_CURVE, gtk_curve); gtype_reg_end();
#endif

	gtype_reg_start(GTK_TYPE_SPINNER, gtk_spinner); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_ENTRY, gtk_entry); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_SPIN_BUTTON, gtk_spin_button); gtype_reg_end();

#ifdef GTK_TYPE_RULER
	gtype_reg_start(GTK_TYPE_RULER, gtk_ruler); gtype_reg_end();
#endif

#ifdef GTK_TYPE_HRULER
	gtype_reg_start(GTK_TYPE_HRULER, gtk_hruler); gtype_reg_end();
#endif

#ifdef GTK_TYPE_VRULER
	gtype_reg_start(GTK_TYPE_VRULER, gtk_vruler); gtype_reg_end();
#endif

	gtype_reg_start(GTK_TYPE_RANGE, gtk_range); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_SCALE, gtk_scale); gtype_reg_end();

#ifdef GTK_TYPE_HSCALE
	gtype_reg_start(GTK_TYPE_HSCALE, gtk_hscale); gtype_reg_end();
#endif

#ifdef GTK_TYPE_VSCALE
	gtype_reg_start(GTK_TYPE_VSCALE, gtk_vscale); gtype_reg_end();
#endif

	gtype_reg_start(GTK_TYPE_SCROLLBAR, gtk_scrollbar); gtype_reg_end();

#ifdef GTK_TYPE_HSCROLLBAR
	gtype_reg_start(GTK_TYPE_HSCROLLBAR, gtk_hscrollbar); gtype_reg_end();
#endif

#ifdef GTK_TYPE_VSCROLLBAR
	gtype_reg_start(GTK_TYPE_VSCROLLBAR, gtk_vscrollbar); gtype_reg_end();
#endif

	gtype_reg_start(GTK_TYPE_SEPARATOR, gtk_separator); gtype_reg_end();

#ifdef GTK_TYPE_HSEPARATOR
	gtype_reg_start(GTK_TYPE_HSEPARATOR, gtk_hseparator); gtype_reg_end();
#endif

#ifdef GTK_TYPE_VSEPARATOR
	gtype_reg_start(GTK_TYPE_VSEPARATOR, gtk_vseparator); gtype_reg_end();
#endif

#ifdef GTK_TYPE_HSV
	gtype_reg_start(GTK_TYPE_HSV, gtk_hsv); gtype_reg_end();
#endif

	gtype_reg_start(GTK_TYPE_INVISIBLE, gtk_invisible); gtype_reg_end();

#ifdef GTK_TYPE_PREVIEW
	gtype_reg_start(GTK_TYPE_PREVIEW, gtk_preview); gtype_reg_end();
#endif

#ifdef GTK_TYPE_PROGRESS
	gtype_reg_start(GTK_TYPE_PROGRESS, gtk_progress); gtype_reg_end();
#endif

	gtype_reg_start(GTK_TYPE_PROGRESS_BAR, gtk_progress_bar); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_ADJUSTMENT, gtk_adjustment); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_CELL_RENDERER, gtk_cell_renderer); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_CELL_RENDERER_TEXT, gtk_cell_renderer_text); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_CELL_RENDERER_ACCEL, gtk_cell_renderer_accel); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_CELL_RENDERER_COMBO, gtk_cell_renderer_combo); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_CELL_RENDERER_SPIN, gtk_cell_renderer_spin); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_CELL_RENDERER_PIXBUF, gtk_cell_renderer_pixbuf); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_CELL_RENDERER_PROGRESS, gtk_cell_renderer_progress); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_CELL_RENDERER_SPINNER, gtk_cell_renderer_spinner); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_CELL_RENDERER_TOGGLE, gtk_cell_renderer_toggle); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_FILE_FILTER, gtk_file_filter); gtype_reg_end();

#ifdef GTK_TYPE_ITEM_FACTORY
	gtype_reg_start(GTK_TYPE_ITEM_FACTORY, gtk_item_factory); gtype_reg_end();
#endif

#ifdef GTK_TYPE_TOOLTIPS
	gtype_reg_start(GTK_TYPE_TOOLTIPS, gtk_tooltips); gtype_reg_end();
#endif

	gtype_reg_start(GTK_TYPE_TREE_VIEW_COLUMN, gtk_tree_view_column); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_RECENT_FILTER, gtk_recent_filter); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_ACCEL_GROUP, gtk_accel_group); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_ACCEL_MAP, gtk_accel_map); gtype_reg_end();

#ifdef GTK_TYPE_ACTION
	gtype_reg_start(GTK_TYPE_ACTION, gtk_action); gtype_reg_end();
#endif

#ifdef GTK_TYPE_TOGGLE_ACTION
	gtype_reg_start(GTK_TYPE_TOGGLE_ACTION, gtk_toggle_action); gtype_reg_end();
#endif

#ifdef GTK_TYPE_RADIO_ACTION
	gtype_reg_start(GTK_TYPE_RADIO_ACTION, gtk_radio_action); gtype_reg_end();
#endif

#ifdef GTK_TYPE_RECENT_ACTION
	gtype_reg_start(GTK_TYPE_RECENT_ACTION, gtk_recent_action); gtype_reg_end();
#endif
	
#ifdef GTK_TYPE_ACTION_GROUP
	gtype_reg_start(GTK_TYPE_ACTION_GROUP, gtk_action_group); gtype_reg_end();
#endif

	gtype_reg_start(GTK_TYPE_CLIPBOARD, gtk_clipboard); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_ENTRY_BUFFER, gtk_entry_buffer); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_ENTRY_COMPLETION, gtk_entry_completion); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_ICON_FACTORY, gtk_icon_factory); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_ICON_THEME, gtk_icon_theme);
		gtype_reg_ffi(GTYPE_SELF, gtk_icon_theme_get_default);
		gtype_reg_ffi(GTYPE_SELF, gtk_icon_theme_get_for_screen, GDK_TYPE_SCREEN);
		gtype_reg_ffi(G_TYPE_NONE, gtk_icon_theme_set_screen, GTYPE_SELF, GDK_TYPE_SCREEN);
		gtype_reg_ffi(G_TYPE_NONE, gtk_icon_theme_set_search_path, GTYPE_SELF, G_TYPE_STRV, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_NONE, gtk_icon_theme_get_search_path, GTYPE_SELF, out G_TYPE_STRV, out G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_NONE, gtk_icon_theme_append_search_path, GTYPE_SELF, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_NONE, gtk_icon_theme_prepend_search_path, GTYPE_SELF, G_TYPE_STRING);
	#if GTK_CHECK_VERSION(3,14,0)
		gtype_reg_ffi(G_TYPE_NONE, gtk_icon_theme_add_resource_path, GTYPE_SELF, G_TYPE_STRING);
	#endif
		gtype_reg_ffi(G_TYPE_NONE, gtk_icon_theme_set_custom_theme, GTYPE_SELF, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_icon_theme_has_icon, GTYPE_SELF, G_TYPE_STRING);
		gtype_reg_ffi(GTK_TYPE_ICON_INFO, gtk_icon_theme_lookup_icon, GTYPE_SELF, G_TYPE_STRING, G_TYPE_INT, GTK_TYPE_ICON_LOOKUP_FLAGS);
		gtype_reg_ffi(GTK_TYPE_ICON_INFO, gtk_icon_theme_choose_icon, GTYPE_SELF, G_TYPE_STRV, G_TYPE_INT, GTK_TYPE_ICON_LOOKUP_FLAGS);
		gtype_reg_ffi(GDK_TYPE_PIXBUF, gtk_icon_theme_load_icon, GTYPE_SELF, G_TYPE_STRING, G_TYPE_INT, GTK_TYPE_ICON_LOOKUP_FLAGS, opt out G_TYPE_ERROR);
		gtype_reg_ffi(GTK_TYPE_ICON_INFO, gtk_icon_theme_lookup_by_gicon, GTYPE_SELF, G_TYPE_ICON, G_TYPE_INT, GTK_TYPE_ICON_LOOKUP_FLAGS);
	gtype_reg_end();

	gtype_reg_start(GTK_TYPE_ICON_INFO, gtk_icon_info);
		gtype_reg_ffi(GTYPE_SELF, gtk_icon_info_copy, GTYPE_SELF);
		gtype_reg_ffi(GTYPE_SELF, gtk_icon_info_new_for_pixbuf, GTYPE_SELF, GDK_TYPE_PIXBUF);
		gtype_reg_ffi(G_TYPE_INT, gtk_icon_info_get_base_size, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_INT, gtk_icon_info_get_base_scale, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_STRING, gtk_icon_info_get_filename, GTYPE_SELF);
		gtype_reg_ffi(GDK_TYPE_PIXBUF, gtk_icon_info_get_builtin_pixbuf, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_icon_info_is_symbolic, GTYPE_SELF);
		gtype_reg_ffi(GDK_TYPE_PIXBUF, gtk_icon_info_load_icon, GTYPE_SELF, out G_TYPE_ERROR);
		gtype_reg_ffi(G_TYPE_STRING, gtk_icon_info_get_display_name, GTYPE_SELF);
	gtype_reg_end();

	gtype_reg_start(GTK_TYPE_IM_CONTEXT, gtk_im_context); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_IM_CONTEXT_SIMPLE, gtk_im_context_simple); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_IM_MULTICONTEXT, gtk_im_multicontext); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_LIST_STORE, gtk_list_store);
		gtype_reg_ffi(G_TYPE_NONE, gtk_list_store_append, GTYPE_SELF, GTK_TYPE_TREE_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_list_store_clear, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE, gtk_list_store_set_value, GTYPE_SELF, GTK_TYPE_TREE_ITER, G_TYPE_INT, G_TYPE_VALUE);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_list_store_remove, GTYPE_SELF, GTK_TYPE_TREE_ITER);
	gtype_reg_end();

	gtype_reg_start(GTK_TYPE_MOUNT_OPERATION, gtk_mount_operation); gtype_reg_end();

#ifdef GTK_TYPE_RC_STYLE
	gtype_reg_start(GTK_TYPE_RC_STYLE, gtk_rc_style); gtype_reg_end();
#endif

	gtype_reg_start(GTK_TYPE_RECENT_MANAGER, gtk_recent_manager); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_SETTINGS, gtk_settings); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_SIZE_GROUP, gtk_size_group); gtype_reg_end();

#ifdef GTK_TYPE_STATUS_ICON
	gtype_reg_start(GTK_TYPE_STATUS_ICON, gtk_status_icon); gtype_reg_end();
#endif

#ifdef GTK_TYPE_STYLE
	gtype_reg_start(GTK_TYPE_STYLE, gtk_style); gtype_reg_end();
#endif

	gtype_reg_start(GTK_TYPE_TEXT_BUFFER, gtk_text_buffer);
		gtype_reg_ffi(G_TYPE_INT, gtk_text_buffer_get_line_count, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_INT, gtk_text_buffer_get_char_count, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_set_text, GTYPE_SELF, G_TYPE_STRING, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_insert, GTYPE_SELF, GTK_TYPE_TEXT_ITER, G_TYPE_STRING, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_insert_at_cursor, GTYPE_SELF, G_TYPE_STRING, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_text_buffer_insert_interactive, GTYPE_SELF, GTK_TYPE_TEXT_ITER, G_TYPE_STRING, G_TYPE_INT, G_TYPE_BOOLEAN);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_text_buffer_insert_interactive_at_cursor, GTYPE_SELF, G_TYPE_STRING, G_TYPE_INT, G_TYPE_BOOLEAN);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_insert_range, GTYPE_SELF, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_text_buffer_insert_range_interactive, GTYPE_SELF, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER, G_TYPE_BOOLEAN);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_delete, GTYPE_SELF, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_text_buffer_delete_interactive, GTYPE_SELF, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER, G_TYPE_BOOLEAN);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_text_buffer_backspace, GTYPE_SELF, GTK_TYPE_TEXT_ITER, G_TYPE_BOOLEAN, G_TYPE_BOOLEAN);
		gtype_reg_ffi_rnew(G_TYPE_STRING, gtk_text_buffer_get_text, GTYPE_SELF, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER, G_TYPE_BOOLEAN);
		gtype_reg_ffi_rnew(G_TYPE_STRING, gtk_text_buffer_get_slice, GTYPE_SELF, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER, G_TYPE_BOOLEAN);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_insert_pixbuf, GTYPE_SELF, GTK_TYPE_TEXT_ITER, GDK_TYPE_PIXBUF);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_insert_child_anchor, GTYPE_SELF, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_CHILD_ANCHOR);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_add_mark, GTYPE_SELF, GTK_TYPE_TEXT_MARK, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi_rnew(GTK_TYPE_TEXT_MARK, gtk_text_buffer_create_mark, GTYPE_SELF, G_TYPE_STRING, GTK_TYPE_TEXT_ITER, G_TYPE_BOOLEAN);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_move_mark, GTYPE_SELF, GTK_TYPE_TEXT_MARK, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_delete_mark, GTYPE_SELF, GTK_TYPE_TEXT_MARK);
		gtype_reg_ffi(GTK_TYPE_TEXT_MARK, gtk_text_buffer_get_mark, GTYPE_SELF, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_move_mark_by_name, GTYPE_SELF, G_TYPE_STRING, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_delete_mark_by_name, GTYPE_SELF, G_TYPE_STRING);
		gtype_reg_ffi(GTK_TYPE_TEXT_MARK, gtk_text_buffer_get_insert, GTYPE_SELF);
		gtype_reg_ffi(GTK_TYPE_TEXT_MARK, gtk_text_buffer_get_selection_bound, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_place_cursor, GTYPE_SELF, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_select_range, GTYPE_SELF, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_apply_tag, GTYPE_SELF, GTK_TYPE_TEXT_TAG, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_remove_tag, GTYPE_SELF, GTK_TYPE_TEXT_TAG, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_apply_tag_by_name, GTYPE_SELF, G_TYPE_STRING, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_remove_tag_by_name, GTYPE_SELF, G_TYPE_STRING, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_remove_all_tags, GTYPE_SELF, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_get_iter_at_line_offset, GTYPE_SELF, GTK_TYPE_TEXT_ITER, G_TYPE_INT, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_get_iter_at_line_index, GTYPE_SELF, GTK_TYPE_TEXT_ITER, G_TYPE_INT, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_get_iter_at_offset, GTYPE_SELF, GTK_TYPE_TEXT_ITER, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_get_iter_at_line, GTYPE_SELF, GTK_TYPE_TEXT_ITER, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_get_start_iter, GTYPE_SELF, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_get_end_iter, GTYPE_SELF, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_get_bounds, GTYPE_SELF, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_get_iter_at_mark, GTYPE_SELF, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_MARK);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_get_iter_at_child_anchor, GTYPE_SELF, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_CHILD_ANCHOR);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_text_buffer_get_modified, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_set_modified, GTYPE_SELF, G_TYPE_BOOLEAN);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_add_selection_clipboard, GTYPE_SELF, GTK_TYPE_CLIPBOARD);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_remove_selection_clipboard, GTYPE_SELF, GTK_TYPE_CLIPBOARD);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_cut_clipboard, GTYPE_SELF, GTK_TYPE_CLIPBOARD, G_TYPE_BOOLEAN);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_copy_clipboard, GTYPE_SELF, GTK_TYPE_CLIPBOARD);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_paste_clipboard, GTYPE_SELF, GTK_TYPE_CLIPBOARD, GTK_TYPE_TEXT_ITER, G_TYPE_BOOLEAN);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_text_buffer_get_selection_bounds, GTYPE_SELF, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_text_buffer_delete_selection, GTYPE_SELF, G_TYPE_BOOLEAN, G_TYPE_BOOLEAN);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_begin_user_action, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_end_user_action, GTYPE_SELF);
	gtype_reg_end();

	gtype_reg_start(GTK_TYPE_TEXT_CHILD_ANCHOR, gtk_text_child_anchor); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_TEXT_MARK, gtk_text_mark); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_TEXT_TAG, gtk_text_tag); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_TEXT_TAG_TABLE, gtk_text_tag_table); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_TREE_MODEL_FILTER, gtk_tree_model_filter); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_TREE_MODEL_SORT, gtk_tree_model_sort); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_TREE_SELECTION, gtk_tree_selection);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_selection_set_mode, GTYPE_SELF, GTK_TYPE_SELECTION_MODE);
		gtype_reg_ffi(GTK_TYPE_SELECTION_MODE, gtk_tree_selection_get_mode, GTYPE_SELF);
		gtype_reg_ffi(GTK_TYPE_TREE_VIEW, gtk_tree_selection_get_tree_view, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_tree_selection_get_selected, GTYPE_SELF, out GTK_TYPE_TREE_MODEL, GTK_TYPE_TREE_ITER);

		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_selection_select_path, GTYPE_SELF, GTK_TYPE_TREE_PATH);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_selection_unselect_path, GTYPE_SELF, GTK_TYPE_TREE_PATH);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_tree_selection_path_is_selected, GTYPE_SELF, GTK_TYPE_TREE_PATH);

		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_selection_select_iter, GTYPE_SELF, GTK_TYPE_TREE_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_selection_unselect_iter, GTYPE_SELF, GTK_TYPE_TREE_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_tree_selection_iter_is_selected, GTYPE_SELF, GTK_TYPE_TREE_ITER);

		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_selection_select_all, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_selection_unselect_all, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_selection_select_range, GTYPE_SELF, GTK_TYPE_TREE_PATH, GTK_TYPE_TREE_PATH);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_selection_unselect_range, GTYPE_SELF, GTK_TYPE_TREE_PATH, GTK_TYPE_TREE_PATH);
	gtype_reg_end();

	gtype_reg_start(GTK_TYPE_TREE_STORE, gtk_tree_store);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_store_append, GTYPE_SELF, GTK_TYPE_TREE_ITER, opt GTK_TYPE_TREE_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_store_prepend, GTYPE_SELF, GTK_TYPE_TREE_ITER, opt GTK_TYPE_TREE_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_store_clear, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_store_set_value, GTYPE_SELF, GTK_TYPE_TREE_ITER, G_TYPE_INT, opt G_TYPE_VALUE);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_tree_store_remove, GTYPE_SELF, GTK_TYPE_TREE_ITER);
	gtype_reg_end();

	gtype_reg_start(GTK_TYPE_WINDOW_GROUP, gtk_window_group); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_TOOLTIP, gtk_tooltip); gtype_reg_end();

#ifdef GTK_TYPE_APPLICATION
	gtype_reg_start(GTK_TYPE_APPLICATION, gtk_application);
		gtype_reg_ffi(GTYPE_SELF, gtk_application_new, G_TYPE_STRING, G_TYPE_APPLICATION_FLAGS);
		gtype_reg_ffi(G_TYPE_NONE, gtk_application_add_window, GTYPE_SELF, GTK_TYPE_WINDOW);
		gtype_reg_ffi(G_TYPE_NONE, gtk_application_remove_window, GTYPE_SELF, GTK_TYPE_WINDOW);

		gtype_reg_ffi(G_TYPE_MENU_MODEL, gtk_application_get_app_menu, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE, gtk_application_set_app_menu, GTYPE_SELF, G_TYPE_MENU_MODEL);

		gtype_reg_ffi(G_TYPE_MENU_MODEL, gtk_application_get_menubar, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE, gtk_application_set_menubar, GTYPE_SELF, G_TYPE_MENU_MODEL);

		gtype_reg_ffi(G_TYPE_UINT, gtk_application_inhibit, GTYPE_SELF, GTK_TYPE_WINDOW, GTK_TYPE_APPLICATION_INHIBIT_FLAGS, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_NONE, gtk_application_uninhibit, GTYPE_SELF, G_TYPE_UINT);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_application_is_inhibited, GTYPE_SELF, GTK_TYPE_APPLICATION_INHIBIT_FLAGS);

		gtype_reg_ffi(GTK_TYPE_WINDOW, gtk_application_get_window_by_id, GTYPE_SELF, G_TYPE_UINT);
		gtype_reg_ffi(GTK_TYPE_WINDOW, gtk_application_get_active_window, GTYPE_SELF);
	gtype_reg_end();
#endif
}

static int _lua_function_callback_wrapper(lua_State* L) {
	lua_pushvalue(L, lua_upvalueindex(1));
	lua_insert(L, 1);
	lua_pushvalue(L, lua_upvalueindex(2));
	lua_insert(L, 2);
	lua_call(L, lua_gettop(L)-1, LUA_MULTRET);
	return lua_gettop(L);
}

static void _gtk_builder_connect_wrapper(GtkBuilder* builder, GObject* object, const gchar* signal_name, const gchar* handler_name, GObject* connect_object, GConnectFlags flags, gpointer user_data) {
	lua_State* L = (lua_State*)user_data;
	lua_pushcfunction(L, glua_signal_connect);
	glua_object_push(L, object);
	lua_pushstring(L, signal_name);
	if( lua_istable(L, 2) ) {
		lua_getfield(L, 2, handler_name);
	} else {
		lua_pushvalue(L, 2);
		lua_pushstring(L, handler_name);
		lua_pushcclosure(L, _lua_function_callback_wrapper, 2);
	}
	if( lua_isfunction(L,-1) ) {
		lua_pushboolean(L, ((flags&G_CONNECT_AFTER) != 0));
		lua_call(L, 4, 0);
	} else {
		lua_pop(L, 4);
		fprintf(stderr, "not find signal handle(%s)\n", handler_name);
	}
}

static int _lua_gtk_builder_add_from_string(lua_State* L) {
	GObject* obj = glua_object_check(L, 1);
	GtkBuilder* builder = GTK_BUILDER(obj);
	if( !builder )
		return luaL_argerror(L, 1, "need GtkBuilder");
	size_t len = 0;
	const char* str = luaL_checklstring(L, 2, &len);
	GError* err = NULL;
	guint res = gtk_builder_add_from_string(builder, str, (gsize)len, &err);
	if( err ) {
		lua_pushstring(L, err->message);
		g_error_free(err);
		return lua_error(L);
	}
	lua_pushinteger(L, (lua_Integer)res);
	return 1;
}

static int _lua_gtk_builder_connect_signals(lua_State* L) {
	GObject* obj = glua_object_check(L, 1);
	GtkBuilder* builder = GTK_BUILDER(obj);
	if( !builder )
		return luaL_argerror(L, 1, "need GtkBuilder");
	if( !(lua_istable(L, 2) || lua_isfunction(L, 2)) )
		return luaL_argerror(L, 2, "need table or function");
	gtk_builder_connect_signals_full(builder, _gtk_builder_connect_wrapper, L);
	return 0;
}

static void gtk_builder_register(lua_State* L) {
	gtype_reg_env_declare();

	gtype_reg_start(GTK_TYPE_BUILDER, gtk_builder);
		gtype_reg_ffi(G_TYPE_OBJECT, gtk_builder_get_object, GTK_TYPE_BUILDER, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_INT, gtk_builder_get_type_from_name, GTK_TYPE_BUILDER, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_UINT, gtk_builder_add_from_file, GTK_TYPE_BUILDER, G_TYPE_STRING, out G_TYPE_ERROR);
		gtype_reg_lua(gtk_builder_add_from_string);
		gtype_reg_lua(gtk_builder_connect_signals);
	gtype_reg_end();
}

static void gtypes_gtk_register(lua_State* L) {
	gtk_globals_register(L);
	gtk_boxed_register(L);
	gtk_interface_register(L);
	gtk_object_register(L);
	gtk_builder_register(L);
}

