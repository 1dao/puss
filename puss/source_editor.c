#include "source_editor.h"

#include <assert.h>
#include <memory.h>
#include <string.h>

#include <lualib.h>
#include <lauxlib.h>

#include <Scintilla.h>
#include <SciLexer.h>
#define GTK
#include <ScintillaWidget.h>

#define source_editor_send(editor, msg, u, s)	scintilla_send_message(SCINTILLA(editor), (msg), (uptr_t)(u), (sptr_t)(s))

static gchar** puss_charset_guess_list = NULL;

typedef ScintillaClass	SourceEditorClass;

#define SOURCE_EDITOR_CLASS(klass)	G_TYPE_CHECK_CLASS_CAST(klass, source_editor_get_type(), SourceEditorClass)

struct _SourceEditor {
	ScintillaObject		parent;
	gboolean			modified;
	const gchar*		charset;
	gboolean			BOM;
	gboolean			CRLF;
};

G_DEFINE_TYPE(SourceEditor, source_editor, scintilla_get_type())

static void source_editor_finalize(GObject* object) {
	G_OBJECT_CLASS(source_editor_parent_class)->finalize(object);
}

static void source_editor_class_init(SourceEditorClass* class) {
	GObjectClass* object_class = G_OBJECT_CLASS(class);
	object_class->finalize = source_editor_finalize;
}

static void source_editor_init(SourceEditor* editor) {
	editor->modified = FALSE;
	editor->BOM = 0;
	editor->charset = 0;
	editor->CRLF = 0;
}


void source_editor_release_resources(void) {
	scintilla_release_resources();
}

SourceEditor* source_editor_new(void) {
	SourceEditor* editor = (SourceEditor*)g_object_new(source_editor_get_type(), NULL);
	gtk_widget_show(GTK_WIDGET(editor));
	return editor;
}

gboolean source_editor_modified(SourceEditor* editor) {
	return editor ? editor->modified : FALSE;
}

static gboolean load_convert_text(gchar** text, gsize* len, const gchar* charset, GError** err) {
	gsize bytes_written = 0;
	gchar* result = g_convert(*text, *len, "UTF-8", charset, 0, &bytes_written, err);
	if( result ) {
		if( g_utf8_validate(result, bytes_written, 0) ) {
			g_free(*text);
			*text = result;
			*len = bytes_written;
			return TRUE;
		}

		g_free(result);
	}

	return FALSE;
}

static gboolean load_bom_convert_text(gchar** text, gsize* len, const gchar** charset, GError** err) {
	// UTF-8		EF BB BF
	// UTF-16(BE)	FE FF
	// UTF-16(LE)	FF FE
	// UTF-32(BE)	00 00 FE FF
	// UTF-32(LE)	FF FE 00 00
	// !!!NOT TEST // UTF-7		2B 2F 76, and one of the following: [ 38 | 39 | 2B | 2F ]
	// !!!NOT TEST // UTF-1		F7 64 4C
	// !!!NOT TEST // UTF-EBCDIC	DD 73 66 73
	// !!!NOT TEST // SCSU			0E FE FF
	// !!!NOT TEST // BOCU-1		FB EE 28 optionally followed by FF
	// GB-18030		84 31 95 33

	gchar* sbuf = *text;
	gsize slen = *len;
	gsize bytes_written = 0;

	if( slen>=3 && memcmp(sbuf, "\xEF\xBB\xBF", 3)==0 ) {
		*charset = "UTF-8";
		if( g_utf8_validate(sbuf+3, slen-3, 0) ) {
			sbuf = g_strdup(sbuf+3);
			slen -= 3;
			goto succeed;
		}

	} else if( slen>=4 && memcmp(sbuf, "\x84\x31\x95\x33", 4)==0 ) {
		*charset = "GB-18030";
		sbuf = g_convert(sbuf, slen, "UTF-8", *charset, 0, &bytes_written, err);
		if( sbuf ) {
			slen = bytes_written;
			goto succeed;
		}

	} else if( slen>=4 && memcmp(sbuf, "\x00\x00\xFE\xFF", 4)==0 ) {
		*charset = "UTF-32BE";
		sbuf = g_convert(sbuf, slen, "UTF-8", *charset, 0, &bytes_written, err);
		if( sbuf ) {
			slen = bytes_written;
			goto succeed;
		}

	} else if( slen>=4 && memcmp(sbuf, "\xFF\xFE\x00\x00", 4)==0 ) {
		*charset = "UTF-32LE";
		sbuf = g_convert(sbuf, slen, "UTF-8", *charset, 0, &bytes_written, err);
		if( sbuf ) {
			slen = bytes_written;
			goto succeed;
		}

	} else if( slen>=2 && memcmp(sbuf, "\xFE\xFF", 2)==0 ) {
		*charset = "UTF-16BE";
		sbuf = g_convert(sbuf, slen, "UTF-8", *charset, 0, &bytes_written, err);
		if( sbuf ) {
			slen = bytes_written;
			goto succeed;
		}

	} else if( slen>=2 && memcmp(sbuf, "\xFF\xFE", 2)==0 ) {
		*charset = "UTF-16LE";
		sbuf = g_convert(sbuf, slen, "UTF-8", *charset, 0, &bytes_written, err);
		if( sbuf ) {
			slen = bytes_written;
			goto succeed;
		}
	}

	return FALSE;

succeed:
	g_free(*text);
	*text = sbuf;
	*len = slen;
	return TRUE;
}

