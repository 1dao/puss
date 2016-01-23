-- puss_gtk2.lua
-- 

main_builder = gtk_builder_new()
main_builder:add_from_file( string.format('%s/%s', puss_fetch_root_path(), 'modules/puss/puss_main_window_gtk2.ui') )
main_window = main_builder:get_object('main_window')
if os.getenv('PUSS_DEBUG') then
	puss_debug_panel_open()
end
puss_modules_open()
main_builder:connect_signals(_ENV)
main_window:show_all()

gtk_main()

