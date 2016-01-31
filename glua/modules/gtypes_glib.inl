// gtypes_glib.inl

#include "../gffireg.h"

#include <gio/gio.h>

static int strv_get(lua_State* L) {
	GValue* v = glua_value_check_type(L, 1, G_TYPE_STRV);
	const GStrv gstrv = (const GStrv)g_value_get_boxed(v);
	int n = (int)g_strv_length(gstrv);
	int i;
	lua_createtable(L, n, 0);
	for( i=0; i<n; ++i ) {
		lua_pushstring(L, gstrv[i]);
		lua_rawseti(L, -2, i+1);
	}
	return 1;
}

static int strv_set(lua_State* L) {
	GValue* v = glua_value_check_type(L, 1, G_TYPE_STRV);
	GStrv strv = NULL;
	if( lua_istable(L, 2) ) {
		int n = (int)lua_rawlen(L, 1);
		int i;
		strv = g_new0(gchar*, (n+1));
		for( i=0; i<n; ++i ) {
			lua_rawgeti(L, 2, i+1);
			if( lua_isstring(L, -1) ) {
				size_t len = 0;
				const char* str = lua_tolstring(L, -1, &len);
				strv[i] = g_strndup(str, len);
			} else {
				strv[i] = g_strdup(lua_tostring(L, -1));
			}
			lua_pop(L, 1);
		}

	} else if( !lua_isnoneornil(L, 2) ) {
		luaL_error(L, "convert to G_TYPE_STRV failed, only support nil or table!");
	}
	g_value_set_boxed(v, strv);
	return 0;
}

static int strv_new(lua_State* L) {
	glua_value_new(L, G_TYPE_STRV);
	lua_pushvalue(L, 1);
	lua_insert(L, 0);
	if( lua_istable(L, 2) )
		strv_set(L);
	lua_settop(L, 1);
	return 1;
}

static int strv_len(lua_State* L) {
	GValue* v = glua_value_check_type(L, 1, G_TYPE_STRV);
	const GStrv gstrv = (const GStrv)g_value_get_boxed(v);
	lua_pushinteger(L, (lua_Integer)g_strv_length(gstrv));
	return 1;
}

static luaL_Reg strv_methods[] =
	{ {"new",		strv_new}
	, {"get",		strv_get}
	, {"set",		strv_set}
	, {"len",		strv_len}
	, {NULL, NULL}
	};

static int _gobject_list_push(lua_State* L, GList* list) {
	GList* p;
	lua_Integer i = 0;
	lua_newtable(L);
	for( p=list; p; p=p->next ) {
		GObject* obj = (GObject*)(p->data);
		if( obj ) {
			glua_object_push(L, obj);
			lua_rawseti(L, -2, ++i);
		}
	}
	g_list_free(list);
	return 1;
}

static int _lua_g_volume_monitor_get_connected_drives(lua_State* L) {
	GVolumeMonitor* monitor = (GVolumeMonitor*)glua_object_check_type(L, 1, G_TYPE_VOLUME_MONITOR);
	return _gobject_list_push( L, g_volume_monitor_get_connected_drives(monitor) );
}

static int _lua_g_volume_monitor_get_volumes(lua_State* L) {
	GVolumeMonitor* monitor = (GVolumeMonitor*)glua_object_check_type(L, 1, G_TYPE_VOLUME_MONITOR);
	return _gobject_list_push( L, g_volume_monitor_get_volumes(monitor) );
}

static int _lua_g_volume_monitor_get_mounts(lua_State* L) {
	GVolumeMonitor* monitor = (GVolumeMonitor*)glua_object_check_type(L, 1, G_TYPE_VOLUME_MONITOR);
	return _gobject_list_push( L, g_volume_monitor_get_mounts(monitor) );
}

