-- puss.lua
-- 

do
	local enums = __sci__.enums
	setmetatable( _ENV, { __index = function(t,k) return rawget(t,k) or rawget(enums,k) end })
end

local gobject = __gobject__
local gobject_metatables = gobject.gtype_get_metatables()

gobject_metatables.GObject =
	{ get = gobject.get
	, set = gobject.set
	, connect = gobject.signal_connect
	}

-- for k,v in pairs(gobject.gtype_get_metatables()) do print(k,v) end

setmetatable(gobject_metatables.GtkWidget, { __index = gobject_metatables.GObject } )
setmetatable(gobject_metatables.GtkContainer, { __index = gobject_metatables.GtkWidget } )
setmetatable(gobject_metatables.GtkNotebook, { __index = gobject_metatables.GtkContainer } )

do
	local source_editor_gtypename = __sci__.__SOURCE_EDITOR_TYPENAME__
	local source_editor_metatable = __sci__.functions
	gobject_metatables[source_editor_gtypename] = source_editor_metatable
	setmetatable(source_editor_metatable, { __index = gobject_metatables.GtkWidget } )
end

-- for k,v in pairs(gobject.gtype_get_metatables()) do print(k,v) end

local puss = __script_system__.__puss__

__script_system__.__modules__ = { puss = __script_system__.puss }

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

local function source_editor_new(label, lang)
	local editor = puss.source_editor_page_new(label)
	editor:set_code_page(SC_CP_UTF8)
	editor:style_set_font(STYLE_DEFAULT, "monospace")
	source_editor_set_language(editor, lang)
	return editor
end

__script_system__.activate = function()
	local editor = source_editor_new('noname.c', 'cpp')
end

__script_system__.open = function(files, hint)
	m = __script_system__.load_module('filebrowser')

	for _, f in ipairs(files) do
		-- local cxt = __script_system__.__root_vfs__:load_utf8(f)
		local editor = source_editor_new(f, 'cpp')
		editor:source_editor_load(f)
		h = editor:connect('focus-in-event', function(w, event, a,b,c,d)
				print('XXXXX', editor, w, event, a,b,c,d)
			end)
		ed = editor
	end

	-- for _,v in ipairs(gobject.gtype_list_properties('SourceEditor')) do print(v:name(), ed[v:name()]) end
	-- print('editor visible = ' .. tostring(ed.visible))
end
