// gtypes_gtk.c

#include "glua.h"

#include <assert.h>

#define GTK_DISABLE_DEPRECATED
#include <gtk/gtk.h>

#include "gffireg.h"

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
		_reg_ffi(G_TYPE_NONE, gtk_disable_setlocale);
		_reg_ffi(PANGO_TYPE_LANGUAGE, gtk_get_default_language);
#if GTK_CHECK_VERSION(3,12,0)
		_reg_ffi(GTK_TYPE_TEXT_DIRECTION, gtk_get_locale_direction);
#endif
		_reg_ffi(G_TYPE_NONE, gtk_main_do_event, GDK_TYPE_EVENT);
		_reg_ffi(G_TYPE_NONE, gtk_main);
		_reg_ffi(G_TYPE_UINT, gtk_main_level);
		_reg_ffi(G_TYPE_NONE, gtk_main_quit);
		_reg_ffi(G_TYPE_BOOLEAN, gtk_main_iteration);
		_reg_ffi(G_TYPE_BOOLEAN, gtk_main_iteration_do, G_TYPE_BOOLEAN);
		_reg_ffi(G_TYPE_BOOLEAN, gtk_true);
		_reg_ffi(G_TYPE_BOOLEAN, gtk_false);
		_reg_ffi(G_TYPE_NONE, gtk_grab_add, GTK_TYPE_WIDGET);
		_reg_ffi(GTK_TYPE_WIDGET, gtk_grab_get_current);
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
		gtype_reg_ffi(G_TYPE_UINT, gdk_event_get_time, GDK_TYPE_EVENT);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gdk_event_get_state, GDK_TYPE_EVENT, out GDK_TYPE_MODIFIER_TYPE);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gdk_event_get_coords, GDK_TYPE_EVENT, out G_TYPE_DOUBLE, out G_TYPE_DOUBLE);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gdk_event_get_root_coords, GDK_TYPE_EVENT, out G_TYPE_DOUBLE, out G_TYPE_DOUBLE);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gdk_event_get_axis, GDK_TYPE_EVENT, GDK_TYPE_AXIS_USE, out G_TYPE_DOUBLE);
		gtype_reg_ffi(G_TYPE_NONE, gdk_event_set_screen, GDK_TYPE_EVENT, GDK_TYPE_SCREEN);
		gtype_reg_ffi(GDK_TYPE_SCREEN, gdk_event_get_screen, GDK_TYPE_EVENT);
#if GTK_CHECK_VERSION(3,0,0)
		gtype_reg_ffi(GDK_TYPE_WINDOW, gdk_event_get_window, GDK_TYPE_EVENT);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gdk_event_get_button, GDK_TYPE_EVENT, out G_TYPE_UINT);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gdk_event_get_click_count, GDK_TYPE_EVENT, out G_TYPE_UINT);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gdk_event_get_keyval, GDK_TYPE_EVENT, out G_TYPE_UINT);
		gtype_reg_ffi_rename(G_TYPE_BOOLEAN, gdk_event_get_keycode, GDK_TYPE_EVENT, out G_TYPE_UINT);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gdk_event_get_scroll_direction, GDK_TYPE_EVENT, out GDK_TYPE_SCROLL_DIRECTION);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gdk_event_get_scroll_deltas, GDK_TYPE_EVENT, out G_TYPE_DOUBLE, out G_TYPE_DOUBLE);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gdk_event_get_axis, GDK_TYPE_EVENT, GDK_TYPE_AXIS_USE, out G_TYPE_DOUBLE);
		gtype_reg_ffi(G_TYPE_NONE, gdk_event_set_device, GDK_TYPE_EVENT, GDK_TYPE_DEVICE);
		gtype_reg_ffi(GDK_TYPE_DEVICE, gdk_event_get_device, GDK_TYPE_EVENT);
		gtype_reg_ffi(G_TYPE_NONE, gdk_event_set_source_device, GDK_TYPE_EVENT, GDK_TYPE_DEVICE);
		gtype_reg_ffi(GDK_TYPE_DEVICE, gdk_event_get_source_device, GDK_TYPE_EVENT);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gdk_event_triggers_context_menu, GDK_TYPE_EVENT);
		gtype_reg_ffi(GDK_TYPE_EVENT_TYPE, gdk_event_get_event_type, GDK_TYPE_EVENT);