static void gtypes_glib_register(lua_State* L) {
	gtype_reg_env_declare();

	// glib boxed
	glua_reg_gtype_index_table(L, G_TYPE_STRV, "g_strv", strv_methods);

	// gio
	gtype_reg_start(G_TYPE_FILE, g_file);
		gtype_reg_ffi(GTYPE_SELF, g_file_new_for_path, G_TYPE_STRING);
		gtype_reg_ffi(GTYPE_SELF, g_file_new_for_uri, G_TYPE_STRING);
		gtype_reg_ffi(GTYPE_SELF, g_file_new_for_commandline_arg, G_TYPE_STRING);
		gtype_reg_ffi(GTYPE_SELF, g_file_new_for_commandline_arg_and_cwd, G_TYPE_STRING, G_TYPE_STRING);
		gtype_reg_ffi(GTYPE_SELF, g_file_parse_name, G_TYPE_STRING);
		gtype_reg_ffi(GTYPE_SELF, g_file_dup, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN, g_file_equal, GTYPE_SELF, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_STRING, g_file_get_basename, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_STRING, g_file_get_path, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_STRING, g_file_get_uri, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_STRING, g_file_get_parse_name, GTYPE_SELF);
		gtype_reg_ffi(GTYPE_SELF, g_file_get_parent, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN, g_file_has_parent, GTYPE_SELF, GTYPE_SELF);
		gtype_reg_ffi(GTYPE_SELF, g_file_get_child, GTYPE_SELF, G_TYPE_STRING);
		gtype_reg_ffi(GTYPE_SELF, g_file_get_child_for_display_name, GTYPE_SELF, G_TYPE_STRING, out G_TYPE_ERROR);
		gtype_reg_ffi(G_TYPE_BOOLEAN, g_file_has_prefix, GTYPE_SELF, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_STRING, g_file_get_relative_path, GTYPE_SELF, GTYPE_SELF);
		gtype_reg_ffi(GTYPE_SELF, g_file_resolve_relative_path, GTYPE_SELF, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_BOOLEAN, g_file_is_native, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN, g_file_has_uri_scheme, GTYPE_SELF, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_STRING, g_file_get_uri_scheme, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_FILE_ENUMERATOR, g_file_enumerate_children, GTYPE_SELF, G_TYPE_STRING, G_TYPE_FILE_QUERY_INFO_FLAGS, opt G_TYPE_CANCELLABLE, opt out G_TYPE_ERROR);
	gtype_reg_end();

	gtype_reg_start(G_TYPE_FILE_ICON, g_file_icon);
		gtype_reg_ffi(GTYPE_SELF, g_file_icon_new, G_TYPE_FILE);
	gtype_reg_end();

	gtype_reg_start(G_TYPE_FILE_INFO, g_file_info);
		gtype_reg_ffi(GTYPE_SELF, g_file_info_dup, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE, g_file_info_copy_into, GTYPE_SELF, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN, g_file_info_has_attribute, GTYPE_SELF, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_BOOLEAN, g_file_info_has_namespace, GTYPE_SELF, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_STRV, g_file_info_list_attributes, GTYPE_SELF, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_FILE_ATTRIBUTE_TYPE, g_file_info_get_attribute_type, GTYPE_SELF, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_NONE, g_file_info_remove_attribute, GTYPE_SELF, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_FILE_ATTRIBUTE_STATUS, g_file_info_get_attribute_status, GTYPE_SELF, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_BOOLEAN, g_file_info_set_attribute_status, GTYPE_SELF, G_TYPE_STRING, G_TYPE_FILE_ATTRIBUTE_STATUS);
		gtype_reg_ffi_rnew(G_TYPE_STRING, g_file_info_get_attribute_as_string, GTYPE_SELF, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_STRING, g_file_info_get_attribute_string, GTYPE_SELF, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_STRING, g_file_info_get_attribute_byte_string, GTYPE_SELF, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_BOOLEAN, g_file_info_get_attribute_boolean, GTYPE_SELF, G_TYPE_STRING);
		if( sizeof(gint)==4 ) {
			gtype_reg_ffi(G_TYPE_UINT, g_file_info_get_attribute_uint32, GTYPE_SELF, G_TYPE_STRING);
			gtype_reg_ffi(G_TYPE_INT, g_file_info_get_attribute_int32, GTYPE_SELF, G_TYPE_STRING);
		} else {
			gtype_reg_ffi(G_TYPE_UINT64, g_file_info_get_attribute_uint32, GTYPE_SELF, G_TYPE_STRING);
			gtype_reg_ffi(G_TYPE_INT64, g_file_info_get_attribute_int32, GTYPE_SELF, G_TYPE_STRING);
		}
		gtype_reg_ffi(G_TYPE_UINT64, g_file_info_get_attribute_uint64, GTYPE_SELF, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_INT64, g_file_info_get_attribute_int64, GTYPE_SELF, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_OBJECT, g_file_info_get_attribute_object, GTYPE_SELF, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_STRV, g_file_info_get_attribute_stringv, GTYPE_SELF, G_TYPE_STRING);
		//gtype_reg_ffi(G_TYPE_NONE, g_file_info_set_attribute, GTYPE_SELF, G_TYPE_STRING, G_TYPE_FILE_ATTRIBUTE_TYPE, G_TYPE_POINTER);
		gtype_reg_ffi(G_TYPE_NONE, g_file_info_set_attribute_string, GTYPE_SELF, G_TYPE_STRING, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_NONE, g_file_info_set_attribute_byte_string, GTYPE_SELF, G_TYPE_STRING, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_NONE, g_file_info_set_attribute_boolean, GTYPE_SELF, G_TYPE_STRING, G_TYPE_BOOLEAN);
		if( sizeof(gint)==4 ) {
			gtype_reg_ffi(G_TYPE_NONE, g_file_info_set_attribute_uint32, GTYPE_SELF, G_TYPE_STRING, G_TYPE_UINT);
			gtype_reg_ffi(G_TYPE_NONE, g_file_info_set_attribute_int32, GTYPE_SELF, G_TYPE_STRING, G_TYPE_INT);
		} else {
			gtype_reg_ffi(G_TYPE_NONE, g_file_info_set_attribute_uint32, GTYPE_SELF, G_TYPE_STRING, G_TYPE_UINT64);
			gtype_reg_ffi(G_TYPE_NONE, g_file_info_set_attribute_int32, GTYPE_SELF, G_TYPE_STRING, G_TYPE_INT64);
		}
		gtype_reg_ffi(G_TYPE_NONE, g_file_info_set_attribute_uint64, GTYPE_SELF, G_TYPE_STRING, G_TYPE_UINT64);
		gtype_reg_ffi(G_TYPE_NONE, g_file_info_set_attribute_int64, GTYPE_SELF, G_TYPE_STRING, G_TYPE_INT64);
		gtype_reg_ffi(G_TYPE_NONE, g_file_info_set_attribute_object, GTYPE_SELF, G_TYPE_STRING, G_TYPE_OBJECT);
		gtype_reg_ffi(G_TYPE_NONE, g_file_info_set_attribute_stringv, GTYPE_SELF, G_TYPE_STRING, G_TYPE_STRV);

		gtype_reg_ffi(G_TYPE_NONE, g_file_info_clear_status, GTYPE_SELF);
#if GLIB_CHECK_VERSION(2,36,0)
		gtype_reg_ffi(G_TYPE_DATE_TIME, g_file_info_get_deletion_date, GTYPE_SELF);
#endif
		gtype_reg_ffi(G_TYPE_FILE_TYPE, g_file_info_get_file_type, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN, g_file_info_get_is_hidden, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN, g_file_info_get_is_backup, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN, g_file_info_get_is_symlink, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_STRING, g_file_info_get_name, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_STRING, g_file_info_get_display_name, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_STRING, g_file_info_get_edit_name, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_ICON, g_file_info_get_icon, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_ICON, g_file_info_get_symbolic_icon, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_STRING, g_file_info_get_content_type, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_INT64, g_file_info_get_size, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_STRING, g_file_info_get_symlink_target, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_STRING, g_file_info_get_etag, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_INT, g_file_info_get_sort_order, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE, g_file_info_set_attribute_mask, GTYPE_SELF, G_TYPE_FILE_ATTRIBUTE_MATCHER);
		gtype_reg_ffi(G_TYPE_NONE, g_file_info_unset_attribute_mask, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE, g_file_info_set_file_type, GTYPE_SELF, G_TYPE_FILE_TYPE);
		gtype_reg_ffi(G_TYPE_NONE, g_file_info_set_is_hidden, GTYPE_SELF, G_TYPE_BOOLEAN);
		gtype_reg_ffi(G_TYPE_NONE, g_file_info_set_is_symlink, GTYPE_SELF, G_TYPE_BOOLEAN);
		gtype_reg_ffi(G_TYPE_NONE, g_file_info_set_name, GTYPE_SELF, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_NONE, g_file_info_set_display_name, GTYPE_SELF, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_NONE, g_file_info_set_edit_name, GTYPE_SELF, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_NONE, g_file_info_set_icon, GTYPE_SELF, G_TYPE_ICON);
		gtype_reg_ffi(G_TYPE_NONE, g_file_info_set_symbolic_icon, GTYPE_SELF, G_TYPE_ICON);
		gtype_reg_ffi(G_TYPE_NONE, g_file_info_set_content_type, GTYPE_SELF, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_NONE, g_file_info_set_size, GTYPE_SELF, G_TYPE_INT64);
		gtype_reg_ffi(G_TYPE_NONE, g_file_info_set_symlink_target, GTYPE_SELF, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_NONE, g_file_info_set_sort_order, GTYPE_SELF, G_TYPE_INT);

		gtype_reg_ffi(G_TYPE_NONE, g_file_info_set_sort_order, GTYPE_SELF, G_TYPE_INT);
	gtype_reg_end();
	
	gtype_reg_start(G_TYPE_FILE_ATTRIBUTE_MATCHER, g_file_attribute_matcher);
		gtype_reg_ffi(GTYPE_SELF, g_file_attribute_matcher_new, G_TYPE_STRING);
		gtype_reg_ffi(GTYPE_SELF, g_file_attribute_matcher_subtract, GTYPE_SELF, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN, g_file_attribute_matcher_matches, GTYPE_SELF, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_BOOLEAN, g_file_attribute_matcher_matches_only, GTYPE_SELF, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_BOOLEAN, g_file_attribute_matcher_enumerate_namespace, GTYPE_SELF, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_STRING, g_file_attribute_matcher_enumerate_next, GTYPE_SELF);
		gtype_reg_ffi_rnew(G_TYPE_STRING, g_file_attribute_matcher_to_string, GTYPE_SELF);
	gtype_reg_end();

	gtype_reg_start(G_TYPE_FILE_ENUMERATOR, g_file_enumerator);
		gtype_reg_ffi(G_TYPE_FILE_INFO, g_file_enumerator_next_file, GTYPE_SELF, opt G_TYPE_CANCELLABLE, opt out G_TYPE_ERROR);
		gtype_reg_ffi(G_TYPE_BOOLEAN, g_file_enumerator_is_closed, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN, g_file_enumerator_has_pending, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE, g_file_enumerator_set_pending, GTYPE_SELF, G_TYPE_BOOLEAN);
		gtype_reg_ffi(G_TYPE_FILE, g_file_enumerator_get_container, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_FILE, g_file_enumerator_get_child, GTYPE_SELF, G_TYPE_FILE_INFO);
	gtype_reg_end();

	gtype_reg_start(G_TYPE_MOUNT, g_mount);
		gtype_reg_ffi(G_TYPE_FILE, g_mount_get_root, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_FILE, g_mount_get_default_location, GTYPE_SELF);
		gtype_reg_ffi_rnew(G_TYPE_STRING, g_mount_get_name, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_ICON, g_mount_get_icon, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_ICON, g_mount_get_symbolic_icon, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_STRING, g_mount_get_uuid, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_VOLUME, g_mount_get_volume, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_DRIVE, g_mount_get_drive, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN, g_mount_can_unmount, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN, g_mount_can_eject, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN, g_mount_is_shadowed, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE, g_mount_shadow, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE, g_mount_unshadow, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_STRING, g_mount_get_sort_key, GTYPE_SELF);
	gtype_reg_end();

	gtype_reg_start(G_TYPE_DRIVE, g_drive);
		gtype_reg_ffi(G_TYPE_STRING, g_drive_get_name, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_ICON, g_drive_get_icon, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_ICON, g_drive_get_symbolic_icon, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN, g_drive_has_volumes, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN, g_drive_is_media_removable, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN, g_drive_has_media, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN, g_drive_is_media_check_automatic, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN, g_drive_can_poll_for_media, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN, g_drive_can_eject, GTYPE_SELF);
		gtype_reg_ffi_rnew(G_TYPE_STRING, g_drive_get_identifier, GTYPE_SELF, G_TYPE_STRING);
		gtype_reg_ffi_rnew(G_TYPE_STRV, g_drive_enumerate_identifiers, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_DRIVE_START_STOP_TYPE, g_drive_get_start_stop_type, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN, g_drive_can_start, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN, g_drive_can_start_degraded, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN, g_drive_can_stop, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_STRING, g_drive_get_sort_key, GTYPE_SELF);
	gtype_reg_end();

	gtype_reg_start(G_TYPE_VOLUME_MONITOR, g_volume_monitor);
		gtype_reg_ffi(GTYPE_SELF, g_volume_monitor_get);
		gtype_reg_lua(g_volume_monitor_get_connected_drives);
		gtype_reg_lua(g_volume_monitor_get_volumes);
		gtype_reg_lua(g_volume_monitor_get_mounts);
		gtype_reg_ffi(G_TYPE_VOLUME, g_volume_monitor_get_volume_for_uuid, GTYPE_SELF, G_TYPE_STRING);
		gtype_reg_ffi(G_TYPE_MOUNT, g_volume_monitor_get_mount_for_uuid, GTYPE_SELF, G_TYPE_STRING);
	gtype_reg_end();

	gtype_reg_start(G_TYPE_APPLICATION, g_application);
		gtype_reg_ffi(G_TYPE_BOOLEAN, g_application_id_is_valid, G_TYPE_STRING);
		gtype_reg_ffi(GTYPE_SELF, g_application_new, G_TYPE_STRING, G_TYPE_APPLICATION_FLAGS);
		gtype_reg_ffi(G_TYPE_BOOLEAN, g_application_get_is_registered, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_BOOLEAN, g_application_get_is_remote, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE, g_application_hold, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE, g_application_release, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE, g_application_activate, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_NONE, g_application_quit, GTYPE_SELF);
		gtype_reg_ffi(GTYPE_SELF, g_application_get_default);
		gtype_reg_ffi(G_TYPE_NONE, g_application_set_default, GTYPE_SELF);
		gtype_reg_ffi(G_TYPE_INT, g_application_run, GTYPE_SELF, G_TYPE_UINT, G_TYPE_STRV);
	gtype_reg_end();

	gtype_reg_start(G_TYPE_MOUNT_OPERATION, g_mount_operation); gtype_reg_end();
}