static gboolean puss_save_file(const gchar* filename, const gchar* text, gssize len, const gchar* charset, gboolean use_BOM, gboolean use_CRLF) {
	gboolean succeed = FALSE;
	GIOChannel* channel = 0;
	const gchar* BOM_str = 0;
	gsize BOM_len = 0;
	GError* err = 0;
	gsize bytes_written = 0;
	gchar* crlf_text = NULL;
	gchar* buf = NULL;

	if( use_CRLF ) {
		const gchar* ps = text;
		const gchar* pe = text+len;
		gchar* pd = (gchar*)g_malloc(len*2+1);
		crlf_text = pd;
		if( *ps=='\n' ) {
			*pd++ = '\r';
			*pd++ = *ps++;
		}

		for( ; ps<pe; ++ps ) {
			if( *ps=='\n' && *(ps-1)!='\r' )
				*pd++ = '\r';
			*pd++ = *ps;
		}

		*pd = '\0';
		text = crlf_text;
		len = (pd - crlf_text);
	}

	buf = g_convert(text, len, charset, "UTF-8", 0, &bytes_written, &err);
	if( !buf )
		goto finished;

	if( use_BOM ) {
		// UTF-8		EF BB BF
		// UTF-16(BE)	FE FF
		// UTF-16(LE)	FF FE
		// UTF-32(BE)	00 00 FE FF
		// UTF-32(LE)	FF FE 00 00
		// !!!NOT USE // UTF-7		2B 2F 76, and one of the following: [ 38 | 39 | 2B | 2F ]
		// !!!NOT USE // UTF-1		F7 64 4C
		// !!!NOT USE // UTF-EBCDIC	DD 73 66 73
		// !!!NOT USE // SCSU			0E FE FF
		// !!!NOT USE // BOCU-1		FB EE 28 optionally followed by FF
		// GB-18030		84 31 95 33

		if( g_str_equal(charset, "UTF-8") ) {
			BOM_str = "\xEF\xBB\xBF";
			BOM_len = 3;

		} else if( g_str_equal(charset, "GB-18030") ) {
			BOM_str = "\x84\x31\x95\x33";
			BOM_len = 4;

		} else if( g_str_equal(charset, "UTF-32BE") ) {
			BOM_str = "\x00\x00\xFE\xFF";
			BOM_len = 4;

		} else if( g_str_equal(charset, "UTF-32LE") ) {
			BOM_str = "\xFF\xFE\x00\x00";
			BOM_len = 4;

		} else if( g_str_equal(charset, "UTF-16BE") ) {
			BOM_str = "\xFE\xFF";
			BOM_len = 2;

		} else if( g_str_equal(charset, "UTF-16LE") ) {
			BOM_str = "\xFF\xFE";
			BOM_len = 2;
		}
	}

	// save file
	channel = g_io_channel_new_file(filename, "w", 0);
	if( !channel )
		goto finished;

	if( g_io_channel_set_encoding(channel, NULL, &err)==G_IO_STATUS_ERROR )
		goto finished;

	if( BOM_str && g_io_channel_write_chars(channel, BOM_str, BOM_len, 0, &err)==G_IO_STATUS_ERROR )
		goto finished;

	if( g_io_channel_write_chars(channel, buf, (gssize)bytes_written, 0, &err)==G_IO_STATUS_ERROR )
		goto finished;

	succeed = TRUE;

finished:
	if( err ) {
		g_warning("puss save file failed : %s", err->message);
		g_error_free(err);
	}

	if( channel )
		g_io_channel_shutdown(channel, TRUE, NULL);
	g_free(buf);
	g_free(crlf_text);
	return succeed;
}

