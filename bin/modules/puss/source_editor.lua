-- source_editor.lua
-- 

function puss_editor_set_language(editor, lang)
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