#endif
	gtype_reg_end();

	gtype_reg_start(GTK_TYPE_PAPER_SIZE, gtk_paper_size); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_TEXT_ITER, gtk_text_iter);
		gtype_reg_boxed_new_use_c_struct_new0(GTK_TYPE_TEXT_ITER, gtk_text_iter_new, GtkTextIter);
		gtype_reg_ffi_rnew(GTK_TYPE_TEXT_ITER, gtk_text_iter_copy, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_INT , gtk_text_iter_get_offset, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_INT , gtk_text_iter_get_line, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_INT , gtk_text_iter_get_line_offset, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_INT , gtk_text_iter_get_line_index, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_INT , gtk_text_iter_get_visible_line_offset, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_INT , gtk_text_iter_get_visible_line_index, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi_rnew(G_TYPE_STRING, gtk_text_iter_get_slice, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi_rnew(G_TYPE_STRING, gtk_text_iter_get_text, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi_rnew(G_TYPE_STRING, gtk_text_iter_get_visible_slice, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi_rnew(G_TYPE_STRING, gtk_text_iter_get_visible_text, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(GDK_TYPE_PIXBUF, gtk_text_iter_get_pixbuf, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(GTK_TYPE_TEXT_CHILD_ANCHOR, gtk_text_iter_get_child_anchor, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_begins_tag, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_TAG);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_ends_tag, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_TAG);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_toggles_tag, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_TAG);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_has_tag, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_TAG);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_editable, GTK_TYPE_TEXT_ITER, G_TYPE_BOOLEAN);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_can_insert, GTK_TYPE_TEXT_ITER, G_TYPE_BOOLEAN);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_starts_word, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_ends_word, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_inside_word, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_starts_sentence, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_ends_sentence, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_inside_sentence, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_starts_line, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_ends_line, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_is_cursor_position, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_INT , gtk_text_iter_get_chars_in_line, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_INT , gtk_text_iter_get_bytes_in_line, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_get_attributes, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ATTRIBUTES);
		gtype_reg_ffi(PANGO_TYPE_LANGUAGE, gtk_text_iter_get_language, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_is_end, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_is_start, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_forward_char, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_backward_char, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_forward_chars, GTK_TYPE_TEXT_ITER, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_backward_chars, GTK_TYPE_TEXT_ITER, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_forward_line, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_backward_line, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_forward_lines, GTK_TYPE_TEXT_ITER, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_backward_lines, GTK_TYPE_TEXT_ITER, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_forward_word_end, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_backward_word_start, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_forward_word_ends, GTK_TYPE_TEXT_ITER, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_backward_word_starts, GTK_TYPE_TEXT_ITER, G_TYPE_INT);
		gtype_reg_ffi( G_TYPE_BOOLEAN , gtk_text_iter_forward_visible_line, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_backward_visible_line, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_forward_visible_lines, GTK_TYPE_TEXT_ITER, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_backward_visible_lines, GTK_TYPE_TEXT_ITER, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_forward_visible_word_end, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_backward_visible_word_start, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_forward_visible_word_ends, GTK_TYPE_TEXT_ITER, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_backward_visible_word_starts, GTK_TYPE_TEXT_ITER, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_forward_sentence_end, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_backward_sentence_start, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_forward_sentence_ends, GTK_TYPE_TEXT_ITER, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_backward_sentence_starts, GTK_TYPE_TEXT_ITER, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_forward_cursor_position, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_backward_cursor_position, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_forward_cursor_positions, GTK_TYPE_TEXT_ITER, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_backward_cursor_positions, GTK_TYPE_TEXT_ITER, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_forward_visible_cursor_position, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_backward_visible_cursor_position, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_forward_visible_cursor_positions, GTK_TYPE_TEXT_ITER, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_backward_visible_cursor_positions, GTK_TYPE_TEXT_ITER, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_NONE , gtk_text_iter_set_offset, GTK_TYPE_TEXT_ITER, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_NONE , gtk_text_iter_set_line, GTK_TYPE_TEXT_ITER, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_NONE , gtk_text_iter_set_line_offset, GTK_TYPE_TEXT_ITER, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_NONE , gtk_text_iter_set_line_index, GTK_TYPE_TEXT_ITER, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_NONE , gtk_text_iter_forward_to_end, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_forward_to_line_end, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_NONE , gtk_text_iter_set_visible_line_offset, GTK_TYPE_TEXT_ITER, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_NONE , gtk_text_iter_set_visible_line_index, GTK_TYPE_TEXT_ITER, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_forward_to_tag_toggle, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_TAG);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_backward_to_tag_toggle, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_TAG);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_forward_search, GTK_TYPE_TEXT_ITER, G_TYPE_STRING, GTK_TYPE_TEXT_SEARCH_FLAGS, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_backward_search, GTK_TYPE_TEXT_ITER, G_TYPE_STRING, GTK_TYPE_TEXT_SEARCH_FLAGS, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_equal, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_INT , gtk_text_iter_compare, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_in_range, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_NONE , gtk_text_iter_order, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER);
	gtype_reg_end();

	gtype_reg_start(GTK_TYPE_REQUISITION, gtk_requisition); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_SELECTION_DATA, gtk_selection_data); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_BORDER, gtk_border); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_TREE_ITER, gtk_tree_iter);
		gtype_reg_boxed_new_use_c_struct_new0(GTK_TYPE_TREE_ITER, gtk_tree_iter_new, GtkTreeIter);
		gtype_reg_ffi_rnew(GTK_TYPE_TREE_ITER, gtk_tree_iter_copy, GTK_TYPE_TREE_ITER);
	gtype_reg_end();

	gtype_reg_start(GTK_TYPE_TREE_PATH, gtk_tree_path); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_ICON_SET, gtk_icon_set); gtype_reg_end();

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
		gtype_reg_ffi(GTK_TYPE_TREE_MODEL_FLAGS, gtk_tree_model_get_flags, GTK_TYPE_TREE_MODEL);
		gtype_reg_ffi(G_TYPE_UINT, gtk_tree_model_get_n_columns, GTK_TYPE_TREE_MODEL);
		gtype_reg_ffi(G_TYPE_UINT, gtk_tree_model_get_column_type, GTK_TYPE_TREE_MODEL, G_TYPE_INT);

		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_tree_model_get_iter, GTK_TYPE_TREE_MODEL, GTK_TYPE_TREE_ITER, GTK_TYPE_TREE_PATH);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_tree_model_get_iter_from_string, GTK_TYPE_TREE_MODEL, GTK_TYPE_TREE_ITER, G_TYPE_STRING);
		gtype_reg_ffi_rnew(G_TYPE_STRING, gtk_tree_model_get_string_from_iter, GTK_TYPE_TREE_MODEL, GTK_TYPE_TREE_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_tree_model_get_iter_first, GTK_TYPE_TREE_MODEL, GTK_TYPE_TREE_ITER);
		gtype_reg_ffi_rnew(GTK_TYPE_TREE_PATH, gtk_tree_model_get_path, GTK_TYPE_TREE_MODEL, GTK_TYPE_TREE_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_model_get_value, GTK_TYPE_TREE_MODEL, GTK_TYPE_TREE_ITER, G_TYPE_INT, G_TYPE_VALUE);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_tree_model_iter_next, GTK_TYPE_TREE_MODEL, GTK_TYPE_TREE_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_tree_model_iter_children, GTK_TYPE_TREE_MODEL, GTK_TYPE_TREE_ITER, GTK_TYPE_TREE_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_tree_model_iter_has_child, GTK_TYPE_TREE_MODEL, GTK_TYPE_TREE_ITER);
		gtype_reg_ffi(G_TYPE_INT, gtk_tree_model_iter_n_children, GTK_TYPE_TREE_MODEL, GTK_TYPE_TREE_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_tree_model_iter_nth_child, GTK_TYPE_TREE_MODEL, GTK_TYPE_TREE_ITER, GTK_TYPE_TREE_ITER, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_tree_model_iter_parent, GTK_TYPE_TREE_MODEL, GTK_TYPE_TREE_ITER, GTK_TYPE_TREE_ITER);
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

