// puss_gtk_module.c

#include "puss_gobject_module.h"

#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include <gtk/gtk.h>

#include "puss_gobject_ffi_reg.h"

#include "luaproxy_import.inl"


static PussGObjectInterface* gobject_iface = NULL;

static void glua_gdk_register(lua_State* L, PussGObjectRegIface* reg_iface, int glua_env_index) {
	// see : share/gdk-doc/html/gtk3/api-index-full.html
	// A
#if GTK_CHECK_VERSION(3,20,0)
	(void)GDK_TYPE_ANCHOR_HINTS;
#endif
	gtype_reg_start(GDK_TYPE_APP_LAUNCH_CONTEXT, gdk_app_launch_context);	gtype_reg_end();

#if GTK_CHECK_VERSION(3,20,0)
	(void)GDK_TYPE_AXIS_FLAGS;
	(void)GDK_TYPE_AXIS_USE;
#endif

	// B
	gtype_reg_global_ffi(G_TYPE_NONE, gdk_beep, G_TYPE_INVALID);
	(void)GDK_TYPE_BYTE_ORDER;

	// C
	(void)GDK_TYPE_CROSSING_MODE;
	gtype_reg_start(GDK_TYPE_CURSOR, gdk_cursor);	gtype_reg_end();
	(void)GDK_TYPE_CURSOR_TYPE;

	// D
#if GTK_CHECK_VERSION(3,20,0)
	gtype_reg_start(GDK_TYPE_DEVICE, gdk_device);	gtype_reg_end();
	gtype_reg_start(GDK_TYPE_DEVICE_MANAGER, gdk_device_manager);	gtype_reg_end();
	gtype_reg_start(GDK_TYPE_DEVICE_PAD, gdk_device_pad);	gtype_reg_end();
	(void)GDK_TYPE_DEVICE_PAD_FEATURE;
	(void)GDK_TYPE_DEVICE_TOOL_TYPE;
	(void)GDK_TYPE_DEVICE_TYPE;
#endif
	gtype_reg_global_ffi(G_TYPE_NONE, gdk_disable_multidevice, G_TYPE_INVALID);
	gtype_reg_start(GDK_TYPE_DISPLAY, gdk_display);	gtype_reg_end();
	gtype_reg_start(GDK_TYPE_DISPLAY_MANAGER, gdk_display_manager);	gtype_reg_end();
	(void)GDK_TYPE_DRAG_ACTION;

#if GTK_CHECK_VERSION(3,20,0)
	(void)GDK_TYPE_DRAG_CANCEL_REASON;
	gtype_reg_start(GDK_TYPE_DRAG_CONTEXT, gdk_drag_context);	gtype_reg_end();
	(void)GDK_TYPE_DRAG_PROTOCOL;
	gtype_reg_start(GDK_TYPE_DRAWING_CONTEXT, gdk_drawing_context);	gtype_reg_end();
#endif
	gtype_reg_global_ffi(G_TYPE_NONE, gdk_drop_finish, GDK_TYPE_DRAG_CONTEXT, G_TYPE_BOOLEAN, G_TYPE_UINT);
	gtype_reg_global_ffi(G_TYPE_NONE, gdk_drop_reply, GDK_TYPE_DRAG_CONTEXT, G_TYPE_BOOLEAN, G_TYPE_UINT);

	// E
	gtype_reg_start(GDK_TYPE_EVENT, gdk_event);
		gtype_reg_ffi(G_TYPE_UINT, gdk_event_get_time, GDK_TYPE_EVENT);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gdk_event_get_state, GDK_TYPE_EVENT, out GDK_TYPE_MODIFIER_TYPE);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gdk_event_get_coords, GDK_TYPE_EVENT, out G_TYPE_DOUBLE, out G_TYPE_DOUBLE);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gdk_event_get_root_coords, GDK_TYPE_EVENT, out G_TYPE_DOUBLE, out G_TYPE_DOUBLE);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gdk_event_get_axis, GDK_TYPE_EVENT, GDK_TYPE_AXIS_USE, out G_TYPE_DOUBLE);
		gtype_reg_ffi(G_TYPE_NONE, gdk_event_set_screen, GDK_TYPE_EVENT, GDK_TYPE_SCREEN);
		gtype_reg_ffi(GDK_TYPE_SCREEN, gdk_event_get_screen, GDK_TYPE_EVENT);
		gtype_reg_ffi(GDK_TYPE_WINDOW, gdk_event_get_window, GDK_TYPE_EVENT);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gdk_event_get_button, GDK_TYPE_EVENT, out G_TYPE_UINT);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gdk_event_get_click_count, GDK_TYPE_EVENT, out G_TYPE_UINT);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gdk_event_get_keyval, GDK_TYPE_EVENT, out G_TYPE_UINT);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gdk_event_get_scroll_direction, GDK_TYPE_EVENT, out GDK_TYPE_SCROLL_DIRECTION);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gdk_event_get_scroll_deltas, GDK_TYPE_EVENT, out G_TYPE_DOUBLE, out G_TYPE_DOUBLE);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gdk_event_get_axis, GDK_TYPE_EVENT, GDK_TYPE_AXIS_USE, out G_TYPE_DOUBLE);
		gtype_reg_ffi(G_TYPE_NONE, gdk_event_set_device, GDK_TYPE_EVENT, GDK_TYPE_DEVICE);
		gtype_reg_ffi(GDK_TYPE_DEVICE, gdk_event_get_device, GDK_TYPE_EVENT);
		gtype_reg_ffi(G_TYPE_NONE, gdk_event_set_source_device, GDK_TYPE_EVENT, GDK_TYPE_DEVICE);
		gtype_reg_ffi(GDK_TYPE_DEVICE, gdk_event_get_source_device, GDK_TYPE_EVENT);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gdk_event_triggers_context_menu, GDK_TYPE_EVENT);
		gtype_reg_ffi(GDK_TYPE_EVENT_TYPE, gdk_event_get_event_type, GDK_TYPE_EVENT);
	gtype_reg_end();
	(void)GDK_TYPE_EVENT_MASK;
	gtype_reg_global_ffi(G_TYPE_BOOLEAN, gdk_events_get_angle, GDK_TYPE_EVENT, GDK_TYPE_EVENT, out G_TYPE_DOUBLE);
	gtype_reg_global_ffi(G_TYPE_BOOLEAN, gdk_events_get_center, GDK_TYPE_EVENT, GDK_TYPE_EVENT, out G_TYPE_DOUBLE, out G_TYPE_DOUBLE);
	gtype_reg_global_ffi(G_TYPE_BOOLEAN, gdk_events_get_distance, GDK_TYPE_EVENT, GDK_TYPE_EVENT, out G_TYPE_DOUBLE);
	gtype_reg_global_ffi(G_TYPE_BOOLEAN, gdk_events_pending, G_TYPE_INVALID);
	(void)GDK_TYPE_EVENT_TYPE;

	// F
	(void)GDK_TYPE_FILTER_RETURN;
	gtype_reg_global_ffi(G_TYPE_NONE, gdk_flush, G_TYPE_INVALID);
	gtype_reg_start(GDK_TYPE_FRAME_CLOCK, gdk_frame_clock);	gtype_reg_end();
	(void)GDK_TYPE_FRAME_CLOCK_PHASE;
	(void)GDK_TYPE_FULLSCREEN_MODE;
	gtype_reg_global_ffi(G_TYPE_NONE, gdk_flush, G_TYPE_INVALID);

	// G
	gtype_reg_global_ffi(GDK_TYPE_WINDOW, gdk_get_default_root_window, G_TYPE_INVALID);
	gtype_reg_global_ffi(G_TYPE_BOOLEAN, gdk_get_show_events, G_TYPE_INVALID);
	(void)GDK_TYPE_GRAB_OWNERSHIP;
	(void)GDK_TYPE_GRAB_STATUS;
	(void)GDK_TYPE_GRAVITY;

	// I
	(void)GDK_TYPE_INPUT_MODE;
	(void)GDK_TYPE_INPUT_SOURCE;

	// K
	gtype_reg_start(GDK_TYPE_KEYMAP, gdk_keymap);	gtype_reg_end();

	// M
	(void)GDK_TYPE_MODIFIER_INTENT;
	(void)GDK_TYPE_MODIFIER_TYPE;

#if GTK_CHECK_VERSION(3,20,0)
	gtype_reg_start(GDK_TYPE_MONITOR, gdk_monitor);	gtype_reg_end();
