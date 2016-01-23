// main.c

#ifdef _WIN32
	#define _CRT_SECURE_NO_WARNINGS
	#define WIN32_LEAN_AND_MEAN
	#include <Windows.h>
	#include <conio.h>

	#ifdef _MSC_VER
		#define inline __inline
	#endif
#endif

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

#define GTK_DISABLE_DEPRECATED 1

#include <glib.h>
#include <gtk/gtk.h>

#include "glua/modules/gtypes_glib.inl"
#include "glua/modules/gtypes_gtk.inl"
#include "glua/modules/gtypes_scintilla.inl"

#ifdef G_OS_WIN32
	static gchar* find_root_filepath(const char* argv0) {
		gchar buf[4096];
		int len = GetModuleFileNameA(0, buf, 4096);
		return g_locale_to_utf8(buf, len, NULL, NULL, NULL);
	}

	G_MODULE_EXPORT int main(int argc, char* argv[]);

#else
	static gchar* find_root_filepath(const char* argv0) {
		gchar* pwd;
		gchar* prj;
		gchar* realpath;
		gchar* filepath = g_find_program_in_path(argv0);

		if( !filepath ) {
			g_printerr(_("ERROR : can not find puss in $PATH\n"));
			return 0;
		}

		if( !g_path_is_absolute(filepath) ) {
			pwd = g_get_current_dir();
			prj = g_build_filename(pwd, filepath, NULL);
			g_free(pwd);
			g_free(filepath);
			filepath = prj;
		}

		if( g_file_test(filepath, G_FILE_TEST_IS_SYMLINK) ) {
			realpath = g_file_read_link(filepath, 0);
			g_free(filepath);
			filepath = realpath;
		}

		if( !g_file_test(filepath, G_FILE_TEST_EXISTS) ) {
			g_printerr(_("ERROR : can not find puss directory!\n"));
			g_printerr(_("        can not use indirect search path in $PATH!\n"));
			g_free(filepath);
			return 0;
		}

		return filepath;
	}

#endif

static int lua_load_main_script(lua_State* L, const char* arg0) {
	int res = 0;
	gsize len = 0;
	gchar* cxt = NULL;
	GError* err = NULL;
	gchar* main_script = NULL;
	gchar* root_path = find_root_filepath(arg0);
	size_t i = strlen(root_path);
	for( --i; i>0; --i ) {
		if( root_path[i]=='\\' || root_path[i]=='/' ) {
			root_path[i] = '\0';
			break;
		}
	}

	main_script = g_build_filename(root_path, "modules", "main.lua", NULL);
	if( g_file_get_contents_utf8(main_script, &cxt, &len, &err) ) {
		res = luaL_loadbuffer(L, cxt, len, "main.lua");
		if( res==LUA_OK ) {
			lua_pushstring(L, root_path);
		}

	} else {
		lua_pushfstring(L, "load main script error : %s\n", err->message);
		g_error_free(err);
		res = 1;
	}

	g_free(cxt);
	g_free(main_script);
	g_free(root_path);
	return res;
}

static int lua_g_file_get_content(lua_State* L) {
	const gchar* fname = luaL_checkstring(L, 1);
	gchar* cnt = NULL;
	gsize len = 0;
	GError* err = NULL;

	if( !g_file_get_contents(fname, &cnt, &len, &err) ) {
		if( err ) {
			lua_pushfstring(L, "get file(%s) content failed: %s\n", fname, err->message);
			g_error_free(err);
			return lua_error(L);
		}
		return luaL_error(L, "get file(%s) content failed!\n", fname);
	}

	lua_pushlstring(L, cnt, len);
	g_free(cnt);
	return 1;
}

int main(int argc, char* argv[]) {
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);

	gtk_init(&argc, &argv);

	gffi_init();
		gtypes_glib_register(L);
		gtypes_gtk_register(L);
		gtypes_scintilla_register(L);
	glua_enum_types_register(L);

	glua_push_master_table(L);
	lua_setglobal(L, "__glua__");

	glua_push_capis_table(L);
		lua_pushcfunction(L, lua_g_file_get_content);	lua_setfield(L, -2, "g_file_get_content");
	lua_pop(L, 1);

	// load main_script
	// push root_path as first argument
	// 
	if( lua_load_main_script(L, argv[0]) ) {
		g_error("load script error : %s", lua_tostring(L, -1));
		lua_pop(L, 1);

	} else {
		// push argv as strv
		{
			gchar** v = g_new0(gchar*, argc+1);
			int i = 0;
			for( ; i<argc; ++i ) {
				v[i] = g_strdup(argv[i]);
			}
			glua_value_push_boxed(L, G_TYPE_STRV, v, TRUE);
		}

		if( glua_pcall(L, 2, 0) ) {
			g_error("pcall error : %s", lua_tostring(L, -1));
			lua_pop(L, 1);
		}
	}

	lua_close(L);

#ifdef _WIN32
	if( getenv("PUSS_DEBUG") ) {
		fprintf(stderr, "press any key to exit...\n");
		_getch();
	}
#endif
	return 0;
}