// fix replace \r\n => \n
// 
static gsize fix_load_CRLF(gchar* text, gsize len) {
	gchar* ps = text;
	gchar* pe = text + len;
	gchar* next;

	for( ; ps<pe; ++ps) {
		if( *ps!='\r' )
			continue;

		next = ps+1;
		if( next < pe ) {
			if( *next=='\n' ) {
				g_memmove(ps, next, (pe-next));
				--pe;
			}
		}
	}
	return (pe - text);
}

static gboolean puss_load_file(const gchar* filename, gchar** text, gsize* len, G_CONST_RETURN gchar** charset, gboolean* use_BOM, gboolean* use_CRLF) {
	gboolean BOM = FALSE;
	const gchar* cs = 0;
	const gchar* locale = 0;
	gchar* sbuf = 0;
	gsize  slen = 0;

	g_return_val_if_fail(filename && text && len , FALSE);
	g_return_val_if_fail(*filename, FALSE);

	if( !g_file_get_contents(filename, &sbuf, &slen, 0) )
		return FALSE;

	// BOM convert to UTF-8 test
	if( load_bom_convert_text(&sbuf, &slen, &cs, 0) ) {
		BOM = TRUE;
		goto load_succeed;
	}

	// UTF-8 tests
	if( g_utf8_validate(sbuf, slen, 0) ) {
		cs = "UTF-8";
		goto load_succeed;
	}

	// charset tests
	if( puss_charset_guess_list ) {
		const gchar** p = puss_charset_guess_list;
		for( ; *p; ++p ) {
			cs = *p;
			if( cs[0]=='\0' )
				continue;

			if( load_convert_text(&sbuf, &slen, cs, 0) )
				goto load_succeed;
		}
	}

	// local tests
	if( !g_get_charset(&locale) ) {		// get locale charset, and not UTF-8
		if( load_convert_text(&sbuf, &slen, locale, 0) ) {
			cs = locale;
			goto load_succeed;
		}
	}

	g_free(sbuf);
	return FALSE;

load_succeed:
	if( use_BOM )
		*use_BOM = BOM;
	if( charset )
		*charset = cs;

	*text = sbuf;
	*len = fix_load_CRLF(sbuf, slen);
	if( *len!=slen ) {

	}

	// TODO: find cr_lf, use it when save
	return TRUE;
}

#ifdef G_OS_WIN32
#define _WIN32_WINNT 0x0500
#include <windows.h>
#endif

gchar* source_editor_format_diskfile_filename(const gchar* filename) {
	gchar* res = 0;

#ifdef G_OS_WIN32
	if( filename[0]!='\\' ) {
		WIN32_FIND_DATAW wfdd;
		HANDLE hfd;
		wchar_t wbuf[32768];
		gchar**  paths;
		wchar_t* wfname;
		gsize len;
		gsize i;
		gsize j;
	
		wfname = (wchar_t*)g_utf8_to_utf16(filename, -1, 0, 0, 0);
		if( wfname ) {
			len = GetFullPathNameW(wfname, 32768, wbuf, 0);
			len = GetLongPathNameW(wbuf, wbuf, 32768);
			g_free(wfname);

			paths = g_new(gchar*, 256);
			paths[0] = g_strdup("_:");
			paths[0][0] = toupper(filename[0]);
			j = 1;

			for( i=3; i<len; ++i ) {
				if( wbuf[i]=='\\' ) {
					wbuf[i] = '\0';

					hfd = FindFirstFileW(wbuf, &wfdd);
					if( hfd != INVALID_HANDLE_VALUE ) {
						paths[j++] = g_utf16_to_utf8((gunichar2*)wfdd.cFileName, -1, 0, 0, 0);
						FindClose(hfd);
					}
					wbuf[i] = '\\';
				}
			}

			hfd = FindFirstFileW(wbuf, &wfdd);
			if( hfd != INVALID_HANDLE_VALUE ) {
				paths[j++] = g_utf16_to_utf8((gunichar2*)wfdd.cFileName, -1, 0, 0, 0);
				FindClose(hfd);
			}
			paths[j] = 0;

			res = g_build_filenamev(paths);
			g_strfreev(paths);
		}
	}

	if( !res )
		res = g_strdup(filename);

	assert( res );

#else
	gboolean succeed = TRUE;
	gchar** p;
	gchar* outs[256];
	gchar** pt = outs;
	gchar** paths = g_strsplit(filename, "/", 0);
	for( p=paths; succeed && *p; ++p ) {
		if( g_str_equal(*p, ".") ) {
			// ignore ./

		} else if( g_str_equal(*p, "..") ) {
			if( pt==outs )
				succeed = FALSE;
			else
				--pt;

		} else {
			*pt = *p;
			++pt;
		}
	}

	if( succeed ) {
		*pt = NULL;
		res = g_strjoinv("/", outs);

	} else {
		res = g_strdup(filename);
	}

	g_strfreev(paths);

#endif

	return res;
}

