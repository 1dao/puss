// source_editor.h
//

#ifndef __PUSS_INC_SOURCE_EDITOR_H__
#define __PUSS_INC_SOURCE_EDITOR_H__

#include <stdlib.h>
#include <glib.h>
#include <gtk/gtk.h>

#ifdef __cplusplus
extern "C" {
#endif

#include <lua.h>

#define SOURCE_EDITOR(obj)		G_TYPE_CHECK_INSTANCE_CAST(obj, source_editor_get_type(), SourceEditor)
#define IS_SOURCE_EDITOR(obj)	G_TYPE_CHECK_INSTANCE_TYPE(obj, source_editor_get_type())

typedef struct _SourceEditor	SourceEditor;

void			source_editor_release_resources(void);

GType			source_editor_get_type(void);

SourceEditor*	source_editor_new(void);

gboolean		source_editor_modified(SourceEditor* editor);
gboolean		source_editor_load(SourceEditor* editor, const gchar* filename);
gboolean		source_editor_save(SourceEditor* editor, const gchar* filename);
void			source_editor_set_text(SourceEditor* editor, const gchar* text, gsize len);

gchar*			source_editor_format_diskfile_filename(const gchar* filename);
void			source_editor_reset_charset_guess(const char* guess_list);		// "GBK;ISO-8859-1;BIG5" ...

// lua wrapper
// 
typedef SourceEditor*	(*SourceEditorCheck)(lua_State* L, int idx);

// create __sci__ for enums & source editor functions
// use source_editor_check() check SourceEditor* from lua_State
// 
void			lua_source_editor_open(lua_State* L, SourceEditorCheck check);

#ifdef __cplusplus
}
#endif

#endif//__PUSS_INC_SOURCE_EDITOR_H__

