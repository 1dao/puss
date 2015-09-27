// gtypes_gtk.inl

// #include <assert.h>
// #include <gtk/gtk.h>
// #include "gffireg.h"

static void gtypes_gtk_boxed_register(lua_State* L) {
	gtype_reg_env_declare();

	gtype_reg_start(GDK_TYPE_EVENT, gdk_event);
		gtype_reg_ffi(G_TYPE_UINT, gdk_event_get_time, GDK_TYPE_EVENT);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gdk_event_get_coords, GDK_TYPE_EVENT, out G_TYPE_DOUBLE, out G_TYPE_DOUBLE);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gdk_event_get_root_coords, GDK_TYPE_EVENT, out G_TYPE_DOUBLE, out G_TYPE_DOUBLE);
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
	glua_reg_gtype_index_table(L, GTK_TYPE_BUILDABLE, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_ORIENTABLE, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_CELL_EDITABLE, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_CELL_LAYOUT, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_EDITABLE, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_FILE_CHOOSER, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_TREE_MODEL, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_TREE_DRAG_SOURCE, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_TREE_DRAG_DEST, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_TREE_SORTABLE, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_PRINT_OPERATION_PREVIEW, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_RECENT_CHOOSER, NULL);

	glua_reg_gtype_index_table(L, GTK_TYPE_TOOL_SHELL, NULL);
}

static void _gtk_builder_connect_wrapper(GtkBuilder* builder, GObject* object, const gchar* signal_name, const gchar* handler_name, GObject* connect_object, GConnectFlags flags, gpointer user_data) {
	lua_State* L = (lua_State*)user_data;
	if( lua_istable(L, 2) ) {
		lua_pushcfunction(L, glua_signal_connect);
		glua_object_push(L, object, TRUE);
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
		glua_object_push(L, object, TRUE);
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

static int lua_gtk_builder_connect(lua_State* L) {
	GObject* obj = glua_object_check(L, 1);
	GtkBuilder* builder = GTK_BUILDER(obj);
	if( !builder )
		return luaL_argerror(L, 1, "need GtkBuilder");
	if( !(lua_istable(L, 2) || lua_isfunction(L, 2)) )
		return luaL_argerror(L, 2, "need table or function");
	gtk_builder_connect_signals_full(builder, _gtk_builder_connect_wrapper, L);
	return 0;
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

	glua_reg_gtype_index_table(L, GTK_TYPE_TREE_VIEW, NULL);

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
		gtype_reg_lua("connect_signals", lua_gtk_builder_connect);
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

static void gtypes_gtk_register(lua_State* L) {
	gtypes_gtk_boxed_register(L);
	gtypes_gtk_interface_register(L);
	gtypes_gtk_object_register(L);
}

