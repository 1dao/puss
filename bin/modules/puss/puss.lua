-- puss.lua
-- 

local root_path, args = ...

local glua = __glua__
local gsci = __gsci__

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

-- local G_APPLICATION_HANDLES_OPEN = (1<<2)

app = glua.GtkApplication('puss.org', G_APPLICATION_HANDLES_OPEN)
app:set_default()

main_builder = nil
main_window = nil

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

function puss_modules_open()
	local editor = glua.Scintilla()
	editor:set_code_page(SC_CP_UTF8)
	editor:style_set_font(STYLE_DEFAULT, "monospace")
	source_editor_set_language(editor, 'cpp')
editor:set_text(nil, [[
#include <stdio.h>

void main(int argc, char* argv[]) {
	return 0;
}
]])

	local sw = glua.GtkScrolledWindow()
	sw:add(editor)
	local doc_panel = main_builder:get_object('doc_panel')
	local label = glua.GtkLabel()
	label:set('label', "test")
	doc_panel:append_page(sw, label)

	editor:grab_focus()
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
		puss_modules_open()
		main_window:show_all()
	end
end

function puss_app_activate(...)
	print('activate', ...)
	puss_main_window_open()
end

function puss_app_open(...)
	print('open', ...)
	puss_main_window_open()
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