#endif

	// N
	(void)GDK_TYPE_NOTIFY_TYPE;

	// O
	(void)GDK_TYPE_OWNER_CHANGE;

	// P
	(void)GDK_TYPE_PROPERTY_STATE;
	(void)GDK_TYPE_PROP_MODE;

	// R
	gtype_reg_start(GDK_TYPE_RGBA, gdk_rgba);	gtype_reg_end();


	// S
	gtype_reg_start(GDK_TYPE_SCREEN, gdk_screen);	gtype_reg_end();
	(void)GDK_TYPE_SCROLL_DIRECTION;
#if GTK_CHECK_VERSION(3,20,0)
	gtype_reg_start(GDK_TYPE_SEAT, gdk_seat);	gtype_reg_end();
	(void)GDK_TYPE_SEAT_CAPABILITIES;
	(void)GDK_TYPE_SETTING_ACTION;
	(void)GDK_TYPE_SUBPIXEL_LAYOUT;
#endif
	// V
	(void)GDK_TYPE_VISIBILITY_STATE;
	(void)GDK_TYPE_VISUAL_TYPE;

	// W
	gtype_reg_start(GDK_TYPE_WINDOW, gdk_window);
		gtype_reg_ffi(G_TYPE_NONE, gdk_window_raise, GDK_TYPE_WINDOW);
	gtype_reg_end();
	(void)GDK_TYPE_WINDOW_ATTRIBUTES_TYPE;
	(void)GDK_TYPE_WINDOW_EDGE;
	(void)GDK_TYPE_WINDOW_HINTS;
	(void)GDK_TYPE_WINDOW_STATE;
	(void)GDK_TYPE_WINDOW_TYPE;
	(void)GDK_TYPE_WINDOW_TYPE_HINT;
	(void)GDK_TYPE_WINDOW_WINDOW_CLASS;
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
	lua_pushcfunction(L, gobject_iface->gsignal_connect);
	gobject_iface->gobject_push(L, object);
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
	GObject* obj = gobject_iface->gobject_check(L, 1);
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
	GObject* obj = gobject_iface->gobject_check(L, 1);
	GtkBuilder* builder = GTK_BUILDER(obj);
	if( !builder )
		return luaL_argerror(L, 1, "need GtkBuilder");
	if( !(lua_istable(L, 2) || lua_isfunction(L, 2)) )
		return luaL_argerror(L, 2, "need table or function");
	gtk_builder_connect_signals_full(builder, _gtk_builder_connect_wrapper, L);
	return 0;
}

static int _lua_gtk_list_store_new(lua_State* L) {
	GtkListStore* store;
	lua_Integer i, n;
	GType* types;
	n = lua_istable(L, 1) ? luaL_len(L, 1) : lua_gettop(L);
	types = g_alloca(sizeof(GType) * (n + 1));
	memset(types, 0, sizeof(GType) * (n + 1));

	if( lua_istable(L, 1) ) {
		for( i=0; i<n; ++i ) {
			lua_rawgeti(L, 1, i+1);
			types[i] = (GType)lua_tointeger(L, -1);
			lua_pop(L, 1);
		}
	} else {
		for( i=0; i<n; ++i ) {
			types[i] = (GType)lua_tointeger(L, (int)i+1);
		}
	}
	store = gtk_list_store_newv((gint)n, types);
	gobject_iface->gobject_push(L, G_OBJECT(store));
	g_object_unref(store);
	return 1;
}

static int _lua_gtk_list_store_set_column_types(lua_State* L) {
	GObject* obj = gobject_iface->gobject_check(L, 1);
	GtkListStore* store = GTK_LIST_STORE(obj);
	lua_Integer i, n;
	GType* types;
	if( !store )
		return luaL_argerror(L, 1, "need GtkListStore");
	n = lua_istable(L, 2) ? luaL_len(L, 2) : (lua_gettop(L) - 1);
	types = g_alloca(sizeof(GType) * (n + 1));
	memset(types, 0, sizeof(GType) * (n + 1));

	if( lua_istable(L, 2) ) {
		for( i=0; i<n; ++i ) {
			lua_rawgeti(L, 2, i+1);
			types[i] = (GType)lua_tointeger(L, -1);
			lua_pop(L, 1);
		}
	} else {
		for( i=0; i<n; ++i ) {
			types[i] = (GType)lua_tointeger(L, (int)i+2);
		}
	}
	gtk_list_store_set_column_types(store, (gint)n, types);
	return 0;
}

static int _lua_gtk_tree_selection_get_selected_rows(lua_State* L) {
	GObject* obj = gobject_iface->gobject_check(L, 1);
	GtkTreeSelection* sel = GTK_TREE_SELECTION(obj);
	GList* sels = gtk_tree_selection_get_selected_rows(sel, NULL);
	GList* p;
	int n = 0;
	lua_newtable(L);
	for( p=sels; p; p=p->next ) {
		GtkTreePath* path = (GtkTreePath*)(p->data);
		if( !path )	continue;
		gobject_iface->gvalue_push_boxed(L, GTK_TYPE_TREE_PATH, path, TRUE);
		lua_rawseti(L, -2, ++n);
	}
	g_list_free(sels);
	return 1;
}

