-- puss.lua
-- 

local root_path, args = ...

glua = __glua__
gsci = __gsci__

do
	local enums = {}
	for etype, values in pairs(glua.enums) do
		for k,v in pairs(values) do enums[k]=v end
	end
	local gsci_enums = gsci.enums
	setmetatable( _ENV, { __index = function(t,k) return rawget(t,k) or rawget(enums,k) or rawget(gsci_enums,k) end })
end

do
	local g_types = glua.types
	local g_new = glua.new

	local function glua_index(t,k)
		local tp = g_types[k]
		if tp and tp.new then return tp.new end			-- use glua.types.SomeType.new
		return function(...) return g_new(k, ...) end	-- use glua.new('SomeType') 
	end

	setmetatable(glua, { __index=glua_index })
end

app = glua.GtkApplication('puss.org', G_APPLICATION_HANDLES_OPEN)
app:set_default()

main_builder = nil
main_window = nil

local function debug_script_invoke(script)
	load(script)()
end

local function puss_debug_panel_open()
	local tv = glua.GtkTextView()
	tv.buffer.text = '-- press ctrl+enter run script, do not forget add environ PUSS_DEBUG=1\nfor k,v in pairs(glua.types) do print(k,v) end\n'

	tv:signal_connect('key-release-event', function(view, ev)
		local st, kc = select(2, ev:get_state()), select(2, ev:get_keycode())
		if st==GDK_CONTROL_MASK and (kc==string.byte('\r') or kc==string.byte('\n')) then
			local text = view.buffer.text
			local ok,err = xpcall(debug_script_invoke, function(e) return debug.traceback(e,2) end, text)
			if not ok then print(err) end
		end
	end)

	local sw = glua.GtkScrolledWindow()
	sw:add(tv)
	local bottom_panel = main_builder:get_object('bottom_panel')
	local label = glua.GtkLabel()
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
	local editor = glua.Scintilla()
	editor:set_code_page(SC_CP_UTF8)
	editor:style_set_font(STYLE_DEFAULT, "monospace")
	local sw = glua.GtkScrolledWindow()
	sw:add(editor)
	local doc_panel = main_builder:get_object('doc_panel')
	local label_widget = glua.GtkLabel()
	label_widget.label = label
	doc_panel:append_page(sw, label_widget)
	sw:show_all()
	return editor
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

function puss_modules_open()
end

function on_main_window_destroy(w, ...)
	print('main window destroy signal handle!')
	return true
end

function puss_main_window_open()
	if not main_builder then
		main_builder = glua.GtkBuilder()
		main_builder:add_from_file(root_path .. '/modules/puss/puss_main_window.ui')
		main_window = main_builder:get_object('main_window')
		app:add_window(main_window)
		main_builder:connect_signals(_ENV)
		if os.getenv('PUSS_DEBUG') then
			puss_debug_panel_open()
		end
		puss_modules_open()
		main_window:show_all()
	end
end

function puss_app_activate(...)
	-- print('activate', ...)
	puss_main_window_open()

	local editor = puss_editor_new('noname')
	source_editor_set_language(editor, 'cpp')

editor:set_text(nil, [[
#include <stdio.h>

void main(int argc, char* argv[]) {
	return 0;
}
]])

end

function puss_app_open(app, files, nfiles, hint)
	-- print('open', app, files, nfiles, hint, #hint)
	puss_main_window_open()
	local t = glua.gobject_array_pointer_parse(files, nfiles)
	for i,v in ipairs(t) do
		puss_open_from_gfile(v)
	end
end

app:signal_connect('activate', puss_app_activate)
app:signal_connect('open', puss_app_open)

-- glua.types.GStrv.new({'aaa','bbb','ccc'})

app:run(args:len(), args)

--[===[

__script_system__.load_module = function(name)
	local pm = __script_system__.__modules__[name]
	if not pm then
		local pth = 'modules/' .. name
		pm = puss.module_create(name, pth .. '/' .. name)
	end
	return pm
end

__script_system__.load_plugin = function(name)
	local pg = __script_system__.__plugins__[name]
	if not pg then
		local pth = 'modules/' .. name
		pg = {}
		setmetatable(pg, { __index=_ENV })
		__script_system__.dofile(pth .. '/' .. name .. '.plugin', pg)
	end
	return pg
end

--]===]