void source_editor_reset_charset_guess(const char* guess_list) {
	if( puss_charset_guess_list )
		g_strfreev(puss_charset_guess_list);

	puss_charset_guess_list = g_strsplit_set("GBK;BIG5", " \t,;", 0);
}

gboolean source_editor_load(SourceEditor* editor, const gchar* filename) {
	g_return_val_if_fail(editor, FALSE);
	g_return_val_if_fail(filename, FALSE);

	gchar* text = 0;
	gsize len = 0;
	gboolean ok = puss_load_file(filename, &text, &len, &(editor->charset), &(editor->BOM), &(editor->CRLF));
	if( ok ) {
		source_editor_send(editor, SCI_SETUNDOCOLLECTION, 0, 0);
		source_editor_send(editor, SCI_SETTEXT, (uptr_t)len, (sptr_t)text);
		source_editor_send(editor, SCI_SETUNDOCOLLECTION, 1, 0);
	}
	return ok;
}

gboolean source_editor_save(SourceEditor* editor, const gchar* filename) {
	sptr_t bytes = source_editor_send(editor, SCI_GETTEXT, 0, 0);
	g_return_val_if_fail(bytes > 0, FALSE);
	gchar* cxt = g_malloc0((gsize)bytes);
	gssize len = (gssize)source_editor_send(editor, SCI_GETTEXT, bytes, cxt);
	return puss_save_file(filename, cxt, len, editor->charset, editor->BOM, editor->CRLF);
}

void source_editor_set_text(SourceEditor* editor, const gchar* text, size_t len) {
	source_editor_send(editor, SCI_SETTEXT, (uptr_t)len, (sptr_t)text);
}

// lua wrapper

typedef enum _IFaceType
	{ IFaceType_void			// void
	, IFaceType_int				// int
	, IFaceType_bool			// bool -> integer, 1=true, 0=false
	, IFaceType_position		// position -> integer position in a document
	, IFaceType_colour			// colour -> colour integer containing red, green and blue bytes.
	, IFaceType_string			// string -> pointer to const character
	, IFaceType_stringresult	// stringresult -> pointer to character, NULL-> return size of result
	, IFaceType_cells			// cells -> pointer to array of cells, each cell containing a style byte and character byte
	, IFaceType_textrange		// textrange -> range of a min and a max position with an output string
	, IFaceType_findtext		// findtext -> searchrange, text -> foundposition
	, IFaceType_keymod			// keymod -> integer containing key in low half and modifiers in high half
	, IFaceType_formatrange		// formatrange
	, IFaceTypeMax
	} IFaceType;

static const char* iface_type_name[] =
	{ "void"
	, "int"
	, "bool"
	, "position"
	, "colour"
	, "string"
	, "stringresult"
	, "cells"
	, "textrange"
	, "findtext"
	, "keymod"
	, "formatrange"
	};

typedef struct _IFaceParam {
	int					vint;
	int					vbool;
	int					vposition;
	unsigned			vcolour;
	const char*			vstring;
} IFaceParam;

typedef struct _IFaceDecl {
	const char*			name;
	const char*			alias;
	unsigned int		message;
	IFaceType			rtype;
	IFaceType			wparam;
	IFaceType			lparam;
} IFaceDecl;

#include "source_editor_scintilla_iface.inl"

static const gchar* SOURCE_EDITOR_NAME = "@__PUSS_SOURCE_EDITOR__@";

static SourceEditor* _null_check(lua_State* L, int idx) {
	luaL_error(L, "need source_editor_check() implement!");
	return NULL;
}

static SourceEditorCheck source_editor_check = _null_check;