static void glua_gtk_register(lua_State* L, PussGObjectRegIface* reg_iface, int glua_env_index) {
	// see : share/gtk-doc/html/gtk3/api-index-full.html
	// A
	gtype_reg_start(GTK_TYPE_ABOUT_DIALOG, gtk_about_dialog); gtype_reg_end();
	(void)GTK_TYPE_ACCEL_FLAGS;
	gtype_reg_start(GTK_TYPE_ACCEL_GROUP, gtk_accel_group); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_ACCEL_LABEL, gtk_accel_label); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_ACCEL_MAP, gtk_accel_map); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_ACCESSIBLE, gtk_accessible); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_ACTIONABLE, gtk_actionable); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_ACTION_BAR, gtk_action_bar); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_ADJUSTMENT, gtk_adjustment); gtype_reg_end();
	(void)GTK_TYPE_ALIGN;
	gtype_reg_start(GTK_TYPE_APP_CHOOSER, gtk_app_chooser); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_APP_CHOOSER_BUTTON, gtk_app_chooser_button); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_APP_CHOOSER_DIALOG, gtk_app_chooser_dialog); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_APP_CHOOSER_WIDGET, gtk_app_chooser_widget); gtype_reg_end();
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
	(void)GTK_TYPE_APPLICATION_INHIBIT_FLAGS;
	gtype_reg_start(GTK_TYPE_APPLICATION_WINDOW, gtk_application_window);
		gtype_reg_ffi(G_TYPE_NONE, gtk_application_window_set_show_menubar, GTK_TYPE_APPLICATION_WINDOW, G_TYPE_BOOLEAN);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_application_window_get_show_menubar, GTK_TYPE_APPLICATION_WINDOW);
		gtype_reg_ffi(G_TYPE_UINT, gtk_application_window_get_id, GTK_TYPE_APPLICATION_WINDOW);
	gtype_reg_end();
	(void)GTK_TYPE_ARROW_PLACEMENT;
	(void)GTK_TYPE_ARROW_TYPE;
	gtype_reg_start(GTK_TYPE_ASPECT_FRAME, gtk_aspect_frame); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_ASSISTANT, gtk_assistant); gtype_reg_end();
	(void)GTK_TYPE_ASSISTANT_PAGE_TYPE;
	(void)GTK_TYPE_ATTACH_OPTIONS;

	// B
	(void)GTK_TYPE_BASELINE_POSITION;
	gtype_reg_start(GTK_TYPE_BIN, gtk_bin);
		gtype_reg_ffi(GTK_TYPE_WIDGET, gtk_bin_get_child, GTK_TYPE_BIN);
		gtype_reg_ffi(GTK_TYPE_WIDGET, gtk_bin_get_child, GTK_TYPE_BIN);
	gtype_reg_end();
	gtype_reg_start(GTK_TYPE_BORDER, gtk_border); gtype_reg_end();
	(void)GTK_TYPE_BORDER_STYLE;
	gtype_reg_start(GTK_TYPE_BOX, gtk_box);
		gtype_reg_ffi(G_TYPE_NONE, gtk_box_pack_start, GTK_TYPE_BOX, GTK_TYPE_WIDGET, G_TYPE_BOOLEAN, G_TYPE_BOOLEAN, G_TYPE_UINT);
		gtype_reg_ffi(G_TYPE_NONE, gtk_box_pack_end, GTK_TYPE_BOX, GTK_TYPE_WIDGET, G_TYPE_BOOLEAN, G_TYPE_BOOLEAN, G_TYPE_UINT);
	gtype_reg_end();
	gtype_reg_start(GTK_TYPE_BUILDABLE, gtk_buildable); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_BUILDER, gtk_builder);
		gtype_reg_ffi(G_TYPE_OBJECT, gtk_builder_get_object, GTK_TYPE_BUILDER, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_INT, gtk_builder_get_type_from_name, GTK_TYPE_BUILDER, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_UINT, gtk_builder_add_from_file, GTK_TYPE_BUILDER, G_TYPE_STRING, out G_TYPE_ERROR);
		gtype_reg_lua(gtk_builder_add_from_string);
		gtype_reg_lua(gtk_builder_connect_signals);
	gtype_reg_end();
	(void)GTK_TYPE_BUILDER_ERROR;
	gtype_reg_start(GTK_TYPE_BUTTON, gtk_button); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_BUTTON_BOX, gtk_button_box); gtype_reg_end();
	(void)GTK_TYPE_BUTTON_BOX_STYLE;
	(void)GTK_TYPE_BUTTON_ROLE;
	(void)GTK_TYPE_BUTTONS_TYPE;

	// C
	gtype_reg_start(GTK_TYPE_CALENDAR, gtk_calendar); gtype_reg_end();
	(void)GTK_TYPE_CALENDAR_DISPLAY_OPTIONS;
	gtype_reg_start(GTK_TYPE_CELL_AREA, gtk_cell_area); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_CELL_AREA_BOX, gtk_cell_area_box); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_CELL_AREA_CONTEXT, gtk_cell_area_context); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_CELL_EDITABLE, gtk_cell_editable); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_CELL_LAYOUT, gtk_cell_layout); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_CELL_RENDERER, gtk_cell_renderer); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_CELL_RENDERER_ACCEL, gtk_cell_renderer_accel); gtype_reg_end();
	(void)GTK_TYPE_CELL_RENDERER_ACCEL_MODE;
	gtype_reg_start(GTK_TYPE_CELL_RENDERER_COMBO, gtk_cell_renderer_combo); gtype_reg_end();
	(void)GTK_TYPE_CELL_RENDERER_MODE;
	gtype_reg_start(GTK_TYPE_CELL_RENDERER_PIXBUF, gtk_cell_renderer_pixbuf); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_CELL_RENDERER_PROGRESS, gtk_cell_renderer_progress); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_CELL_RENDERER_SPIN, gtk_cell_renderer_spin); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_CELL_RENDERER_SPINNER, gtk_cell_renderer_spinner); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_CELL_RENDERER_STATE, gtk_cell_renderer_state); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_CELL_RENDERER_TEXT, gtk_cell_renderer_text); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_CELL_RENDERER_TOGGLE, gtk_cell_renderer_toggle); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_CELL_VIEW, gtk_cell_view); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_CHECK_BUTTON, gtk_check_button); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_CHECK_MENU_ITEM, gtk_check_menu_item); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_CLIPBOARD, gtk_clipboard); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_COLOR_BUTTON, gtk_color_button); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_COLOR_CHOOSER, gtk_color_coloser); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_COLOR_CHOOSER_DIALOG, gtk_color_coloser_dialog); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_COLOR_CHOOSER_WIDGET, gtk_color_chooser_widget); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_COMBO_BOX, gtk_combo_box); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_COMBO_BOX_TEXT, gtk_combo_box_text); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_CONTAINER, gtk_container);
		gtype_reg_ffi(G_TYPE_NONE, gtk_container_add, GTK_TYPE_CONTAINER, GTK_TYPE_WIDGET);
		gtype_reg_ffi(G_TYPE_NONE, gtk_container_remove, GTK_TYPE_CONTAINER, GTK_TYPE_WIDGET);
		gtype_reg_ffi(G_TYPE_NONE, gtk_container_set_focus_child, GTK_TYPE_CONTAINER, GTK_TYPE_WIDGET);
		gtype_reg_ffi(GTK_TYPE_WIDGET, gtk_container_get_focus_child, GTK_TYPE_CONTAINER);
	gtype_reg_end();
	(void)GTK_TYPE_CORNER_TYPE;
	gtype_reg_start(GTK_TYPE_CSS_PROVIDER, gtk_css_provider); gtype_reg_end();
	(void)GTK_TYPE_CSS_PROVIDER_ERROR;
	gtype_reg_start(GTK_TYPE_CSS_SECTION, gtk_css_section); gtype_reg_end();
	(void)GTK_TYPE_CSS_SECTION_TYPE;

	// D
	(void)GTK_TYPE_DELETE_TYPE;
	(void)GTK_TYPE_DEST_DEFAULTS;
	gtype_reg_start(GTK_TYPE_DIALOG, gtk_dialog);
		gtype_reg_ffi(G_TYPE_INT, gtk_dialog_run, GTK_TYPE_DIALOG);
		gtype_reg_ffi(G_TYPE_NONE, gtk_dialog_response, GTK_TYPE_DIALOG, G_TYPE_INT);
		gtype_reg_ffi(GTK_TYPE_WIDGET, gtk_dialog_add_button, GTK_TYPE_DIALOG, G_TYPE_STRING, G_TYPE_INT);
	gtype_reg_end();
	(void)GTK_TYPE_DIALOG_FLAGS;
	(void)GTK_TYPE_DIRECTION_TYPE;
	(void)GTK_TYPE_DRAG_RESULT;
	gtype_reg_start(GTK_TYPE_DRAWING_AREA, gtk_drawing_area); gtype_reg_end();

	// E
	gtype_reg_start(GTK_TYPE_EDITABLE, gtk_editable); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_ENTRY, gtk_entry); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_ENTRY_BUFFER, gtk_entry_buffer); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_ENTRY_COMPLETION, gtk_entry_completion); gtype_reg_end();
	(void)GTK_TYPE_ENTRY_ICON_POSITION;
	gtype_reg_start(GTK_TYPE_EVENT_BOX, gtk_event_box); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_EVENT_CONTROLLER, gtk_event_controller); gtype_reg_end();
	(void)GTK_TYPE_EVENT_SEQUENCE_STATE;
	gtype_reg_start(GTK_TYPE_EXPANDER, gtk_expander); gtype_reg_end();
	(void)GTK_TYPE_EXPANDER_STYLE;

	// F
	gtype_reg_start(GTK_TYPE_FILE_CHOOSER, gtk_file_chooser);
		gtype_reg_ffi_rnew(G_TYPE_STRING, gtk_file_chooser_get_filename, GTK_TYPE_FILE_CHOOSER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_file_chooser_set_current_folder, GTK_TYPE_FILE_CHOOSER, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_NONE, gtk_file_chooser_set_current_name, GTK_TYPE_FILE_CHOOSER, G_TYPE_STRING);
	gtype_reg_end();
	(void)GTK_TYPE_FILE_CHOOSER_ACTION;
	gtype_reg_start(GTK_TYPE_FILE_CHOOSER_BUTTON, gtk_file_chooser);	gtype_reg_end();
	(void)GTK_TYPE_FILE_CHOOSER_CONFIRMATION;
	gtype_reg_start(GTK_TYPE_FILE_CHOOSER_DIALOG, gtk_file_chooser_dialog); gtype_reg_end();
	(void)GTK_TYPE_FILE_CHOOSER_ERROR;
#if GTK_CHECK_VERSION(3,20,0)
	gtype_reg_start(GTK_TYPE_FILE_CHOOSER_NATIVE, gtk_file_chooser_native);
		gtype_reg_ffi(GTK_TYPE_FILE_CHOOSER_NATIVE, gtk_file_chooser_native_new, G_TYPE_STRING, opt GTK_TYPE_WINDOW, GTK_TYPE_FILE_CHOOSER_ACTION, opt G_TYPE_STRING, opt G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_STRING, gtk_file_chooser_native_get_accept_label, GTK_TYPE_FILE_CHOOSER_NATIVE);
		gtype_reg_ffi(G_TYPE_NONE, gtk_file_chooser_native_set_accept_label, GTK_TYPE_FILE_CHOOSER_NATIVE, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_STRING, gtk_file_chooser_native_get_cancel_label, GTK_TYPE_FILE_CHOOSER_NATIVE);
		gtype_reg_ffi(G_TYPE_NONE, gtk_file_chooser_native_set_cancel_label, GTK_TYPE_FILE_CHOOSER_NATIVE, G_TYPE_STRING);
	gtype_reg_end();
