-- puss.lua
-- 

dofile('debug_console.lua')
dofile('source_editor.lua')

function puss_modules_open()
	-- TODO :
	puss_load_module('filebrowser')
end

function on_main_window_delete(w, ...)
	print('on_main_window_delete signal handle!')
	gtk_main_quit()
end

function on_main_window_destroy(w, ...)
	print('on_main_window_destroy signal handle!')
	return true
end

__module_exports__.open_file = function(label, filename, line)
	local editor = puss_editor_new(label)
	puss_editor_set_language(editor, 'cpp')
	local cxt = g_file_get_content(filename)
	editor:set_text(nil, cxt)
	return editor
end

if GTK_MAJOR_VERSION==3 then
	dofile('puss-gtk3.lua')
else
	dofile('puss-gtk2.lua')
end
