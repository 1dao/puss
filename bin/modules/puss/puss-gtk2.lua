-- puss_gtk2.lua
-- 

__module_exports__.main_builder = load_glade()
__module_exports__.main_window = main_builder:get_object('main_window')
if os.getenv('PUSS_DEBUG') then
	puss_debug_panel_open()
end
puss_modules_open()
main_builder:connect_signals(_ENV)
main_window:show_all()

gtk_main()