#endif
	gtype_reg_start(GTK_TYPE_FILE_CHOOSER_WIDGET, gtk_file_chooser_widget); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_FILE_FILTER, gtk_file_filter); 
		gtype_reg_ffi(G_TYPE_NONE, gtk_file_filter_set_name, GTK_TYPE_FILE_FILTER, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_NONE, gtk_file_filter_add_pattern, GTK_TYPE_FILE_FILTER, G_TYPE_STRING);
	gtype_reg_end();
	(void)GTK_TYPE_FILE_FILTER_FLAGS;
	gtype_reg_start(GTK_TYPE_FIXED, gtk_fixed); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_FLOW_BOX, gtk_flow_box); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_FONT_BUTTON, gtk_font_button); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_FONT_CHOOSER, gtk_font_chooser); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_FONT_CHOOSER_DIALOG, gtk_font_chooser_dialog); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_FONT_CHOOSER_WIDGET, gtk_font_chooser_widget); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_FRAME, gtk_frame); gtype_reg_end();

	// G
	gtype_reg_start(GTK_TYPE_GESTURE, gtk_gesture); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_GESTURE_DRAG, gtk_gesture_drag); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_GESTURE_LONG_PRESS, gtk_gesture_long_press); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_GESTURE_MULTI_PRESS, gtk_gesture_multi_press); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_GESTURE_PAN, gtk_gesture_pan); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_GESTURE_ROTATE, gtk_gesture_rotate); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_GESTURE_SINGLE, gtk_gesture_single); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_GESTURE_SWIPE, gtk_gesture_swipe); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_GESTURE_ZOOM, gtk_gesture_zoom); gtype_reg_end();
	gtype_reg_global_ffi(GDK_TYPE_EVENT, gtk_get_current_event, G_TYPE_INVALID);
	gtype_reg_global_ffi(GDK_TYPE_DEVICE, gtk_get_current_event_device, G_TYPE_INVALID);
	gtype_reg_global_ffi(G_TYPE_BOOLEAN, gtk_get_current_event_state, out GDK_TYPE_MODIFIER_TYPE);
	gtype_reg_global_ffi(G_TYPE_UINT, gtk_get_current_event_time, G_TYPE_INVALID);
	gtype_reg_global_ffi(PANGO_TYPE_LANGUAGE, gtk_get_default_language, G_TYPE_INVALID);
	gtype_reg_global_ffi(GTK_TYPE_WIDGET, gtk_get_event_widget, GDK_TYPE_EVENT);
	gtype_reg_start(GTK_TYPE_GL_AREA, gtk_gl_area); gtype_reg_end();
	gtype_reg_global_ffi(G_TYPE_NONE, gtk_grab_add, GTK_TYPE_WIDGET);
	gtype_reg_global_ffi(GTK_TYPE_WIDGET, gtk_grab_get_current, G_TYPE_INVALID);
	gtype_reg_global_ffi(G_TYPE_NONE, gtk_grab_remove, GTK_TYPE_WIDGET);
	gtype_reg_start(GTK_TYPE_GRID, gtk_grid); gtype_reg_end();

	// H
	gtype_reg_start(GTK_TYPE_HEADER_BAR, gtk_header_bar); gtype_reg_end();

	// I
	gtype_reg_start(GTK_TYPE_ICON_INFO, gtk_icon_info); gtype_reg_end();
	(void)GTK_TYPE_ICON_LOOKUP_FLAGS;
	(void)GTK_TYPE_ICON_SIZE;
	gtype_reg_start(GTK_TYPE_ICON_THEME, gtk_icon_theme); gtype_reg_end();
	(void)GTK_TYPE_ICON_THEME_ERROR;
	gtype_reg_start(GTK_TYPE_ICON_VIEW, gtk_icon_view); gtype_reg_end();
	(void)GTK_TYPE_ICON_VIEW_DROP_POSITION;
	gtype_reg_start(GTK_TYPE_IMAGE, gtk_image); gtype_reg_end();
	(void)GTK_TYPE_IMAGE_TYPE;
	gtype_reg_start(GTK_TYPE_IM_CONTEXT, gtk_im_context); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_IM_CONTEXT_SIMPLE, gtk_im_context_simple); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_IM_MULTICONTEXT, gtk_im_multicontext); gtype_reg_end();
	(void)GTK_TYPE_IM_PREEDIT_STYLE;
	(void)GTK_TYPE_IM_STATUS_STYLE;
	gtype_reg_start(GTK_TYPE_INFO_BAR, gtk_info_bar); gtype_reg_end();
	(void)GTK_TYPE_INPUT_HINTS;
	(void)GTK_TYPE_INPUT_PURPOSE;
	gtype_reg_start(GTK_TYPE_INVISIBLE, gtk_invisible); gtype_reg_end();

	// J
	(void)GTK_TYPE_JUNCTION_SIDES;
	(void)GTK_TYPE_JUSTIFICATION;

	// K

	// L
	gtype_reg_start(GTK_TYPE_LABEL, gtk_label); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_LAYOUT, gtk_layout); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_LEVEL_BAR, gtk_level_bar); gtype_reg_end();
	(void)GTK_TYPE_LEVEL_BAR_MODE;
	(void)GTK_TYPE_LICENSE;
	gtype_reg_start(GTK_TYPE_LINK_BUTTON, gtk_link_button); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_LIST_BOX, gtk_list_box); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_LIST_BOX_ROW, gtk_list_box_row); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_LIST_STORE, gtk_list_store);
		gtype_reg_lua(gtk_list_store_new);
		gtype_reg_lua(gtk_list_store_set_column_types);
		gtype_reg_ffi(G_TYPE_NONE, gtk_list_store_append, GTK_TYPE_LIST_STORE, GTK_TYPE_TREE_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_list_store_clear, GTK_TYPE_LIST_STORE);
		gtype_reg_ffi(G_TYPE_NONE, gtk_list_store_insert, GTK_TYPE_LIST_STORE, GTK_TYPE_TREE_ITER, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_NONE, gtk_list_store_insert_before, GTK_TYPE_LIST_STORE, GTK_TYPE_TREE_ITER, GTK_TYPE_TREE_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_list_store_insert_after, GTK_TYPE_LIST_STORE, GTK_TYPE_TREE_ITER, GTK_TYPE_TREE_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_list_store_prepend, GTK_TYPE_LIST_STORE, GTK_TYPE_TREE_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_list_store_remove, GTK_TYPE_LIST_STORE, GTK_TYPE_TREE_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_list_store_set_value, GTK_TYPE_LIST_STORE, GTK_TYPE_TREE_ITER, G_TYPE_INT, G_TYPE_VALUE);
	gtype_reg_end();
	gtype_reg_start(GTK_TYPE_LOCK_BUTTON, gtk_lock_button); gtype_reg_end();

	// M
	gtype_reg_global_ffi(G_TYPE_NONE, gtk_main, G_TYPE_INVALID);
	gtype_reg_global_ffi(G_TYPE_NONE, gtk_main_do_event, GDK_TYPE_EVENT);
	gtype_reg_global_ffi(G_TYPE_BOOLEAN, gtk_main_iteration, G_TYPE_INVALID);
	gtype_reg_global_ffi(G_TYPE_BOOLEAN, gtk_main_iteration_do, G_TYPE_BOOLEAN);
	gtype_reg_global_ffi(G_TYPE_UINT, gtk_main_level, G_TYPE_INVALID);
	gtype_reg_global_ffi(G_TYPE_NONE, gtk_main_quit, G_TYPE_INVALID);
	lua_pushinteger(L, GTK_MAJOR_VERSION);	lua_setfield(L, glua_env_index, "GTK_MAJOR_VERSION");
	gtype_reg_start(GTK_TYPE_MENU, gtk_menu); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_MENU_BAR, gtk_menu_bar); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_MENU_BUTTON, gtk_menu_button); gtype_reg_end();
	(void)GTK_TYPE_MENU_DIRECTION_TYPE;
	gtype_reg_start(GTK_TYPE_MENU_ITEM, gtk_menu_item); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_MENU_SHELL, gtk_menu_shell); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_MENU_TOOL_BUTTON, gtk_menu_tool_button); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_MESSAGE_DIALOG, gtk_message_dialog); gtype_reg_end();
	(void)GTK_TYPE_MESSAGE_TYPE;
	lua_pushinteger(L, GTK_MICRO_VERSION);	lua_setfield(L, glua_env_index, "GTK_MICRO_VERSION");
	lua_pushinteger(L, GTK_MINOR_VERSION);	lua_setfield(L, glua_env_index, "GTK_MINOR_VERSION");
	gtype_reg_start(GTK_TYPE_MODEL_BUTTON, gtk_model_button); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_MOUNT_OPERATION, gtk_mount_operation); gtype_reg_end();
	(void)GTK_TYPE_MOVEMENT_STEP;

	// N

