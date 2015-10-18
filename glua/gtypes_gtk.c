// gtypes_gtk.c

#include "glua.h"

#include <assert.h>

#define GTK_DISABLE_DEPRECATED
#include <gtk/gtk.h>

#include "gffireg.h"

static void gtk_globals_register(lua_State* L) {
	glua_push_master_table(L);
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
	static gboolean lua_gdk_event_get_keycode(const GdkEvent *event, guint *keycode) {
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
		gtype_reg_ffi(G_TYPE_NONE, gdk_event_get_screen, GDK_TYPE_EVENT, out GDK_TYPE_SCREEN);
#if GTK_CHECK_VERSION(3,0,0)
		gtype_reg_ffi(GDK_TYPE_WINDOW, gdk_event_get_window, GDK_TYPE_EVENT);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gdk_event_get_button, GDK_TYPE_EVENT, out G_TYPE_UINT);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gdk_event_get_click_count, GDK_TYPE_EVENT, out G_TYPE_UINT);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gdk_event_get_keyval, GDK_TYPE_EVENT, out G_TYPE_UINT);
		gtype_reg_ffi_rename("get_keycode", G_TYPE_BOOLEAN, lua_gdk_event_get_keycode, GDK_TYPE_EVENT, out G_TYPE_UINT);
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

	glua_reg_gtype_index_table(L, GTK_TYPE_PAPER_SIZE, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_TEXT_ITER, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_REQUISITION, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_SELECTION_DATA, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_BORDER, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_TREE_ITER, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_TREE_PATH, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_ICON_SET, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_TARGET_LIST, NULL);
}

static void gtk_interface_register(lua_State* L) {
	gtype_reg_env_declare();

	glua_reg_gtype_index_table(L, GTK_TYPE_BUILDABLE, NULL);

#ifdef GTK_TYPE_ACTIVATABLE
	glua_reg_gtype_index_table(L, GTK_TYPE_ACTIVATABLE, NULL);
#endif

	glua_reg_gtype_index_table(L, GTK_TYPE_ORIENTABLE, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_CELL_EDITABLE, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_CELL_LAYOUT, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_EDITABLE, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_FILE_CHOOSER, NULL);

	gtype_reg_start(GTK_TYPE_TREE_MODEL, gtk_type_tree);
		gtype_reg_ffi(GTK_TYPE_TREE_MODEL_FLAGS, gtk_tree_model_get_flags, GTK_TYPE_TREE_MODEL);
		gtype_reg_ffi(G_TYPE_UINT, gtk_tree_model_get_n_columns, GTK_TYPE_TREE_MODEL);
		gtype_reg_ffi(G_TYPE_UINT, gtk_tree_model_get_column_type, GTK_TYPE_TREE_MODEL, G_TYPE_INT);

		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_tree_model_get_iter, GTK_TYPE_TREE_MODEL, GTK_TYPE_TREE_ITER, GTK_TYPE_TREE_PATH);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_tree_model_get_iter_from_string, GTK_TYPE_TREE_MODEL, GTK_TYPE_TREE_ITER, G_TYPE_STRING);

		gtype_reg_ffi_rnew(G_TYPE_STRING, gtk_tree_model_get_string_from_iter, GTK_TYPE_TREE_MODEL, GTK_TYPE_TREE_ITER);

		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_tree_model_get_iter_first, GTK_TYPE_TREE_MODEL, GTK_TYPE_TREE_ITER);

		gtype_reg_ffi_rnew(GTK_TYPE_TREE_PATH, gtk_tree_model_get_iter_first, GTK_TYPE_TREE_MODEL, GTK_TYPE_TREE_ITER);

		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_model_get_value, GTK_TYPE_TREE_MODEL, GTK_TYPE_TREE_ITER, G_TYPE_INT, G_TYPE_VALUE);
	gtype_reg_end();

	glua_reg_gtype_index_table(L, GTK_TYPE_TREE_DRAG_SOURCE, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_TREE_DRAG_DEST, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_TREE_SORTABLE, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_PRINT_OPERATION_PREVIEW, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_RECENT_CHOOSER, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_TOOL_SHELL, NULL);
}

