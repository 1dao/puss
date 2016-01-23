-- puss.lua
-- 

main_builder = nil
main_window = nil

function puss_modules_open()
	-- TODO 
end

function on_main_window_delete(w, ...)
	print('on_main_window_delete signal handle!')
	gtk_main_quit()
end

function on_main_window_destroy(w, ...)
	print('on_main_window_destroy signal handle!')
	return true
end

dofile('debug_console.lua')
dofile('source_editor.lua')

if GTK_MAJOR_VERSION==3 then
	dofile('puss_gtk3.lua')
else
	dofile('puss_gtk2.lua')
end