#if GTK_CHECK_VERSION(3,20,0)
	gtype_reg_start(GTK_TYPE_NATIVE_DIALOG, gtk_native_dialog);
		gtype_reg_ffi(G_TYPE_NONE, gtk_native_dialog_show, GTK_TYPE_NATIVE_DIALOG);
		gtype_reg_ffi(G_TYPE_NONE, gtk_native_dialog_hide, GTK_TYPE_NATIVE_DIALOG);
		gtype_reg_ffi(G_TYPE_NONE, gtk_native_dialog_destroy, GTK_TYPE_NATIVE_DIALOG);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_native_dialog_get_visible, GTK_TYPE_NATIVE_DIALOG);
		gtype_reg_ffi(G_TYPE_NONE, gtk_native_dialog_set_modal, GTK_TYPE_NATIVE_DIALOG, G_TYPE_BOOLEAN);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_native_dialog_get_modal, GTK_TYPE_NATIVE_DIALOG);
		gtype_reg_ffi(G_TYPE_NONE, gtk_native_dialog_set_title, GTK_TYPE_NATIVE_DIALOG, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_STRING, gtk_native_dialog_get_title, GTK_TYPE_NATIVE_DIALOG);
		gtype_reg_ffi(G_TYPE_NONE, gtk_native_dialog_set_transient_for, GTK_TYPE_NATIVE_DIALOG, GTK_TYPE_WINDOW);
		gtype_reg_ffi(GTK_TYPE_WINDOW, gtk_native_dialog_get_transient_for, GTK_TYPE_NATIVE_DIALOG);
		gtype_reg_ffi(G_TYPE_INT, gtk_native_dialog_run, GTK_TYPE_NATIVE_DIALOG);
	gtype_reg_end();
#endif
	gtype_reg_start(GTK_TYPE_NOTEBOOK, gtk_notebook);
		gtype_reg_ffi(G_TYPE_INT, gtk_notebook_append_page, GTK_TYPE_NOTEBOOK, GTK_TYPE_WIDGET, GTK_TYPE_WIDGET);
		gtype_reg_ffi(G_TYPE_INT, gtk_notebook_prepend_page, GTK_TYPE_NOTEBOOK, GTK_TYPE_WIDGET, GTK_TYPE_WIDGET);
		gtype_reg_ffi(G_TYPE_INT, gtk_notebook_insert_page, GTK_TYPE_NOTEBOOK, GTK_TYPE_WIDGET, GTK_TYPE_WIDGET, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_NONE, gtk_notebook_remove_page, GTK_TYPE_NOTEBOOK, G_TYPE_INT);
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
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_notebook_get_tab_reorderable, GTK_TYPE_NOTEBOOK, GTK_TYPE_WIDGET);
		gtype_reg_ffi(G_TYPE_NONE, gtk_notebook_set_tab_reorderable, GTK_TYPE_NOTEBOOK, GTK_TYPE_WIDGET, G_TYPE_BOOLEAN);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_notebook_get_tab_detachable, GTK_TYPE_NOTEBOOK, GTK_TYPE_WIDGET);
		gtype_reg_ffi(G_TYPE_NONE, gtk_notebook_set_tab_detachable, GTK_TYPE_NOTEBOOK, GTK_TYPE_WIDGET, G_TYPE_BOOLEAN);
		gtype_reg_ffi(GTK_TYPE_WIDGET, gtk_notebook_get_action_widget, GTK_TYPE_NOTEBOOK, GTK_TYPE_PACK_TYPE);
		gtype_reg_ffi(G_TYPE_NONE, gtk_notebook_set_action_widget, GTK_TYPE_NOTEBOOK, GTK_TYPE_WIDGET, GTK_TYPE_PACK_TYPE);
	gtype_reg_end();
	(void)GTK_TYPE_NUMBER_UP_LAYOUT;

	// O
	gtype_reg_start(GTK_TYPE_OFFSCREEN_WINDOW, gtk_offscreen_window); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_ORIENTABLE, gtk_orientable); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_OVERLAY, gtk_overlay);
		gtype_reg_ffi(G_TYPE_NONE, gtk_overlay_add_overlay, GTK_TYPE_OVERLAY, GTK_TYPE_WIDGET);
		gtype_reg_ffi(G_TYPE_NONE, gtk_overlay_reorder_overlay, GTK_TYPE_OVERLAY, GTK_TYPE_WIDGET, G_TYPE_INT);
	gtype_reg_end();

	// P
#if GTK_CHECK_VERSION(3,20,0)
	(void)GTK_TYPE_PACK_DIRECTION;
	(void)GTK_TYPE_PACK_TYPE;
	(void)GTK_TYPE_PAD_ACTION_TYPE;
	gtype_reg_start(GTK_TYPE_PAD_CONTROLLER, gtk_pad_controller); gtype_reg_end();
	(void)GTK_TYPE_PAGE_ORIENTATION;
#endif
	(void)GTK_TYPE_PAGE_SET;
	gtype_reg_start(GTK_TYPE_PAGE_SETUP, gtk_page_setup); gtype_reg_end();
	(void)GTK_TYPE_PAN_DIRECTION;
	gtype_reg_start(GTK_TYPE_PANED, gtk_paned); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_PAPER_SIZE, gtk_paper_size); gtype_reg_end();
	(void)GTK_TYPE_PATH_PRIORITY_TYPE;
	(void)GTK_TYPE_PATH_TYPE;
	(void)GTK_TYPE_PLACES_OPEN_FLAGS;
	gtype_reg_start(GTK_TYPE_PLACES_SIDEBAR, gtk_places_sidebar); gtype_reg_end();
	(void)GTK_TYPE_POLICY_TYPE;
	gtype_reg_start(GTK_TYPE_POPOVER, gtk_popover); gtype_reg_end();
	(void)GTK_TYPE_POSITION_TYPE;
	gtype_reg_start(GTK_TYPE_POPOVER, gtk_popover); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_PRINT_CONTEXT, gtk_print_context); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_PRINT_DUPLEX, gtk_print_duplex); gtype_reg_end();
	(void)GTK_TYPE_PRINT_ERROR;
	gtype_reg_start(GTK_TYPE_PRINT_OPERATION, gtk_print_operation); gtype_reg_end();
	(void)GTK_TYPE_PRINT_OPERATION_ACTION;
	gtype_reg_start(GTK_TYPE_PRINT_OPERATION_PREVIEW, gtk_print_operation_preview); gtype_reg_end();
	(void)GTK_TYPE_PRINT_OPERATION_RESULT;
	(void)GTK_TYPE_PRINT_PAGES;
	(void)GTK_TYPE_PRINT_QUALITY;
	(void)GTK_TYPE_PRINT_SETTINGS;
	(void)GTK_TYPE_PRINT_STATUS;
	gtype_reg_start(GTK_TYPE_PROGRESS_BAR, gtk_progress_bar); gtype_reg_end();
	gtype_reg_global_ffi(G_TYPE_NONE, gtk_propagate_event, GTK_TYPE_WIDGET, GDK_TYPE_EVENT);
	(void)GTK_TYPE_PROPAGATION_PHASE;

	// R
	gtype_reg_start(GTK_TYPE_RADIO_BUTTON, gtk_radio_button); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_RADIO_MENU_ITEM, gtk_radio_menu_item); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_RADIO_TOOL_BUTTON, gtk_radio_tool_button); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_RANGE, gtk_range); gtype_reg_end();
	(void)GTK_TYPE_RC_FLAGS;
	(void)GTK_TYPE_RC_TOKEN_TYPE;
	gtype_reg_start(GTK_TYPE_RECENT_CHOOSER, gtk_recent_chooser); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_RECENT_CHOOSER_DIALOG, gtk_recent_chooser_dialog); gtype_reg_end();
	(void)GTK_TYPE_RECENT_CHOOSER_ERROR;
	gtype_reg_start(GTK_TYPE_RECENT_CHOOSER_MENU, gtk_recent_chooser_menu); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_RECENT_CHOOSER_WIDGET, gtk_recent_chooser_widget); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_RECENT_FILTER, gtk_recent_filter); gtype_reg_end();
	(void)GTK_TYPE_RECENT_FILTER_FLAGS;
	gtype_reg_start(GTK_TYPE_RECENT_MANAGER, gtk_recent_manager); gtype_reg_end();
	(void)GTK_TYPE_RECENT_MANAGER_ERROR;
	(void)GTK_TYPE_RECENT_SORT_TYPE;
	(void)GTK_TYPE_REGION_FLAGS;
	(void)GTK_TYPE_RELIEF_STYLE;
	gtype_reg_start(GTK_TYPE_REQUISITION, gtk_requisition); gtype_reg_end();
	(void)GTK_TYPE_RESIZE_MODE;
	(void)GTK_TYPE_RESPONSE_TYPE;
	gtype_reg_start(GTK_TYPE_REVEALER, gtk_revealer); gtype_reg_end();
	(void)GTK_TYPE_REVEALER_TRANSITION_TYPE;
	gtype_reg_global_ffi(G_TYPE_NONE, gtk_rgb_to_hsv, G_TYPE_DOUBLE, G_TYPE_DOUBLE, G_TYPE_DOUBLE, out G_TYPE_DOUBLE, out G_TYPE_DOUBLE, out G_TYPE_DOUBLE);

	// S
	gtype_reg_start(GTK_TYPE_SCALE, gtk_scale); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_SCALE_BUTTON, gtk_scale_button); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_SCROLLABLE, gtk_scrollable); gtype_reg_end();
	(void)GTK_TYPE_SCROLLABLE_POLICY;
	gtype_reg_start(GTK_TYPE_SCROLLBAR, gtk_scrollbar); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_SCROLLED_WINDOW, gtk_scrolled_window); gtype_reg_end();
	(void)GTK_TYPE_SCROLL_STEP;
	(void)GTK_TYPE_SCROLL_TYPE;
	gtype_reg_start(GTK_TYPE_SEARCH_BAR, gtk_search_bar); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_SEARCH_ENTRY, gtk_search_entry); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_SELECTION_DATA, gtk_selection_data); gtype_reg_end();
	(void)GTK_TYPE_SELECTION_MODE;
	(void)GTK_TYPE_SENSITIVITY_TYPE;
	gtype_reg_start(GTK_TYPE_SEPARATOR, gtk_separator); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_SEPARATOR_MENU_ITEM, gtk_separator_menu_item); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_SEPARATOR_TOOL_ITEM, gtk_separator_tool_item); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_SETTINGS, gtk_settings);
		gtype_reg_ffi(GTK_TYPE_SETTINGS, gtk_settings_get_default, G_TYPE_INVALID);
		gtype_reg_ffi(GTK_TYPE_SETTINGS, gtk_settings_get_for_screen, GDK_TYPE_SCREEN);