static void gtk_object_register(lua_State* L) {
	gtype_reg_env_declare();

	glua_reg_gtype_index_table(L, G_TYPE_INITIALLY_UNOWNED, NULL);

#ifdef GTK_TYPE_OBJECT
	glua_reg_gtype_index_table(L, GTK_TYPE_OBJECT, NULL);
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
		gtype_reg_ffi(G_TYPE_NONE, gtk_widget_get_pointer, GTK_TYPE_WIDGET
			, out G_TYPE_INT
			, out G_TYPE_INT
			);
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

	glua_reg_gtype_index_table(L, GTK_TYPE_DIALOG, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_ABOUT_DIALOG, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_FILE_CHOOSER_DIALOG, NULL);

#ifdef GTK_TYPE_INPUT_DIALOG
	glua_reg_gtype_index_table(L, GTK_TYPE_INPUT_DIALOG, NULL);
#endif

#ifdef GTK_TYPE_COLOR_SELECTION_DIALOG
	glua_reg_gtype_index_table(L, GTK_TYPE_COLOR_SELECTION_DIALOG, NULL);
#endif

#ifdef GTK_TYPE_FONT_SELECTION_DIALOG
	glua_reg_gtype_index_table(L, GTK_TYPE_FONT_SELECTION_DIALOG, NULL);
#endif

	glua_reg_gtype_index_table(L, GTK_TYPE_MESSAGE_DIALOG, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_RECENT_CHOOSER_DIALOG, NULL);

#ifdef GTK_TYPE_APPLICATION_WINDOW
	gtype_reg_start(GTK_TYPE_APPLICATION_WINDOW, gtk_application_window);
		gtype_reg_ffi(G_TYPE_NONE, gtk_application_window_set_show_menubar, GTK_TYPE_APPLICATION_WINDOW, G_TYPE_BOOLEAN);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_application_window_get_show_menubar, GTK_TYPE_APPLICATION_WINDOW);
		gtype_reg_ffi(G_TYPE_UINT, gtk_application_window_get_id, GTK_TYPE_APPLICATION_WINDOW);
	gtype_reg_end();
#endif

	glua_reg_gtype_index_table(L, GTK_TYPE_ASSISTANT, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_OFFSCREEN_WINDOW, NULL);
	
#ifdef GTK_TYPE_ALIGNMENT
	glua_reg_gtype_index_table(L, GTK_TYPE_ALIGNMENT, NULL);
#endif

	glua_reg_gtype_index_table(L, GTK_TYPE_FRAME, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_ASPECT_FRAME, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_BUTTON, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_TOGGLE_BUTTON, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_CHECK_BUTTON, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_RADIO_BUTTON, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_COLOR_BUTTON, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_FONT_BUTTON, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_LINK_BUTTON, NULL);

#ifdef GTK_TYPE_OPTION_MENU
	glua_reg_gtype_index_table(L, GTK_TYPE_OPTION_MENU, NULL);
#endif

	glua_reg_gtype_index_table(L, GTK_TYPE_SCALE_BUTTON, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_VOLUME_BUTTON, NULL);

#ifdef GTK_TYPE_ITEM
	glua_reg_gtype_index_table(L, GTK_TYPE_ITEM, NULL);
#endif

	glua_reg_gtype_index_table(L, GTK_TYPE_MENU_ITEM, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_CHECK_MENU_ITEM, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_RADIO_MENU_ITEM, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_SEPARATOR_MENU_ITEM, NULL);

#ifdef GTK_TYPE_LIST_ITEM
	glua_reg_gtype_index_table(L, GTK_TYPE_LIST_ITEM, NULL);
#endif

#ifdef GTK_TYPE_IMAGE_MENU_ITEM
	glua_reg_gtype_index_table(L, GTK_TYPE_IMAGE_MENU_ITEM, NULL);