#ifdef GTK_TYPE_OBJECT
	gtype_reg_start(GTK_TYPE_OBJECT, gtk_object); gtype_reg_end();
#endif

	gtype_reg_start(GTK_TYPE_WIDGET, gtk_widget);
		gtype_reg_ffi(GTK_TYPE_WIDGET, gtk_widget_destroy);
		gtype_reg_ffi(G_TYPE_NONE, gtk_widget_unparent, GTK_TYPE_WIDGET);
		gtype_reg_ffi(G_TYPE_NONE, gtk_widget_show, GTK_TYPE_WIDGET);
		gtype_reg_ffi(G_TYPE_NONE, gtk_widget_hide, GTK_TYPE_WIDGET);
		gtype_reg_ffi(G_TYPE_NONE, gtk_widget_show_all, GTK_TYPE_WIDGET);
		gtype_reg_ffi(G_TYPE_NONE, gtk_widget_queue_draw, GTK_TYPE_WIDGET);
		gtype_reg_ffi(G_TYPE_NONE, gtk_widget_queue_resize, GTK_TYPE_WIDGET);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_widget_activate, GTK_TYPE_WIDGET);
		gtype_reg_ffi(G_TYPE_NONE, gtk_widget_reparent, GTK_TYPE_WIDGET);
		gtype_reg_ffi(G_TYPE_NONE, gtk_widget_grab_focus, GTK_TYPE_WIDGET);
		gtype_reg_ffi(G_TYPE_NONE, gtk_widget_grab_default, GTK_TYPE_WIDGET);
		gtype_reg_ffi(G_TYPE_NONE, gtk_widget_grab_default, GTK_TYPE_WIDGET);
		gtype_reg_ffi(G_TYPE_NONE, gtk_widget_grab_default, GTK_TYPE_WIDGET);
		gtype_reg_ffi(G_TYPE_NONE, gtk_widget_get_pointer, GTK_TYPE_WIDGET, out G_TYPE_INT, out G_TYPE_INT);
	gtype_reg_end();

	gtype_reg_start(GTK_TYPE_CONTAINER, gtk_container);
		gtype_reg_ffi(G_TYPE_NONE, gtk_container_add, GTK_TYPE_CONTAINER, GTK_TYPE_WIDGET);
		gtype_reg_ffi(G_TYPE_NONE, gtk_container_remove, GTK_TYPE_CONTAINER, GTK_TYPE_WIDGET);
		gtype_reg_ffi(G_TYPE_NONE, gtk_container_set_focus_child, GTK_TYPE_CONTAINER, GTK_TYPE_WIDGET);
		gtype_reg_ffi(GTK_TYPE_WIDGET, gtk_container_get_focus_child, GTK_TYPE_CONTAINER);
	gtype_reg_end();

	gtype_reg_start(GTK_TYPE_BIN, gtk_bin);
		gtype_reg_ffi(GTK_TYPE_WIDGET, gtk_bin_get_child);
		gtype_reg_ffi(GTK_TYPE_WIDGET, gtk_bin_get_child);
	gtype_reg_end();

	gtype_reg_start(GTK_TYPE_WINDOW, gtk_window);
		gtype_reg_ffi(G_TYPE_NONE, gtk_window_add_accel_group, GTK_TYPE_WINDOW, GTK_TYPE_ACCEL_GROUP);
		gtype_reg_ffi(G_TYPE_NONE, gtk_window_remove_accel_group, GTK_TYPE_WINDOW, GTK_TYPE_ACCEL_GROUP);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_window_activate_focus, GTK_TYPE_WINDOW);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_window_activate_default, GTK_TYPE_WINDOW);
		gtype_reg_ffi(G_TYPE_NONE, gtk_window_set_modal, GTK_TYPE_WINDOW, G_TYPE_BOOLEAN);
		gtype_reg_ffi(G_TYPE_NONE, gtk_window_set_default_size, GTK_TYPE_WINDOW, G_TYPE_INT, G_TYPE_INT);
