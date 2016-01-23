-- puss_gtk3.lua
-- 

local glua = __glua__

local function puss_main_window_open(ui_file)
	assert( main_builder==nil, 'not support open twice!' )
	main_builder = gtk_builder_new()
	main_builder:add_from_file( string.format('%s/%s', puss_fetch_root_path(), ui_file) )
	main_window = main_builder:get_object('main_window')
	main_builder:connect_signals(_ENV)
	if os.getenv('PUSS_DEBUG') then
		puss_debug_panel_open()
	end
	puss_modules_open()
	main_window:show_all()
end

local function puss_app_activate(...)
	print('activate', ...)
	if not main_window then
		puss_main_window_open('modules/puss/puss_main_window_gtk3.ui')
		app:add_window(main_window)

		local editor = puss_editor_new('noname')
		puss_editor_set_language(editor, 'cpp')
	end

	main_window.window:raise()
end

local function puss_open_from_gfile(gfile)
	local editor = puss_editor_new(gfile:get_basename())
	puss_editor_set_language(editor, 'cpp')
	local cxt = g_file_get_content(gfile:get_path())
	editor:set_text(nil, cxt)
	return editor
end

local function puss_app_open(app, files, nfiles, hint)
	print('open', app, files, nfiles, hint, #hint)
	if not main_window then
		puss_main_window_open('modules/puss/puss_main_window_gtk3.ui')
		app:add_window(main_window)
	end

	local t = glua.gobject_array_pointer_parse(files, nfiles)
	for i,v in ipairs(t) do
		-- print('open', app, files, nfiles, hint, #hint)
		puss_open_from_gfile(v)
	end
end

app = gtk_application_new('puss.org', G_APPLICATION_HANDLES_OPEN)
app:set_default()
app:signal_connect('activate', puss_app_activate)
app:signal_connect('open', puss_app_open)

local args = puss_fetch_args()
app:run(args:len(), args)