#endif

#ifdef GTK_TYPE_TEAROFF_MENU_ITEM
	glua_reg_gtype_index_table(L, GTK_TYPE_TEAROFF_MENU_ITEM, NULL);
#endif

	glua_reg_gtype_index_table(L, GTK_TYPE_COMBO_BOX, NULL);

#ifdef GTK_TYPE_COMBO_BOX_ENTRY
	glua_reg_gtype_index_table(L, GTK_TYPE_COMBO_BOX_ENTRY, NULL);
#endif

	glua_reg_gtype_index_table(L, GTK_TYPE_COMBO_BOX_TEXT, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_EVENT_BOX, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_EXPANDER, NULL);

#ifdef GTK_TYPE_HANDLE_BOX
	glua_reg_gtype_index_table(L, GTK_TYPE_HANDLE_BOX, NULL);
#endif

	glua_reg_gtype_index_table(L, GTK_TYPE_TOOL_ITEM, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_TOOL_BUTTON, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_MENU_TOOL_BUTTON, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_TOGGLE_TOOL_BUTTON, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_RADIO_TOOL_BUTTON, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_SEPARATOR_TOOL_ITEM, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_SCROLLED_WINDOW, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_VIEWPORT, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_BOX, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_BUTTON_BOX, NULL);

#ifdef GTK_TYPE_VBOX
	glua_reg_gtype_index_table(L, GTK_TYPE_VBOX, NULL);
#endif

#ifdef GTK_TYPE_HBOX
	glua_reg_gtype_index_table(L, GTK_TYPE_HBOX, NULL);
#endif

#ifdef GTK_TYPE_CLIST
	glua_reg_gtype_index_table(L, GTK_TYPE_CLIST, NULL);
#endif

	glua_reg_gtype_index_table(L, GTK_TYPE_FIXED, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_PANED, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_ICON_VIEW, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_LAYOUT, NULL);

#ifdef GTK_TYPE_LIST
	glua_reg_gtype_index_table(L, GTK_TYPE_LIST, NULL);
#endif

	glua_reg_gtype_index_table(L, GTK_TYPE_MENU_SHELL, NULL);

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
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_tree_view_get_path_at_pos, GTK_TYPE_TREE_VIEW, G_TYPE_INT, G_TYPE_INT, GTK_TYPE_TREE_PATH
				, out GTK_TYPE_TREE_VIEW_COLUMN
				, out G_TYPE_INT
				, out G_TYPE_INT
				);

#if GTK_CHECK_VERSION(3,4,0)
		gtype_reg_ffi(G_TYPE_UINT, gtk_tree_view_get_n_columns, GTK_TYPE_TREE_VIEW);
#endif
	gtype_reg_end();

	glua_reg_gtype_index_table(L, GTK_TYPE_TEXT_VIEW, NULL);

#ifdef GTK_TYPE_TABLE
	glua_reg_gtype_index_table(L, GTK_TYPE_TABLE, NULL);
#endif

	glua_reg_gtype_index_table(L, GTK_TYPE_TOOLBAR, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_TOOL_ITEM_GROUP, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_MISC, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_LABEL, NULL);

#ifdef GTK_TYPE_ARROW
	glua_reg_gtype_index_table(L, GTK_TYPE_ARROW, NULL);
#endif

	glua_reg_gtype_index_table(L, GTK_TYPE_IMAGE, NULL);

#ifdef GTK_TYPE_PIXMAP
	glua_reg_gtype_index_table(L, GTK_TYPE_PIXMAP, NULL);
#endif

	glua_reg_gtype_index_table(L, GTK_TYPE_CALENDAR, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_CELL_VIEW, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_DRAWING_AREA, NULL);

#ifdef GTK_TYPE_CURVE
	glua_reg_gtype_index_table(L, GTK_TYPE_CURVE, NULL);
