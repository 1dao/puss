// gtypes_gtk.c

#include "glua.h"

#include <assert.h>
#include <gtk/gtk.h>

#if GTK_MAJOR_VERSION==3

#include "gffireg.h"
#include "gtypes_gtk_common.inl"

static gboolean lua_gdk_event_get_keycode(const GdkEvent *event, guint *keycode) {
	guint16 code = 0;
	gboolean res = gdk_event_get_keycode(event, &code);
	*keycode = code;
	return res;
}

static void gtypes_gtk_boxed_register(lua_State* L) {
	gtype_reg_env_declare();

	gtype_reg_start(GDK_TYPE_EVENT, gdk_event);
		gtype_reg_ffi(GDK_TYPE_WINDOW, gdk_event_get_window, GDK_TYPE_EVENT);
		gtype_reg_ffi(G_TYPE_UINT, gdk_event_get_time, GDK_TYPE_EVENT);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gdk_event_get_state, GDK_TYPE_EVENT, out GDK_TYPE_MODIFIER_TYPE);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gdk_event_get_coords, GDK_TYPE_EVENT, out G_TYPE_DOUBLE, out G_TYPE_DOUBLE);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gdk_event_get_root_coords, GDK_TYPE_EVENT, out G_TYPE_DOUBLE, out G_TYPE_DOUBLE);
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
		gtype_reg_ffi(G_TYPE_NONE, gdk_event_set_screen, GDK_TYPE_EVENT, GDK_TYPE_SCREEN);
		gtype_reg_ffi(G_TYPE_NONE, gdk_event_get_screen, GDK_TYPE_EVENT, out GDK_TYPE_SCREEN);
		gtype_reg_ffi(GDK_TYPE_EVENT_TYPE, gdk_event_get_event_type, GDK_TYPE_EVENT);
	gtype_reg_end();

	glua_reg_gtype_index_table(L, GTK_TYPE_PAPER_SIZE, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_TEXT_ITER, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_REQUISITION, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_SELECTION_DATA, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_BORDER, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_TREE_ITER, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_TREE_PATH, NULL);
}