#if GTK_CHECK_VERSION(3,20,0)
		gtype_reg_ffi(G_TYPE_NONE, gtk_settings_reset_property, GTK_TYPE_SETTINGS, G_TYPE_STRING);
#endif
	gtype_reg_end();
	(void)GTK_TYPE_SHADOW_TYPE;

#if GTK_CHECK_VERSION(3,20,0)
	gtype_reg_start(GTK_TYPE_SHORTCUTS_GROUP, gtk_shortcuts_group); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_SHORTCUTS_SECTION, gtk_shortcuts_section); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_SHORTCUTS_SHORTCUT, gtk_shortcuts_shortcut); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_SHORTCUTS_WINDOW, gtk_shortcuts_window); gtype_reg_end();
	(void)GTK_TYPE_SHORTCUT_TYPE;
	gtype_reg_global_ffi(G_TYPE_BOOLEAN, gtk_show_uri_on_window, GTK_TYPE_WINDOW, G_TYPE_STRING, G_TYPE_UINT, out G_TYPE_ERROR);
	gtype_reg_start(GTK_TYPE_SIZE_GROUP, gtk_size_group); gtype_reg_end();
#endif
	(void)GTK_TYPE_SIZE_GROUP_MODE;
	(void)GTK_TYPE_SIZE_REQUEST_MODE;
	(void)GTK_TYPE_SORT_TYPE;
	gtype_reg_start(GTK_TYPE_SPIN_BUTTON, gtk_spin_button); gtype_reg_end();
	(void)GTK_TYPE_SPIN_BUTTON_UPDATE_POLICY;
	gtype_reg_start(GTK_TYPE_SPINNER, gtk_spinner); gtype_reg_end();
	(void)GTK_TYPE_SPIN_TYPE;
	gtype_reg_start(GTK_TYPE_STACK, gtk_stack); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_STACK_SIDEBAR, gtk_stack_sidebar); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_STACK_SWITCHER, gtk_stack_switcher); gtype_reg_end();
	(void)GTK_TYPE_STACK_TRANSITION_TYPE;
	(void)GTK_TYPE_STATE_FLAGS;
	(void)GTK_TYPE_STATE_TYPE;
	gtype_reg_start(GTK_TYPE_STATUSBAR, gtk_statusbar); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_STYLE_CONTEXT, gtk_style_context); gtype_reg_end();

#if GTK_CHECK_VERSION(3,20,0)
	(void)GTK_TYPE_STYLE_CONTEXT_PRINT_FLAGS;