#endif

	glua_reg_gtype_index_table(L, GTK_TYPE_SPINNER, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_ENTRY, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_SPIN_BUTTON, NULL);

#ifdef GTK_TYPE_RULER
	glua_reg_gtype_index_table(L, GTK_TYPE_RULER, NULL);
#endif

#ifdef GTK_TYPE_HRULER
	glua_reg_gtype_index_table(L, GTK_TYPE_HRULER, NULL);
#endif

#ifdef GTK_TYPE_VRULER
	glua_reg_gtype_index_table(L, GTK_TYPE_VRULER, NULL);
#endif

	glua_reg_gtype_index_table(L, GTK_TYPE_RANGE, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_SCALE, NULL);

#ifdef GTK_TYPE_HSCALE
	glua_reg_gtype_index_table(L, GTK_TYPE_HSCALE, NULL);
#endif

#ifdef GTK_TYPE_VSCALE
	glua_reg_gtype_index_table(L, GTK_TYPE_VSCALE, NULL);
#endif

	glua_reg_gtype_index_table(L, GTK_TYPE_SCROLLBAR, NULL);

#ifdef GTK_TYPE_HSCROLLBAR
	glua_reg_gtype_index_table(L, GTK_TYPE_HSCROLLBAR, NULL);
#endif

#ifdef GTK_TYPE_VSCROLLBAR
	glua_reg_gtype_index_table(L, GTK_TYPE_VSCROLLBAR, NULL);
#endif

	glua_reg_gtype_index_table(L, GTK_TYPE_SEPARATOR, NULL);

#ifdef GTK_TYPE_HSEPARATOR
	glua_reg_gtype_index_table(L, GTK_TYPE_HSEPARATOR, NULL);
#endif

#ifdef GTK_TYPE_VSEPARATOR
	glua_reg_gtype_index_table(L, GTK_TYPE_VSEPARATOR, NULL);
#endif

#ifdef GTK_TYPE_HSV
	glua_reg_gtype_index_table(L, GTK_TYPE_HSV, NULL);
#endif

	glua_reg_gtype_index_table(L, GTK_TYPE_INVISIBLE, NULL);

#ifdef GTK_TYPE_PREVIEW
	glua_reg_gtype_index_table(L, GTK_TYPE_PREVIEW, NULL);
#endif

#ifdef GTK_TYPE_PROGRESS
	glua_reg_gtype_index_table(L, GTK_TYPE_PROGRESS, NULL);
#endif

	glua_reg_gtype_index_table(L, GTK_TYPE_PROGRESS_BAR, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_ADJUSTMENT, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_CELL_RENDERER, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_CELL_RENDERER_TEXT, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_CELL_RENDERER_ACCEL, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_CELL_RENDERER_COMBO, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_CELL_RENDERER_SPIN, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_CELL_RENDERER_PIXBUF, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_CELL_RENDERER_PROGRESS, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_CELL_RENDERER_SPINNER, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_CELL_RENDERER_TOGGLE, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_FILE_FILTER, NULL);

#ifdef GTK_TYPE_ITEM_FACTORY
	glua_reg_gtype_index_table(L, GTK_TYPE_ITEM_FACTORY, NULL);
#endif

#ifdef GTK_TYPE_TOOLTIPS
	glua_reg_gtype_index_table(L, GTK_TYPE_TOOLTIPS, NULL);
#endif

	glua_reg_gtype_index_table(L, GTK_TYPE_TREE_VIEW_COLUMN, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_RECENT_FILTER, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_ACCEL_GROUP, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_ACCEL_MAP, NULL);

#ifdef GTK_TYPE_ACTION
	glua_reg_gtype_index_table(L, GTK_TYPE_ACTION, NULL);
#endif

#ifdef GTK_TYPE_TOGGLE_ACTION
	glua_reg_gtype_index_table(L, GTK_TYPE_TOGGLE_ACTION, NULL);
#endif

