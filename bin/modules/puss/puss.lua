-- puss.lua
-- 

-- init

local g_capis = {}
local g_enums = {}
local gsci_enums = __gsci__.enums

glua = __glua__

-- overwrite methods
do
	local tree_model_get_value = glua.capis.gtk_tree_model_get_value
	glua.capis.gtk_tree_model_get_value = function(model, iter, column)
		local v = glua.gnew_uninit_value()
		tree_model_get_value(model, iter, column, v)
		return v()
	end
	glua.types.GtkTreeModel.get_value = glua.capis.gtk_tree_model_get_value
end

-- load enums
for etype, values in pairs(glua.enums) do
	for k,v in pairs(values) do g_enums[k]=v end
end

-- load capis
g_capis = glua.capis

-- utils
glua.list_methods = function(o)
	ks.log_debug('list methods, gtype name =', glua.gtype_name_from_instance(o) )
	local tp = glua.gtype_from_instance(o)
	if tp then
		local tp = glua.__gtypes__[tp]
		local keys = {}
		for k,v in pairs(tp) do table.insert(keys, k) end
		table.sort(keys)
		for _, k in ipairs(keys) do print('', k, tp[k]) end
	end
end

glua.list_properties = function(o)
	local gtypename = glua.gtype_name_from_instance(o)
	ks.log_debug('list properties, gtype name =', gtypename)
	local props = glua.gtype_list_properties(gtypename) or {}
	local keys = {}
	for _,p in pairs(props) do table.insert(keys, p:name()) end
	table.sort(keys)
	for _, k in ipairs(keys) do print('', k, o:get(k)) end
end

setmetatable( _ENV, {__index=function(t,k) return rawget(g_capis,k) or rawget(g_enums,k) or rawget(gsci_enums,k) end} )

-- start

local root_path, args = ...

main_builder = nil
main_window = nil

local function debug_script_invoke(script)
	load(script)()
end

local function puss_debug_panel_open()
	local tv = gtk_text_view_new()
	tv.buffer.text = '-- press ctrl+enter run script, do not forget add environ PUSS_DEBUG=1\nfor k,v in pairs(glua.types) do print(k,v) end\n'

	local function puss_debug_panel_output(s)
		local txt = tv.buffer.text
		txt = txt .. tostring(s) .. '\n'
		tv.buffer.text = txt
	end
	print = puss_debug_panel_output

	tv:signal_connect('key-release-event', function(view, ev)
		local st, kc = select(2, ev:get_state()), select(2, ev:get_keycode())
		if st==GDK_CONTROL_MASK and (kc==string.byte('\r') or kc==string.byte('\n')) then
			local text = view.buffer.text
			local ok,err = xpcall(debug_script_invoke, function(e) return debug.traceback(e,2) end, text)
			if not ok then puss_debug_panel_output('ERROR : ' .. err .. '\n\n') end
		end
	end)

	local sw = gtk_scrolled_window_new()
	sw:add(tv)
	local bottom_panel = main_builder:get_object('bottom_panel')
	local label = gtk_label_new()
	label.label = 'debug'
	bottom_panel:append_page(sw, label)
end

local function source_editor_set_language(editor, lang)
	editor:set_lexer_language(nil, lang)
	if lang=='cpp' then
		local cpp_keywords = [[
			asm auto bool break case catch char class const 
			const_cast continue default delete do double 
			dynamic_cast else enum explicit extern false finally 
			float for friend goto if inline int long mutable 
			namespace new operator private protected public 
			register reinterpret_cast register return short signed 
			sizeof static static_cast struct switch template 
			this throw true try typedef typeid typename 
			union unsigned using virtual void volatile 
			wchar_t while
			]]

		editor:set_key_words(0, cpp_keywords)
		editor:style_set_fore(SCE_C_WORD, 0x00FF0000);
		editor:style_set_fore(SCE_C_STRING, 0x001515A3);
		editor:style_set_fore(SCE_C_CHARACTER, 0x00FF0000);
		editor:style_set_fore(SCE_C_PREPROCESSOR, 0x00808080);
		editor:style_set_fore(SCE_C_COMMENT, 0x00808080);
		editor:style_set_fore(SCE_C_COMMENTLINE, 0x00008000);
		editor:style_set_fore(SCE_C_COMMENTDOC, 0x00008000);
	end
end

function puss_editor_new(label)
	local editor = gtk_scintilla_new()
	editor:set_code_page(SC_CP_UTF8)
	editor:style_set_font(STYLE_DEFAULT, "monospace")
	local sw = gtk_scrolled_window_new()
	sw:add(editor)
	local doc_panel = main_builder:get_object('doc_panel')
	local label_widget = gtk_label_new()
	label_widget.label = label
	doc_panel:append_page(sw, label_widget)
	sw:show_all()
	return editor
end

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

function puss_main_window_open(ui_file)
	if not main_builder then
		main_builder = gtk_builder_new()
		main_builder:add_from_file(ui_file)
		main_window = main_builder:get_object('main_window')
		main_builder:connect_signals(_ENV)
		if os.getenv('PUSS_DEBUG') then
			puss_debug_panel_open()
		end
		puss_modules_open()
		main_window:show_all()
	end
end

if GTK_MAJOR_VERSION==3 then

	local function puss_app_activate(...)
		-- print('activate', ...)
		puss_main_window_open(root_path .. '/modules/puss/puss_main_window_gtk3.ui')
		app:add_window(main_window)

		local editor = puss_editor_new('noname')
		source_editor_set_language(editor, 'cpp')

		editor:set_text(nil, '#include <stdio.h>' ..
				'' ..
				'void main(int argc, char* argv[]) {' .. 
				'	return 0;' .. 
				'}' .. 
				'')
	end

	local function puss_app_open(app, files, nfiles, hint)
		-- print('open', app, files, nfiles, hint, #hint)
		puss_main_window_open(root_path .. '/modules/puss/puss_main_window_gtk3.ui')
		app:add_window(main_window)

		local t = glua.gobject_array_pointer_parse(files, nfiles)
		for i,v in ipairs(t) do
			-- print('open', app, files, nfiles, hint, #hint)
			puss_open_from_gfile(v)
		end
	end

	function puss_open_from_gfile(gfile)
		local editor = puss_editor_new(gfile:get_basename())
		source_editor_set_language(editor, 'cpp')
		local f = io.open(gfile:get_path(), 'r')
		local cxt = f:read('*a')
		f:close()
		editor:set_text(nil, cxt)
		return editor
	end

	app = gtk_application_new('puss.org', G_APPLICATION_HANDLES_OPEN)
	app:set_default()
	app:signal_connect('activate', puss_app_activate)
	app:signal_connect('open', puss_app_open)
	app:run(args:len(), args)

else
	-- gtk2 demo
	puss_main_window_open(root_path .. '/modules/puss/puss_main_window_gtk2.ui')
	gtk_main()
end