#if GTK_CHECK_VERSION(3,0,0)
		gtype_reg_ffi(G_TYPE_NONE, gtk_window_set_default_geometry, GTK_TYPE_WINDOW, G_TYPE_INT, G_TYPE_INT);
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
		gtype_reg_ffi(G_TYPE_NONE, gtk_application_window_set_show_menubar, GTK_TYPE_APPLICATION_WINDOW, G_TYPE_BOOLEAN);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_application_window_get_show_menubar, GTK_TYPE_APPLICATION_WINDOW);
		gtype_reg_ffi(G_TYPE_UINT, gtk_application_window_get_id, GTK_TYPE_APPLICATION_WINDOW);
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

	gtype_reg_start(GTK_TYPE_ICON_VIEW, gtk_icon_view); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_LAYOUT, gtk_layout); gtype_reg_end();

#ifdef GTK_TYPE_LIST
	gtype_reg_start(GTK_TYPE_LIST, gtk_list); gtype_reg_end();
#endif

	gtype_reg_start(GTK_TYPE_MENU_SHELL, gtk_menu_shell); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_NOTEBOOK, gtk_notebook);
		gtype_reg_ffi(G_TYPE_INT, gtk_notebook_append_page, GTK_TYPE_NOTEBOOK, GTK_TYPE_WIDGET, GTK_TYPE_WIDGET);
		gtype_reg_ffi(G_TYPE_INT, gtk_notebook_prepend_page, GTK_TYPE_NOTEBOOK, GTK_TYPE_WIDGET, GTK_TYPE_WIDGET);
		gtype_reg_ffi(G_TYPE_INT, gtk_notebook_insert_page, GTK_TYPE_NOTEBOOK, GTK_TYPE_WIDGET, GTK_TYPE_WIDGET, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_INT, gtk_notebook_remove_page, GTK_TYPE_NOTEBOOK, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_INT, gtk_notebook_get_current_page, GTK_TYPE_NOTEBOOK);
		gtype_reg_ffi(GTK_TYPE_WIDGET, gtk_notebook_get_nth_page, GTK_TYPE_NOTEBOOK, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_INT, gtk_notebook_get_n_pages, GTK_TYPE_NOTEBOOK);
		gtype_reg_ffi(G_TYPE_INT, gtk_notebook_page_num, GTK_TYPE_NOTEBOOK, GTK_TYPE_WIDGET);
		gtype_reg_ffi(G_TYPE_NONE, gtk_notebook_set_current_page, GTK_TYPE_NOTEBOOK, G_TYPE_INT);
		gtype_reg_ffi(GTK_TYPE_WIDGET, gtk_notebook_get_tab_label, GTK_TYPE_NOTEBOOK, GTK_TYPE_WIDGET);
		gtype_reg_ffi(G_TYPE_NONE, gtk_notebook_set_tab_label, GTK_TYPE_NOTEBOOK, GTK_TYPE_WIDGET, GTK_TYPE_WIDGET);
		gtype_reg_ffi(G_TYPE_NONE, gtk_notebook_set_tab_label_text, GTK_TYPE_NOTEBOOK, GTK_TYPE_WIDGET, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_STRING, gtk_notebook_get_tab_label_text, GTK_TYPE_NOTEBOOK, GTK_TYPE_WIDGET);
		gtype_reg_ffi(G_TYPE_NONE, gtk_notebook_reorder_child, GTK_TYPE_NOTEBOOK, GTK_TYPE_WIDGET, G_TYPE_INT);
	gtype_reg_end();

	gtype_reg_start(GTK_TYPE_TREE_VIEW, gtk_tree_view);
		gtype_reg_ffi(GTK_TYPE_WIDGET, gtk_tree_view_new);
		gtype_reg_ffi(GTK_TYPE_WIDGET, gtk_tree_view_new_with_model, GTK_TYPE_TREE_MODEL);
		gtype_reg_ffi(GTK_TYPE_TREE_SELECTION, gtk_tree_view_get_selection, GTK_TYPE_TREE_VIEW);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_view_columns_autosize, GTK_TYPE_TREE_VIEW);

		gtype_reg_ffi(G_TYPE_INT, gtk_tree_view_append_column, GTK_TYPE_TREE_VIEW, GTK_TYPE_TREE_VIEW_COLUMN);
		gtype_reg_ffi(G_TYPE_INT, gtk_tree_view_remove_column, GTK_TYPE_TREE_VIEW, GTK_TYPE_TREE_VIEW_COLUMN);
		gtype_reg_ffi(G_TYPE_INT, gtk_tree_view_insert_column, GTK_TYPE_TREE_VIEW, GTK_TYPE_TREE_VIEW_COLUMN, G_TYPE_INT);
		gtype_reg_ffi(GTK_TYPE_TREE_VIEW_COLUMN, gtk_tree_view_get_column, GTK_TYPE_TREE_VIEW, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_view_move_column_after, GTK_TYPE_TREE_VIEW, GTK_TYPE_TREE_VIEW_COLUMN, GTK_TYPE_TREE_VIEW_COLUMN);

		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_view_scroll_to_point, GTK_TYPE_TREE_VIEW, G_TYPE_INT, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_view_scroll_to_cell, GTK_TYPE_TREE_VIEW, GTK_TYPE_TREE_PATH, GTK_TYPE_TREE_VIEW_COLUMN, G_TYPE_BOOLEAN, G_TYPE_FLOAT, G_TYPE_FLOAT);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_view_row_activated, GTK_TYPE_TREE_VIEW, GTK_TYPE_TREE_PATH, GTK_TYPE_TREE_VIEW_COLUMN);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_view_expand_all, GTK_TYPE_TREE_VIEW);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_view_collapse_all, GTK_TYPE_TREE_VIEW);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_view_expand_to_path, GTK_TYPE_TREE_VIEW, GTK_TYPE_TREE_PATH);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_view_expand_row, GTK_TYPE_TREE_VIEW, GTK_TYPE_TREE_PATH, G_TYPE_BOOLEAN);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_tree_view_collapse_row, GTK_TYPE_TREE_VIEW, GTK_TYPE_TREE_PATH);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_tree_view_row_expanded, GTK_TYPE_TREE_VIEW, GTK_TYPE_TREE_PATH);

		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_view_set_cursor, GTK_TYPE_TREE_VIEW, GTK_TYPE_TREE_PATH, GTK_TYPE_TREE_VIEW_COLUMN, G_TYPE_BOOLEAN);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_view_set_cursor_on_cell, GTK_TYPE_TREE_VIEW, GTK_TYPE_TREE_PATH, GTK_TYPE_TREE_VIEW_COLUMN, GTK_TYPE_CELL_RENDERER, G_TYPE_BOOLEAN);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_view_get_cursor, GTK_TYPE_TREE_VIEW, GTK_TYPE_TREE_PATH, out GTK_TYPE_TREE_VIEW_COLUMN);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_tree_view_get_path_at_pos, GTK_TYPE_TREE_VIEW, G_TYPE_INT, G_TYPE_INT, GTK_TYPE_TREE_PATH, out GTK_TYPE_TREE_VIEW_COLUMN, out G_TYPE_INT, out G_TYPE_INT);