#endif
	gtype_reg_start(GTK_TYPE_STYLE_PROVIDER, gtk_style_provider); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_SWITCH, gtk_switch); gtype_reg_end();

	// T
	(void)GTK_TYPE_TARGET_FLAGS;
	gtype_reg_start(GTK_TYPE_TARGET_LIST, gtk_target_list); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_TEXT_ATTRIBUTES, gtk_text_attributes); gtype_reg_end();
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
	(void)GTK_TYPE_TEXT_BUFFER_TARGET_INFO;
	gtype_reg_start(GTK_TYPE_TEXT_CHILD_ANCHOR, gtk_text_child_anchor); gtype_reg_end();
	(void)GTK_TYPE_TEXT_DIRECTION;
	(void)GTK_TYPE_TEXT_EXTEND_SELECTION;
	gtype_reg_start(GTK_TYPE_TEXT_ITER, gtk_text_iter);
		gtype_reg_boxed_new_use_c_struct0(GTK_TYPE_TEXT_ITER, gtk_text_iter_new, GtkTextIter);
		gtype_reg_ffi(GTK_TYPE_TEXT_ITER, gtk_text_iter_copy, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_INT , gtk_text_iter_get_offset, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_INT , gtk_text_iter_get_line, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_INT , gtk_text_iter_get_line_offset, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_INT , gtk_text_iter_get_line_index, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_INT , gtk_text_iter_get_visible_line_offset, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(G_TYPE_INT , gtk_text_iter_get_visible_line_index, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi_rnew(G_TYPE_STRING, gtk_text_iter_get_slice, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi_rnew(G_TYPE_STRING, gtk_text_iter_get_text, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi_rnew(G_TYPE_STRING, gtk_text_iter_get_visible_slice, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER);
#if GTK_CHECK_VERSION(3,20,0)
		gtype_reg_ffi_rnew(G_TYPE_STRING, gtk_text_iter_get_visible_text, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_ITER);
#endif
		gtype_reg_ffi(GDK_TYPE_PIXBUF, gtk_text_iter_get_pixbuf, GTK_TYPE_TEXT_ITER);
		gtype_reg_ffi(GTK_TYPE_TEXT_CHILD_ANCHOR, gtk_text_iter_get_child_anchor, GTK_TYPE_TEXT_ITER);
#if GTK_CHECK_VERSION(3,20,0)
		gtype_reg_ffi(G_TYPE_BOOLEAN , gtk_text_iter_starts_tag, GTK_TYPE_TEXT_ITER, GTK_TYPE_TEXT_TAG);
#endif
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
	gtype_reg_start(GTK_TYPE_TEXT_MARK, gtk_text_mark); gtype_reg_end();
	(void)GTK_TYPE_TEXT_SEARCH_FLAGS;
	gtype_reg_start(GTK_TYPE_TEXT_TAG, gtk_text_tag);
		gtype_reg_ffi(GTK_TYPE_TEXT_TAG, gtk_text_tag_new, G_TYPE_STRING);
	gtype_reg_end();
	gtype_reg_start(GTK_TYPE_TEXT_TAG_TABLE, gtk_text_tag_table);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_tag_table_add, GTK_TYPE_TEXT_TAG_TABLE, GTK_TYPE_TEXT_TAG);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_tag_table_remove, GTK_TYPE_TEXT_TAG_TABLE, GTK_TYPE_TEXT_TAG);
		gtype_reg_ffi(GTK_TYPE_TEXT_TAG, gtk_text_tag_table_lookup, GTK_TYPE_TEXT_TAG_TABLE, G_TYPE_STRING);
	gtype_reg_end();
	gtype_reg_start(GTK_TYPE_TEXT_VIEW, gtk_text_view);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_text_view_scroll_to_iter, GTK_TYPE_TEXT_VIEW, GTK_TYPE_TEXT_ITER, G_TYPE_DOUBLE, G_TYPE_BOOLEAN, G_TYPE_DOUBLE, G_TYPE_DOUBLE);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_view_scroll_to_mark, GTK_TYPE_TEXT_VIEW, GTK_TYPE_TEXT_MARK, G_TYPE_DOUBLE, G_TYPE_BOOLEAN, G_TYPE_DOUBLE, G_TYPE_DOUBLE);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_view_scroll_mark_onscreen, GTK_TYPE_TEXT_VIEW, GTK_TYPE_TEXT_MARK);
		gtype_reg_ffi(G_TYPE_NONE, gtk_text_view_place_cursor_onscreen, GTK_TYPE_TEXT_VIEW);
	gtype_reg_end();
	(void)GTK_TYPE_TEXT_VIEW_LAYER;
	(void)GTK_TYPE_TEXT_WINDOW_TYPE;
	gtype_reg_start(GTK_TYPE_TOGGLE_BUTTON, gtk_toggle_button); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_TOGGLE_TOOL_BUTTON, gtk_toggle_tool_button); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_TOOLBAR, gtk_toolbar); gtype_reg_end();
	(void)GTK_TYPE_TOOLBAR_SPACE_STYLE;
	(void)GTK_TYPE_TOOLBAR_STYLE;
	gtype_reg_start(GTK_TYPE_TOOL_BUTTON, gtk_tool_button); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_TOOL_ITEM, gtk_tool_item); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_TOOL_ITEM_GROUP, gtk_tool_item_group); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_TOOL_PALETTE, gtk_tool_palette); gtype_reg_end();
	(void)GTK_TYPE_TOOL_PALETTE_DRAG_TARGETS;
	gtype_reg_start(GTK_TYPE_TOOL_SHELL, gtk_tool_shell); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_TOOLTIP, gtk_tooltip); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_TREE_DRAG_DEST, gtk_tree_drag_dest); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_TREE_DRAG_SOURCE, gtk_tree_drag_source); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_TREE_ITER, gtk_tree_iter);
		gtype_reg_boxed_new_use_c_struct0(GTK_TYPE_TREE_ITER, gtk_tree_iter_new, GtkTreeIter);
		gtype_reg_ffi_rnew(GTK_TYPE_TREE_ITER, gtk_tree_iter_copy, GTK_TYPE_TREE_ITER);
	gtype_reg_end();
	gtype_reg_start(GTK_TYPE_TREE_MODEL, gtk_tree_model);
		gtype_reg_ffi(GTK_TYPE_TREE_MODEL_FLAGS, gtk_tree_model_get_flags, GTK_TYPE_TREE_MODEL);
		gtype_reg_ffi(G_TYPE_UINT, gtk_tree_model_get_n_columns, GTK_TYPE_TREE_MODEL);
		gtype_reg_ffi(G_TYPE_UINT, gtk_tree_model_get_column_type, GTK_TYPE_TREE_MODEL, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_tree_model_get_iter, GTK_TYPE_TREE_MODEL, GTK_TYPE_TREE_ITER, GTK_TYPE_TREE_PATH);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_tree_model_get_iter_from_string, GTK_TYPE_TREE_MODEL, GTK_TYPE_TREE_ITER, G_TYPE_STRING);
		gtype_reg_ffi_rnew(G_TYPE_STRING, gtk_tree_model_get_string_from_iter, GTK_TYPE_TREE_MODEL, GTK_TYPE_TREE_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_tree_model_get_iter_first, GTK_TYPE_TREE_MODEL, GTK_TYPE_TREE_ITER);
		gtype_reg_ffi(GTK_TYPE_TREE_PATH, gtk_tree_model_get_path, GTK_TYPE_TREE_MODEL, GTK_TYPE_TREE_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_model_get_value, GTK_TYPE_TREE_MODEL, GTK_TYPE_TREE_ITER, G_TYPE_INT, G_TYPE_VALUE);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_tree_model_iter_next, GTK_TYPE_TREE_MODEL, GTK_TYPE_TREE_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_tree_model_iter_children, GTK_TYPE_TREE_MODEL, GTK_TYPE_TREE_ITER, GTK_TYPE_TREE_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_tree_model_iter_has_child, GTK_TYPE_TREE_MODEL, GTK_TYPE_TREE_ITER);
		gtype_reg_ffi(G_TYPE_INT, gtk_tree_model_iter_n_children, GTK_TYPE_TREE_MODEL, GTK_TYPE_TREE_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_tree_model_iter_nth_child, GTK_TYPE_TREE_MODEL, GTK_TYPE_TREE_ITER, GTK_TYPE_TREE_ITER, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_tree_model_iter_parent, GTK_TYPE_TREE_MODEL, GTK_TYPE_TREE_ITER, GTK_TYPE_TREE_ITER);
	gtype_reg_end();
	gtype_reg_start(GTK_TYPE_TREE_MODEL_FILTER, gtk_tree_model_filter); 
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_model_filter_set_visible_column, GTK_TYPE_TREE_MODEL_FILTER, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_model_filter_refilter, GTK_TYPE_TREE_MODEL_FILTER);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_tree_model_filter_convert_child_iter_to_iter, GTK_TYPE_TREE_MODEL_FILTER, GTK_TYPE_TREE_ITER, GTK_TYPE_TREE_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_model_filter_convert_iter_to_child_iter, GTK_TYPE_TREE_MODEL_FILTER, GTK_TYPE_TREE_ITER, GTK_TYPE_TREE_ITER);
		gtype_reg_ffi(GTK_TYPE_TREE_PATH, gtk_tree_model_filter_convert_child_path_to_path, GTK_TYPE_TREE_MODEL_FILTER, GTK_TYPE_TREE_PATH);
		gtype_reg_ffi(GTK_TYPE_TREE_PATH, gtk_tree_model_filter_convert_path_to_child_path, GTK_TYPE_TREE_MODEL_FILTER, GTK_TYPE_TREE_PATH);
	gtype_reg_end();
	gtype_reg_start(GTK_TYPE_TREE_MODEL_SORT, gtk_tree_model_sort); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_TREE_PATH, gtk_tree_path);
		gtype_reg_ffi(GTK_TYPE_TREE_PATH, gtk_tree_path_new_from_string, G_TYPE_STRING);
	gtype_reg_end();
	gtype_reg_start(GTK_TYPE_TREE_ROW_REFERENCE, gtk_tree_row_reference); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_TREE_SELECTION, gtk_tree_selection);
		gtype_reg_ffi(GTK_TYPE_TREE_VIEW, gtk_tree_selection_get_tree_view, GTK_TYPE_TREE_SELECTION);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_tree_selection_get_selected, GTK_TYPE_TREE_SELECTION, out GTK_TYPE_TREE_MODEL, GTK_TYPE_TREE_ITER);
		gtype_reg_lua(gtk_tree_selection_get_selected_rows);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_selection_select_path, GTK_TYPE_TREE_SELECTION, GTK_TYPE_TREE_PATH);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_selection_unselect_path, GTK_TYPE_TREE_SELECTION, GTK_TYPE_TREE_PATH);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_tree_selection_path_is_selected, GTK_TYPE_TREE_SELECTION, GTK_TYPE_TREE_PATH);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_selection_select_iter, GTK_TYPE_TREE_SELECTION, GTK_TYPE_TREE_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_selection_unselect_iter, GTK_TYPE_TREE_SELECTION, GTK_TYPE_TREE_ITER);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_tree_selection_iter_is_selected, GTK_TYPE_TREE_SELECTION, GTK_TYPE_TREE_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_selection_select_all, GTK_TYPE_TREE_SELECTION);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_selection_unselect_all, GTK_TYPE_TREE_SELECTION);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_selection_select_range, GTK_TYPE_TREE_SELECTION, GTK_TYPE_TREE_PATH, GTK_TYPE_TREE_PATH);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_selection_unselect_range, GTK_TYPE_TREE_SELECTION, GTK_TYPE_TREE_PATH, GTK_TYPE_TREE_PATH);
	gtype_reg_end();
	gtype_reg_start(GTK_TYPE_TREE_SORTABLE, gtk_tree_sortable); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_TREE_STORE, gtk_tree_store);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_store_append, GTK_TYPE_TREE_STORE, GTK_TYPE_TREE_ITER, opt GTK_TYPE_TREE_ITER);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_store_clear, GTK_TYPE_TREE_STORE);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_store_set_value, GTK_TYPE_TREE_STORE, GTK_TYPE_TREE_ITER, G_TYPE_INT, G_TYPE_VALUE);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_tree_store_remove, GTK_TYPE_TREE_STORE, GTK_TYPE_TREE_ITER);
	gtype_reg_end();
	gtype_reg_start(GTK_TYPE_TREE_VIEW, gtk_tree_view);
		gtype_reg_ffi(GTK_TYPE_WIDGET, gtk_tree_view_new, G_TYPE_INVALID);
		gtype_reg_ffi(GTK_TYPE_WIDGET, gtk_tree_view_new_with_model, GTK_TYPE_TREE_MODEL);
		gtype_reg_ffi(GTK_TYPE_TREE_SELECTION, gtk_tree_view_get_selection, GTK_TYPE_TREE_VIEW);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_view_columns_autosize, GTK_TYPE_TREE_VIEW);
		gtype_reg_ffi(G_TYPE_INT, gtk_tree_view_append_column, GTK_TYPE_TREE_VIEW, GTK_TYPE_TREE_VIEW_COLUMN);
		gtype_reg_ffi(G_TYPE_INT, gtk_tree_view_remove_column, GTK_TYPE_TREE_VIEW, GTK_TYPE_TREE_VIEW_COLUMN);
		gtype_reg_ffi(G_TYPE_INT, gtk_tree_view_insert_column, GTK_TYPE_TREE_VIEW, GTK_TYPE_TREE_VIEW_COLUMN, G_TYPE_INT);
		gtype_reg_ffi(GTK_TYPE_TREE_VIEW_COLUMN, gtk_tree_view_get_column, GTK_TYPE_TREE_VIEW, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_view_move_column_after, GTK_TYPE_TREE_VIEW, GTK_TYPE_TREE_VIEW_COLUMN, GTK_TYPE_TREE_VIEW_COLUMN);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_view_scroll_to_point, GTK_TYPE_TREE_VIEW, G_TYPE_INT, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_view_scroll_to_cell, GTK_TYPE_TREE_VIEW, GTK_TYPE_TREE_PATH, opt GTK_TYPE_TREE_VIEW_COLUMN, G_TYPE_BOOLEAN, G_TYPE_FLOAT, G_TYPE_FLOAT);
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
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_tree_view_get_path_at_pos, GTK_TYPE_TREE_VIEW, G_TYPE_INT, G_TYPE_INT, out GTK_TYPE_TREE_PATH, out GTK_TYPE_TREE_VIEW_COLUMN, out G_TYPE_INT, out G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_UINT, gtk_tree_view_get_n_columns, GTK_TYPE_TREE_VIEW);
	gtype_reg_end();
	gtype_reg_start(GTK_TYPE_TREE_VIEW_COLUMN, gtk_tree_view_column);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_view_column_add_attribute, GTK_TYPE_TREE_VIEW_COLUMN, GTK_TYPE_CELL_RENDERER, G_TYPE_STRING, G_TYPE_INT);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_view_column_pack_end, GTK_TYPE_TREE_VIEW_COLUMN, GTK_TYPE_CELL_RENDERER, G_TYPE_BOOLEAN);
		gtype_reg_ffi(G_TYPE_NONE, gtk_tree_view_column_pack_start, GTK_TYPE_TREE_VIEW_COLUMN, GTK_TYPE_CELL_RENDERER, G_TYPE_BOOLEAN);
	gtype_reg_end();
	(void)GTK_TYPE_TREE_VIEW_COLUMN_SIZING;
	(void)GTK_TYPE_TREE_VIEW_DROP_POSITION;
	(void)GTK_TYPE_TREE_VIEW_GRID_LINES;

	// U
	(void)GTK_TYPE_UI_MANAGER_ITEM_TYPE;
	gtype_reg_start(GTK_TYPE_UNIT, gtk_type_unit); gtype_reg_end();

	// V
	gtype_reg_start(GTK_TYPE_VIEWPORT, gtk_viewport); gtype_reg_end();
	gtype_reg_start(GTK_TYPE_VOLUME_BUTTON, gtk_volume_button); gtype_reg_end();

	// W
	gtype_reg_start(GTK_TYPE_WIDGET, gtk_widget);
		gtype_reg_ffi(G_TYPE_NONE, gtk_widget_destroy, GTK_TYPE_WIDGET);
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
	(void)GTK_TYPE_WIDGET_HELP_TYPE;
	gtype_reg_start(GTK_TYPE_WIDGET_PATH, gtk_widget_path);	gtype_reg_end();
	gtype_reg_start(GTK_TYPE_WINDOW, gtk_window);
		gtype_reg_ffi(G_TYPE_NONE, gtk_window_add_accel_group, GTK_TYPE_WINDOW, GTK_TYPE_ACCEL_GROUP);
		gtype_reg_ffi(G_TYPE_NONE, gtk_window_remove_accel_group, GTK_TYPE_WINDOW, GTK_TYPE_ACCEL_GROUP);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_window_activate_focus, GTK_TYPE_WINDOW);
		gtype_reg_ffi(G_TYPE_BOOLEAN, gtk_window_activate_default, GTK_TYPE_WINDOW);
		gtype_reg_ffi(G_TYPE_NONE, gtk_window_set_modal, GTK_TYPE_WINDOW, G_TYPE_BOOLEAN);
		gtype_reg_ffi(G_TYPE_NONE, gtk_window_set_default_size, GTK_TYPE_WINDOW, G_TYPE_INT, G_TYPE_INT);
		gtype_reg_ffi(GDK_TYPE_WINDOW, gtk_widget_get_window, GTK_TYPE_WINDOW);
		gtype_reg_ffi(G_TYPE_NONE, gtk_window_set_default_size, GTK_TYPE_WINDOW, G_TYPE_INT, G_TYPE_INT);
	gtype_reg_end();
	gtype_reg_start(GTK_TYPE_WINDOW_GROUP, gtk_window_group); gtype_reg_end();
	(void)GTK_TYPE_WINDOW_POSITION;
	(void)GTK_TYPE_WINDOW_TYPE;
	(void)GTK_TYPE_WRAP_MODE;
}