static void gtypes_gtk_interface_register(lua_State* L) {
	gtype_reg_env_declare();

	glua_reg_gtype_index_table(L, GTK_TYPE_BUILDABLE, NULL);

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

static void gtypes_gtk_object_register(lua_State* L) {
	gtype_reg_env_declare();

	gtype_reg_start(GTK_TYPE_WIDGET, gtk_widget);
		gtype_reg_ffi(GTK_TYPE_WIDGET, gtk_widget_destroy);
		gtype_reg_ffi(G_TYPE_NONE, gtk_widget_unparent, GTK_TYPE_WIDGET);
		gtype_reg_ffi(G_TYPE_NONE, gtk_widget_show, GTK_TYPE_WIDGET);
		gtype_reg_ffi(G_TYPE_NONE, gtk_widget_hide, GTK_TYPE_WIDGET);
		gtype_reg_ffi(G_TYPE_NONE, gtk_widget_show_all, GTK_TYPE_WIDGET);
		gtype_reg_ffi(G_TYPE_NONE, gtk_widget_queue_draw, GTK_TYPE_WIDGET);
		gtype_reg_ffi(G_TYPE_NONE, gtk_widget_queue_resize, GTK_TYPE_WIDGET);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_widget_activate, GTK_TYPE_WIDGET);
		gtype_reg_ffi(G_TYPE_NONE, gtk_widget_grab_focus, GTK_TYPE_WIDGET);
		gtype_reg_ffi(G_TYPE_NONE, gtk_widget_grab_default, GTK_TYPE_WIDGET);
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
		gtype_reg_ffi(G_TYPE_NONE, gtk_window_set_default_geometry, GTK_TYPE_WINDOW, G_TYPE_INT, G_TYPE_INT);
	gtype_reg_end();

	glua_reg_gtype_index_table(L, GTK_TYPE_DIALOG, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_ABOUT_DIALOG, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_FILE_CHOOSER_DIALOG, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_MESSAGE_DIALOG, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_RECENT_CHOOSER_DIALOG, NULL);

	gtype_reg_start(GTK_TYPE_APPLICATION_WINDOW, gtk_application_window);
		gtype_reg_ffi(G_TYPE_NONE, gtk_application_window_set_show_menubar, GTK_TYPE_APPLICATION_WINDOW, G_TYPE_BOOLEAN);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_application_window_get_show_menubar, GTK_TYPE_APPLICATION_WINDOW);
		gtype_reg_ffi(G_TYPE_UINT, gtk_application_window_get_id, GTK_TYPE_APPLICATION_WINDOW);
	gtype_reg_end();

	glua_reg_gtype_index_table(L, GTK_TYPE_ASSISTANT, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_OFFSCREEN_WINDOW, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_FRAME, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_ASPECT_FRAME, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_BUTTON, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_TOGGLE_BUTTON, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_CHECK_BUTTON, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_RADIO_BUTTON, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_COLOR_BUTTON, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_FONT_BUTTON, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_LINK_BUTTON, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_SCALE_BUTTON, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_VOLUME_BUTTON, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_MENU_ITEM, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_CHECK_MENU_ITEM, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_RADIO_MENU_ITEM, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_SEPARATOR_MENU_ITEM, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_COMBO_BOX, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_COMBO_BOX_TEXT, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_EVENT_BOX, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_EXPANDER, NULL);

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

	glua_reg_gtype_index_table(L, GTK_TYPE_FIXED, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_PANED, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_ICON_VIEW, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_LAYOUT, NULL);

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

	glua_reg_gtype_index_table(L, GTK_TYPE_TEXT_VIEW, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_TOOLBAR, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_TOOL_ITEM_GROUP, NULL);

	gtype_reg_start(GTK_TYPE_TREE_VIEW, gtk_tree_view);
		gtype_reg_ffi(GTK_TYPE_WIDGET, gtk_tree_view_new);
		gtype_reg_ffi(GTK_TYPE_WIDGET, gtk_tree_view_new_with_model, GTK_TYPE_TREE_MODEL);
		gtype_reg_ffi(GTK_TYPE_TREE_SELECTION, gtk_tree_view_get_selection, GTK_TYPE_TREE_VIEW);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_view_columns_autosize, GTK_TYPE_TREE_VIEW);

		gtype_reg_ffi(G_TYPE_INT, gtk_tree_view_append_column, GTK_TYPE_TREE_VIEW, GTK_TYPE_TREE_VIEW_COLUMN);
		gtype_reg_ffi(G_TYPE_INT, gtk_tree_view_remove_column, GTK_TYPE_TREE_VIEW, GTK_TYPE_TREE_VIEW_COLUMN);
		gtype_reg_ffi(G_TYPE_INT, gtk_tree_view_insert_column, GTK_TYPE_TREE_VIEW, GTK_TYPE_TREE_VIEW_COLUMN, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_UINT, gtk_tree_view_get_n_columns, GTK_TYPE_TREE_VIEW);
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
	gtype_reg_end();

	glua_reg_gtype_index_table(L, GTK_TYPE_LABEL, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_IMAGE, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_CALENDAR, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_CELL_VIEW, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_DRAWING_AREA, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_SPINNER, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_ENTRY, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_SPIN_BUTTON, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_RANGE, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_SCALE, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_SCROLLBAR, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_SEPARATOR, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_INVISIBLE, NULL);

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

	glua_reg_gtype_index_table(L, GTK_TYPE_TREE_VIEW_COLUMN, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_RECENT_FILTER, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_ACCEL_GROUP, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_ACCEL_MAP, NULL);

	gtype_reg_start(GTK_TYPE_BUILDER, gtk_builder);
		gtype_reg_ffi(G_TYPE_OBJECT, gtk_builder_get_object, GTK_TYPE_BUILDER, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_INT, gtk_builder_get_type_from_name, GTK_TYPE_BUILDER, G_TYPE_STRING);
		gtype_reg_lua("add_from_string", lua_gtk_builder_add_from_string);
		gtype_reg_lua("add_from_file", lua_gtk_builder_add_from_file);
		gtype_reg_lua("connect_signals", lua_gtk_builder_connect_signals);
	gtype_reg_end();

	glua_reg_gtype_index_table(L, GTK_TYPE_CLIPBOARD, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_ENTRY_BUFFER, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_ENTRY_COMPLETION, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_ICON_THEME, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_IM_CONTEXT, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_IM_CONTEXT_SIMPLE, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_IM_MULTICONTEXT, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_LIST_STORE, NULL);

	glua_reg_gtype_index_table(L, G_TYPE_MOUNT_OPERATION, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_MOUNT_OPERATION, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_RECENT_MANAGER, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_SETTINGS, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_SIZE_GROUP, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_STATUS_ICON, NULL);

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
}

void gtypes_gtk_register(lua_State* L) {
	gtk_globals_register(L);
	gtypes_gtk_boxed_register(L);
	gtypes_gtk_interface_register(L);
	gtypes_gtk_object_register(L);
}

#endif//GTK_MAJOR_VERSION==3