#if GTK_CHECK_VERSION(3,4,0)
		gtype_reg_ffi(G_TYPE_UINT, gtk_tree_view_get_n_columns, GTK_TYPE_TREE_VIEW);
#endif
	gtype_reg_end();

	gtype_reg_start(GTK_TYPE_TEXT_VIEW, gtk_text_view);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_text_view_scroll_to_iter, GTK_TYPE_TEXT_VIEW, GTK_TYPE_TEXT_ITER, G_TYPE_DOUBLE, G_TYPE_BOOLEAN, G_TYPE_DOUBLE, G_TYPE_DOUBLE);
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

	gtype_reg_start(GTK_TYPE_ICON_THEME, gtk_icon_theme); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_IM_CONTEXT, gtk_im_context); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_IM_CONTEXT_SIMPLE, gtk_im_context_simple); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_IM_MULTICONTEXT, gtk_im_multicontext); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_LIST_STORE, gtk_list_store);
		gtype_reg_ffi(G_TYPE_NONE, gtk_list_store_append, GTK_TYPE_LIST_STORE, GTK_TYPE_TREE_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_list_store_clear, GTK_TYPE_LIST_STORE);
		gtype_reg_ffi(G_TYPE_NONE, gtk_list_store_set_value, GTK_TYPE_LIST_STORE, GTK_TYPE_TREE_ITER, G_TYPE_INT, G_TYPE_VALUE);
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
		gtype_reg_ffi(G_TYPE_INT, gtk_text_buffer_get_line_count, GTK_TYPE_TEXT_BUFFER);
		gtype_reg_ffi(G_TYPE_INT, gtk_text_buffer_get_char_count, GTK_TYPE_TEXT_BUFFER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_set_text, GTK_TYPE_TEXT_BUFFER, G_TYPE_STRING, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_insert, GTK_TYPE_TEXT_BUFFER, GTK_TYPE_TEXT_ITER, G_TYPE_STRING, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_insert_at_cursor, GTK_TYPE_TEXT_BUFFER, G_TYPE_STRING, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_text_buffer_insert_interactive, GTK_TYPE_TEXT_BUFFER, GTK_TYPE_TEXT_ITER, G_TYPE_STRING, G_TYPE_INT, G_TYPE_BOOLEAN);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_text_buffer_insert_interactive_at_cursor, GTK_TYPE_TEXT_BUFFER, G_TYPE_STRING, G_TYPE_INT, G_TYPE_BOOLEAN);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_insert_range, GTK_TYPE_TEXT_BUFFER, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_text_buffer_insert_range_interactive, GTK_TYPE_TEXT_BUFFER, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER, G_TYPE_BOOLEAN);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_delete, GTK_TYPE_TEXT_BUFFER, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_text_buffer_delete_interactive, GTK_TYPE_TEXT_BUFFER, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER, G_TYPE_BOOLEAN);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_text_buffer_backspace, GTK_TYPE_TEXT_BUFFER, GTK_TYPE_TEXT_ITER, G_TYPE_BOOLEAN, G_TYPE_BOOLEAN);
		gtype_reg_ffi_rnew(G_TYPE_STRING, gtk_text_buffer_get_text, GTK_TYPE_TEXT_BUFFER, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER, G_TYPE_BOOLEAN);
		gtype_reg_ffi_rnew(G_TYPE_STRING, gtk_text_buffer_get_slice, GTK_TYPE_TEXT_BUFFER, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER, G_TYPE_BOOLEAN);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_insert_pixbuf, GTK_TYPE_TEXT_BUFFER, GTK_TYPE_TEXT_ITER, GDK_TYPE_PIXBUF);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_insert_child_anchor, GTK_TYPE_TEXT_BUFFER, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_CHILD_ANCHOR);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_add_mark, GTK_TYPE_TEXT_BUFFER, GTK_TYPE_TEXT_MARK, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(GTK_TYPE_TEXT_MARK, gtk_text_buffer_create_mark, GTK_TYPE_TEXT_BUFFER, G_TYPE_STRING, GTK_TYPE_TEXT_ITER, G_TYPE_BOOLEAN);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_move_mark, GTK_TYPE_TEXT_BUFFER, GTK_TYPE_TEXT_MARK, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_delete_mark, GTK_TYPE_TEXT_BUFFER, GTK_TYPE_TEXT_MARK);
		gtype_reg_ffi(GTK_TYPE_TEXT_MARK, gtk_text_buffer_get_mark, GTK_TYPE_TEXT_BUFFER, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_move_mark_by_name, GTK_TYPE_TEXT_BUFFER, G_TYPE_STRING, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_delete_mark_by_name, GTK_TYPE_TEXT_BUFFER, G_TYPE_STRING);
		gtype_reg_ffi(GTK_TYPE_TEXT_MARK, gtk_text_buffer_get_insert, GTK_TYPE_TEXT_BUFFER);
		gtype_reg_ffi(GTK_TYPE_TEXT_MARK, gtk_text_buffer_get_selection_bound, GTK_TYPE_TEXT_BUFFER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_place_cursor, GTK_TYPE_TEXT_BUFFER, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_select_range, GTK_TYPE_TEXT_BUFFER, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_apply_tag, GTK_TYPE_TEXT_BUFFER, GTK_TYPE_TEXT_TAG, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_remove_tag, GTK_TYPE_TEXT_BUFFER, GTK_TYPE_TEXT_TAG, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_apply_tag_by_name, GTK_TYPE_TEXT_BUFFER, G_TYPE_STRING, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_remove_tag_by_name, GTK_TYPE_TEXT_BUFFER, G_TYPE_STRING, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_remove_all_tags, GTK_TYPE_TEXT_BUFFER, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_get_iter_at_line_offset, GTK_TYPE_TEXT_BUFFER, GTK_TYPE_TEXT_ITER, G_TYPE_INT, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_get_iter_at_line_index, GTK_TYPE_TEXT_BUFFER, GTK_TYPE_TEXT_ITER, G_TYPE_INT, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_get_iter_at_offset, GTK_TYPE_TEXT_BUFFER, GTK_TYPE_TEXT_ITER, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_get_iter_at_line, GTK_TYPE_TEXT_BUFFER, GTK_TYPE_TEXT_ITER, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_get_start_iter, GTK_TYPE_TEXT_BUFFER, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_get_end_iter, GTK_TYPE_TEXT_BUFFER, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_get_bounds, GTK_TYPE_TEXT_BUFFER, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_get_iter_at_mark, GTK_TYPE_TEXT_BUFFER, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_MARK);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_get_iter_at_child_anchor, GTK_TYPE_TEXT_BUFFER, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_CHILD_ANCHOR);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_text_buffer_get_modified, GTK_TYPE_TEXT_BUFFER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_set_modified, GTK_TYPE_TEXT_BUFFER, G_TYPE_BOOLEAN);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_add_selection_clipboard, GTK_TYPE_TEXT_BUFFER, GTK_TYPE_CLIPBOARD);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_remove_selection_clipboard, GTK_TYPE_TEXT_BUFFER, GTK_TYPE_CLIPBOARD);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_cut_clipboard, GTK_TYPE_TEXT_BUFFER, GTK_TYPE_CLIPBOARD, G_TYPE_BOOLEAN);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_copy_clipboard, GTK_TYPE_TEXT_BUFFER, GTK_TYPE_CLIPBOARD);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_paste_clipboard, GTK_TYPE_TEXT_BUFFER, GTK_TYPE_CLIPBOARD, GTK_TYPE_TEXT_ITER, G_TYPE_BOOLEAN);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_text_buffer_get_selection_bounds, GTK_TYPE_TEXT_BUFFER, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_text_buffer_delete_selection, GTK_TYPE_TEXT_BUFFER, G_TYPE_BOOLEAN, G_TYPE_BOOLEAN);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_begin_user_action, GTK_TYPE_TEXT_BUFFER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_buffer_end_user_action, GTK_TYPE_TEXT_BUFFER);
	gtype_reg_end();

	gtype_reg_start(GTK_TYPE_TEXT_CHILD_ANCHOR, gtk_text_child_anchor); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_TEXT_MARK, gtk_text_mark); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_TEXT_TAG, gtk_text_tag); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_TEXT_TAG_TABLE, gtk_text_tag_table); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_TREE_MODEL_FILTER, gtk_tree_model_filter); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_TREE_MODEL_SORT, gtk_tree_model_sort); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_TREE_SELECTION, gtk_tree_selection); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_TREE_STORE, gtk_tree_store);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_store_append, GTK_TYPE_TREE_STORE, GTK_TYPE_TREE_ITER, opt GTK_TYPE_TREE_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_store_clear, GTK_TYPE_TREE_STORE);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_store_set_value, GTK_TYPE_TREE_STORE, GTK_TYPE_TREE_ITER, G_TYPE_INT, G_TYPE_VALUE);
	gtype_reg_end();

	gtype_reg_start(GTK_TYPE_WINDOW_GROUP, gtk_window_group); gtype_reg_end();

	gtype_reg_start(GTK_TYPE_TOOLTIP, gtk_tooltip); gtype_reg_end();