static int gtk_run_once(lua_State* L) {
	while( gtk_events_pending() )
		gtk_main_iteration();
	return 0;
}

static void glua_gtk_helper_register(lua_State* L, PussGObjectRegIface* reg_iface, int glua_env_index) {
	const char* gtk_helper_script = "local glua = ...\n"
		"local tree_model_get_value = glua.__raw_gtk_tree_model_get_value or glua.gtk_tree_model_get_value\n"
		"glua.__raw_gtk_tree_model_get_value = tree_model_get_value\n"
		"local temp_value = glua.gnew_uninit_value()\n"
		"glua.gtk_tree_model_get_value = function(model, iter, column)\n"
		"	tree_model_get_value(model, iter, column, temp_value)\n"
		"	return temp_value(true)\n"
		"end\n"
		"glua.types.GtkTreeModel.get_value = glua.gtk_tree_model_get_value\n"
		"\n"
		;

	if( luaL_loadbuffer(L, gtk_helper_script, strlen(gtk_helper_script), "<gtk_helper_script>") )
		lua_error(L);
	lua_pushvalue(L, glua_env_index);
	lua_call(L, 1, 0);

	lua_pushcfunction(L, gtk_run_once);
	lua_setfield(L, glua_env_index, "gtk_run_once");
}

static gboolean __gtk_inited = FALSE;
static int __gtk_argc = 1;
static char __gtk_arg0[64] = { '.', '/', 'a', 'p', 'p', 0 };
static char* __gtk_args[2] = { __gtk_arg0, NULL };
static char** __gtk_argv = __gtk_args;

PUSS_MODULE_EXPORT void* __puss_module_init__(lua_State* L, PussInterface* puss, void* ud) {
	if( !gobject_iface ) {
		guint64 now = (guint64)g_get_real_time();
		__lua_proxy_import__(puss->luaproxy());

		gobject_iface = puss->require(L, "puss_gobject", ud);
		if( !gobject_iface ) {
			luaL_error(L, "require puss_gobject failed!");
			return NULL;
		}

		sprintf(__gtk_arg0, "puss_gtk_%u_%u", (unsigned)(now>>32), (unsigned)(now));
		gtk_init(&__gtk_argc, &__gtk_argv);
	}

	gobject_iface->module_reg(L, glua_gdk_register);
	gobject_iface->module_reg(L, glua_gtk_register);
	gobject_iface->module_reg(L, glua_gtk_helper_register);
	return NULL;
}

