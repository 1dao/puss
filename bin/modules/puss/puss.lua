-- puss.lua
-- 

main_builder = nil
main_window = nil

function puss_modules_open()
end

function on_main_window_delete(w, ...)
	print('on_main_window_delete signal handle!')
	gtk_main_quit()
end

function on_main_window_destroy(w, ...)
	print('on_main_window_destroy signal handle!')
	return true
end

puss_do_module_script('puss/debug_console.lua')
puss_do_module_script('puss/source_editor.lua')

if GTK_MAJOR_VERSION==3 then
	puss_do_module_script('puss/puss_gtk3.lua')
else
	puss_do_module_script('puss/puss_gtk2.lua')
end