static int _lua_sci_send_wrap(lua_State* L) {
	IFaceDecl* decl = (IFaceDecl*)lua_touserdata(L, lua_upvalueindex(1));
	SourceEditor* editor = source_editor_check(L, 1);
	int nret = 0;
	uptr_t wparam = 0;
	sptr_t lparam = 0;

	switch( decl->wparam ) {
	case IFaceType_void:	break;
	case IFaceType_bool:	wparam = (uptr_t)lua_toboolean(L, 2);		break;
	case IFaceType_colour:
	case IFaceType_position:
	case IFaceType_int:		wparam = (uptr_t)luaL_checknumber(L, 2);	break;
	case IFaceType_string:	wparam = (uptr_t)luaL_checkstring(L, 2);	break;
	default:
		if( decl->wparam < IFaceTypeMax )
			return luaL_error(L, "not support wparam type(%s)", iface_type_name[decl->wparam]);
		return luaL_error(L, "not support wparam type(%d) system error!", decl->wparam);
	}

	switch( decl->lparam ) {
	case IFaceType_void:	break;
	case IFaceType_bool:	lparam = (sptr_t)lua_toboolean(L, 3);		break;
	case IFaceType_colour:
	case IFaceType_position:
	case IFaceType_int:		lparam = (sptr_t)luaL_checknumber(L, 3);	break;
	case IFaceType_string:	lparam = (sptr_t)luaL_checkstring(L, 3);	break;
	case IFaceType_stringresult:
		{
			int len = (int)source_editor_send(editor, decl->message, wparam, lparam);
			if( len <= 0 )
				return luaL_error(L, "lparam stringresult fetch length failed!");
			wparam = (uptr_t)len;
			lparam = (sptr_t)lua_newuserdata(L, (size_t)len);
		}
		break;
	default:
		if( decl->lparam < IFaceTypeMax )
			return luaL_error(L, "not support lparam type(%s)", iface_type_name[decl->lparam]);
		return luaL_error(L, "not support lparam type(%d) system error!", decl->lparam);
	}

	sptr_t ret = source_editor_send(editor, decl->message, wparam, lparam);
	switch( decl->rtype ) {
	case IFaceType_void:	break;
	case IFaceType_bool:	lua_pushboolean(L, (int)ret);	++nret;	break;
	case IFaceType_colour:
	case IFaceType_position:
	case IFaceType_int:		lua_pushnumber(L, (lua_Number)ret);	++nret;	break;
	default:
		if( decl->rtype < IFaceTypeMax )
			return luaL_error(L, "not support return type(%s)", iface_type_name[decl->rtype]);
		return luaL_error(L, "not support return type(%d) system error!", decl->rtype);
	}

	if( decl->lparam==IFaceType_stringresult ) {
		lua_pushlstring(L, (const char*)lparam, (size_t)ret);
		++nret;
	}

	return nret;
}

static int _lua_sci_load(lua_State* L) {
	SourceEditor* editor = source_editor_check(L, 1);
	const char* pth = luaL_checkstring(L, 2);
	source_editor_load(editor, pth);
	return 0;
}

static int _lua_sci_save(lua_State* L) {
	SourceEditor* editor = source_editor_check(L, 1);
	const char* pth = luaL_checkstring(L, 2);
	source_editor_save(editor, pth);
	return 0;
}

void lua_source_editor_open(lua_State* L, SourceEditorCheck check) {
	IFaceDecl* p;

	source_editor_check = check ? check : _null_check;

	// __sci__
	lua_newtable(L);

	// __sci__.functions
	lua_newtable(L);
	{
		// fun/get/set
		for( p = sci_functions; p->name; ++p ) {
			lua_pushlightuserdata(L, p);
			lua_pushcclosure(L, _lua_sci_send_wrap, 1);
			lua_pushvalue(L, -1);
			lua_setfield(L, -3, p->name);
			lua_setfield(L, -2, p->alias);
		}

		// source editor functions
		lua_pushcfunction(L, _lua_sci_load);	lua_setfield(L, -2, "source_editor_load");
		lua_pushcfunction(L, _lua_sci_save);	lua_setfield(L, -2, "source_editor_save");
	}
	lua_setfield(L, -2, "functions");

	// __sci__.enums
	lua_newtable(L);
	sci_values_push(L, -1);
	lua_setfield(L, -2, "enums");

	// register SOURCE_EDITOR_TYPE
	lua_pushinteger(L, (lua_Integer)source_editor_get_type());
	lua_setfield(L, -2, "__SOURCE_EDITOR_TYPE__");
	lua_pushstring(L, g_type_name(source_editor_get_type()));
	lua_setfield(L, -2, "__SOURCE_EDITOR_TYPENAME__");

	// set global
	lua_setglobal(L, "__sci__");
}