#ifdef GTK_TYPE_APPLICATION
	gtype_reg_start(GTK_TYPE_APPLICATION, gtk_application);
		gtype_reg_ffi(GTK_TYPE_APPLICATION, gtk_application_new, G_TYPE_STRING, G_TYPE_APPLICATION_FLAGS);
		gtype_reg_ffi(G_TYPE_NONE, gtk_application_add_window, GTK_TYPE_APPLICATION, GTK_TYPE_WINDOW);
		gtype_reg_ffi(G_TYPE_NONE, gtk_application_remove_window, GTK_TYPE_APPLICATION, GTK_TYPE_WINDOW);

		gtype_reg_ffi(G_TYPE_MENU_MODEL, gtk_application_get_app_menu, GTK_TYPE_APPLICATION);
		gtype_reg_ffi(G_TYPE_NONE, gtk_application_set_app_menu, GTK_TYPE_APPLICATION, G_TYPE_MENU_MODEL);

		gtype_reg_ffi(G_TYPE_MENU_MODEL, gtk_application_get_menubar, GTK_TYPE_APPLICATION);
		gtype_reg_ffi(G_TYPE_NONE, gtk_application_set_menubar, GTK_TYPE_APPLICATION, G_TYPE_MENU_MODEL);

		gtype_reg_ffi(G_TYPE_UINT, gtk_application_inhibit, GTK_TYPE_APPLICATION, GTK_TYPE_WINDOW, GTK_TYPE_APPLICATION_INHIBIT_FLAGS, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_NONE, gtk_application_uninhibit, GTK_TYPE_APPLICATION, G_TYPE_UINT);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_application_is_inhibited, GTK_TYPE_APPLICATION, GTK_TYPE_APPLICATION_INHIBIT_FLAGS);

		gtype_reg_ffi(GTK_TYPE_WINDOW, gtk_application_get_window_by_id, GTK_TYPE_APPLICATION, G_TYPE_UINT);
		gtype_reg_ffi(GTK_TYPE_WINDOW, gtk_application_get_active_window, GTK_TYPE_APPLICATION);
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

static int _lua_gtk_builder_add_from_file(lua_State* L) {
	GObject* obj = glua_object_check(L, 1);
	GtkBuilder* builder = GTK_BUILDER(obj);
	if( !builder )
		return luaL_argerror(L, 1, "need GtkBuilder");
	const char* fname = luaL_checkstring(L, 2);
	GError* err = NULL;
	guint res = gtk_builder_add_from_file(builder, fname, &err);
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
		gtype_reg_lua(gtk_builder_add_from_string);
		gtype_reg_lua(gtk_builder_add_from_file);
		gtype_reg_lua(gtk_builder_connect_signals);
	gtype_reg_end();
}

void gtypes_gtk_register(lua_State* L) {
	gtk_globals_register(L);
	gtk_boxed_register(L);
	gtk_interface_register(L);
	gtk_object_register(L);
	gtk_builder_register(L);
}