#ifdef GTK_TYPE_RADIO_ACTION
	glua_reg_gtype_index_table(L, GTK_TYPE_RADIO_ACTION, NULL);
#endif

#ifdef GTK_TYPE_RECENT_ACTION
	glua_reg_gtype_index_table(L, GTK_TYPE_RECENT_ACTION, NULL);
#endif
	
#ifdef GTK_TYPE_ACTION_GROUP
	glua_reg_gtype_index_table(L, GTK_TYPE_ACTION_GROUP, NULL);
#endif

	glua_reg_gtype_index_table(L, GTK_TYPE_CLIPBOARD, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_ENTRY_BUFFER, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_ENTRY_COMPLETION, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_ICON_FACTORY, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_ICON_THEME, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_IM_CONTEXT, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_IM_CONTEXT_SIMPLE, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_IM_MULTICONTEXT, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_LIST_STORE, NULL);

	glua_reg_gtype_index_table(L, G_TYPE_MOUNT_OPERATION, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_MOUNT_OPERATION, NULL);

#ifdef GTK_TYPE_RC_STYLE
	glua_reg_gtype_index_table(L, GTK_TYPE_RC_STYLE, NULL);
#endif

	glua_reg_gtype_index_table(L, GTK_TYPE_RECENT_MANAGER, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_SETTINGS, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_SIZE_GROUP, NULL);

#ifdef GTK_TYPE_STATUS_ICON
	glua_reg_gtype_index_table(L, GTK_TYPE_STATUS_ICON, NULL);
#endif

#ifdef GTK_TYPE_STYLE
	glua_reg_gtype_index_table(L, GTK_TYPE_STYLE, NULL);
#endif

	glua_reg_gtype_index_table(L, GTK_TYPE_TEXT_BUFFER, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_TEXT_CHILD_ANCHOR, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_TEXT_MARK, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_TEXT_TAG, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_TEXT_TAG_TABLE, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_TREE_MODEL_FILTER, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_TREE_MODEL_SORT, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_TREE_SELECTION, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_TREE_STORE, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_WINDOW_GROUP, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_TOOLTIP, NULL);

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

static void _gtk_builder_connect_wrapper(GtkBuilder* builder, GObject* object, const gchar* signal_name, const gchar* handler_name, GObject* connect_object, GConnectFlags flags, gpointer user_data) {
	lua_State* L = (lua_State*)user_data;
	if( lua_istable(L, 2) ) {
		lua_pushcfunction(L, glua_signal_connect);
		glua_object_push(L, object);
		lua_pushstring(L, signal_name);
		lua_getfield(L, 2, handler_name);
		if( lua_isfunction(L,-1) ) {
			lua_pushboolean(L, ((flags&G_CONNECT_AFTER) != 0));
			lua_call(L, 4, 0);
		} else {
			lua_pop(L, 4);
			fprintf(stderr, "not find signal handle(%s)\n", handler_name);
		}
	} else {
		assert( lua_isfunction(L, 2) );
		lua_pushvalue(L, 2);
		glua_object_push(L, object);
		lua_pushstring(L, signal_name);
		lua_pushstring(L, handler_name);
		lua_pushboolean(L, ((flags&G_CONNECT_AFTER) != 0));
		lua_call(L, 4, 0);
	}
}

static int lua_gtk_builder_add_from_string(lua_State* L) {
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

static int lua_gtk_builder_add_from_file(lua_State* L) {
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

static int lua_gtk_builder_connect_signals(lua_State* L) {
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
		gtype_reg_lua("add_from_string", lua_gtk_builder_add_from_string);
		gtype_reg_lua("add_from_file", lua_gtk_builder_add_from_file);
		gtype_reg_lua("connect_signals", lua_gtk_builder_connect_signals);
	gtype_reg_end();
}

void gtypes_gtk_register(lua_State* L) {
	gtk_globals_register(L);
	gtk_boxed_register(L);
	gtk_interface_register(L);
	gtk_object_register(L);
	gtk_builder_register(L);
}

