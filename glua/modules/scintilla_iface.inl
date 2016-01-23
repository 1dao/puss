// NOTICE : generate by scintilla_face.lua
static IFaceDecl sci_functions[] =
	{ { "AddText", "add_text", 2001, IFaceType_void, IFaceType_int, IFaceType_string }
	, { "AddStyledText", "add_styled_text", 2002, IFaceType_void, IFaceType_int, IFaceType_cells }
	, { "InsertText", "insert_text", 2003, IFaceType_void, IFaceType_position, IFaceType_string }
	, { "ChangeInsertion", "change_insertion", 2672, IFaceType_void, IFaceType_int, IFaceType_string }
	, { "ClearAll", "clear_all", 2004, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "DeleteRange", "delete_range", 2645, IFaceType_void, IFaceType_position, IFaceType_int }
	, { "ClearDocumentStyle", "clear_document_style", 2005, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "GetLength", "get_length", 2006, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "GetCharAt", "get_char_at", 2007, IFaceType_int, IFaceType_position, IFaceType_void }
	, { "GetCurrentPos", "get_current_pos", 2008, IFaceType_position, IFaceType_void, IFaceType_void }
	, { "GetAnchor", "get_anchor", 2009, IFaceType_position, IFaceType_void, IFaceType_void }
	, { "GetStyleAt", "get_style_at", 2010, IFaceType_int, IFaceType_position, IFaceType_void }
	, { "Redo", "redo", 2011, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "SetUndoCollection", "set_undo_collection", 2012, IFaceType_void, IFaceType_bool, IFaceType_void }
	, { "SelectAll", "select_all", 2013, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "SetSavePoint", "set_save_point", 2014, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "GetStyledText", "get_styled_text", 2015, IFaceType_int, IFaceType_void, IFaceType_textrange }
	, { "CanRedo", "can_redo", 2016, IFaceType_bool, IFaceType_void, IFaceType_void }
	, { "MarkerLineFromHandle", "marker_line_from_handle", 2017, IFaceType_int, IFaceType_int, IFaceType_void }
	, { "MarkerDeleteHandle", "marker_delete_handle", 2018, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetUndoCollection", "get_undo_collection", 2019, IFaceType_bool, IFaceType_void, IFaceType_void }
	, { "GetViewWS", "get_view_ws", 2020, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetViewWS", "set_view_ws", 2021, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "PositionFromPoint", "position_from_point", 2022, IFaceType_position, IFaceType_int, IFaceType_int }
	, { "PositionFromPointClose", "position_from_point_close", 2023, IFaceType_position, IFaceType_int, IFaceType_int }
	, { "GotoLine", "goto_line", 2024, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GotoPos", "goto_pos", 2025, IFaceType_void, IFaceType_position, IFaceType_void }
	, { "SetAnchor", "set_anchor", 2026, IFaceType_void, IFaceType_position, IFaceType_void }
	, { "GetCurLine", "get_cur_line", 2027, IFaceType_int, IFaceType_int, IFaceType_stringresult }
	, { "GetEndStyled", "get_end_styled", 2028, IFaceType_position, IFaceType_void, IFaceType_void }
	, { "ConvertEOLs", "convert_eo_ls", 2029, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetEOLMode", "get_eol_mode", 2030, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetEOLMode", "set_eol_mode", 2031, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "StartStyling", "start_styling", 2032, IFaceType_void, IFaceType_position, IFaceType_int }
	, { "SetStyling", "set_styling", 2033, IFaceType_void, IFaceType_int, IFaceType_int }
	, { "GetBufferedDraw", "get_buffered_draw", 2034, IFaceType_bool, IFaceType_void, IFaceType_void }
	, { "SetBufferedDraw", "set_buffered_draw", 2035, IFaceType_void, IFaceType_bool, IFaceType_void }
	, { "SetTabWidth", "set_tab_width", 2036, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetTabWidth", "get_tab_width", 2121, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "ClearTabStops", "clear_tab_stops", 2675, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "AddTabStop", "add_tab_stop", 2676, IFaceType_void, IFaceType_int, IFaceType_int }
	, { "GetNextTabStop", "get_next_tab_stop", 2677, IFaceType_int, IFaceType_int, IFaceType_int }
	, { "SetCodePage", "set_code_page", 2037, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetIMEInteraction", "get_ime_interaction", 2678, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetIMEInteraction", "set_ime_interaction", 2679, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "MarkerDefine", "marker_define", 2040, IFaceType_void, IFaceType_int, IFaceType_int }
	, { "MarkerSetFore", "marker_set_fore", 2041, IFaceType_void, IFaceType_int, IFaceType_colour }
	, { "MarkerSetBack", "marker_set_back", 2042, IFaceType_void, IFaceType_int, IFaceType_colour }
	, { "MarkerSetBackSelected", "marker_set_back_selected", 2292, IFaceType_void, IFaceType_int, IFaceType_colour }
	, { "MarkerEnableHighlight", "marker_enable_highlight", 2293, IFaceType_void, IFaceType_bool, IFaceType_void }
	, { "MarkerAdd", "marker_add", 2043, IFaceType_int, IFaceType_int, IFaceType_int }
	, { "MarkerDelete", "marker_delete", 2044, IFaceType_void, IFaceType_int, IFaceType_int }
	, { "MarkerDeleteAll", "marker_delete_all", 2045, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "MarkerGet", "marker_get", 2046, IFaceType_int, IFaceType_int, IFaceType_void }
	, { "MarkerNext", "marker_next", 2047, IFaceType_int, IFaceType_int, IFaceType_int }
	, { "MarkerPrevious", "marker_previous", 2048, IFaceType_int, IFaceType_int, IFaceType_int }
	, { "MarkerDefinePixmap", "marker_define_pixmap", 2049, IFaceType_void, IFaceType_int, IFaceType_string }
	, { "MarkerAddSet", "marker_add_set", 2466, IFaceType_void, IFaceType_int, IFaceType_int }
	, { "MarkerSetAlpha", "marker_set_alpha", 2476, IFaceType_void, IFaceType_int, IFaceType_int }
	, { "SetMarginTypeN", "set_margin_type_n", 2240, IFaceType_void, IFaceType_int, IFaceType_int }
	, { "GetMarginTypeN", "get_margin_type_n", 2241, IFaceType_int, IFaceType_int, IFaceType_void }
	, { "SetMarginWidthN", "set_margin_width_n", 2242, IFaceType_void, IFaceType_int, IFaceType_int }
	, { "GetMarginWidthN", "get_margin_width_n", 2243, IFaceType_int, IFaceType_int, IFaceType_void }
	, { "SetMarginMaskN", "set_margin_mask_n", 2244, IFaceType_void, IFaceType_int, IFaceType_int }
	, { "GetMarginMaskN", "get_margin_mask_n", 2245, IFaceType_int, IFaceType_int, IFaceType_void }
	, { "SetMarginSensitiveN", "set_margin_sensitive_n", 2246, IFaceType_void, IFaceType_int, IFaceType_bool }
	, { "GetMarginSensitiveN", "get_margin_sensitive_n", 2247, IFaceType_bool, IFaceType_int, IFaceType_void }
	, { "SetMarginCursorN", "set_margin_cursor_n", 2248, IFaceType_void, IFaceType_int, IFaceType_int }
	, { "GetMarginCursorN", "get_margin_cursor_n", 2249, IFaceType_int, IFaceType_int, IFaceType_void }
	, { "StyleClearAll", "style_clear_all", 2050, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "StyleSetFore", "style_set_fore", 2051, IFaceType_void, IFaceType_int, IFaceType_colour }
	, { "StyleSetBack", "style_set_back", 2052, IFaceType_void, IFaceType_int, IFaceType_colour }
	, { "StyleSetBold", "style_set_bold", 2053, IFaceType_void, IFaceType_int, IFaceType_bool }
	, { "StyleSetItalic", "style_set_italic", 2054, IFaceType_void, IFaceType_int, IFaceType_bool }
	, { "StyleSetSize", "style_set_size", 2055, IFaceType_void, IFaceType_int, IFaceType_int }
	, { "StyleSetFont", "style_set_font", 2056, IFaceType_void, IFaceType_int, IFaceType_string }
	, { "StyleSetEOLFilled", "style_set_eol_filled", 2057, IFaceType_void, IFaceType_int, IFaceType_bool }
	, { "StyleResetDefault", "style_reset_default", 2058, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "StyleSetUnderline", "style_set_underline", 2059, IFaceType_void, IFaceType_int, IFaceType_bool }
	, { "StyleGetFore", "style_get_fore", 2481, IFaceType_colour, IFaceType_int, IFaceType_void }
	, { "StyleGetBack", "style_get_back", 2482, IFaceType_colour, IFaceType_int, IFaceType_void }
	, { "StyleGetBold", "style_get_bold", 2483, IFaceType_bool, IFaceType_int, IFaceType_void }
	, { "StyleGetItalic", "style_get_italic", 2484, IFaceType_bool, IFaceType_int, IFaceType_void }
	, { "StyleGetSize", "style_get_size", 2485, IFaceType_int, IFaceType_int, IFaceType_void }
	, { "StyleGetFont", "style_get_font", 2486, IFaceType_int, IFaceType_int, IFaceType_stringresult }
	, { "StyleGetEOLFilled", "style_get_eol_filled", 2487, IFaceType_bool, IFaceType_int, IFaceType_void }
	, { "StyleGetUnderline", "style_get_underline", 2488, IFaceType_bool, IFaceType_int, IFaceType_void }
	, { "StyleGetCase", "style_get_case", 2489, IFaceType_int, IFaceType_int, IFaceType_void }
	, { "StyleGetCharacterSet", "style_get_character_set", 2490, IFaceType_int, IFaceType_int, IFaceType_void }
	, { "StyleGetVisible", "style_get_visible", 2491, IFaceType_bool, IFaceType_int, IFaceType_void }
	, { "StyleGetChangeable", "style_get_changeable", 2492, IFaceType_bool, IFaceType_int, IFaceType_void }
	, { "StyleGetHotSpot", "style_get_hot_spot", 2493, IFaceType_bool, IFaceType_int, IFaceType_void }
	, { "StyleSetCase", "style_set_case", 2060, IFaceType_void, IFaceType_int, IFaceType_int }
	, { "StyleSetSizeFractional", "style_set_size_fractional", 2061, IFaceType_void, IFaceType_int, IFaceType_int }
	, { "StyleGetSizeFractional", "style_get_size_fractional", 2062, IFaceType_int, IFaceType_int, IFaceType_void }
	, { "StyleSetWeight", "style_set_weight", 2063, IFaceType_void, IFaceType_int, IFaceType_int }
	, { "StyleGetWeight", "style_get_weight", 2064, IFaceType_int, IFaceType_int, IFaceType_void }
	, { "StyleSetCharacterSet", "style_set_character_set", 2066, IFaceType_void, IFaceType_int, IFaceType_int }
	, { "StyleSetHotSpot", "style_set_hot_spot", 2409, IFaceType_void, IFaceType_int, IFaceType_bool }
	, { "SetSelFore", "set_sel_fore", 2067, IFaceType_void, IFaceType_bool, IFaceType_colour }
	, { "SetSelBack", "set_sel_back", 2068, IFaceType_void, IFaceType_bool, IFaceType_colour }
	, { "GetSelAlpha", "get_sel_alpha", 2477, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetSelAlpha", "set_sel_alpha", 2478, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetSelEOLFilled", "get_sel_eol_filled", 2479, IFaceType_bool, IFaceType_void, IFaceType_void }
	, { "SetSelEOLFilled", "set_sel_eol_filled", 2480, IFaceType_void, IFaceType_bool, IFaceType_void }
	, { "SetCaretFore", "set_caret_fore", 2069, IFaceType_void, IFaceType_colour, IFaceType_void }
	, { "AssignCmdKey", "assign_cmd_key", 2070, IFaceType_void, IFaceType_keymod, IFaceType_int }
	, { "ClearCmdKey", "clear_cmd_key", 2071, IFaceType_void, IFaceType_keymod, IFaceType_void }
	, { "ClearAllCmdKeys", "clear_all_cmd_keys", 2072, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "SetStylingEx", "set_styling_ex", 2073, IFaceType_void, IFaceType_int, IFaceType_string }
	, { "StyleSetVisible", "style_set_visible", 2074, IFaceType_void, IFaceType_int, IFaceType_bool }
	, { "GetCaretPeriod", "get_caret_period", 2075, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetCaretPeriod", "set_caret_period", 2076, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "SetWordChars", "set_word_chars", 2077, IFaceType_void, IFaceType_void, IFaceType_string }
	, { "GetWordChars", "get_word_chars", 2646, IFaceType_int, IFaceType_void, IFaceType_stringresult }
	, { "BeginUndoAction", "begin_undo_action", 2078, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "EndUndoAction", "end_undo_action", 2079, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "IndicSetStyle", "indic_set_style", 2080, IFaceType_void, IFaceType_int, IFaceType_int }
	, { "IndicGetStyle", "indic_get_style", 2081, IFaceType_int, IFaceType_int, IFaceType_void }
	, { "IndicSetFore", "indic_set_fore", 2082, IFaceType_void, IFaceType_int, IFaceType_colour }
	, { "IndicGetFore", "indic_get_fore", 2083, IFaceType_colour, IFaceType_int, IFaceType_void }
	, { "IndicSetUnder", "indic_set_under", 2510, IFaceType_void, IFaceType_int, IFaceType_bool }
	, { "IndicGetUnder", "indic_get_under", 2511, IFaceType_bool, IFaceType_int, IFaceType_void }
	, { "IndicSetHoverStyle", "indic_set_hover_style", 2680, IFaceType_void, IFaceType_int, IFaceType_int }
	, { "IndicGetHoverStyle", "indic_get_hover_style", 2681, IFaceType_int, IFaceType_int, IFaceType_void }
	, { "IndicSetHoverFore", "indic_set_hover_fore", 2682, IFaceType_void, IFaceType_int, IFaceType_colour }
	, { "IndicGetHoverFore", "indic_get_hover_fore", 2683, IFaceType_colour, IFaceType_int, IFaceType_void }
	, { "IndicSetFlags", "indic_set_flags", 2684, IFaceType_void, IFaceType_int, IFaceType_int }
	, { "IndicGetFlags", "indic_get_flags", 2685, IFaceType_int, IFaceType_int, IFaceType_void }
	, { "SetWhitespaceFore", "set_whitespace_fore", 2084, IFaceType_void, IFaceType_bool, IFaceType_colour }
	, { "SetWhitespaceBack", "set_whitespace_back", 2085, IFaceType_void, IFaceType_bool, IFaceType_colour }
	, { "SetWhitespaceSize", "set_whitespace_size", 2086, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetWhitespaceSize", "get_whitespace_size", 2087, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetStyleBits", "set_style_bits", 2090, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetStyleBits", "get_style_bits", 2091, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetLineState", "set_line_state", 2092, IFaceType_void, IFaceType_int, IFaceType_int }
	, { "GetLineState", "get_line_state", 2093, IFaceType_int, IFaceType_int, IFaceType_void }
	, { "GetMaxLineState", "get_max_line_state", 2094, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "GetCaretLineVisible", "get_caret_line_visible", 2095, IFaceType_bool, IFaceType_void, IFaceType_void }
	, { "SetCaretLineVisible", "set_caret_line_visible", 2096, IFaceType_void, IFaceType_bool, IFaceType_void }
	, { "GetCaretLineBack", "get_caret_line_back", 2097, IFaceType_colour, IFaceType_void, IFaceType_void }
	, { "SetCaretLineBack", "set_caret_line_back", 2098, IFaceType_void, IFaceType_colour, IFaceType_void }
	, { "StyleSetChangeable", "style_set_changeable", 2099, IFaceType_void, IFaceType_int, IFaceType_bool }
	, { "AutoCShow", "auto_c_show", 2100, IFaceType_void, IFaceType_int, IFaceType_string }
	, { "AutoCCancel", "auto_c_cancel", 2101, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "AutoCActive", "auto_c_active", 2102, IFaceType_bool, IFaceType_void, IFaceType_void }
	, { "AutoCPosStart", "auto_c_pos_start", 2103, IFaceType_position, IFaceType_void, IFaceType_void }
	, { "AutoCComplete", "auto_c_complete", 2104, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "AutoCStops", "auto_c_stops", 2105, IFaceType_void, IFaceType_void, IFaceType_string }
	, { "AutoCSetSeparator", "auto_c_set_separator", 2106, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "AutoCGetSeparator", "auto_c_get_separator", 2107, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "AutoCSelect", "auto_c_select", 2108, IFaceType_void, IFaceType_void, IFaceType_string }
	, { "AutoCSetCancelAtStart", "auto_c_set_cancel_at_start", 2110, IFaceType_void, IFaceType_bool, IFaceType_void }
	, { "AutoCGetCancelAtStart", "auto_c_get_cancel_at_start", 2111, IFaceType_bool, IFaceType_void, IFaceType_void }
	, { "AutoCSetFillUps", "auto_c_set_fill_ups", 2112, IFaceType_void, IFaceType_void, IFaceType_string }
	, { "AutoCSetChooseSingle", "auto_c_set_choose_single", 2113, IFaceType_void, IFaceType_bool, IFaceType_void }
	, { "AutoCGetChooseSingle", "auto_c_get_choose_single", 2114, IFaceType_bool, IFaceType_void, IFaceType_void }
	, { "AutoCSetIgnoreCase", "auto_c_set_ignore_case", 2115, IFaceType_void, IFaceType_bool, IFaceType_void }
	, { "AutoCGetIgnoreCase", "auto_c_get_ignore_case", 2116, IFaceType_bool, IFaceType_void, IFaceType_void }
	, { "UserListShow", "user_list_show", 2117, IFaceType_void, IFaceType_int, IFaceType_string }
	, { "AutoCSetAutoHide", "auto_c_set_auto_hide", 2118, IFaceType_void, IFaceType_bool, IFaceType_void }
	, { "AutoCGetAutoHide", "auto_c_get_auto_hide", 2119, IFaceType_bool, IFaceType_void, IFaceType_void }
	, { "AutoCSetDropRestOfWord", "auto_c_set_drop_rest_of_word", 2270, IFaceType_void, IFaceType_bool, IFaceType_void }
	, { "AutoCGetDropRestOfWord", "auto_c_get_drop_rest_of_word", 2271, IFaceType_bool, IFaceType_void, IFaceType_void }
	, { "RegisterImage", "register_image", 2405, IFaceType_void, IFaceType_int, IFaceType_string }
	, { "ClearRegisteredImages", "clear_registered_images", 2408, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "AutoCGetTypeSeparator", "auto_c_get_type_separator", 2285, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "AutoCSetTypeSeparator", "auto_c_set_type_separator", 2286, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "AutoCSetMaxWidth", "auto_c_set_max_width", 2208, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "AutoCGetMaxWidth", "auto_c_get_max_width", 2209, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "AutoCSetMaxHeight", "auto_c_set_max_height", 2210, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "AutoCGetMaxHeight", "auto_c_get_max_height", 2211, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetIndent", "set_indent", 2122, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetIndent", "get_indent", 2123, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetUseTabs", "set_use_tabs", 2124, IFaceType_void, IFaceType_bool, IFaceType_void }
	, { "GetUseTabs", "get_use_tabs", 2125, IFaceType_bool, IFaceType_void, IFaceType_void }
	, { "SetLineIndentation", "set_line_indentation", 2126, IFaceType_void, IFaceType_int, IFaceType_int }
	, { "GetLineIndentation", "get_line_indentation", 2127, IFaceType_int, IFaceType_int, IFaceType_void }
	, { "GetLineIndentPosition", "get_line_indent_position", 2128, IFaceType_position, IFaceType_int, IFaceType_void }
	, { "GetColumn", "get_column", 2129, IFaceType_int, IFaceType_position, IFaceType_void }
	, { "CountCharacters", "count_characters", 2633, IFaceType_int, IFaceType_int, IFaceType_int }
	, { "SetHScrollBar", "set_h_scroll_bar", 2130, IFaceType_void, IFaceType_bool, IFaceType_void }
	, { "GetHScrollBar", "get_h_scroll_bar", 2131, IFaceType_bool, IFaceType_void, IFaceType_void }
	, { "SetIndentationGuides", "set_indentation_guides", 2132, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetIndentationGuides", "get_indentation_guides", 2133, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetHighlightGuide", "set_highlight_guide", 2134, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetHighlightGuide", "get_highlight_guide", 2135, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "GetLineEndPosition", "get_line_end_position", 2136, IFaceType_position, IFaceType_int, IFaceType_void }
	, { "GetCodePage", "get_code_page", 2137, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "GetCaretFore", "get_caret_fore", 2138, IFaceType_colour, IFaceType_void, IFaceType_void }
	, { "GetReadOnly", "get_read_only", 2140, IFaceType_bool, IFaceType_void, IFaceType_void }
	, { "SetCurrentPos", "set_current_pos", 2141, IFaceType_void, IFaceType_position, IFaceType_void }
	, { "SetSelectionStart", "set_selection_start", 2142, IFaceType_void, IFaceType_position, IFaceType_void }
	, { "GetSelectionStart", "get_selection_start", 2143, IFaceType_position, IFaceType_void, IFaceType_void }
	, { "SetSelectionEnd", "set_selection_end", 2144, IFaceType_void, IFaceType_position, IFaceType_void }
	, { "GetSelectionEnd", "get_selection_end", 2145, IFaceType_position, IFaceType_void, IFaceType_void }
	, { "SetEmptySelection", "set_empty_selection", 2556, IFaceType_void, IFaceType_position, IFaceType_void }
	, { "SetPrintMagnification", "set_print_magnification", 2146, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetPrintMagnification", "get_print_magnification", 2147, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetPrintColourMode", "set_print_colour_mode", 2148, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetPrintColourMode", "get_print_colour_mode", 2149, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "FindText", "find_text", 2150, IFaceType_position, IFaceType_int, IFaceType_findtext }
	, { "FormatRange", "format_range", 2151, IFaceType_position, IFaceType_bool, IFaceType_formatrange }
	, { "GetFirstVisibleLine", "get_first_visible_line", 2152, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "GetLine", "get_line", 2153, IFaceType_int, IFaceType_int, IFaceType_stringresult }
	, { "GetLineCount", "get_line_count", 2154, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetMarginLeft", "set_margin_left", 2155, IFaceType_void, IFaceType_void, IFaceType_int }
	, { "GetMarginLeft", "get_margin_left", 2156, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetMarginRight", "set_margin_right", 2157, IFaceType_void, IFaceType_void, IFaceType_int }
	, { "GetMarginRight", "get_margin_right", 2158, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "GetModify", "get_modify", 2159, IFaceType_bool, IFaceType_void, IFaceType_void }
	, { "SetSel", "set_sel", 2160, IFaceType_void, IFaceType_position, IFaceType_position }
	, { "GetSelText", "get_sel_text", 2161, IFaceType_int, IFaceType_void, IFaceType_stringresult }
	, { "GetTextRange", "get_text_range", 2162, IFaceType_int, IFaceType_void, IFaceType_textrange }
	, { "HideSelection", "hide_selection", 2163, IFaceType_void, IFaceType_bool, IFaceType_void }
	, { "PointXFromPosition", "point_x_from_position", 2164, IFaceType_int, IFaceType_void, IFaceType_position }
	, { "PointYFromPosition", "point_y_from_position", 2165, IFaceType_int, IFaceType_void, IFaceType_position }
	, { "LineFromPosition", "line_from_position", 2166, IFaceType_int, IFaceType_position, IFaceType_void }
	, { "PositionFromLine", "position_from_line", 2167, IFaceType_position, IFaceType_int, IFaceType_void }
	, { "LineScroll", "line_scroll", 2168, IFaceType_void, IFaceType_int, IFaceType_int }
	, { "ScrollCaret", "scroll_caret", 2169, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "ScrollRange", "scroll_range", 2569, IFaceType_void, IFaceType_position, IFaceType_position }
	, { "ReplaceSel", "replace_sel", 2170, IFaceType_void, IFaceType_void, IFaceType_string }
	, { "SetReadOnly", "set_read_only", 2171, IFaceType_void, IFaceType_bool, IFaceType_void }
	, { "Null", "null", 2172, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "CanPaste", "can_paste", 2173, IFaceType_bool, IFaceType_void, IFaceType_void }
	, { "CanUndo", "can_undo", 2174, IFaceType_bool, IFaceType_void, IFaceType_void }
	, { "EmptyUndoBuffer", "empty_undo_buffer", 2175, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "Undo", "undo", 2176, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "Cut", "cut", 2177, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "Copy", "copy", 2178, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "Paste", "paste", 2179, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "Clear", "clear", 2180, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "SetText", "set_text", 2181, IFaceType_void, IFaceType_void, IFaceType_string }
	, { "GetText", "get_text", 2182, IFaceType_int, IFaceType_int, IFaceType_stringresult }
	, { "GetTextLength", "get_text_length", 2183, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "GetDirectFunction", "get_direct_function", 2184, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "GetDirectPointer", "get_direct_pointer", 2185, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetOvertype", "set_overtype", 2186, IFaceType_void, IFaceType_bool, IFaceType_void }
	, { "GetOvertype", "get_overtype", 2187, IFaceType_bool, IFaceType_void, IFaceType_void }
	, { "SetCaretWidth", "set_caret_width", 2188, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetCaretWidth", "get_caret_width", 2189, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetTargetStart", "set_target_start", 2190, IFaceType_void, IFaceType_position, IFaceType_void }
	, { "GetTargetStart", "get_target_start", 2191, IFaceType_position, IFaceType_void, IFaceType_void }
	, { "SetTargetEnd", "set_target_end", 2192, IFaceType_void, IFaceType_position, IFaceType_void }
	, { "GetTargetEnd", "get_target_end", 2193, IFaceType_position, IFaceType_void, IFaceType_void }
	, { "SetTargetRange", "set_target_range", 2686, IFaceType_void, IFaceType_position, IFaceType_position }
	, { "GetTargetText", "get_target_text", 2687, IFaceType_int, IFaceType_void, IFaceType_stringresult }
	, { "TargetFromSelection", "target_from_selection", 2287, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "TargetWholeDocument", "target_whole_document", 2690, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "ReplaceTarget", "replace_target", 2194, IFaceType_int, IFaceType_int, IFaceType_string }
	, { "ReplaceTargetRE", "replace_target_re", 2195, IFaceType_int, IFaceType_int, IFaceType_string }
	, { "SearchInTarget", "search_in_target", 2197, IFaceType_int, IFaceType_int, IFaceType_string }
	, { "SetSearchFlags", "set_search_flags", 2198, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetSearchFlags", "get_search_flags", 2199, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "CallTipShow", "call_tip_show", 2200, IFaceType_void, IFaceType_position, IFaceType_string }
	, { "CallTipCancel", "call_tip_cancel", 2201, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "CallTipActive", "call_tip_active", 2202, IFaceType_bool, IFaceType_void, IFaceType_void }
	, { "CallTipPosStart", "call_tip_pos_start", 2203, IFaceType_position, IFaceType_void, IFaceType_void }
	, { "CallTipSetPosStart", "call_tip_set_pos_start", 2214, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "CallTipSetHlt", "call_tip_set_hlt", 2204, IFaceType_void, IFaceType_int, IFaceType_int }
	, { "CallTipSetBack", "call_tip_set_back", 2205, IFaceType_void, IFaceType_colour, IFaceType_void }
	, { "CallTipSetFore", "call_tip_set_fore", 2206, IFaceType_void, IFaceType_colour, IFaceType_void }
	, { "CallTipSetForeHlt", "call_tip_set_fore_hlt", 2207, IFaceType_void, IFaceType_colour, IFaceType_void }
	, { "CallTipUseStyle", "call_tip_use_style", 2212, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "CallTipSetPosition", "call_tip_set_position", 2213, IFaceType_void, IFaceType_bool, IFaceType_void }
	, { "VisibleFromDocLine", "visible_from_doc_line", 2220, IFaceType_int, IFaceType_int, IFaceType_void }
	, { "DocLineFromVisible", "doc_line_from_visible", 2221, IFaceType_int, IFaceType_int, IFaceType_void }
	, { "WrapCount", "wrap_count", 2235, IFaceType_int, IFaceType_int, IFaceType_void }
	, { "SetFoldLevel", "set_fold_level", 2222, IFaceType_void, IFaceType_int, IFaceType_int }
	, { "GetFoldLevel", "get_fold_level", 2223, IFaceType_int, IFaceType_int, IFaceType_void }
	, { "GetLastChild", "get_last_child", 2224, IFaceType_int, IFaceType_int, IFaceType_int }
	, { "GetFoldParent", "get_fold_parent", 2225, IFaceType_int, IFaceType_int, IFaceType_void }
	, { "ShowLines", "show_lines", 2226, IFaceType_void, IFaceType_int, IFaceType_int }
	, { "HideLines", "hide_lines", 2227, IFaceType_void, IFaceType_int, IFaceType_int }
	, { "GetLineVisible", "get_line_visible", 2228, IFaceType_bool, IFaceType_int, IFaceType_void }
	, { "GetAllLinesVisible", "get_all_lines_visible", 2236, IFaceType_bool, IFaceType_void, IFaceType_void }
	, { "SetFoldExpanded", "set_fold_expanded", 2229, IFaceType_void, IFaceType_int, IFaceType_bool }
	, { "GetFoldExpanded", "get_fold_expanded", 2230, IFaceType_bool, IFaceType_int, IFaceType_void }
	, { "ToggleFold", "toggle_fold", 2231, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "FoldLine", "fold_line", 2237, IFaceType_void, IFaceType_int, IFaceType_int }
	, { "FoldChildren", "fold_children", 2238, IFaceType_void, IFaceType_int, IFaceType_int }
	, { "ExpandChildren", "expand_children", 2239, IFaceType_void, IFaceType_int, IFaceType_int }
	, { "FoldAll", "fold_all", 2662, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "EnsureVisible", "ensure_visible", 2232, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "SetAutomaticFold", "set_automatic_fold", 2663, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetAutomaticFold", "get_automatic_fold", 2664, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetFoldFlags", "set_fold_flags", 2233, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "EnsureVisibleEnforcePolicy", "ensure_visible_enforce_policy", 2234, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "SetTabIndents", "set_tab_indents", 2260, IFaceType_void, IFaceType_bool, IFaceType_void }
	, { "GetTabIndents", "get_tab_indents", 2261, IFaceType_bool, IFaceType_void, IFaceType_void }
	, { "SetBackSpaceUnIndents", "set_back_space_un_indents", 2262, IFaceType_void, IFaceType_bool, IFaceType_void }
	, { "GetBackSpaceUnIndents", "get_back_space_un_indents", 2263, IFaceType_bool, IFaceType_void, IFaceType_void }
	, { "SetMouseDwellTime", "set_mouse_dwell_time", 2264, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetMouseDwellTime", "get_mouse_dwell_time", 2265, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "WordStartPosition", "word_start_position", 2266, IFaceType_int, IFaceType_position, IFaceType_bool }
	, { "WordEndPosition", "word_end_position", 2267, IFaceType_int, IFaceType_position, IFaceType_bool }
	, { "IsRangeWord", "is_range_word", 2691, IFaceType_bool, IFaceType_position, IFaceType_position }
	, { "SetWrapMode", "set_wrap_mode", 2268, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetWrapMode", "get_wrap_mode", 2269, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetWrapVisualFlags", "set_wrap_visual_flags", 2460, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetWrapVisualFlags", "get_wrap_visual_flags", 2461, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetWrapVisualFlagsLocation", "set_wrap_visual_flags_location", 2462, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetWrapVisualFlagsLocation", "get_wrap_visual_flags_location", 2463, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetWrapStartIndent", "set_wrap_start_indent", 2464, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetWrapStartIndent", "get_wrap_start_indent", 2465, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetWrapIndentMode", "set_wrap_indent_mode", 2472, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetWrapIndentMode", "get_wrap_indent_mode", 2473, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetLayoutCache", "set_layout_cache", 2272, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetLayoutCache", "get_layout_cache", 2273, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetScrollWidth", "set_scroll_width", 2274, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetScrollWidth", "get_scroll_width", 2275, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetScrollWidthTracking", "set_scroll_width_tracking", 2516, IFaceType_void, IFaceType_bool, IFaceType_void }
	, { "GetScrollWidthTracking", "get_scroll_width_tracking", 2517, IFaceType_bool, IFaceType_void, IFaceType_void }
	, { "TextWidth", "text_width", 2276, IFaceType_int, IFaceType_int, IFaceType_string }
	, { "SetEndAtLastLine", "set_end_at_last_line", 2277, IFaceType_void, IFaceType_bool, IFaceType_void }
	, { "GetEndAtLastLine", "get_end_at_last_line", 2278, IFaceType_bool, IFaceType_void, IFaceType_void }
	, { "TextHeight", "text_height", 2279, IFaceType_int, IFaceType_int, IFaceType_void }
	, { "SetVScrollBar", "set_v_scroll_bar", 2280, IFaceType_void, IFaceType_bool, IFaceType_void }
	, { "GetVScrollBar", "get_v_scroll_bar", 2281, IFaceType_bool, IFaceType_void, IFaceType_void }
	, { "AppendText", "append_text", 2282, IFaceType_void, IFaceType_int, IFaceType_string }
	, { "GetTwoPhaseDraw", "get_two_phase_draw", 2283, IFaceType_bool, IFaceType_void, IFaceType_void }
	, { "SetTwoPhaseDraw", "set_two_phase_draw", 2284, IFaceType_void, IFaceType_bool, IFaceType_void }
	, { "GetPhasesDraw", "get_phases_draw", 2673, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetPhasesDraw", "set_phases_draw", 2674, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "SetFontQuality", "set_font_quality", 2611, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetFontQuality", "get_font_quality", 2612, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetFirstVisibleLine", "set_first_visible_line", 2613, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "SetMultiPaste", "set_multi_paste", 2614, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetMultiPaste", "get_multi_paste", 2615, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "GetTag", "get_tag", 2616, IFaceType_int, IFaceType_int, IFaceType_stringresult }
	, { "LinesJoin", "lines_join", 2288, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "LinesSplit", "lines_split", 2289, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "SetFoldMarginColour", "set_fold_margin_colour", 2290, IFaceType_void, IFaceType_bool, IFaceType_colour }
	, { "SetFoldMarginHiColour", "set_fold_margin_hi_colour", 2291, IFaceType_void, IFaceType_bool, IFaceType_colour }
	, { "LineDown", "line_down", 2300, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "LineDownExtend", "line_down_extend", 2301, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "LineUp", "line_up", 2302, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "LineUpExtend", "line_up_extend", 2303, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "CharLeft", "char_left", 2304, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "CharLeftExtend", "char_left_extend", 2305, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "CharRight", "char_right", 2306, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "CharRightExtend", "char_right_extend", 2307, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "WordLeft", "word_left", 2308, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "WordLeftExtend", "word_left_extend", 2309, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "WordRight", "word_right", 2310, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "WordRightExtend", "word_right_extend", 2311, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "Home", "home", 2312, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "HomeExtend", "home_extend", 2313, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "LineEnd", "line_end", 2314, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "LineEndExtend", "line_end_extend", 2315, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "DocumentStart", "document_start", 2316, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "DocumentStartExtend", "document_start_extend", 2317, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "DocumentEnd", "document_end", 2318, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "DocumentEndExtend", "document_end_extend", 2319, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "PageUp", "page_up", 2320, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "PageUpExtend", "page_up_extend", 2321, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "PageDown", "page_down", 2322, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "PageDownExtend", "page_down_extend", 2323, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "EditToggleOvertype", "edit_toggle_overtype", 2324, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "Cancel", "cancel", 2325, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "DeleteBack", "delete_back", 2326, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "Tab", "tab", 2327, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "BackTab", "back_tab", 2328, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "NewLine", "new_line", 2329, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "FormFeed", "form_feed", 2330, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "VCHome", "c_home", 2331, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "VCHomeExtend", "c_home_extend", 2332, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "ZoomIn", "zoom_in", 2333, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "ZoomOut", "zoom_out", 2334, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "DelWordLeft", "del_word_left", 2335, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "DelWordRight", "del_word_right", 2336, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "DelWordRightEnd", "del_word_right_end", 2518, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "LineCut", "line_cut", 2337, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "LineDelete", "line_delete", 2338, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "LineTranspose", "line_transpose", 2339, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "LineDuplicate", "line_duplicate", 2404, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "LowerCase", "lower_case", 2340, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "UpperCase", "upper_case", 2341, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "LineScrollDown", "line_scroll_down", 2342, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "LineScrollUp", "line_scroll_up", 2343, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "DeleteBackNotLine", "delete_back_not_line", 2344, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "HomeDisplay", "home_display", 2345, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "HomeDisplayExtend", "home_display_extend", 2346, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "LineEndDisplay", "line_end_display", 2347, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "LineEndDisplayExtend", "line_end_display_extend", 2348, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "HomeWrap", "home_wrap", 2349, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "HomeWrapExtend", "home_wrap_extend", 2450, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "LineEndWrap", "line_end_wrap", 2451, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "LineEndWrapExtend", "line_end_wrap_extend", 2452, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "VCHomeWrap", "c_home_wrap", 2453, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "VCHomeWrapExtend", "c_home_wrap_extend", 2454, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "LineCopy", "line_copy", 2455, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "MoveCaretInsideView", "move_caret_inside_view", 2401, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "LineLength", "line_length", 2350, IFaceType_int, IFaceType_int, IFaceType_void }
	, { "BraceHighlight", "brace_highlight", 2351, IFaceType_void, IFaceType_position, IFaceType_position }
	, { "BraceHighlightIndicator", "brace_highlight_indicator", 2498, IFaceType_void, IFaceType_bool, IFaceType_int }
	, { "BraceBadLight", "brace_bad_light", 2352, IFaceType_void, IFaceType_position, IFaceType_void }
	, { "BraceBadLightIndicator", "brace_bad_light_indicator", 2499, IFaceType_void, IFaceType_bool, IFaceType_int }
	, { "BraceMatch", "brace_match", 2353, IFaceType_position, IFaceType_position, IFaceType_void }
	, { "GetViewEOL", "get_view_eol", 2355, IFaceType_bool, IFaceType_void, IFaceType_void }
	, { "SetViewEOL", "set_view_eol", 2356, IFaceType_void, IFaceType_bool, IFaceType_void }
	, { "GetDocPointer", "get_doc_pointer", 2357, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetDocPointer", "set_doc_pointer", 2358, IFaceType_void, IFaceType_void, IFaceType_int }
	, { "SetModEventMask", "set_mod_event_mask", 2359, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetEdgeColumn", "get_edge_column", 2360, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetEdgeColumn", "set_edge_column", 2361, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetEdgeMode", "get_edge_mode", 2362, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetEdgeMode", "set_edge_mode", 2363, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetEdgeColour", "get_edge_colour", 2364, IFaceType_colour, IFaceType_void, IFaceType_void }
	, { "SetEdgeColour", "set_edge_colour", 2365, IFaceType_void, IFaceType_colour, IFaceType_void }
	, { "SearchAnchor", "search_anchor", 2366, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "SearchNext", "search_next", 2367, IFaceType_int, IFaceType_int, IFaceType_string }
	, { "SearchPrev", "search_prev", 2368, IFaceType_int, IFaceType_int, IFaceType_string }
	, { "LinesOnScreen", "lines_on_screen", 2370, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "UsePopUp", "use_pop_up", 2371, IFaceType_void, IFaceType_bool, IFaceType_void }
	, { "SelectionIsRectangle", "selection_is_rectangle", 2372, IFaceType_bool, IFaceType_void, IFaceType_void }
	, { "SetZoom", "set_zoom", 2373, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetZoom", "get_zoom", 2374, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "CreateDocument", "create_document", 2375, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "AddRefDocument", "add_ref_document", 2376, IFaceType_void, IFaceType_void, IFaceType_int }
	, { "ReleaseDocument", "release_document", 2377, IFaceType_void, IFaceType_void, IFaceType_int }
	, { "GetModEventMask", "get_mod_event_mask", 2378, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetFocus", "set_focus", 2380, IFaceType_void, IFaceType_bool, IFaceType_void }
	, { "GetFocus", "get_focus", 2381, IFaceType_bool, IFaceType_void, IFaceType_void }
	, { "SetStatus", "set_status", 2382, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetStatus", "get_status", 2383, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetMouseDownCaptures", "set_mouse_down_captures", 2384, IFaceType_void, IFaceType_bool, IFaceType_void }
	, { "GetMouseDownCaptures", "get_mouse_down_captures", 2385, IFaceType_bool, IFaceType_void, IFaceType_void }
	, { "SetCursor", "set_cursor", 2386, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetCursor", "get_cursor", 2387, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetControlCharSymbol", "set_control_char_symbol", 2388, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetControlCharSymbol", "get_control_char_symbol", 2389, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "WordPartLeft", "word_part_left", 2390, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "WordPartLeftExtend", "word_part_left_extend", 2391, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "WordPartRight", "word_part_right", 2392, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "WordPartRightExtend", "word_part_right_extend", 2393, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "SetVisiblePolicy", "set_visible_policy", 2394, IFaceType_void, IFaceType_int, IFaceType_int }
	, { "DelLineLeft", "del_line_left", 2395, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "DelLineRight", "del_line_right", 2396, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "SetXOffset", "set_x_offset", 2397, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetXOffset", "get_x_offset", 2398, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "ChooseCaretX", "choose_caret_x", 2399, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "GrabFocus", "grab_focus", 2400, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "SetXCaretPolicy", "set_x_caret_policy", 2402, IFaceType_void, IFaceType_int, IFaceType_int }
	, { "SetYCaretPolicy", "set_y_caret_policy", 2403, IFaceType_void, IFaceType_int, IFaceType_int }
	, { "SetPrintWrapMode", "set_print_wrap_mode", 2406, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetPrintWrapMode", "get_print_wrap_mode", 2407, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetHotspotActiveFore", "set_hotspot_active_fore", 2410, IFaceType_void, IFaceType_bool, IFaceType_colour }
	, { "GetHotspotActiveFore", "get_hotspot_active_fore", 2494, IFaceType_colour, IFaceType_void, IFaceType_void }
	, { "SetHotspotActiveBack", "set_hotspot_active_back", 2411, IFaceType_void, IFaceType_bool, IFaceType_colour }
	, { "GetHotspotActiveBack", "get_hotspot_active_back", 2495, IFaceType_colour, IFaceType_void, IFaceType_void }
	, { "SetHotspotActiveUnderline", "set_hotspot_active_underline", 2412, IFaceType_void, IFaceType_bool, IFaceType_void }
	, { "GetHotspotActiveUnderline", "get_hotspot_active_underline", 2496, IFaceType_bool, IFaceType_void, IFaceType_void }
	, { "SetHotspotSingleLine", "set_hotspot_single_line", 2421, IFaceType_void, IFaceType_bool, IFaceType_void }
	, { "GetHotspotSingleLine", "get_hotspot_single_line", 2497, IFaceType_bool, IFaceType_void, IFaceType_void }
	, { "ParaDown", "para_down", 2413, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "ParaDownExtend", "para_down_extend", 2414, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "ParaUp", "para_up", 2415, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "ParaUpExtend", "para_up_extend", 2416, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "PositionBefore", "position_before", 2417, IFaceType_position, IFaceType_position, IFaceType_void }
	, { "PositionAfter", "position_after", 2418, IFaceType_position, IFaceType_position, IFaceType_void }
	, { "PositionRelative", "position_relative", 2670, IFaceType_position, IFaceType_position, IFaceType_int }
	, { "CopyRange", "copy_range", 2419, IFaceType_void, IFaceType_position, IFaceType_position }
	, { "CopyText", "copy_text", 2420, IFaceType_void, IFaceType_int, IFaceType_string }
	, { "SetSelectionMode", "set_selection_mode", 2422, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetSelectionMode", "get_selection_mode", 2423, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "GetLineSelStartPosition", "get_line_sel_start_position", 2424, IFaceType_position, IFaceType_int, IFaceType_void }
	, { "GetLineSelEndPosition", "get_line_sel_end_position", 2425, IFaceType_position, IFaceType_int, IFaceType_void }
	, { "LineDownRectExtend", "line_down_rect_extend", 2426, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "LineUpRectExtend", "line_up_rect_extend", 2427, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "CharLeftRectExtend", "char_left_rect_extend", 2428, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "CharRightRectExtend", "char_right_rect_extend", 2429, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "HomeRectExtend", "home_rect_extend", 2430, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "VCHomeRectExtend", "c_home_rect_extend", 2431, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "LineEndRectExtend", "line_end_rect_extend", 2432, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "PageUpRectExtend", "page_up_rect_extend", 2433, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "PageDownRectExtend", "page_down_rect_extend", 2434, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "StutteredPageUp", "stuttered_page_up", 2435, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "StutteredPageUpExtend", "stuttered_page_up_extend", 2436, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "StutteredPageDown", "stuttered_page_down", 2437, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "StutteredPageDownExtend", "stuttered_page_down_extend", 2438, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "WordLeftEnd", "word_left_end", 2439, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "WordLeftEndExtend", "word_left_end_extend", 2440, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "WordRightEnd", "word_right_end", 2441, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "WordRightEndExtend", "word_right_end_extend", 2442, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "SetWhitespaceChars", "set_whitespace_chars", 2443, IFaceType_void, IFaceType_void, IFaceType_string }
	, { "GetWhitespaceChars", "get_whitespace_chars", 2647, IFaceType_int, IFaceType_void, IFaceType_stringresult }
	, { "SetPunctuationChars", "set_punctuation_chars", 2648, IFaceType_void, IFaceType_void, IFaceType_string }
	, { "GetPunctuationChars", "get_punctuation_chars", 2649, IFaceType_int, IFaceType_void, IFaceType_stringresult }
	, { "SetCharsDefault", "set_chars_default", 2444, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "AutoCGetCurrent", "auto_c_get_current", 2445, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "AutoCGetCurrentText", "auto_c_get_current_text", 2610, IFaceType_int, IFaceType_void, IFaceType_stringresult }
	, { "AutoCSetCaseInsensitiveBehaviour", "auto_c_set_case_insensitive_behaviour", 2634, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "AutoCGetCaseInsensitiveBehaviour", "auto_c_get_case_insensitive_behaviour", 2635, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "AutoCSetMulti", "auto_c_set_multi", 2636, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "AutoCGetMulti", "auto_c_get_multi", 2637, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "AutoCSetOrder", "auto_c_set_order", 2660, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "AutoCGetOrder", "auto_c_get_order", 2661, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "Allocate", "allocate", 2446, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "TargetAsUTF8", "target_as_utf8", 2447, IFaceType_int, IFaceType_void, IFaceType_stringresult }
	, { "SetLengthForEncode", "set_length_for_encode", 2448, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "EncodedFromUTF8", "encoded_from_utf8", 2449, IFaceType_int, IFaceType_string, IFaceType_stringresult }
	, { "FindColumn", "find_column", 2456, IFaceType_int, IFaceType_int, IFaceType_int }
	, { "GetCaretSticky", "get_caret_sticky", 2457, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetCaretSticky", "set_caret_sticky", 2458, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "ToggleCaretSticky", "toggle_caret_sticky", 2459, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "SetPasteConvertEndings", "set_paste_convert_endings", 2467, IFaceType_void, IFaceType_bool, IFaceType_void }
	, { "GetPasteConvertEndings", "get_paste_convert_endings", 2468, IFaceType_bool, IFaceType_void, IFaceType_void }
	, { "SelectionDuplicate", "selection_duplicate", 2469, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "SetCaretLineBackAlpha", "set_caret_line_back_alpha", 2470, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetCaretLineBackAlpha", "get_caret_line_back_alpha", 2471, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetCaretStyle", "set_caret_style", 2512, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetCaretStyle", "get_caret_style", 2513, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetIndicatorCurrent", "set_indicator_current", 2500, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetIndicatorCurrent", "get_indicator_current", 2501, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetIndicatorValue", "set_indicator_value", 2502, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetIndicatorValue", "get_indicator_value", 2503, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "IndicatorFillRange", "indicator_fill_range", 2504, IFaceType_void, IFaceType_int, IFaceType_int }
	, { "IndicatorClearRange", "indicator_clear_range", 2505, IFaceType_void, IFaceType_int, IFaceType_int }
	, { "IndicatorAllOnFor", "indicator_all_on_for", 2506, IFaceType_int, IFaceType_int, IFaceType_void }
	, { "IndicatorValueAt", "indicator_value_at", 2507, IFaceType_int, IFaceType_int, IFaceType_int }
	, { "IndicatorStart", "indicator_start", 2508, IFaceType_int, IFaceType_int, IFaceType_int }
	, { "IndicatorEnd", "indicator_end", 2509, IFaceType_int, IFaceType_int, IFaceType_int }
	, { "SetPositionCache", "set_position_cache", 2514, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetPositionCache", "get_position_cache", 2515, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "CopyAllowLine", "copy_allow_line", 2519, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "GetCharacterPointer", "get_character_pointer", 2520, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "GetRangePointer", "get_range_pointer", 2643, IFaceType_int, IFaceType_int, IFaceType_int }
	, { "GetGapPosition", "get_gap_position", 2644, IFaceType_position, IFaceType_void, IFaceType_void }
	, { "IndicSetAlpha", "indic_set_alpha", 2523, IFaceType_void, IFaceType_int, IFaceType_int }
	, { "IndicGetAlpha", "indic_get_alpha", 2524, IFaceType_int, IFaceType_int, IFaceType_void }
	, { "IndicSetOutlineAlpha", "indic_set_outline_alpha", 2558, IFaceType_void, IFaceType_int, IFaceType_int }
	, { "IndicGetOutlineAlpha", "indic_get_outline_alpha", 2559, IFaceType_int, IFaceType_int, IFaceType_void }
	, { "SetExtraAscent", "set_extra_ascent", 2525, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetExtraAscent", "get_extra_ascent", 2526, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetExtraDescent", "set_extra_descent", 2527, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetExtraDescent", "get_extra_descent", 2528, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "MarkerSymbolDefined", "marker_symbol_defined", 2529, IFaceType_int, IFaceType_int, IFaceType_void }
	, { "MarginSetText", "margin_set_text", 2530, IFaceType_void, IFaceType_int, IFaceType_string }
	, { "MarginGetText", "margin_get_text", 2531, IFaceType_int, IFaceType_int, IFaceType_stringresult }
	, { "MarginSetStyle", "margin_set_style", 2532, IFaceType_void, IFaceType_int, IFaceType_int }
	, { "MarginGetStyle", "margin_get_style", 2533, IFaceType_int, IFaceType_int, IFaceType_void }
	, { "MarginSetStyles", "margin_set_styles", 2534, IFaceType_void, IFaceType_int, IFaceType_string }
	, { "MarginGetStyles", "margin_get_styles", 2535, IFaceType_int, IFaceType_int, IFaceType_stringresult }
	, { "MarginTextClearAll", "margin_text_clear_all", 2536, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "MarginSetStyleOffset", "margin_set_style_offset", 2537, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "MarginGetStyleOffset", "margin_get_style_offset", 2538, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetMarginOptions", "set_margin_options", 2539, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetMarginOptions", "get_margin_options", 2557, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "AnnotationSetText", "annotation_set_text", 2540, IFaceType_void, IFaceType_int, IFaceType_string }
	, { "AnnotationGetText", "annotation_get_text", 2541, IFaceType_int, IFaceType_int, IFaceType_stringresult }
	, { "AnnotationSetStyle", "annotation_set_style", 2542, IFaceType_void, IFaceType_int, IFaceType_int }
	, { "AnnotationGetStyle", "annotation_get_style", 2543, IFaceType_int, IFaceType_int, IFaceType_void }
	, { "AnnotationSetStyles", "annotation_set_styles", 2544, IFaceType_void, IFaceType_int, IFaceType_string }
	, { "AnnotationGetStyles", "annotation_get_styles", 2545, IFaceType_int, IFaceType_int, IFaceType_stringresult }
	, { "AnnotationGetLines", "annotation_get_lines", 2546, IFaceType_int, IFaceType_int, IFaceType_void }
	, { "AnnotationClearAll", "annotation_clear_all", 2547, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "AnnotationSetVisible", "annotation_set_visible", 2548, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "AnnotationGetVisible", "annotation_get_visible", 2549, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "AnnotationSetStyleOffset", "annotation_set_style_offset", 2550, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "AnnotationGetStyleOffset", "annotation_get_style_offset", 2551, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "ReleaseAllExtendedStyles", "release_all_extended_styles", 2552, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "AllocateExtendedStyles", "allocate_extended_styles", 2553, IFaceType_int, IFaceType_int, IFaceType_void }
	, { "AddUndoAction", "add_undo_action", 2560, IFaceType_void, IFaceType_int, IFaceType_int }
	, { "CharPositionFromPoint", "char_position_from_point", 2561, IFaceType_position, IFaceType_int, IFaceType_int }
	, { "CharPositionFromPointClose", "char_position_from_point_close", 2562, IFaceType_position, IFaceType_int, IFaceType_int }
	, { "SetMouseSelectionRectangularSwitch", "set_mouse_selection_rectangular_switch", 2668, IFaceType_void, IFaceType_bool, IFaceType_void }
	, { "GetMouseSelectionRectangularSwitch", "get_mouse_selection_rectangular_switch", 2669, IFaceType_bool, IFaceType_void, IFaceType_void }
	, { "SetMultipleSelection", "set_multiple_selection", 2563, IFaceType_void, IFaceType_bool, IFaceType_void }
	, { "GetMultipleSelection", "get_multiple_selection", 2564, IFaceType_bool, IFaceType_void, IFaceType_void }
	, { "SetAdditionalSelectionTyping", "set_additional_selection_typing", 2565, IFaceType_void, IFaceType_bool, IFaceType_void }
	, { "GetAdditionalSelectionTyping", "get_additional_selection_typing", 2566, IFaceType_bool, IFaceType_void, IFaceType_void }
	, { "SetAdditionalCaretsBlink", "set_additional_carets_blink", 2567, IFaceType_void, IFaceType_bool, IFaceType_void }
	, { "GetAdditionalCaretsBlink", "get_additional_carets_blink", 2568, IFaceType_bool, IFaceType_void, IFaceType_void }
	, { "SetAdditionalCaretsVisible", "set_additional_carets_visible", 2608, IFaceType_void, IFaceType_bool, IFaceType_void }
	, { "GetAdditionalCaretsVisible", "get_additional_carets_visible", 2609, IFaceType_bool, IFaceType_void, IFaceType_void }
	, { "GetSelections", "get_selections", 2570, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "GetSelectionEmpty", "get_selection_empty", 2650, IFaceType_bool, IFaceType_void, IFaceType_void }
	, { "ClearSelections", "clear_selections", 2571, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "SetSelection", "set_selection", 2572, IFaceType_int, IFaceType_int, IFaceType_int }
	, { "AddSelection", "add_selection", 2573, IFaceType_int, IFaceType_int, IFaceType_int }
	, { "DropSelectionN", "drop_selection_n", 2671, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "SetMainSelection", "set_main_selection", 2574, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetMainSelection", "get_main_selection", 2575, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetSelectionNCaret", "set_selection_n_caret", 2576, IFaceType_void, IFaceType_int, IFaceType_position }
	, { "GetSelectionNCaret", "get_selection_n_caret", 2577, IFaceType_position, IFaceType_int, IFaceType_void }
	, { "SetSelectionNAnchor", "set_selection_n_anchor", 2578, IFaceType_void, IFaceType_int, IFaceType_position }
	, { "GetSelectionNAnchor", "get_selection_n_anchor", 2579, IFaceType_position, IFaceType_int, IFaceType_void }
	, { "SetSelectionNCaretVirtualSpace", "set_selection_n_caret_virtual_space", 2580, IFaceType_void, IFaceType_int, IFaceType_int }
	, { "GetSelectionNCaretVirtualSpace", "get_selection_n_caret_virtual_space", 2581, IFaceType_int, IFaceType_int, IFaceType_void }
	, { "SetSelectionNAnchorVirtualSpace", "set_selection_n_anchor_virtual_space", 2582, IFaceType_void, IFaceType_int, IFaceType_int }
	, { "GetSelectionNAnchorVirtualSpace", "get_selection_n_anchor_virtual_space", 2583, IFaceType_int, IFaceType_int, IFaceType_void }
	, { "SetSelectionNStart", "set_selection_n_start", 2584, IFaceType_void, IFaceType_int, IFaceType_position }
	, { "GetSelectionNStart", "get_selection_n_start", 2585, IFaceType_position, IFaceType_int, IFaceType_void }
	, { "SetSelectionNEnd", "set_selection_n_end", 2586, IFaceType_void, IFaceType_int, IFaceType_position }
	, { "GetSelectionNEnd", "get_selection_n_end", 2587, IFaceType_position, IFaceType_int, IFaceType_void }
	, { "SetRectangularSelectionCaret", "set_rectangular_selection_caret", 2588, IFaceType_void, IFaceType_position, IFaceType_void }
	, { "GetRectangularSelectionCaret", "get_rectangular_selection_caret", 2589, IFaceType_position, IFaceType_void, IFaceType_void }
	, { "SetRectangularSelectionAnchor", "set_rectangular_selection_anchor", 2590, IFaceType_void, IFaceType_position, IFaceType_void }
	, { "GetRectangularSelectionAnchor", "get_rectangular_selection_anchor", 2591, IFaceType_position, IFaceType_void, IFaceType_void }
	, { "SetRectangularSelectionCaretVirtualSpace", "set_rectangular_selection_caret_virtual_space", 2592, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetRectangularSelectionCaretVirtualSpace", "get_rectangular_selection_caret_virtual_space", 2593, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetRectangularSelectionAnchorVirtualSpace", "set_rectangular_selection_anchor_virtual_space", 2594, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetRectangularSelectionAnchorVirtualSpace", "get_rectangular_selection_anchor_virtual_space", 2595, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetVirtualSpaceOptions", "set_virtual_space_options", 2596, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetVirtualSpaceOptions", "get_virtual_space_options", 2597, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetRectangularSelectionModifier", "set_rectangular_selection_modifier", 2598, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetRectangularSelectionModifier", "get_rectangular_selection_modifier", 2599, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetAdditionalSelFore", "set_additional_sel_fore", 2600, IFaceType_void, IFaceType_colour, IFaceType_void }
	, { "SetAdditionalSelBack", "set_additional_sel_back", 2601, IFaceType_void, IFaceType_colour, IFaceType_void }
	, { "SetAdditionalSelAlpha", "set_additional_sel_alpha", 2602, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetAdditionalSelAlpha", "get_additional_sel_alpha", 2603, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetAdditionalCaretFore", "set_additional_caret_fore", 2604, IFaceType_void, IFaceType_colour, IFaceType_void }
	, { "GetAdditionalCaretFore", "get_additional_caret_fore", 2605, IFaceType_colour, IFaceType_void, IFaceType_void }
	, { "RotateSelection", "rotate_selection", 2606, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "SwapMainAnchorCaret", "swap_main_anchor_caret", 2607, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "MultipleSelectAddNext", "multiple_select_add_next", 2688, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "MultipleSelectAddEach", "multiple_select_add_each", 2689, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "ChangeLexerState", "change_lexer_state", 2617, IFaceType_int, IFaceType_position, IFaceType_position }
	, { "ContractedFoldNext", "contracted_fold_next", 2618, IFaceType_int, IFaceType_int, IFaceType_void }
	, { "VerticalCentreCaret", "vertical_centre_caret", 2619, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "MoveSelectedLinesUp", "move_selected_lines_up", 2620, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "MoveSelectedLinesDown", "move_selected_lines_down", 2621, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "SetIdentifier", "set_identifier", 2622, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetIdentifier", "get_identifier", 2623, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "RGBAImageSetWidth", "gba_image_set_width", 2624, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "RGBAImageSetHeight", "gba_image_set_height", 2625, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "RGBAImageSetScale", "gba_image_set_scale", 2651, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "MarkerDefineRGBAImage", "marker_define_rgba_image", 2626, IFaceType_void, IFaceType_int, IFaceType_string }
	, { "RegisterRGBAImage", "register_rgba_image", 2627, IFaceType_void, IFaceType_int, IFaceType_string }
	, { "ScrollToStart", "scroll_to_start", 2628, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "ScrollToEnd", "scroll_to_end", 2629, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "SetTechnology", "set_technology", 2630, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetTechnology", "get_technology", 2631, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "CreateLoader", "create_loader", 2632, IFaceType_int, IFaceType_int, IFaceType_void }
	, { "FindIndicatorShow", "find_indicator_show", 2640, IFaceType_void, IFaceType_position, IFaceType_position }
	, { "FindIndicatorFlash", "find_indicator_flash", 2641, IFaceType_void, IFaceType_position, IFaceType_position }
	, { "FindIndicatorHide", "find_indicator_hide", 2642, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "VCHomeDisplay", "c_home_display", 2652, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "VCHomeDisplayExtend", "c_home_display_extend", 2653, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "GetCaretLineVisibleAlways", "get_caret_line_visible_always", 2654, IFaceType_bool, IFaceType_void, IFaceType_void }
	, { "SetCaretLineVisibleAlways", "set_caret_line_visible_always", 2655, IFaceType_void, IFaceType_bool, IFaceType_void }
	, { "SetLineEndTypesAllowed", "set_line_end_types_allowed", 2656, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetLineEndTypesAllowed", "get_line_end_types_allowed", 2657, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "GetLineEndTypesActive", "get_line_end_types_active", 2658, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "SetRepresentation", "set_representation", 2665, IFaceType_void, IFaceType_string, IFaceType_string }
	, { "GetRepresentation", "get_representation", 2666, IFaceType_int, IFaceType_string, IFaceType_stringresult }
	, { "ClearRepresentation", "clear_representation", 2667, IFaceType_void, IFaceType_string, IFaceType_void }
	, { "StartRecord", "start_record", 3001, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "StopRecord", "stop_record", 3002, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "SetLexer", "set_lexer", 4001, IFaceType_void, IFaceType_int, IFaceType_void }
	, { "GetLexer", "get_lexer", 4002, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "Colourise", "colourise", 4003, IFaceType_void, IFaceType_position, IFaceType_position }
	, { "SetProperty", "set_property", 4004, IFaceType_void, IFaceType_string, IFaceType_string }
	, { "SetKeyWords", "set_key_words", 4005, IFaceType_void, IFaceType_int, IFaceType_string }
	, { "SetLexerLanguage", "set_lexer_language", 4006, IFaceType_void, IFaceType_void, IFaceType_string }
	, { "LoadLexerLibrary", "load_lexer_library", 4007, IFaceType_void, IFaceType_void, IFaceType_string }
	, { "GetProperty", "get_property", 4008, IFaceType_int, IFaceType_string, IFaceType_stringresult }
	, { "GetPropertyExpanded", "get_property_expanded", 4009, IFaceType_int, IFaceType_string, IFaceType_stringresult }
	, { "GetPropertyInt", "get_property_int", 4010, IFaceType_int, IFaceType_string, IFaceType_void }
	, { "GetStyleBitsNeeded", "get_style_bits_needed", 4011, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "GetLexerLanguage", "get_lexer_language", 4012, IFaceType_int, IFaceType_void, IFaceType_stringresult }
	, { "PrivateLexerCall", "private_lexer_call", 4013, IFaceType_int, IFaceType_int, IFaceType_int }
	, { "PropertyNames", "property_names", 4014, IFaceType_int, IFaceType_void, IFaceType_stringresult }
	, { "PropertyType", "property_type", 4015, IFaceType_int, IFaceType_string, IFaceType_void }
	, { "DescribeProperty", "describe_property", 4016, IFaceType_int, IFaceType_string, IFaceType_stringresult }
	, { "DescribeKeyWordSets", "describe_key_word_sets", 4017, IFaceType_int, IFaceType_void, IFaceType_stringresult }
	, { "GetLineEndTypesSupported", "get_line_end_types_supported", 4018, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "AllocateSubStyles", "allocate_sub_styles", 4020, IFaceType_int, IFaceType_int, IFaceType_int }
	, { "GetSubStylesStart", "get_sub_styles_start", 4021, IFaceType_int, IFaceType_int, IFaceType_void }
	, { "GetSubStylesLength", "get_sub_styles_length", 4022, IFaceType_int, IFaceType_int, IFaceType_void }
	, { "GetStyleFromSubStyle", "get_style_from_sub_style", 4027, IFaceType_int, IFaceType_int, IFaceType_void }
	, { "GetPrimaryStyleFromStyle", "get_primary_style_from_style", 4028, IFaceType_int, IFaceType_int, IFaceType_void }
	, { "FreeSubStyles", "free_sub_styles", 4023, IFaceType_void, IFaceType_void, IFaceType_void }
	, { "SetIdentifiers", "set_identifiers", 4024, IFaceType_void, IFaceType_int, IFaceType_string }
	, { "DistanceToSecondaryStyles", "distance_to_secondary_styles", 4025, IFaceType_int, IFaceType_void, IFaceType_void }
	, { "GetSubStyleBases", "get_sub_style_bases", 4026, IFaceType_int, IFaceType_void, IFaceType_stringresult }
	, { "GetUsePalette", "get_use_palette", 2139, IFaceType_bool, IFaceType_void, IFaceType_void }
	, { "SetUsePalette", "set_use_palette", 2039, IFaceType_void, IFaceType_bool, IFaceType_void }
	, { "SetKeysUnicode", "set_keys_unicode", 2521, IFaceType_void, IFaceType_bool, IFaceType_void }
	, { "GetKeysUnicode", "get_keys_unicode", 2522, IFaceType_bool, IFaceType_void, IFaceType_void }
	,  { NULL, NULL, 0, IFaceType_void, IFaceType_void, IFaceType_void}
	};

static void sci_values_push(lua_State* L, int t) {
	lua_pushvalue(L, t);
	lua_pushnumber(L, -1); lua_setfield(L, -2, "INVALID_POSITION");
	lua_pushnumber(L, 2000); lua_setfield(L, -2, "SCI_START");
	lua_pushnumber(L, 3000); lua_setfield(L, -2, "SCI_OPTIONAL_START");
	lua_pushnumber(L, 4000); lua_setfield(L, -2, "SCI_LEXER_START");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCWS_INVISIBLE");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCWS_VISIBLEALWAYS");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCWS_VISIBLEAFTERINDENT");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SC_EOL_CRLF");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SC_EOL_CR");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SC_EOL_LF");
	lua_pushnumber(L, 65001); lua_setfield(L, -2, "SC_CP_UTF8");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SC_IME_WINDOWED");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SC_IME_INLINE");
	lua_pushnumber(L, 31); lua_setfield(L, -2, "MARKER_MAX");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SC_MARK_CIRCLE");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SC_MARK_ROUNDRECT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SC_MARK_ARROW");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SC_MARK_SMALLRECT");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SC_MARK_SHORTARROW");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SC_MARK_EMPTY");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SC_MARK_ARROWDOWN");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SC_MARK_MINUS");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SC_MARK_PLUS");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SC_MARK_VLINE");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SC_MARK_LCORNER");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SC_MARK_TCORNER");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SC_MARK_BOXPLUS");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SC_MARK_BOXPLUSCONNECTED");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SC_MARK_BOXMINUS");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SC_MARK_BOXMINUSCONNECTED");
	lua_pushnumber(L, 16); lua_setfield(L, -2, "SC_MARK_LCORNERCURVE");
	lua_pushnumber(L, 17); lua_setfield(L, -2, "SC_MARK_TCORNERCURVE");
	lua_pushnumber(L, 18); lua_setfield(L, -2, "SC_MARK_CIRCLEPLUS");
	lua_pushnumber(L, 19); lua_setfield(L, -2, "SC_MARK_CIRCLEPLUSCONNECTED");
	lua_pushnumber(L, 20); lua_setfield(L, -2, "SC_MARK_CIRCLEMINUS");
	lua_pushnumber(L, 21); lua_setfield(L, -2, "SC_MARK_CIRCLEMINUSCONNECTED");
	lua_pushnumber(L, 22); lua_setfield(L, -2, "SC_MARK_BACKGROUND");
	lua_pushnumber(L, 23); lua_setfield(L, -2, "SC_MARK_DOTDOTDOT");
	lua_pushnumber(L, 24); lua_setfield(L, -2, "SC_MARK_ARROWS");
	lua_pushnumber(L, 25); lua_setfield(L, -2, "SC_MARK_PIXMAP");
	lua_pushnumber(L, 26); lua_setfield(L, -2, "SC_MARK_FULLRECT");
	lua_pushnumber(L, 27); lua_setfield(L, -2, "SC_MARK_LEFTRECT");
	lua_pushnumber(L, 28); lua_setfield(L, -2, "SC_MARK_AVAILABLE");
	lua_pushnumber(L, 29); lua_setfield(L, -2, "SC_MARK_UNDERLINE");
	lua_pushnumber(L, 30); lua_setfield(L, -2, "SC_MARK_RGBAIMAGE");
	lua_pushnumber(L, 31); lua_setfield(L, -2, "SC_MARK_BOOKMARK");
	lua_pushnumber(L, 10000); lua_setfield(L, -2, "SC_MARK_CHARACTER");
	lua_pushnumber(L, 25); lua_setfield(L, -2, "SC_MARKNUM_FOLDEREND");
	lua_pushnumber(L, 26); lua_setfield(L, -2, "SC_MARKNUM_FOLDEROPENMID");
	lua_pushnumber(L, 27); lua_setfield(L, -2, "SC_MARKNUM_FOLDERMIDTAIL");
	lua_pushnumber(L, 28); lua_setfield(L, -2, "SC_MARKNUM_FOLDERTAIL");
	lua_pushnumber(L, 29); lua_setfield(L, -2, "SC_MARKNUM_FOLDERSUB");
	lua_pushnumber(L, 30); lua_setfield(L, -2, "SC_MARKNUM_FOLDER");
	lua_pushnumber(L, 31); lua_setfield(L, -2, "SC_MARKNUM_FOLDEROPEN");
	lua_pushnumber(L, 0xFE000000); lua_setfield(L, -2, "SC_MASK_FOLDERS");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SC_MAX_MARGIN");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SC_MARGIN_SYMBOL");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SC_MARGIN_NUMBER");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SC_MARGIN_BACK");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SC_MARGIN_FORE");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SC_MARGIN_TEXT");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SC_MARGIN_RTEXT");
	lua_pushnumber(L, 32); lua_setfield(L, -2, "STYLE_DEFAULT");
	lua_pushnumber(L, 33); lua_setfield(L, -2, "STYLE_LINENUMBER");
	lua_pushnumber(L, 34); lua_setfield(L, -2, "STYLE_BRACELIGHT");
	lua_pushnumber(L, 35); lua_setfield(L, -2, "STYLE_BRACEBAD");
	lua_pushnumber(L, 36); lua_setfield(L, -2, "STYLE_CONTROLCHAR");
	lua_pushnumber(L, 37); lua_setfield(L, -2, "STYLE_INDENTGUIDE");
	lua_pushnumber(L, 38); lua_setfield(L, -2, "STYLE_CALLTIP");
	lua_pushnumber(L, 39); lua_setfield(L, -2, "STYLE_LASTPREDEFINED");
	lua_pushnumber(L, 255); lua_setfield(L, -2, "STYLE_MAX");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SC_CHARSET_ANSI");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SC_CHARSET_DEFAULT");
	lua_pushnumber(L, 186); lua_setfield(L, -2, "SC_CHARSET_BALTIC");
	lua_pushnumber(L, 136); lua_setfield(L, -2, "SC_CHARSET_CHINESEBIG5");
	lua_pushnumber(L, 238); lua_setfield(L, -2, "SC_CHARSET_EASTEUROPE");
	lua_pushnumber(L, 134); lua_setfield(L, -2, "SC_CHARSET_GB2312");
	lua_pushnumber(L, 161); lua_setfield(L, -2, "SC_CHARSET_GREEK");
	lua_pushnumber(L, 129); lua_setfield(L, -2, "SC_CHARSET_HANGUL");
	lua_pushnumber(L, 77); lua_setfield(L, -2, "SC_CHARSET_MAC");
	lua_pushnumber(L, 255); lua_setfield(L, -2, "SC_CHARSET_OEM");
	lua_pushnumber(L, 204); lua_setfield(L, -2, "SC_CHARSET_RUSSIAN");
	lua_pushnumber(L, 1251); lua_setfield(L, -2, "SC_CHARSET_CYRILLIC");
	lua_pushnumber(L, 128); lua_setfield(L, -2, "SC_CHARSET_SHIFTJIS");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SC_CHARSET_SYMBOL");
	lua_pushnumber(L, 162); lua_setfield(L, -2, "SC_CHARSET_TURKISH");
	lua_pushnumber(L, 130); lua_setfield(L, -2, "SC_CHARSET_JOHAB");
	lua_pushnumber(L, 177); lua_setfield(L, -2, "SC_CHARSET_HEBREW");
	lua_pushnumber(L, 178); lua_setfield(L, -2, "SC_CHARSET_ARABIC");
	lua_pushnumber(L, 163); lua_setfield(L, -2, "SC_CHARSET_VIETNAMESE");
	lua_pushnumber(L, 222); lua_setfield(L, -2, "SC_CHARSET_THAI");
	lua_pushnumber(L, 1000); lua_setfield(L, -2, "SC_CHARSET_8859_15");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SC_CASE_MIXED");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SC_CASE_UPPER");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SC_CASE_LOWER");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SC_CASE_CAMEL");
	lua_pushnumber(L, 100); lua_setfield(L, -2, "SC_FONT_SIZE_MULTIPLIER");
	lua_pushnumber(L, 400); lua_setfield(L, -2, "SC_WEIGHT_NORMAL");
	lua_pushnumber(L, 600); lua_setfield(L, -2, "SC_WEIGHT_SEMIBOLD");
	lua_pushnumber(L, 700); lua_setfield(L, -2, "SC_WEIGHT_BOLD");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "INDIC_PLAIN");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "INDIC_SQUIGGLE");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "INDIC_TT");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "INDIC_DIAGONAL");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "INDIC_STRIKE");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "INDIC_HIDDEN");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "INDIC_BOX");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "INDIC_ROUNDBOX");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "INDIC_STRAIGHTBOX");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "INDIC_DASH");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "INDIC_DOTS");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "INDIC_SQUIGGLELOW");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "INDIC_DOTBOX");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "INDIC_SQUIGGLEPIXMAP");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "INDIC_COMPOSITIONTHICK");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "INDIC_COMPOSITIONTHIN");
	lua_pushnumber(L, 16); lua_setfield(L, -2, "INDIC_FULLBOX");
	lua_pushnumber(L, 17); lua_setfield(L, -2, "INDIC_TEXTFORE");
	lua_pushnumber(L, 32); lua_setfield(L, -2, "INDIC_IME");
	lua_pushnumber(L, 35); lua_setfield(L, -2, "INDIC_IME_MAX");
	lua_pushnumber(L, 35); lua_setfield(L, -2, "INDIC_MAX");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "INDIC_CONTAINER");
	lua_pushnumber(L, 0x20); lua_setfield(L, -2, "INDIC0_MASK");
	lua_pushnumber(L, 0x40); lua_setfield(L, -2, "INDIC1_MASK");
	lua_pushnumber(L, 0x80); lua_setfield(L, -2, "INDIC2_MASK");
	lua_pushnumber(L, 0xE0); lua_setfield(L, -2, "INDICS_MASK");
	lua_pushnumber(L, 0x1000000); lua_setfield(L, -2, "SC_INDICVALUEBIT");
	lua_pushnumber(L, 0xFFFFFF); lua_setfield(L, -2, "SC_INDICVALUEMASK");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SC_INDICFLAG_VALUEFORE");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SC_IV_NONE");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SC_IV_REAL");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SC_IV_LOOKFORWARD");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SC_IV_LOOKBOTH");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SC_PRINT_NORMAL");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SC_PRINT_INVERTLIGHT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SC_PRINT_BLACKONWHITE");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SC_PRINT_COLOURONWHITE");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SC_PRINT_COLOURONWHITEDEFAULTBG");
	lua_pushnumber(L, 0x2); lua_setfield(L, -2, "SCFIND_WHOLEWORD");
	lua_pushnumber(L, 0x4); lua_setfield(L, -2, "SCFIND_MATCHCASE");
	lua_pushnumber(L, 0x00100000); lua_setfield(L, -2, "SCFIND_WORDSTART");
	lua_pushnumber(L, 0x00200000); lua_setfield(L, -2, "SCFIND_REGEXP");
	lua_pushnumber(L, 0x00400000); lua_setfield(L, -2, "SCFIND_POSIX");
	lua_pushnumber(L, 0x00800000); lua_setfield(L, -2, "SCFIND_CXX11REGEX");
	lua_pushnumber(L, 0x400); lua_setfield(L, -2, "SC_FOLDLEVELBASE");
	lua_pushnumber(L, 0x1000); lua_setfield(L, -2, "SC_FOLDLEVELWHITEFLAG");
	lua_pushnumber(L, 0x2000); lua_setfield(L, -2, "SC_FOLDLEVELHEADERFLAG");
	lua_pushnumber(L, 0x0FFF); lua_setfield(L, -2, "SC_FOLDLEVELNUMBERMASK");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SC_FOLDACTION_CONTRACT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SC_FOLDACTION_EXPAND");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SC_FOLDACTION_TOGGLE");
	lua_pushnumber(L, 0x0001); lua_setfield(L, -2, "SC_AUTOMATICFOLD_SHOW");
	lua_pushnumber(L, 0x0002); lua_setfield(L, -2, "SC_AUTOMATICFOLD_CLICK");
	lua_pushnumber(L, 0x0004); lua_setfield(L, -2, "SC_AUTOMATICFOLD_CHANGE");
	lua_pushnumber(L, 0x0002); lua_setfield(L, -2, "SC_FOLDFLAG_LINEBEFORE_EXPANDED");
	lua_pushnumber(L, 0x0004); lua_setfield(L, -2, "SC_FOLDFLAG_LINEBEFORE_CONTRACTED");
	lua_pushnumber(L, 0x0008); lua_setfield(L, -2, "SC_FOLDFLAG_LINEAFTER_EXPANDED");
	lua_pushnumber(L, 0x0010); lua_setfield(L, -2, "SC_FOLDFLAG_LINEAFTER_CONTRACTED");
	lua_pushnumber(L, 0x0040); lua_setfield(L, -2, "SC_FOLDFLAG_LEVELNUMBERS");
	lua_pushnumber(L, 0x0080); lua_setfield(L, -2, "SC_FOLDFLAG_LINESTATE");
	lua_pushnumber(L, 10000000); lua_setfield(L, -2, "SC_TIME_FOREVER");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SC_WRAP_NONE");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SC_WRAP_WORD");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SC_WRAP_CHAR");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SC_WRAP_WHITESPACE");
	lua_pushnumber(L, 0x0000); lua_setfield(L, -2, "SC_WRAPVISUALFLAG_NONE");
	lua_pushnumber(L, 0x0001); lua_setfield(L, -2, "SC_WRAPVISUALFLAG_END");
	lua_pushnumber(L, 0x0002); lua_setfield(L, -2, "SC_WRAPVISUALFLAG_START");
	lua_pushnumber(L, 0x0004); lua_setfield(L, -2, "SC_WRAPVISUALFLAG_MARGIN");
	lua_pushnumber(L, 0x0000); lua_setfield(L, -2, "SC_WRAPVISUALFLAGLOC_DEFAULT");
	lua_pushnumber(L, 0x0001); lua_setfield(L, -2, "SC_WRAPVISUALFLAGLOC_END_BY_TEXT");
	lua_pushnumber(L, 0x0002); lua_setfield(L, -2, "SC_WRAPVISUALFLAGLOC_START_BY_TEXT");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SC_WRAPINDENT_FIXED");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SC_WRAPINDENT_SAME");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SC_WRAPINDENT_INDENT");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SC_CACHE_NONE");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SC_CACHE_CARET");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SC_CACHE_PAGE");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SC_CACHE_DOCUMENT");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SC_PHASES_ONE");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SC_PHASES_TWO");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SC_PHASES_MULTIPLE");
	lua_pushnumber(L, 0xF); lua_setfield(L, -2, "SC_EFF_QUALITY_MASK");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SC_EFF_QUALITY_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SC_EFF_QUALITY_NON_ANTIALIASED");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SC_EFF_QUALITY_ANTIALIASED");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SC_EFF_QUALITY_LCD_OPTIMIZED");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SC_MULTIPASTE_ONCE");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SC_MULTIPASTE_EACH");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "EDGE_NONE");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "EDGE_LINE");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "EDGE_BACKGROUND");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SC_STATUS_OK");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SC_STATUS_FAILURE");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SC_STATUS_BADALLOC");
	lua_pushnumber(L, 1000); lua_setfield(L, -2, "SC_STATUS_WARN_START");
	lua_pushnumber(L, 1001); lua_setfield(L, -2, "SC_STATUS_WARN_REGEX");
	lua_pushnumber(L, -1); lua_setfield(L, -2, "SC_CURSORNORMAL");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SC_CURSORARROW");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SC_CURSORWAIT");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SC_CURSORREVERSEARROW");
	lua_pushnumber(L, 0x01); lua_setfield(L, -2, "VISIBLE_SLOP");
	lua_pushnumber(L, 0x04); lua_setfield(L, -2, "VISIBLE_STRICT");
	lua_pushnumber(L, 0x01); lua_setfield(L, -2, "CARET_SLOP");
	lua_pushnumber(L, 0x04); lua_setfield(L, -2, "CARET_STRICT");
	lua_pushnumber(L, 0x10); lua_setfield(L, -2, "CARET_JUMPS");
	lua_pushnumber(L, 0x08); lua_setfield(L, -2, "CARET_EVEN");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SC_SEL_STREAM");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SC_SEL_RECTANGLE");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SC_SEL_LINES");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SC_SEL_THIN");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SC_CASEINSENSITIVEBEHAVIOUR_RESPECTCASE");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SC_CASEINSENSITIVEBEHAVIOUR_IGNORECASE");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SC_MULTIAUTOC_ONCE");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SC_MULTIAUTOC_EACH");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SC_ORDER_PRESORTED");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SC_ORDER_PERFORMSORT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SC_ORDER_CUSTOM");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SC_CARETSTICKY_OFF");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SC_CARETSTICKY_ON");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SC_CARETSTICKY_WHITESPACE");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SC_ALPHA_TRANSPARENT");
	lua_pushnumber(L, 255); lua_setfield(L, -2, "SC_ALPHA_OPAQUE");
	lua_pushnumber(L, 256); lua_setfield(L, -2, "SC_ALPHA_NOALPHA");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "CARETSTYLE_INVISIBLE");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "CARETSTYLE_LINE");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "CARETSTYLE_BLOCK");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SC_MARGINOPTION_NONE");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SC_MARGINOPTION_SUBLINESELECT");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "ANNOTATION_HIDDEN");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "ANNOTATION_STANDARD");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "ANNOTATION_BOXED");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "ANNOTATION_INDENTED");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "UNDO_MAY_COALESCE");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCVS_NONE");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCVS_RECTANGULARSELECTION");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCVS_USERACCESSIBLE");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SC_TECHNOLOGY_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SC_TECHNOLOGY_DIRECTWRITE");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SC_TECHNOLOGY_DIRECTWRITERETAIN");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SC_TECHNOLOGY_DIRECTWRITEDC");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SC_LINE_END_TYPE_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SC_LINE_END_TYPE_UNICODE");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "KEYWORDSET_MAX");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SC_TYPE_BOOLEAN");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SC_TYPE_INTEGER");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SC_TYPE_STRING");
	lua_pushnumber(L, 0x1); lua_setfield(L, -2, "SC_MOD_INSERTTEXT");
	lua_pushnumber(L, 0x2); lua_setfield(L, -2, "SC_MOD_DELETETEXT");
	lua_pushnumber(L, 0x4); lua_setfield(L, -2, "SC_MOD_CHANGESTYLE");
	lua_pushnumber(L, 0x8); lua_setfield(L, -2, "SC_MOD_CHANGEFOLD");
	lua_pushnumber(L, 0x10); lua_setfield(L, -2, "SC_PERFORMED_USER");
	lua_pushnumber(L, 0x20); lua_setfield(L, -2, "SC_PERFORMED_UNDO");
	lua_pushnumber(L, 0x40); lua_setfield(L, -2, "SC_PERFORMED_REDO");
	lua_pushnumber(L, 0x80); lua_setfield(L, -2, "SC_MULTISTEPUNDOREDO");
	lua_pushnumber(L, 0x100); lua_setfield(L, -2, "SC_LASTSTEPINUNDOREDO");
	lua_pushnumber(L, 0x200); lua_setfield(L, -2, "SC_MOD_CHANGEMARKER");
	lua_pushnumber(L, 0x400); lua_setfield(L, -2, "SC_MOD_BEFOREINSERT");
	lua_pushnumber(L, 0x800); lua_setfield(L, -2, "SC_MOD_BEFOREDELETE");
	lua_pushnumber(L, 0x1000); lua_setfield(L, -2, "SC_MULTILINEUNDOREDO");
	lua_pushnumber(L, 0x2000); lua_setfield(L, -2, "SC_STARTACTION");
	lua_pushnumber(L, 0x4000); lua_setfield(L, -2, "SC_MOD_CHANGEINDICATOR");
	lua_pushnumber(L, 0x8000); lua_setfield(L, -2, "SC_MOD_CHANGELINESTATE");
	lua_pushnumber(L, 0x10000); lua_setfield(L, -2, "SC_MOD_CHANGEMARGIN");
	lua_pushnumber(L, 0x20000); lua_setfield(L, -2, "SC_MOD_CHANGEANNOTATION");
	lua_pushnumber(L, 0x40000); lua_setfield(L, -2, "SC_MOD_CONTAINER");
	lua_pushnumber(L, 0x80000); lua_setfield(L, -2, "SC_MOD_LEXERSTATE");
	lua_pushnumber(L, 0x100000); lua_setfield(L, -2, "SC_MOD_INSERTCHECK");
	lua_pushnumber(L, 0x200000); lua_setfield(L, -2, "SC_MOD_CHANGETABSTOPS");
	lua_pushnumber(L, 0x3FFFFF); lua_setfield(L, -2, "SC_MODEVENTMASKALL");
	lua_pushnumber(L, 0x1); lua_setfield(L, -2, "SC_UPDATE_CONTENT");
	lua_pushnumber(L, 0x2); lua_setfield(L, -2, "SC_UPDATE_SELECTION");
	lua_pushnumber(L, 0x4); lua_setfield(L, -2, "SC_UPDATE_V_SCROLL");
	lua_pushnumber(L, 0x8); lua_setfield(L, -2, "SC_UPDATE_H_SCROLL");
	lua_pushnumber(L, 768); lua_setfield(L, -2, "SCEN_CHANGE");
	lua_pushnumber(L, 512); lua_setfield(L, -2, "SCEN_SETFOCUS");
	lua_pushnumber(L, 256); lua_setfield(L, -2, "SCEN_KILLFOCUS");
	lua_pushnumber(L, 300); lua_setfield(L, -2, "SCK_DOWN");
	lua_pushnumber(L, 301); lua_setfield(L, -2, "SCK_UP");
	lua_pushnumber(L, 302); lua_setfield(L, -2, "SCK_LEFT");
	lua_pushnumber(L, 303); lua_setfield(L, -2, "SCK_RIGHT");
	lua_pushnumber(L, 304); lua_setfield(L, -2, "SCK_HOME");
	lua_pushnumber(L, 305); lua_setfield(L, -2, "SCK_END");
	lua_pushnumber(L, 306); lua_setfield(L, -2, "SCK_PRIOR");
	lua_pushnumber(L, 307); lua_setfield(L, -2, "SCK_NEXT");
	lua_pushnumber(L, 308); lua_setfield(L, -2, "SCK_DELETE");
	lua_pushnumber(L, 309); lua_setfield(L, -2, "SCK_INSERT");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCK_ESCAPE");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCK_BACK");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCK_TAB");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCK_RETURN");
	lua_pushnumber(L, 310); lua_setfield(L, -2, "SCK_ADD");
	lua_pushnumber(L, 311); lua_setfield(L, -2, "SCK_SUBTRACT");
	lua_pushnumber(L, 312); lua_setfield(L, -2, "SCK_DIVIDE");
	lua_pushnumber(L, 313); lua_setfield(L, -2, "SCK_WIN");
	lua_pushnumber(L, 314); lua_setfield(L, -2, "SCK_RWIN");
	lua_pushnumber(L, 315); lua_setfield(L, -2, "SCK_MENU");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCMOD_NORM");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCMOD_SHIFT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCMOD_CTRL");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCMOD_ALT");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCMOD_SUPER");
	lua_pushnumber(L, 16); lua_setfield(L, -2, "SCMOD_META");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SC_AC_FILLUP");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SC_AC_DOUBLECLICK");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SC_AC_TAB");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SC_AC_NEWLINE");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SC_AC_COMMAND");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCLEX_CONTAINER");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCLEX_NULL");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCLEX_PYTHON");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCLEX_CPP");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCLEX_HTML");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCLEX_XML");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCLEX_PERL");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCLEX_SQL");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCLEX_VB");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCLEX_PROPERTIES");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCLEX_ERRORLIST");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCLEX_MAKEFILE");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCLEX_BATCH");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCLEX_XCODE");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCLEX_LATEX");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCLEX_LUA");
	lua_pushnumber(L, 16); lua_setfield(L, -2, "SCLEX_DIFF");
	lua_pushnumber(L, 17); lua_setfield(L, -2, "SCLEX_CONF");
	lua_pushnumber(L, 18); lua_setfield(L, -2, "SCLEX_PASCAL");
	lua_pushnumber(L, 19); lua_setfield(L, -2, "SCLEX_AVE");
	lua_pushnumber(L, 20); lua_setfield(L, -2, "SCLEX_ADA");
	lua_pushnumber(L, 21); lua_setfield(L, -2, "SCLEX_LISP");
	lua_pushnumber(L, 22); lua_setfield(L, -2, "SCLEX_RUBY");
	lua_pushnumber(L, 23); lua_setfield(L, -2, "SCLEX_EIFFEL");
	lua_pushnumber(L, 24); lua_setfield(L, -2, "SCLEX_EIFFELKW");
	lua_pushnumber(L, 25); lua_setfield(L, -2, "SCLEX_TCL");
	lua_pushnumber(L, 26); lua_setfield(L, -2, "SCLEX_NNCRONTAB");
	lua_pushnumber(L, 27); lua_setfield(L, -2, "SCLEX_BULLANT");
	lua_pushnumber(L, 28); lua_setfield(L, -2, "SCLEX_VBSCRIPT");
	lua_pushnumber(L, 31); lua_setfield(L, -2, "SCLEX_BAAN");
	lua_pushnumber(L, 32); lua_setfield(L, -2, "SCLEX_MATLAB");
	lua_pushnumber(L, 33); lua_setfield(L, -2, "SCLEX_SCRIPTOL");
	lua_pushnumber(L, 34); lua_setfield(L, -2, "SCLEX_ASM");
	lua_pushnumber(L, 35); lua_setfield(L, -2, "SCLEX_CPPNOCASE");
	lua_pushnumber(L, 36); lua_setfield(L, -2, "SCLEX_FORTRAN");
	lua_pushnumber(L, 37); lua_setfield(L, -2, "SCLEX_F77");
	lua_pushnumber(L, 38); lua_setfield(L, -2, "SCLEX_CSS");
	lua_pushnumber(L, 39); lua_setfield(L, -2, "SCLEX_POV");
	lua_pushnumber(L, 40); lua_setfield(L, -2, "SCLEX_LOUT");
	lua_pushnumber(L, 41); lua_setfield(L, -2, "SCLEX_ESCRIPT");
	lua_pushnumber(L, 42); lua_setfield(L, -2, "SCLEX_PS");
	lua_pushnumber(L, 43); lua_setfield(L, -2, "SCLEX_NSIS");
	lua_pushnumber(L, 44); lua_setfield(L, -2, "SCLEX_MMIXAL");
	lua_pushnumber(L, 45); lua_setfield(L, -2, "SCLEX_CLW");
	lua_pushnumber(L, 46); lua_setfield(L, -2, "SCLEX_CLWNOCASE");
	lua_pushnumber(L, 47); lua_setfield(L, -2, "SCLEX_LOT");
	lua_pushnumber(L, 48); lua_setfield(L, -2, "SCLEX_YAML");
	lua_pushnumber(L, 49); lua_setfield(L, -2, "SCLEX_TEX");
	lua_pushnumber(L, 50); lua_setfield(L, -2, "SCLEX_METAPOST");
	lua_pushnumber(L, 51); lua_setfield(L, -2, "SCLEX_POWERBASIC");
	lua_pushnumber(L, 52); lua_setfield(L, -2, "SCLEX_FORTH");
	lua_pushnumber(L, 53); lua_setfield(L, -2, "SCLEX_ERLANG");
	lua_pushnumber(L, 54); lua_setfield(L, -2, "SCLEX_OCTAVE");
	lua_pushnumber(L, 55); lua_setfield(L, -2, "SCLEX_MSSQL");
	lua_pushnumber(L, 56); lua_setfield(L, -2, "SCLEX_VERILOG");
	lua_pushnumber(L, 57); lua_setfield(L, -2, "SCLEX_KIX");
	lua_pushnumber(L, 58); lua_setfield(L, -2, "SCLEX_GUI4CLI");
	lua_pushnumber(L, 59); lua_setfield(L, -2, "SCLEX_SPECMAN");
	lua_pushnumber(L, 60); lua_setfield(L, -2, "SCLEX_AU3");
	lua_pushnumber(L, 61); lua_setfield(L, -2, "SCLEX_APDL");
	lua_pushnumber(L, 62); lua_setfield(L, -2, "SCLEX_BASH");
	lua_pushnumber(L, 63); lua_setfield(L, -2, "SCLEX_ASN1");
	lua_pushnumber(L, 64); lua_setfield(L, -2, "SCLEX_VHDL");
	lua_pushnumber(L, 65); lua_setfield(L, -2, "SCLEX_CAML");
	lua_pushnumber(L, 66); lua_setfield(L, -2, "SCLEX_BLITZBASIC");
	lua_pushnumber(L, 67); lua_setfield(L, -2, "SCLEX_PUREBASIC");
	lua_pushnumber(L, 68); lua_setfield(L, -2, "SCLEX_HASKELL");
	lua_pushnumber(L, 69); lua_setfield(L, -2, "SCLEX_PHPSCRIPT");
	lua_pushnumber(L, 70); lua_setfield(L, -2, "SCLEX_TADS3");
	lua_pushnumber(L, 71); lua_setfield(L, -2, "SCLEX_REBOL");
	lua_pushnumber(L, 72); lua_setfield(L, -2, "SCLEX_SMALLTALK");
	lua_pushnumber(L, 73); lua_setfield(L, -2, "SCLEX_FLAGSHIP");
	lua_pushnumber(L, 74); lua_setfield(L, -2, "SCLEX_CSOUND");
	lua_pushnumber(L, 75); lua_setfield(L, -2, "SCLEX_FREEBASIC");
	lua_pushnumber(L, 76); lua_setfield(L, -2, "SCLEX_INNOSETUP");
	lua_pushnumber(L, 77); lua_setfield(L, -2, "SCLEX_OPAL");
	lua_pushnumber(L, 78); lua_setfield(L, -2, "SCLEX_SPICE");
	lua_pushnumber(L, 79); lua_setfield(L, -2, "SCLEX_D");
	lua_pushnumber(L, 80); lua_setfield(L, -2, "SCLEX_CMAKE");
	lua_pushnumber(L, 81); lua_setfield(L, -2, "SCLEX_GAP");
	lua_pushnumber(L, 82); lua_setfield(L, -2, "SCLEX_PLM");
	lua_pushnumber(L, 83); lua_setfield(L, -2, "SCLEX_PROGRESS");
	lua_pushnumber(L, 84); lua_setfield(L, -2, "SCLEX_ABAQUS");
	lua_pushnumber(L, 85); lua_setfield(L, -2, "SCLEX_ASYMPTOTE");
	lua_pushnumber(L, 86); lua_setfield(L, -2, "SCLEX_R");
	lua_pushnumber(L, 87); lua_setfield(L, -2, "SCLEX_MAGIK");
	lua_pushnumber(L, 88); lua_setfield(L, -2, "SCLEX_POWERSHELL");
	lua_pushnumber(L, 89); lua_setfield(L, -2, "SCLEX_MYSQL");
	lua_pushnumber(L, 90); lua_setfield(L, -2, "SCLEX_PO");
	lua_pushnumber(L, 91); lua_setfield(L, -2, "SCLEX_TAL");
	lua_pushnumber(L, 92); lua_setfield(L, -2, "SCLEX_COBOL");
	lua_pushnumber(L, 93); lua_setfield(L, -2, "SCLEX_TACL");
	lua_pushnumber(L, 94); lua_setfield(L, -2, "SCLEX_SORCUS");
	lua_pushnumber(L, 95); lua_setfield(L, -2, "SCLEX_POWERPRO");
	lua_pushnumber(L, 96); lua_setfield(L, -2, "SCLEX_NIMROD");
	lua_pushnumber(L, 97); lua_setfield(L, -2, "SCLEX_SML");
	lua_pushnumber(L, 98); lua_setfield(L, -2, "SCLEX_MARKDOWN");
	lua_pushnumber(L, 99); lua_setfield(L, -2, "SCLEX_TXT2TAGS");
	lua_pushnumber(L, 100); lua_setfield(L, -2, "SCLEX_A68K");
	lua_pushnumber(L, 101); lua_setfield(L, -2, "SCLEX_MODULA");
	lua_pushnumber(L, 102); lua_setfield(L, -2, "SCLEX_COFFEESCRIPT");
	lua_pushnumber(L, 103); lua_setfield(L, -2, "SCLEX_TCMD");
	lua_pushnumber(L, 104); lua_setfield(L, -2, "SCLEX_AVS");
	lua_pushnumber(L, 105); lua_setfield(L, -2, "SCLEX_ECL");
	lua_pushnumber(L, 106); lua_setfield(L, -2, "SCLEX_OSCRIPT");
	lua_pushnumber(L, 107); lua_setfield(L, -2, "SCLEX_VISUALPROLOG");
	lua_pushnumber(L, 108); lua_setfield(L, -2, "SCLEX_LITERATEHASKELL");
	lua_pushnumber(L, 109); lua_setfield(L, -2, "SCLEX_STTXT");
	lua_pushnumber(L, 110); lua_setfield(L, -2, "SCLEX_KVIRC");
	lua_pushnumber(L, 111); lua_setfield(L, -2, "SCLEX_RUST");
	lua_pushnumber(L, 112); lua_setfield(L, -2, "SCLEX_DMAP");
	lua_pushnumber(L, 113); lua_setfield(L, -2, "SCLEX_AS");
	lua_pushnumber(L, 114); lua_setfield(L, -2, "SCLEX_DMIS");
	lua_pushnumber(L, 115); lua_setfield(L, -2, "SCLEX_REGISTRY");
	lua_pushnumber(L, 116); lua_setfield(L, -2, "SCLEX_BIBTEX");
	lua_pushnumber(L, 117); lua_setfield(L, -2, "SCLEX_SREC");
	lua_pushnumber(L, 118); lua_setfield(L, -2, "SCLEX_IHEX");
	lua_pushnumber(L, 119); lua_setfield(L, -2, "SCLEX_TEHEX");
	lua_pushnumber(L, 1000); lua_setfield(L, -2, "SCLEX_AUTOMATIC");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_P_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_P_COMMENTLINE");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_P_NUMBER");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_P_STRING");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_P_CHARACTER");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_P_WORD");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_P_TRIPLE");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_P_TRIPLEDOUBLE");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_P_CLASSNAME");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_P_DEFNAME");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_P_OPERATOR");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_P_IDENTIFIER");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_P_COMMENTBLOCK");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_P_STRINGEOL");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_P_WORD2");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_P_DECORATOR");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_C_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_C_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_C_COMMENTLINE");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_C_COMMENTDOC");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_C_NUMBER");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_C_WORD");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_C_STRING");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_C_CHARACTER");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_C_UUID");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_C_PREPROCESSOR");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_C_OPERATOR");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_C_IDENTIFIER");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_C_STRINGEOL");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_C_VERBATIM");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_C_REGEX");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_C_COMMENTLINEDOC");
	lua_pushnumber(L, 16); lua_setfield(L, -2, "SCE_C_WORD2");
	lua_pushnumber(L, 17); lua_setfield(L, -2, "SCE_C_COMMENTDOCKEYWORD");
	lua_pushnumber(L, 18); lua_setfield(L, -2, "SCE_C_COMMENTDOCKEYWORDERROR");
	lua_pushnumber(L, 19); lua_setfield(L, -2, "SCE_C_GLOBALCLASS");
	lua_pushnumber(L, 20); lua_setfield(L, -2, "SCE_C_STRINGRAW");
	lua_pushnumber(L, 21); lua_setfield(L, -2, "SCE_C_TRIPLEVERBATIM");
	lua_pushnumber(L, 22); lua_setfield(L, -2, "SCE_C_HASHQUOTEDSTRING");
	lua_pushnumber(L, 23); lua_setfield(L, -2, "SCE_C_PREPROCESSORCOMMENT");
	lua_pushnumber(L, 24); lua_setfield(L, -2, "SCE_C_PREPROCESSORCOMMENTDOC");
	lua_pushnumber(L, 25); lua_setfield(L, -2, "SCE_C_USERLITERAL");
	lua_pushnumber(L, 26); lua_setfield(L, -2, "SCE_C_TASKMARKER");
	lua_pushnumber(L, 27); lua_setfield(L, -2, "SCE_C_ESCAPESEQUENCE");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_D_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_D_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_D_COMMENTLINE");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_D_COMMENTDOC");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_D_COMMENTNESTED");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_D_NUMBER");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_D_WORD");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_D_WORD2");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_D_WORD3");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_D_TYPEDEF");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_D_STRING");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_D_STRINGEOL");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_D_CHARACTER");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_D_OPERATOR");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_D_IDENTIFIER");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_D_COMMENTLINEDOC");
	lua_pushnumber(L, 16); lua_setfield(L, -2, "SCE_D_COMMENTDOCKEYWORD");
	lua_pushnumber(L, 17); lua_setfield(L, -2, "SCE_D_COMMENTDOCKEYWORDERROR");
	lua_pushnumber(L, 18); lua_setfield(L, -2, "SCE_D_STRINGB");
	lua_pushnumber(L, 19); lua_setfield(L, -2, "SCE_D_STRINGR");
	lua_pushnumber(L, 20); lua_setfield(L, -2, "SCE_D_WORD5");
	lua_pushnumber(L, 21); lua_setfield(L, -2, "SCE_D_WORD6");
	lua_pushnumber(L, 22); lua_setfield(L, -2, "SCE_D_WORD7");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_TCL_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_TCL_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_TCL_COMMENTLINE");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_TCL_NUMBER");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_TCL_WORD_IN_QUOTE");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_TCL_IN_QUOTE");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_TCL_OPERATOR");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_TCL_IDENTIFIER");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_TCL_SUBSTITUTION");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_TCL_SUB_BRACE");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_TCL_MODIFIER");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_TCL_EXPAND");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_TCL_WORD");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_TCL_WORD2");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_TCL_WORD3");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_TCL_WORD4");
	lua_pushnumber(L, 16); lua_setfield(L, -2, "SCE_TCL_WORD5");
	lua_pushnumber(L, 17); lua_setfield(L, -2, "SCE_TCL_WORD6");
	lua_pushnumber(L, 18); lua_setfield(L, -2, "SCE_TCL_WORD7");
	lua_pushnumber(L, 19); lua_setfield(L, -2, "SCE_TCL_WORD8");
	lua_pushnumber(L, 20); lua_setfield(L, -2, "SCE_TCL_COMMENT_BOX");
	lua_pushnumber(L, 21); lua_setfield(L, -2, "SCE_TCL_BLOCK_COMMENT");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_H_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_H_TAG");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_H_TAGUNKNOWN");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_H_ATTRIBUTE");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_H_ATTRIBUTEUNKNOWN");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_H_NUMBER");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_H_DOUBLESTRING");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_H_SINGLESTRING");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_H_OTHER");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_H_COMMENT");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_H_ENTITY");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_H_TAGEND");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_H_XMLSTART");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_H_XMLEND");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_H_SCRIPT");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_H_ASP");
	lua_pushnumber(L, 16); lua_setfield(L, -2, "SCE_H_ASPAT");
	lua_pushnumber(L, 17); lua_setfield(L, -2, "SCE_H_CDATA");
	lua_pushnumber(L, 18); lua_setfield(L, -2, "SCE_H_QUESTION");
	lua_pushnumber(L, 19); lua_setfield(L, -2, "SCE_H_VALUE");
	lua_pushnumber(L, 20); lua_setfield(L, -2, "SCE_H_XCCOMMENT");
	lua_pushnumber(L, 21); lua_setfield(L, -2, "SCE_H_SGML_DEFAULT");
	lua_pushnumber(L, 22); lua_setfield(L, -2, "SCE_H_SGML_COMMAND");
	lua_pushnumber(L, 23); lua_setfield(L, -2, "SCE_H_SGML_1ST_PARAM");
	lua_pushnumber(L, 24); lua_setfield(L, -2, "SCE_H_SGML_DOUBLESTRING");
	lua_pushnumber(L, 25); lua_setfield(L, -2, "SCE_H_SGML_SIMPLESTRING");
	lua_pushnumber(L, 26); lua_setfield(L, -2, "SCE_H_SGML_ERROR");
	lua_pushnumber(L, 27); lua_setfield(L, -2, "SCE_H_SGML_SPECIAL");
	lua_pushnumber(L, 28); lua_setfield(L, -2, "SCE_H_SGML_ENTITY");
	lua_pushnumber(L, 29); lua_setfield(L, -2, "SCE_H_SGML_COMMENT");
	lua_pushnumber(L, 30); lua_setfield(L, -2, "SCE_H_SGML_1ST_PARAM_COMMENT");
	lua_pushnumber(L, 31); lua_setfield(L, -2, "SCE_H_SGML_BLOCK_DEFAULT");
	lua_pushnumber(L, 40); lua_setfield(L, -2, "SCE_HJ_START");
	lua_pushnumber(L, 41); lua_setfield(L, -2, "SCE_HJ_DEFAULT");
	lua_pushnumber(L, 42); lua_setfield(L, -2, "SCE_HJ_COMMENT");
	lua_pushnumber(L, 43); lua_setfield(L, -2, "SCE_HJ_COMMENTLINE");
	lua_pushnumber(L, 44); lua_setfield(L, -2, "SCE_HJ_COMMENTDOC");
	lua_pushnumber(L, 45); lua_setfield(L, -2, "SCE_HJ_NUMBER");
	lua_pushnumber(L, 46); lua_setfield(L, -2, "SCE_HJ_WORD");
	lua_pushnumber(L, 47); lua_setfield(L, -2, "SCE_HJ_KEYWORD");
	lua_pushnumber(L, 48); lua_setfield(L, -2, "SCE_HJ_DOUBLESTRING");
	lua_pushnumber(L, 49); lua_setfield(L, -2, "SCE_HJ_SINGLESTRING");
	lua_pushnumber(L, 50); lua_setfield(L, -2, "SCE_HJ_SYMBOLS");
	lua_pushnumber(L, 51); lua_setfield(L, -2, "SCE_HJ_STRINGEOL");
	lua_pushnumber(L, 52); lua_setfield(L, -2, "SCE_HJ_REGEX");
	lua_pushnumber(L, 55); lua_setfield(L, -2, "SCE_HJA_START");
	lua_pushnumber(L, 56); lua_setfield(L, -2, "SCE_HJA_DEFAULT");
	lua_pushnumber(L, 57); lua_setfield(L, -2, "SCE_HJA_COMMENT");
	lua_pushnumber(L, 58); lua_setfield(L, -2, "SCE_HJA_COMMENTLINE");
	lua_pushnumber(L, 59); lua_setfield(L, -2, "SCE_HJA_COMMENTDOC");
	lua_pushnumber(L, 60); lua_setfield(L, -2, "SCE_HJA_NUMBER");
	lua_pushnumber(L, 61); lua_setfield(L, -2, "SCE_HJA_WORD");
	lua_pushnumber(L, 62); lua_setfield(L, -2, "SCE_HJA_KEYWORD");
	lua_pushnumber(L, 63); lua_setfield(L, -2, "SCE_HJA_DOUBLESTRING");
	lua_pushnumber(L, 64); lua_setfield(L, -2, "SCE_HJA_SINGLESTRING");
	lua_pushnumber(L, 65); lua_setfield(L, -2, "SCE_HJA_SYMBOLS");
	lua_pushnumber(L, 66); lua_setfield(L, -2, "SCE_HJA_STRINGEOL");
	lua_pushnumber(L, 67); lua_setfield(L, -2, "SCE_HJA_REGEX");
	lua_pushnumber(L, 70); lua_setfield(L, -2, "SCE_HB_START");
	lua_pushnumber(L, 71); lua_setfield(L, -2, "SCE_HB_DEFAULT");
	lua_pushnumber(L, 72); lua_setfield(L, -2, "SCE_HB_COMMENTLINE");
	lua_pushnumber(L, 73); lua_setfield(L, -2, "SCE_HB_NUMBER");
	lua_pushnumber(L, 74); lua_setfield(L, -2, "SCE_HB_WORD");
	lua_pushnumber(L, 75); lua_setfield(L, -2, "SCE_HB_STRING");
	lua_pushnumber(L, 76); lua_setfield(L, -2, "SCE_HB_IDENTIFIER");
	lua_pushnumber(L, 77); lua_setfield(L, -2, "SCE_HB_STRINGEOL");
	lua_pushnumber(L, 80); lua_setfield(L, -2, "SCE_HBA_START");
	lua_pushnumber(L, 81); lua_setfield(L, -2, "SCE_HBA_DEFAULT");
	lua_pushnumber(L, 82); lua_setfield(L, -2, "SCE_HBA_COMMENTLINE");
	lua_pushnumber(L, 83); lua_setfield(L, -2, "SCE_HBA_NUMBER");
	lua_pushnumber(L, 84); lua_setfield(L, -2, "SCE_HBA_WORD");
	lua_pushnumber(L, 85); lua_setfield(L, -2, "SCE_HBA_STRING");
	lua_pushnumber(L, 86); lua_setfield(L, -2, "SCE_HBA_IDENTIFIER");
	lua_pushnumber(L, 87); lua_setfield(L, -2, "SCE_HBA_STRINGEOL");
	lua_pushnumber(L, 90); lua_setfield(L, -2, "SCE_HP_START");
	lua_pushnumber(L, 91); lua_setfield(L, -2, "SCE_HP_DEFAULT");
	lua_pushnumber(L, 92); lua_setfield(L, -2, "SCE_HP_COMMENTLINE");
	lua_pushnumber(L, 93); lua_setfield(L, -2, "SCE_HP_NUMBER");
	lua_pushnumber(L, 94); lua_setfield(L, -2, "SCE_HP_STRING");
	lua_pushnumber(L, 95); lua_setfield(L, -2, "SCE_HP_CHARACTER");
	lua_pushnumber(L, 96); lua_setfield(L, -2, "SCE_HP_WORD");
	lua_pushnumber(L, 97); lua_setfield(L, -2, "SCE_HP_TRIPLE");
	lua_pushnumber(L, 98); lua_setfield(L, -2, "SCE_HP_TRIPLEDOUBLE");
	lua_pushnumber(L, 99); lua_setfield(L, -2, "SCE_HP_CLASSNAME");
	lua_pushnumber(L, 100); lua_setfield(L, -2, "SCE_HP_DEFNAME");
	lua_pushnumber(L, 101); lua_setfield(L, -2, "SCE_HP_OPERATOR");
	lua_pushnumber(L, 102); lua_setfield(L, -2, "SCE_HP_IDENTIFIER");
	lua_pushnumber(L, 104); lua_setfield(L, -2, "SCE_HPHP_COMPLEX_VARIABLE");
	lua_pushnumber(L, 105); lua_setfield(L, -2, "SCE_HPA_START");
	lua_pushnumber(L, 106); lua_setfield(L, -2, "SCE_HPA_DEFAULT");
	lua_pushnumber(L, 107); lua_setfield(L, -2, "SCE_HPA_COMMENTLINE");
	lua_pushnumber(L, 108); lua_setfield(L, -2, "SCE_HPA_NUMBER");
	lua_pushnumber(L, 109); lua_setfield(L, -2, "SCE_HPA_STRING");
	lua_pushnumber(L, 110); lua_setfield(L, -2, "SCE_HPA_CHARACTER");
	lua_pushnumber(L, 111); lua_setfield(L, -2, "SCE_HPA_WORD");
	lua_pushnumber(L, 112); lua_setfield(L, -2, "SCE_HPA_TRIPLE");
	lua_pushnumber(L, 113); lua_setfield(L, -2, "SCE_HPA_TRIPLEDOUBLE");
	lua_pushnumber(L, 114); lua_setfield(L, -2, "SCE_HPA_CLASSNAME");
	lua_pushnumber(L, 115); lua_setfield(L, -2, "SCE_HPA_DEFNAME");
	lua_pushnumber(L, 116); lua_setfield(L, -2, "SCE_HPA_OPERATOR");
	lua_pushnumber(L, 117); lua_setfield(L, -2, "SCE_HPA_IDENTIFIER");
	lua_pushnumber(L, 118); lua_setfield(L, -2, "SCE_HPHP_DEFAULT");
	lua_pushnumber(L, 119); lua_setfield(L, -2, "SCE_HPHP_HSTRING");
	lua_pushnumber(L, 120); lua_setfield(L, -2, "SCE_HPHP_SIMPLESTRING");
	lua_pushnumber(L, 121); lua_setfield(L, -2, "SCE_HPHP_WORD");
	lua_pushnumber(L, 122); lua_setfield(L, -2, "SCE_HPHP_NUMBER");
	lua_pushnumber(L, 123); lua_setfield(L, -2, "SCE_HPHP_VARIABLE");
	lua_pushnumber(L, 124); lua_setfield(L, -2, "SCE_HPHP_COMMENT");
	lua_pushnumber(L, 125); lua_setfield(L, -2, "SCE_HPHP_COMMENTLINE");
	lua_pushnumber(L, 126); lua_setfield(L, -2, "SCE_HPHP_HSTRING_VARIABLE");
	lua_pushnumber(L, 127); lua_setfield(L, -2, "SCE_HPHP_OPERATOR");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_PL_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_PL_ERROR");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_PL_COMMENTLINE");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_PL_POD");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_PL_NUMBER");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_PL_WORD");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_PL_STRING");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_PL_CHARACTER");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_PL_PUNCTUATION");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_PL_PREPROCESSOR");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_PL_OPERATOR");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_PL_IDENTIFIER");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_PL_SCALAR");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_PL_ARRAY");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_PL_HASH");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_PL_SYMBOLTABLE");
	lua_pushnumber(L, 16); lua_setfield(L, -2, "SCE_PL_VARIABLE_INDEXER");
	lua_pushnumber(L, 17); lua_setfield(L, -2, "SCE_PL_REGEX");
	lua_pushnumber(L, 18); lua_setfield(L, -2, "SCE_PL_REGSUBST");
	lua_pushnumber(L, 19); lua_setfield(L, -2, "SCE_PL_LONGQUOTE");
	lua_pushnumber(L, 20); lua_setfield(L, -2, "SCE_PL_BACKTICKS");
	lua_pushnumber(L, 21); lua_setfield(L, -2, "SCE_PL_DATASECTION");
	lua_pushnumber(L, 22); lua_setfield(L, -2, "SCE_PL_HERE_DELIM");
	lua_pushnumber(L, 23); lua_setfield(L, -2, "SCE_PL_HERE_Q");
	lua_pushnumber(L, 24); lua_setfield(L, -2, "SCE_PL_HERE_QQ");
	lua_pushnumber(L, 25); lua_setfield(L, -2, "SCE_PL_HERE_QX");
	lua_pushnumber(L, 26); lua_setfield(L, -2, "SCE_PL_STRING_Q");
	lua_pushnumber(L, 27); lua_setfield(L, -2, "SCE_PL_STRING_QQ");
	lua_pushnumber(L, 28); lua_setfield(L, -2, "SCE_PL_STRING_QX");
	lua_pushnumber(L, 29); lua_setfield(L, -2, "SCE_PL_STRING_QR");
	lua_pushnumber(L, 30); lua_setfield(L, -2, "SCE_PL_STRING_QW");
	lua_pushnumber(L, 31); lua_setfield(L, -2, "SCE_PL_POD_VERB");
	lua_pushnumber(L, 40); lua_setfield(L, -2, "SCE_PL_SUB_PROTOTYPE");
	lua_pushnumber(L, 41); lua_setfield(L, -2, "SCE_PL_FORMAT_IDENT");
	lua_pushnumber(L, 42); lua_setfield(L, -2, "SCE_PL_FORMAT");
	lua_pushnumber(L, 43); lua_setfield(L, -2, "SCE_PL_STRING_VAR");
	lua_pushnumber(L, 44); lua_setfield(L, -2, "SCE_PL_XLAT");
	lua_pushnumber(L, 54); lua_setfield(L, -2, "SCE_PL_REGEX_VAR");
	lua_pushnumber(L, 55); lua_setfield(L, -2, "SCE_PL_REGSUBST_VAR");
	lua_pushnumber(L, 57); lua_setfield(L, -2, "SCE_PL_BACKTICKS_VAR");
	lua_pushnumber(L, 61); lua_setfield(L, -2, "SCE_PL_HERE_QQ_VAR");
	lua_pushnumber(L, 62); lua_setfield(L, -2, "SCE_PL_HERE_QX_VAR");
	lua_pushnumber(L, 64); lua_setfield(L, -2, "SCE_PL_STRING_QQ_VAR");
	lua_pushnumber(L, 65); lua_setfield(L, -2, "SCE_PL_STRING_QX_VAR");
	lua_pushnumber(L, 66); lua_setfield(L, -2, "SCE_PL_STRING_QR_VAR");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_RB_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_RB_ERROR");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_RB_COMMENTLINE");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_RB_POD");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_RB_NUMBER");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_RB_WORD");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_RB_STRING");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_RB_CHARACTER");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_RB_CLASSNAME");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_RB_DEFNAME");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_RB_OPERATOR");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_RB_IDENTIFIER");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_RB_REGEX");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_RB_GLOBAL");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_RB_SYMBOL");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_RB_MODULE_NAME");
	lua_pushnumber(L, 16); lua_setfield(L, -2, "SCE_RB_INSTANCE_VAR");
	lua_pushnumber(L, 17); lua_setfield(L, -2, "SCE_RB_CLASS_VAR");
	lua_pushnumber(L, 18); lua_setfield(L, -2, "SCE_RB_BACKTICKS");
	lua_pushnumber(L, 19); lua_setfield(L, -2, "SCE_RB_DATASECTION");
	lua_pushnumber(L, 20); lua_setfield(L, -2, "SCE_RB_HERE_DELIM");
	lua_pushnumber(L, 21); lua_setfield(L, -2, "SCE_RB_HERE_Q");
	lua_pushnumber(L, 22); lua_setfield(L, -2, "SCE_RB_HERE_QQ");
	lua_pushnumber(L, 23); lua_setfield(L, -2, "SCE_RB_HERE_QX");
	lua_pushnumber(L, 24); lua_setfield(L, -2, "SCE_RB_STRING_Q");
	lua_pushnumber(L, 25); lua_setfield(L, -2, "SCE_RB_STRING_QQ");
	lua_pushnumber(L, 26); lua_setfield(L, -2, "SCE_RB_STRING_QX");
	lua_pushnumber(L, 27); lua_setfield(L, -2, "SCE_RB_STRING_QR");
	lua_pushnumber(L, 28); lua_setfield(L, -2, "SCE_RB_STRING_QW");
	lua_pushnumber(L, 29); lua_setfield(L, -2, "SCE_RB_WORD_DEMOTED");
	lua_pushnumber(L, 30); lua_setfield(L, -2, "SCE_RB_STDIN");
	lua_pushnumber(L, 31); lua_setfield(L, -2, "SCE_RB_STDOUT");
	lua_pushnumber(L, 40); lua_setfield(L, -2, "SCE_RB_STDERR");
	lua_pushnumber(L, 41); lua_setfield(L, -2, "SCE_RB_UPPER_BOUND");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_B_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_B_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_B_NUMBER");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_B_KEYWORD");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_B_STRING");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_B_PREPROCESSOR");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_B_OPERATOR");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_B_IDENTIFIER");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_B_DATE");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_B_STRINGEOL");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_B_KEYWORD2");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_B_KEYWORD3");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_B_KEYWORD4");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_B_CONSTANT");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_B_ASM");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_B_LABEL");
	lua_pushnumber(L, 16); lua_setfield(L, -2, "SCE_B_ERROR");
	lua_pushnumber(L, 17); lua_setfield(L, -2, "SCE_B_HEXNUMBER");
	lua_pushnumber(L, 18); lua_setfield(L, -2, "SCE_B_BINNUMBER");
	lua_pushnumber(L, 19); lua_setfield(L, -2, "SCE_B_COMMENTBLOCK");
	lua_pushnumber(L, 20); lua_setfield(L, -2, "SCE_B_DOCLINE");
	lua_pushnumber(L, 21); lua_setfield(L, -2, "SCE_B_DOCBLOCK");
	lua_pushnumber(L, 22); lua_setfield(L, -2, "SCE_B_DOCKEYWORD");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_PROPS_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_PROPS_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_PROPS_SECTION");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_PROPS_ASSIGNMENT");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_PROPS_DEFVAL");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_PROPS_KEY");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_L_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_L_COMMAND");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_L_TAG");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_L_MATH");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_L_COMMENT");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_L_TAG2");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_L_MATH2");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_L_COMMENT2");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_L_VERBATIM");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_L_SHORTCMD");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_L_SPECIAL");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_L_CMDOPT");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_L_ERROR");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_LUA_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_LUA_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_LUA_COMMENTLINE");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_LUA_COMMENTDOC");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_LUA_NUMBER");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_LUA_WORD");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_LUA_STRING");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_LUA_CHARACTER");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_LUA_LITERALSTRING");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_LUA_PREPROCESSOR");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_LUA_OPERATOR");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_LUA_IDENTIFIER");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_LUA_STRINGEOL");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_LUA_WORD2");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_LUA_WORD3");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_LUA_WORD4");
	lua_pushnumber(L, 16); lua_setfield(L, -2, "SCE_LUA_WORD5");
	lua_pushnumber(L, 17); lua_setfield(L, -2, "SCE_LUA_WORD6");
	lua_pushnumber(L, 18); lua_setfield(L, -2, "SCE_LUA_WORD7");
	lua_pushnumber(L, 19); lua_setfield(L, -2, "SCE_LUA_WORD8");
	lua_pushnumber(L, 20); lua_setfield(L, -2, "SCE_LUA_LABEL");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_ERR_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_ERR_PYTHON");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_ERR_GCC");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_ERR_MS");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_ERR_CMD");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_ERR_BORLAND");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_ERR_PERL");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_ERR_NET");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_ERR_LUA");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_ERR_CTAG");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_ERR_DIFF_CHANGED");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_ERR_DIFF_ADDITION");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_ERR_DIFF_DELETION");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_ERR_DIFF_MESSAGE");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_ERR_PHP");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_ERR_ELF");
	lua_pushnumber(L, 16); lua_setfield(L, -2, "SCE_ERR_IFC");
	lua_pushnumber(L, 17); lua_setfield(L, -2, "SCE_ERR_IFORT");
	lua_pushnumber(L, 18); lua_setfield(L, -2, "SCE_ERR_ABSF");
	lua_pushnumber(L, 19); lua_setfield(L, -2, "SCE_ERR_TIDY");
	lua_pushnumber(L, 20); lua_setfield(L, -2, "SCE_ERR_JAVA_STACK");
	lua_pushnumber(L, 21); lua_setfield(L, -2, "SCE_ERR_VALUE");
	lua_pushnumber(L, 22); lua_setfield(L, -2, "SCE_ERR_GCC_INCLUDED_FROM");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_BAT_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_BAT_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_BAT_WORD");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_BAT_LABEL");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_BAT_HIDE");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_BAT_COMMAND");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_BAT_IDENTIFIER");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_BAT_OPERATOR");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_TCMD_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_TCMD_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_TCMD_WORD");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_TCMD_LABEL");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_TCMD_HIDE");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_TCMD_COMMAND");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_TCMD_IDENTIFIER");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_TCMD_OPERATOR");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_TCMD_ENVIRONMENT");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_TCMD_EXPANSION");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_TCMD_CLABEL");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_MAKE_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_MAKE_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_MAKE_PREPROCESSOR");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_MAKE_IDENTIFIER");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_MAKE_OPERATOR");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_MAKE_TARGET");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_MAKE_IDEOL");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_DIFF_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_DIFF_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_DIFF_COMMAND");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_DIFF_HEADER");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_DIFF_POSITION");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_DIFF_DELETED");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_DIFF_ADDED");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_DIFF_CHANGED");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_CONF_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_CONF_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_CONF_NUMBER");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_CONF_IDENTIFIER");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_CONF_EXTENSION");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_CONF_PARAMETER");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_CONF_STRING");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_CONF_OPERATOR");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_CONF_IP");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_CONF_DIRECTIVE");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_AVE_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_AVE_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_AVE_NUMBER");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_AVE_WORD");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_AVE_STRING");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_AVE_ENUM");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_AVE_STRINGEOL");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_AVE_IDENTIFIER");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_AVE_OPERATOR");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_AVE_WORD1");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_AVE_WORD2");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_AVE_WORD3");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_AVE_WORD4");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_AVE_WORD5");
	lua_pushnumber(L, 16); lua_setfield(L, -2, "SCE_AVE_WORD6");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_ADA_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_ADA_WORD");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_ADA_IDENTIFIER");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_ADA_NUMBER");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_ADA_DELIMITER");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_ADA_CHARACTER");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_ADA_CHARACTEREOL");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_ADA_STRING");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_ADA_STRINGEOL");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_ADA_LABEL");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_ADA_COMMENTLINE");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_ADA_ILLEGAL");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_BAAN_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_BAAN_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_BAAN_COMMENTDOC");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_BAAN_NUMBER");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_BAAN_WORD");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_BAAN_STRING");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_BAAN_PREPROCESSOR");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_BAAN_OPERATOR");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_BAAN_IDENTIFIER");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_BAAN_STRINGEOL");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_BAAN_WORD2");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_LISP_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_LISP_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_LISP_NUMBER");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_LISP_KEYWORD");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_LISP_KEYWORD_KW");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_LISP_SYMBOL");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_LISP_STRING");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_LISP_STRINGEOL");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_LISP_IDENTIFIER");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_LISP_OPERATOR");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_LISP_SPECIAL");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_LISP_MULTI_COMMENT");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_EIFFEL_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_EIFFEL_COMMENTLINE");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_EIFFEL_NUMBER");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_EIFFEL_WORD");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_EIFFEL_STRING");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_EIFFEL_CHARACTER");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_EIFFEL_OPERATOR");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_EIFFEL_IDENTIFIER");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_EIFFEL_STRINGEOL");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_NNCRONTAB_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_NNCRONTAB_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_NNCRONTAB_TASK");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_NNCRONTAB_SECTION");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_NNCRONTAB_KEYWORD");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_NNCRONTAB_MODIFIER");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_NNCRONTAB_ASTERISK");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_NNCRONTAB_NUMBER");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_NNCRONTAB_STRING");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_NNCRONTAB_ENVIRONMENT");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_NNCRONTAB_IDENTIFIER");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_FORTH_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_FORTH_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_FORTH_COMMENT_ML");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_FORTH_IDENTIFIER");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_FORTH_CONTROL");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_FORTH_KEYWORD");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_FORTH_DEFWORD");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_FORTH_PREWORD1");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_FORTH_PREWORD2");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_FORTH_NUMBER");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_FORTH_STRING");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_FORTH_LOCALE");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_MATLAB_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_MATLAB_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_MATLAB_COMMAND");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_MATLAB_NUMBER");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_MATLAB_KEYWORD");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_MATLAB_STRING");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_MATLAB_OPERATOR");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_MATLAB_IDENTIFIER");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_MATLAB_DOUBLEQUOTESTRING");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_SCRIPTOL_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_SCRIPTOL_WHITE");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_SCRIPTOL_COMMENTLINE");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_SCRIPTOL_PERSISTENT");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_SCRIPTOL_CSTYLE");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_SCRIPTOL_COMMENTBLOCK");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_SCRIPTOL_NUMBER");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_SCRIPTOL_STRING");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_SCRIPTOL_CHARACTER");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_SCRIPTOL_STRINGEOL");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_SCRIPTOL_KEYWORD");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_SCRIPTOL_OPERATOR");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_SCRIPTOL_IDENTIFIER");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_SCRIPTOL_TRIPLE");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_SCRIPTOL_CLASSNAME");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_SCRIPTOL_PREPROCESSOR");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_ASM_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_ASM_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_ASM_NUMBER");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_ASM_STRING");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_ASM_OPERATOR");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_ASM_IDENTIFIER");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_ASM_CPUINSTRUCTION");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_ASM_MATHINSTRUCTION");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_ASM_REGISTER");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_ASM_DIRECTIVE");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_ASM_DIRECTIVEOPERAND");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_ASM_COMMENTBLOCK");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_ASM_CHARACTER");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_ASM_STRINGEOL");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_ASM_EXTINSTRUCTION");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_ASM_COMMENTDIRECTIVE");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_F_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_F_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_F_NUMBER");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_F_STRING1");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_F_STRING2");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_F_STRINGEOL");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_F_OPERATOR");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_F_IDENTIFIER");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_F_WORD");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_F_WORD2");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_F_WORD3");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_F_PREPROCESSOR");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_F_OPERATOR2");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_F_LABEL");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_F_CONTINUATION");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_CSS_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_CSS_TAG");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_CSS_CLASS");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_CSS_PSEUDOCLASS");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_CSS_UNKNOWN_PSEUDOCLASS");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_CSS_OPERATOR");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_CSS_IDENTIFIER");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_CSS_UNKNOWN_IDENTIFIER");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_CSS_VALUE");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_CSS_COMMENT");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_CSS_ID");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_CSS_IMPORTANT");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_CSS_DIRECTIVE");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_CSS_DOUBLESTRING");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_CSS_SINGLESTRING");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_CSS_IDENTIFIER2");
	lua_pushnumber(L, 16); lua_setfield(L, -2, "SCE_CSS_ATTRIBUTE");
	lua_pushnumber(L, 17); lua_setfield(L, -2, "SCE_CSS_IDENTIFIER3");
	lua_pushnumber(L, 18); lua_setfield(L, -2, "SCE_CSS_PSEUDOELEMENT");
	lua_pushnumber(L, 19); lua_setfield(L, -2, "SCE_CSS_EXTENDED_IDENTIFIER");
	lua_pushnumber(L, 20); lua_setfield(L, -2, "SCE_CSS_EXTENDED_PSEUDOCLASS");
	lua_pushnumber(L, 21); lua_setfield(L, -2, "SCE_CSS_EXTENDED_PSEUDOELEMENT");
	lua_pushnumber(L, 22); lua_setfield(L, -2, "SCE_CSS_MEDIA");
	lua_pushnumber(L, 23); lua_setfield(L, -2, "SCE_CSS_VARIABLE");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_POV_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_POV_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_POV_COMMENTLINE");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_POV_NUMBER");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_POV_OPERATOR");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_POV_IDENTIFIER");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_POV_STRING");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_POV_STRINGEOL");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_POV_DIRECTIVE");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_POV_BADDIRECTIVE");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_POV_WORD2");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_POV_WORD3");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_POV_WORD4");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_POV_WORD5");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_POV_WORD6");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_POV_WORD7");
	lua_pushnumber(L, 16); lua_setfield(L, -2, "SCE_POV_WORD8");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_LOUT_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_LOUT_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_LOUT_NUMBER");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_LOUT_WORD");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_LOUT_WORD2");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_LOUT_WORD3");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_LOUT_WORD4");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_LOUT_STRING");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_LOUT_OPERATOR");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_LOUT_IDENTIFIER");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_LOUT_STRINGEOL");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_ESCRIPT_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_ESCRIPT_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_ESCRIPT_COMMENTLINE");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_ESCRIPT_COMMENTDOC");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_ESCRIPT_NUMBER");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_ESCRIPT_WORD");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_ESCRIPT_STRING");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_ESCRIPT_OPERATOR");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_ESCRIPT_IDENTIFIER");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_ESCRIPT_BRACE");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_ESCRIPT_WORD2");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_ESCRIPT_WORD3");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_PS_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_PS_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_PS_DSC_COMMENT");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_PS_DSC_VALUE");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_PS_NUMBER");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_PS_NAME");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_PS_KEYWORD");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_PS_LITERAL");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_PS_IMMEVAL");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_PS_PAREN_ARRAY");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_PS_PAREN_DICT");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_PS_PAREN_PROC");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_PS_TEXT");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_PS_HEXSTRING");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_PS_BASE85STRING");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_PS_BADSTRINGCHAR");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_NSIS_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_NSIS_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_NSIS_STRINGDQ");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_NSIS_STRINGLQ");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_NSIS_STRINGRQ");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_NSIS_FUNCTION");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_NSIS_VARIABLE");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_NSIS_LABEL");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_NSIS_USERDEFINED");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_NSIS_SECTIONDEF");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_NSIS_SUBSECTIONDEF");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_NSIS_IFDEFINEDEF");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_NSIS_MACRODEF");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_NSIS_STRINGVAR");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_NSIS_NUMBER");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_NSIS_SECTIONGROUP");
	lua_pushnumber(L, 16); lua_setfield(L, -2, "SCE_NSIS_PAGEEX");
	lua_pushnumber(L, 17); lua_setfield(L, -2, "SCE_NSIS_FUNCTIONDEF");
	lua_pushnumber(L, 18); lua_setfield(L, -2, "SCE_NSIS_COMMENTBOX");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_MMIXAL_LEADWS");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_MMIXAL_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_MMIXAL_LABEL");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_MMIXAL_OPCODE");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_MMIXAL_OPCODE_PRE");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_MMIXAL_OPCODE_VALID");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_MMIXAL_OPCODE_UNKNOWN");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_MMIXAL_OPCODE_POST");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_MMIXAL_OPERANDS");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_MMIXAL_NUMBER");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_MMIXAL_REF");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_MMIXAL_CHAR");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_MMIXAL_STRING");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_MMIXAL_REGISTER");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_MMIXAL_HEX");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_MMIXAL_OPERATOR");
	lua_pushnumber(L, 16); lua_setfield(L, -2, "SCE_MMIXAL_SYMBOL");
	lua_pushnumber(L, 17); lua_setfield(L, -2, "SCE_MMIXAL_INCLUDE");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_CLW_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_CLW_LABEL");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_CLW_COMMENT");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_CLW_STRING");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_CLW_USER_IDENTIFIER");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_CLW_INTEGER_CONSTANT");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_CLW_REAL_CONSTANT");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_CLW_PICTURE_STRING");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_CLW_KEYWORD");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_CLW_COMPILER_DIRECTIVE");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_CLW_RUNTIME_EXPRESSIONS");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_CLW_BUILTIN_PROCEDURES_FUNCTION");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_CLW_STRUCTURE_DATA_TYPE");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_CLW_ATTRIBUTE");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_CLW_STANDARD_EQUATE");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_CLW_ERROR");
	lua_pushnumber(L, 16); lua_setfield(L, -2, "SCE_CLW_DEPRECATED");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_LOT_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_LOT_HEADER");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_LOT_BREAK");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_LOT_SET");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_LOT_PASS");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_LOT_FAIL");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_LOT_ABORT");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_YAML_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_YAML_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_YAML_IDENTIFIER");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_YAML_KEYWORD");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_YAML_NUMBER");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_YAML_REFERENCE");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_YAML_DOCUMENT");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_YAML_TEXT");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_YAML_ERROR");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_YAML_OPERATOR");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_TEX_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_TEX_SPECIAL");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_TEX_GROUP");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_TEX_SYMBOL");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_TEX_COMMAND");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_TEX_TEXT");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_METAPOST_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_METAPOST_SPECIAL");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_METAPOST_GROUP");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_METAPOST_SYMBOL");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_METAPOST_COMMAND");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_METAPOST_TEXT");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_METAPOST_EXTRA");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_ERLANG_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_ERLANG_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_ERLANG_VARIABLE");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_ERLANG_NUMBER");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_ERLANG_KEYWORD");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_ERLANG_STRING");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_ERLANG_OPERATOR");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_ERLANG_ATOM");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_ERLANG_FUNCTION_NAME");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_ERLANG_CHARACTER");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_ERLANG_MACRO");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_ERLANG_RECORD");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_ERLANG_PREPROC");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_ERLANG_NODE_NAME");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_ERLANG_COMMENT_FUNCTION");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_ERLANG_COMMENT_MODULE");
	lua_pushnumber(L, 16); lua_setfield(L, -2, "SCE_ERLANG_COMMENT_DOC");
	lua_pushnumber(L, 17); lua_setfield(L, -2, "SCE_ERLANG_COMMENT_DOC_MACRO");
	lua_pushnumber(L, 18); lua_setfield(L, -2, "SCE_ERLANG_ATOM_QUOTED");
	lua_pushnumber(L, 19); lua_setfield(L, -2, "SCE_ERLANG_MACRO_QUOTED");
	lua_pushnumber(L, 20); lua_setfield(L, -2, "SCE_ERLANG_RECORD_QUOTED");
	lua_pushnumber(L, 21); lua_setfield(L, -2, "SCE_ERLANG_NODE_NAME_QUOTED");
	lua_pushnumber(L, 22); lua_setfield(L, -2, "SCE_ERLANG_BIFS");
	lua_pushnumber(L, 23); lua_setfield(L, -2, "SCE_ERLANG_MODULES");
	lua_pushnumber(L, 24); lua_setfield(L, -2, "SCE_ERLANG_MODULES_ATT");
	lua_pushnumber(L, 31); lua_setfield(L, -2, "SCE_ERLANG_UNKNOWN");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_MSSQL_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_MSSQL_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_MSSQL_LINE_COMMENT");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_MSSQL_NUMBER");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_MSSQL_STRING");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_MSSQL_OPERATOR");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_MSSQL_IDENTIFIER");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_MSSQL_VARIABLE");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_MSSQL_COLUMN_NAME");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_MSSQL_STATEMENT");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_MSSQL_DATATYPE");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_MSSQL_SYSTABLE");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_MSSQL_GLOBAL_VARIABLE");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_MSSQL_FUNCTION");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_MSSQL_STORED_PROCEDURE");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_MSSQL_DEFAULT_PREF_DATATYPE");
	lua_pushnumber(L, 16); lua_setfield(L, -2, "SCE_MSSQL_COLUMN_NAME_2");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_V_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_V_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_V_COMMENTLINE");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_V_COMMENTLINEBANG");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_V_NUMBER");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_V_WORD");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_V_STRING");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_V_WORD2");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_V_WORD3");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_V_PREPROCESSOR");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_V_OPERATOR");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_V_IDENTIFIER");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_V_STRINGEOL");
	lua_pushnumber(L, 19); lua_setfield(L, -2, "SCE_V_USER");
	lua_pushnumber(L, 20); lua_setfield(L, -2, "SCE_V_COMMENT_WORD");
	lua_pushnumber(L, 21); lua_setfield(L, -2, "SCE_V_INPUT");
	lua_pushnumber(L, 22); lua_setfield(L, -2, "SCE_V_OUTPUT");
	lua_pushnumber(L, 23); lua_setfield(L, -2, "SCE_V_INOUT");
	lua_pushnumber(L, 24); lua_setfield(L, -2, "SCE_V_PORT_CONNECT");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_KIX_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_KIX_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_KIX_STRING1");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_KIX_STRING2");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_KIX_NUMBER");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_KIX_VAR");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_KIX_MACRO");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_KIX_KEYWORD");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_KIX_FUNCTIONS");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_KIX_OPERATOR");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_KIX_COMMENTSTREAM");
	lua_pushnumber(L, 31); lua_setfield(L, -2, "SCE_KIX_IDENTIFIER");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_GC_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_GC_COMMENTLINE");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_GC_COMMENTBLOCK");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_GC_GLOBAL");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_GC_EVENT");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_GC_ATTRIBUTE");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_GC_CONTROL");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_GC_COMMAND");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_GC_STRING");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_GC_OPERATOR");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_SN_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_SN_CODE");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_SN_COMMENTLINE");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_SN_COMMENTLINEBANG");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_SN_NUMBER");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_SN_WORD");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_SN_STRING");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_SN_WORD2");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_SN_WORD3");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_SN_PREPROCESSOR");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_SN_OPERATOR");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_SN_IDENTIFIER");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_SN_STRINGEOL");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_SN_REGEXTAG");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_SN_SIGNAL");
	lua_pushnumber(L, 19); lua_setfield(L, -2, "SCE_SN_USER");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_AU3_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_AU3_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_AU3_COMMENTBLOCK");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_AU3_NUMBER");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_AU3_FUNCTION");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_AU3_KEYWORD");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_AU3_MACRO");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_AU3_STRING");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_AU3_OPERATOR");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_AU3_VARIABLE");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_AU3_SENT");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_AU3_PREPROCESSOR");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_AU3_SPECIAL");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_AU3_EXPAND");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_AU3_COMOBJ");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_AU3_UDF");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_APDL_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_APDL_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_APDL_COMMENTBLOCK");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_APDL_NUMBER");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_APDL_STRING");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_APDL_OPERATOR");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_APDL_WORD");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_APDL_PROCESSOR");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_APDL_COMMAND");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_APDL_SLASHCOMMAND");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_APDL_STARCOMMAND");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_APDL_ARGUMENT");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_APDL_FUNCTION");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_SH_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_SH_ERROR");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_SH_COMMENTLINE");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_SH_NUMBER");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_SH_WORD");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_SH_STRING");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_SH_CHARACTER");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_SH_OPERATOR");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_SH_IDENTIFIER");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_SH_SCALAR");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_SH_PARAM");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_SH_BACKTICKS");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_SH_HERE_DELIM");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_SH_HERE_Q");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_ASN1_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_ASN1_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_ASN1_IDENTIFIER");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_ASN1_STRING");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_ASN1_OID");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_ASN1_SCALAR");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_ASN1_KEYWORD");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_ASN1_ATTRIBUTE");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_ASN1_DESCRIPTOR");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_ASN1_TYPE");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_ASN1_OPERATOR");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_VHDL_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_VHDL_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_VHDL_COMMENTLINEBANG");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_VHDL_NUMBER");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_VHDL_STRING");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_VHDL_OPERATOR");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_VHDL_IDENTIFIER");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_VHDL_STRINGEOL");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_VHDL_KEYWORD");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_VHDL_STDOPERATOR");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_VHDL_ATTRIBUTE");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_VHDL_STDFUNCTION");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_VHDL_STDPACKAGE");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_VHDL_STDTYPE");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_VHDL_USERWORD");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_VHDL_BLOCK_COMMENT");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_CAML_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_CAML_IDENTIFIER");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_CAML_TAGNAME");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_CAML_KEYWORD");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_CAML_KEYWORD2");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_CAML_KEYWORD3");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_CAML_LINENUM");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_CAML_OPERATOR");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_CAML_NUMBER");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_CAML_CHAR");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_CAML_WHITE");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_CAML_STRING");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_CAML_COMMENT");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_CAML_COMMENT1");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_CAML_COMMENT2");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_CAML_COMMENT3");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_HA_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_HA_IDENTIFIER");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_HA_KEYWORD");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_HA_NUMBER");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_HA_STRING");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_HA_CHARACTER");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_HA_CLASS");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_HA_MODULE");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_HA_CAPITAL");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_HA_DATA");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_HA_IMPORT");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_HA_OPERATOR");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_HA_INSTANCE");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_HA_COMMENTLINE");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_HA_COMMENTBLOCK");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_HA_COMMENTBLOCK2");
	lua_pushnumber(L, 16); lua_setfield(L, -2, "SCE_HA_COMMENTBLOCK3");
	lua_pushnumber(L, 17); lua_setfield(L, -2, "SCE_HA_PRAGMA");
	lua_pushnumber(L, 18); lua_setfield(L, -2, "SCE_HA_PREPROCESSOR");
	lua_pushnumber(L, 19); lua_setfield(L, -2, "SCE_HA_STRINGEOL");
	lua_pushnumber(L, 20); lua_setfield(L, -2, "SCE_HA_RESERVED_OPERATOR");
	lua_pushnumber(L, 21); lua_setfield(L, -2, "SCE_HA_LITERATE_COMMENT");
	lua_pushnumber(L, 22); lua_setfield(L, -2, "SCE_HA_LITERATE_CODEDELIM");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_T3_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_T3_X_DEFAULT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_T3_PREPROCESSOR");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_T3_BLOCK_COMMENT");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_T3_LINE_COMMENT");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_T3_OPERATOR");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_T3_KEYWORD");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_T3_NUMBER");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_T3_IDENTIFIER");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_T3_S_STRING");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_T3_D_STRING");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_T3_X_STRING");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_T3_LIB_DIRECTIVE");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_T3_MSG_PARAM");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_T3_HTML_TAG");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_T3_HTML_DEFAULT");
	lua_pushnumber(L, 16); lua_setfield(L, -2, "SCE_T3_HTML_STRING");
	lua_pushnumber(L, 17); lua_setfield(L, -2, "SCE_T3_USER1");
	lua_pushnumber(L, 18); lua_setfield(L, -2, "SCE_T3_USER2");
	lua_pushnumber(L, 19); lua_setfield(L, -2, "SCE_T3_USER3");
	lua_pushnumber(L, 20); lua_setfield(L, -2, "SCE_T3_BRACE");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_REBOL_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_REBOL_COMMENTLINE");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_REBOL_COMMENTBLOCK");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_REBOL_PREFACE");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_REBOL_OPERATOR");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_REBOL_CHARACTER");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_REBOL_QUOTEDSTRING");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_REBOL_BRACEDSTRING");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_REBOL_NUMBER");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_REBOL_PAIR");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_REBOL_TUPLE");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_REBOL_BINARY");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_REBOL_MONEY");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_REBOL_ISSUE");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_REBOL_TAG");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_REBOL_FILE");
	lua_pushnumber(L, 16); lua_setfield(L, -2, "SCE_REBOL_EMAIL");
	lua_pushnumber(L, 17); lua_setfield(L, -2, "SCE_REBOL_URL");
	lua_pushnumber(L, 18); lua_setfield(L, -2, "SCE_REBOL_DATE");
	lua_pushnumber(L, 19); lua_setfield(L, -2, "SCE_REBOL_TIME");
	lua_pushnumber(L, 20); lua_setfield(L, -2, "SCE_REBOL_IDENTIFIER");
	lua_pushnumber(L, 21); lua_setfield(L, -2, "SCE_REBOL_WORD");
	lua_pushnumber(L, 22); lua_setfield(L, -2, "SCE_REBOL_WORD2");
	lua_pushnumber(L, 23); lua_setfield(L, -2, "SCE_REBOL_WORD3");
	lua_pushnumber(L, 24); lua_setfield(L, -2, "SCE_REBOL_WORD4");
	lua_pushnumber(L, 25); lua_setfield(L, -2, "SCE_REBOL_WORD5");
	lua_pushnumber(L, 26); lua_setfield(L, -2, "SCE_REBOL_WORD6");
	lua_pushnumber(L, 27); lua_setfield(L, -2, "SCE_REBOL_WORD7");
	lua_pushnumber(L, 28); lua_setfield(L, -2, "SCE_REBOL_WORD8");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_SQL_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_SQL_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_SQL_COMMENTLINE");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_SQL_COMMENTDOC");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_SQL_NUMBER");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_SQL_WORD");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_SQL_STRING");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_SQL_CHARACTER");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_SQL_SQLPLUS");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_SQL_SQLPLUS_PROMPT");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_SQL_OPERATOR");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_SQL_IDENTIFIER");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_SQL_SQLPLUS_COMMENT");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_SQL_COMMENTLINEDOC");
	lua_pushnumber(L, 16); lua_setfield(L, -2, "SCE_SQL_WORD2");
	lua_pushnumber(L, 17); lua_setfield(L, -2, "SCE_SQL_COMMENTDOCKEYWORD");
	lua_pushnumber(L, 18); lua_setfield(L, -2, "SCE_SQL_COMMENTDOCKEYWORDERROR");
	lua_pushnumber(L, 19); lua_setfield(L, -2, "SCE_SQL_USER1");
	lua_pushnumber(L, 20); lua_setfield(L, -2, "SCE_SQL_USER2");
	lua_pushnumber(L, 21); lua_setfield(L, -2, "SCE_SQL_USER3");
	lua_pushnumber(L, 22); lua_setfield(L, -2, "SCE_SQL_USER4");
	lua_pushnumber(L, 23); lua_setfield(L, -2, "SCE_SQL_QUOTEDIDENTIFIER");
	lua_pushnumber(L, 24); lua_setfield(L, -2, "SCE_SQL_QOPERATOR");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_ST_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_ST_STRING");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_ST_NUMBER");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_ST_COMMENT");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_ST_SYMBOL");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_ST_BINARY");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_ST_BOOL");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_ST_SELF");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_ST_SUPER");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_ST_NIL");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_ST_GLOBAL");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_ST_RETURN");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_ST_SPECIAL");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_ST_KWSEND");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_ST_ASSIGN");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_ST_CHARACTER");
	lua_pushnumber(L, 16); lua_setfield(L, -2, "SCE_ST_SPEC_SEL");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_FS_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_FS_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_FS_COMMENTLINE");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_FS_COMMENTDOC");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_FS_COMMENTLINEDOC");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_FS_COMMENTDOCKEYWORD");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_FS_COMMENTDOCKEYWORDERROR");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_FS_KEYWORD");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_FS_KEYWORD2");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_FS_KEYWORD3");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_FS_KEYWORD4");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_FS_NUMBER");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_FS_STRING");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_FS_PREPROCESSOR");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_FS_OPERATOR");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_FS_IDENTIFIER");
	lua_pushnumber(L, 16); lua_setfield(L, -2, "SCE_FS_DATE");
	lua_pushnumber(L, 17); lua_setfield(L, -2, "SCE_FS_STRINGEOL");
	lua_pushnumber(L, 18); lua_setfield(L, -2, "SCE_FS_CONSTANT");
	lua_pushnumber(L, 19); lua_setfield(L, -2, "SCE_FS_WORDOPERATOR");
	lua_pushnumber(L, 20); lua_setfield(L, -2, "SCE_FS_DISABLEDCODE");
	lua_pushnumber(L, 21); lua_setfield(L, -2, "SCE_FS_DEFAULT_C");
	lua_pushnumber(L, 22); lua_setfield(L, -2, "SCE_FS_COMMENTDOC_C");
	lua_pushnumber(L, 23); lua_setfield(L, -2, "SCE_FS_COMMENTLINEDOC_C");
	lua_pushnumber(L, 24); lua_setfield(L, -2, "SCE_FS_KEYWORD_C");
	lua_pushnumber(L, 25); lua_setfield(L, -2, "SCE_FS_KEYWORD2_C");
	lua_pushnumber(L, 26); lua_setfield(L, -2, "SCE_FS_NUMBER_C");
	lua_pushnumber(L, 27); lua_setfield(L, -2, "SCE_FS_STRING_C");
	lua_pushnumber(L, 28); lua_setfield(L, -2, "SCE_FS_PREPROCESSOR_C");
	lua_pushnumber(L, 29); lua_setfield(L, -2, "SCE_FS_OPERATOR_C");
	lua_pushnumber(L, 30); lua_setfield(L, -2, "SCE_FS_IDENTIFIER_C");
	lua_pushnumber(L, 31); lua_setfield(L, -2, "SCE_FS_STRINGEOL_C");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_CSOUND_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_CSOUND_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_CSOUND_NUMBER");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_CSOUND_OPERATOR");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_CSOUND_INSTR");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_CSOUND_IDENTIFIER");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_CSOUND_OPCODE");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_CSOUND_HEADERSTMT");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_CSOUND_USERKEYWORD");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_CSOUND_COMMENTBLOCK");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_CSOUND_PARAM");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_CSOUND_ARATE_VAR");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_CSOUND_KRATE_VAR");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_CSOUND_IRATE_VAR");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_CSOUND_GLOBAL_VAR");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_CSOUND_STRINGEOL");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_INNO_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_INNO_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_INNO_KEYWORD");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_INNO_PARAMETER");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_INNO_SECTION");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_INNO_PREPROC");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_INNO_INLINE_EXPANSION");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_INNO_COMMENT_PASCAL");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_INNO_KEYWORD_PASCAL");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_INNO_KEYWORD_USER");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_INNO_STRING_DOUBLE");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_INNO_STRING_SINGLE");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_INNO_IDENTIFIER");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_OPAL_SPACE");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_OPAL_COMMENT_BLOCK");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_OPAL_COMMENT_LINE");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_OPAL_INTEGER");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_OPAL_KEYWORD");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_OPAL_SORT");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_OPAL_STRING");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_OPAL_PAR");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_OPAL_BOOL_CONST");
	lua_pushnumber(L, 32); lua_setfield(L, -2, "SCE_OPAL_DEFAULT");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_SPICE_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_SPICE_IDENTIFIER");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_SPICE_KEYWORD");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_SPICE_KEYWORD2");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_SPICE_KEYWORD3");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_SPICE_NUMBER");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_SPICE_DELIMITER");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_SPICE_VALUE");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_SPICE_COMMENTLINE");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_CMAKE_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_CMAKE_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_CMAKE_STRINGDQ");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_CMAKE_STRINGLQ");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_CMAKE_STRINGRQ");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_CMAKE_COMMANDS");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_CMAKE_PARAMETERS");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_CMAKE_VARIABLE");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_CMAKE_USERDEFINED");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_CMAKE_WHILEDEF");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_CMAKE_FOREACHDEF");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_CMAKE_IFDEFINEDEF");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_CMAKE_MACRODEF");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_CMAKE_STRINGVAR");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_CMAKE_NUMBER");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_GAP_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_GAP_IDENTIFIER");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_GAP_KEYWORD");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_GAP_KEYWORD2");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_GAP_KEYWORD3");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_GAP_KEYWORD4");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_GAP_STRING");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_GAP_CHAR");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_GAP_OPERATOR");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_GAP_COMMENT");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_GAP_NUMBER");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_GAP_STRINGEOL");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_PLM_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_PLM_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_PLM_STRING");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_PLM_NUMBER");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_PLM_IDENTIFIER");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_PLM_OPERATOR");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_PLM_CONTROL");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_PLM_KEYWORD");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_4GL_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_4GL_NUMBER");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_4GL_WORD");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_4GL_STRING");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_4GL_CHARACTER");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_4GL_PREPROCESSOR");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_4GL_OPERATOR");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_4GL_IDENTIFIER");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_4GL_BLOCK");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_4GL_END");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_4GL_COMMENT1");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_4GL_COMMENT2");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_4GL_COMMENT3");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_4GL_COMMENT4");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_4GL_COMMENT5");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_4GL_COMMENT6");
	lua_pushnumber(L, 16); lua_setfield(L, -2, "SCE_4GL_DEFAULT_");
	lua_pushnumber(L, 17); lua_setfield(L, -2, "SCE_4GL_NUMBER_");
	lua_pushnumber(L, 18); lua_setfield(L, -2, "SCE_4GL_WORD_");
	lua_pushnumber(L, 19); lua_setfield(L, -2, "SCE_4GL_STRING_");
	lua_pushnumber(L, 20); lua_setfield(L, -2, "SCE_4GL_CHARACTER_");
	lua_pushnumber(L, 21); lua_setfield(L, -2, "SCE_4GL_PREPROCESSOR_");
	lua_pushnumber(L, 22); lua_setfield(L, -2, "SCE_4GL_OPERATOR_");
	lua_pushnumber(L, 23); lua_setfield(L, -2, "SCE_4GL_IDENTIFIER_");
	lua_pushnumber(L, 24); lua_setfield(L, -2, "SCE_4GL_BLOCK_");
	lua_pushnumber(L, 25); lua_setfield(L, -2, "SCE_4GL_END_");
	lua_pushnumber(L, 26); lua_setfield(L, -2, "SCE_4GL_COMMENT1_");
	lua_pushnumber(L, 27); lua_setfield(L, -2, "SCE_4GL_COMMENT2_");
	lua_pushnumber(L, 28); lua_setfield(L, -2, "SCE_4GL_COMMENT3_");
	lua_pushnumber(L, 29); lua_setfield(L, -2, "SCE_4GL_COMMENT4_");
	lua_pushnumber(L, 30); lua_setfield(L, -2, "SCE_4GL_COMMENT5_");
	lua_pushnumber(L, 31); lua_setfield(L, -2, "SCE_4GL_COMMENT6_");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_ABAQUS_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_ABAQUS_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_ABAQUS_COMMENTBLOCK");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_ABAQUS_NUMBER");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_ABAQUS_STRING");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_ABAQUS_OPERATOR");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_ABAQUS_WORD");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_ABAQUS_PROCESSOR");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_ABAQUS_COMMAND");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_ABAQUS_SLASHCOMMAND");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_ABAQUS_STARCOMMAND");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_ABAQUS_ARGUMENT");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_ABAQUS_FUNCTION");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_ASY_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_ASY_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_ASY_COMMENTLINE");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_ASY_NUMBER");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_ASY_WORD");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_ASY_STRING");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_ASY_CHARACTER");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_ASY_OPERATOR");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_ASY_IDENTIFIER");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_ASY_STRINGEOL");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_ASY_COMMENTLINEDOC");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_ASY_WORD2");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_R_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_R_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_R_KWORD");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_R_BASEKWORD");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_R_OTHERKWORD");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_R_NUMBER");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_R_STRING");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_R_STRING2");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_R_OPERATOR");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_R_IDENTIFIER");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_R_INFIX");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_R_INFIXEOL");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_MAGIK_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_MAGIK_COMMENT");
	lua_pushnumber(L, 16); lua_setfield(L, -2, "SCE_MAGIK_HYPER_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_MAGIK_STRING");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_MAGIK_CHARACTER");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_MAGIK_NUMBER");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_MAGIK_IDENTIFIER");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_MAGIK_OPERATOR");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_MAGIK_FLOW");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_MAGIK_CONTAINER");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_MAGIK_BRACKET_BLOCK");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_MAGIK_BRACE_BLOCK");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_MAGIK_SQBRACKET_BLOCK");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_MAGIK_UNKNOWN_KEYWORD");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_MAGIK_KEYWORD");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_MAGIK_PRAGMA");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_MAGIK_SYMBOL");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_POWERSHELL_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_POWERSHELL_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_POWERSHELL_STRING");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_POWERSHELL_CHARACTER");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_POWERSHELL_NUMBER");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_POWERSHELL_VARIABLE");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_POWERSHELL_OPERATOR");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_POWERSHELL_IDENTIFIER");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_POWERSHELL_KEYWORD");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_POWERSHELL_CMDLET");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_POWERSHELL_ALIAS");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_POWERSHELL_FUNCTION");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_POWERSHELL_USER1");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_POWERSHELL_COMMENTSTREAM");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_POWERSHELL_HERE_STRING");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_POWERSHELL_HERE_CHARACTER");
	lua_pushnumber(L, 16); lua_setfield(L, -2, "SCE_POWERSHELL_COMMENTDOCKEYWORD");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_MYSQL_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_MYSQL_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_MYSQL_COMMENTLINE");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_MYSQL_VARIABLE");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_MYSQL_SYSTEMVARIABLE");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_MYSQL_KNOWNSYSTEMVARIABLE");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_MYSQL_NUMBER");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_MYSQL_MAJORKEYWORD");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_MYSQL_KEYWORD");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_MYSQL_DATABASEOBJECT");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_MYSQL_PROCEDUREKEYWORD");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_MYSQL_STRING");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_MYSQL_SQSTRING");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_MYSQL_DQSTRING");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_MYSQL_OPERATOR");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_MYSQL_FUNCTION");
	lua_pushnumber(L, 16); lua_setfield(L, -2, "SCE_MYSQL_IDENTIFIER");
	lua_pushnumber(L, 17); lua_setfield(L, -2, "SCE_MYSQL_QUOTEDIDENTIFIER");
	lua_pushnumber(L, 18); lua_setfield(L, -2, "SCE_MYSQL_USER1");
	lua_pushnumber(L, 19); lua_setfield(L, -2, "SCE_MYSQL_USER2");
	lua_pushnumber(L, 20); lua_setfield(L, -2, "SCE_MYSQL_USER3");
	lua_pushnumber(L, 21); lua_setfield(L, -2, "SCE_MYSQL_HIDDENCOMMAND");
	lua_pushnumber(L, 22); lua_setfield(L, -2, "SCE_MYSQL_PLACEHOLDER");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_PO_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_PO_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_PO_MSGID");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_PO_MSGID_TEXT");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_PO_MSGSTR");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_PO_MSGSTR_TEXT");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_PO_MSGCTXT");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_PO_MSGCTXT_TEXT");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_PO_FUZZY");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_PO_PROGRAMMER_COMMENT");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_PO_REFERENCE");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_PO_FLAGS");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_PO_MSGID_TEXT_EOL");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_PO_MSGSTR_TEXT_EOL");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_PO_MSGCTXT_TEXT_EOL");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_PO_ERROR");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_PAS_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_PAS_IDENTIFIER");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_PAS_COMMENT");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_PAS_COMMENT2");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_PAS_COMMENTLINE");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_PAS_PREPROCESSOR");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_PAS_PREPROCESSOR2");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_PAS_NUMBER");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_PAS_HEXNUMBER");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_PAS_WORD");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_PAS_STRING");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_PAS_STRINGEOL");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_PAS_CHARACTER");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_PAS_OPERATOR");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_PAS_ASM");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_SORCUS_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_SORCUS_COMMAND");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_SORCUS_PARAMETER");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_SORCUS_COMMENTLINE");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_SORCUS_STRING");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_SORCUS_STRINGEOL");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_SORCUS_IDENTIFIER");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_SORCUS_OPERATOR");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_SORCUS_NUMBER");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_SORCUS_CONSTANT");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_POWERPRO_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_POWERPRO_COMMENTBLOCK");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_POWERPRO_COMMENTLINE");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_POWERPRO_NUMBER");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_POWERPRO_WORD");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_POWERPRO_WORD2");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_POWERPRO_WORD3");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_POWERPRO_WORD4");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_POWERPRO_DOUBLEQUOTEDSTRING");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_POWERPRO_SINGLEQUOTEDSTRING");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_POWERPRO_LINECONTINUE");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_POWERPRO_OPERATOR");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_POWERPRO_IDENTIFIER");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_POWERPRO_STRINGEOL");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_POWERPRO_VERBATIM");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_POWERPRO_ALTQUOTE");
	lua_pushnumber(L, 16); lua_setfield(L, -2, "SCE_POWERPRO_FUNCTION");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_SML_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_SML_IDENTIFIER");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_SML_TAGNAME");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_SML_KEYWORD");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_SML_KEYWORD2");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_SML_KEYWORD3");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_SML_LINENUM");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_SML_OPERATOR");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_SML_NUMBER");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_SML_CHAR");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_SML_STRING");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_SML_COMMENT");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_SML_COMMENT1");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_SML_COMMENT2");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_SML_COMMENT3");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_MARKDOWN_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_MARKDOWN_LINE_BEGIN");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_MARKDOWN_STRONG1");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_MARKDOWN_STRONG2");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_MARKDOWN_EM1");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_MARKDOWN_EM2");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_MARKDOWN_HEADER1");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_MARKDOWN_HEADER2");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_MARKDOWN_HEADER3");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_MARKDOWN_HEADER4");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_MARKDOWN_HEADER5");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_MARKDOWN_HEADER6");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_MARKDOWN_PRECHAR");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_MARKDOWN_ULIST_ITEM");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_MARKDOWN_OLIST_ITEM");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_MARKDOWN_BLOCKQUOTE");
	lua_pushnumber(L, 16); lua_setfield(L, -2, "SCE_MARKDOWN_STRIKEOUT");
	lua_pushnumber(L, 17); lua_setfield(L, -2, "SCE_MARKDOWN_HRULE");
	lua_pushnumber(L, 18); lua_setfield(L, -2, "SCE_MARKDOWN_LINK");
	lua_pushnumber(L, 19); lua_setfield(L, -2, "SCE_MARKDOWN_CODE");
	lua_pushnumber(L, 20); lua_setfield(L, -2, "SCE_MARKDOWN_CODE2");
	lua_pushnumber(L, 21); lua_setfield(L, -2, "SCE_MARKDOWN_CODEBK");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_TXT2TAGS_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_TXT2TAGS_LINE_BEGIN");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_TXT2TAGS_STRONG1");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_TXT2TAGS_STRONG2");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_TXT2TAGS_EM1");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_TXT2TAGS_EM2");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_TXT2TAGS_HEADER1");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_TXT2TAGS_HEADER2");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_TXT2TAGS_HEADER3");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_TXT2TAGS_HEADER4");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_TXT2TAGS_HEADER5");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_TXT2TAGS_HEADER6");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_TXT2TAGS_PRECHAR");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_TXT2TAGS_ULIST_ITEM");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_TXT2TAGS_OLIST_ITEM");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_TXT2TAGS_BLOCKQUOTE");
	lua_pushnumber(L, 16); lua_setfield(L, -2, "SCE_TXT2TAGS_STRIKEOUT");
	lua_pushnumber(L, 17); lua_setfield(L, -2, "SCE_TXT2TAGS_HRULE");
	lua_pushnumber(L, 18); lua_setfield(L, -2, "SCE_TXT2TAGS_LINK");
	lua_pushnumber(L, 19); lua_setfield(L, -2, "SCE_TXT2TAGS_CODE");
	lua_pushnumber(L, 20); lua_setfield(L, -2, "SCE_TXT2TAGS_CODE2");
	lua_pushnumber(L, 21); lua_setfield(L, -2, "SCE_TXT2TAGS_CODEBK");
	lua_pushnumber(L, 22); lua_setfield(L, -2, "SCE_TXT2TAGS_COMMENT");
	lua_pushnumber(L, 23); lua_setfield(L, -2, "SCE_TXT2TAGS_OPTION");
	lua_pushnumber(L, 24); lua_setfield(L, -2, "SCE_TXT2TAGS_PREPROC");
	lua_pushnumber(L, 25); lua_setfield(L, -2, "SCE_TXT2TAGS_POSTPROC");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_A68K_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_A68K_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_A68K_NUMBER_DEC");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_A68K_NUMBER_BIN");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_A68K_NUMBER_HEX");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_A68K_STRING1");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_A68K_OPERATOR");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_A68K_CPUINSTRUCTION");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_A68K_EXTINSTRUCTION");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_A68K_REGISTER");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_A68K_DIRECTIVE");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_A68K_MACRO_ARG");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_A68K_LABEL");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_A68K_STRING2");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_A68K_IDENTIFIER");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_A68K_MACRO_DECLARATION");
	lua_pushnumber(L, 16); lua_setfield(L, -2, "SCE_A68K_COMMENT_WORD");
	lua_pushnumber(L, 17); lua_setfield(L, -2, "SCE_A68K_COMMENT_SPECIAL");
	lua_pushnumber(L, 18); lua_setfield(L, -2, "SCE_A68K_COMMENT_DOXYGEN");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_MODULA_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_MODULA_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_MODULA_DOXYCOMM");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_MODULA_DOXYKEY");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_MODULA_KEYWORD");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_MODULA_RESERVED");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_MODULA_NUMBER");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_MODULA_BASENUM");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_MODULA_FLOAT");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_MODULA_STRING");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_MODULA_STRSPEC");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_MODULA_CHAR");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_MODULA_CHARSPEC");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_MODULA_PROC");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_MODULA_PRAGMA");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_MODULA_PRGKEY");
	lua_pushnumber(L, 16); lua_setfield(L, -2, "SCE_MODULA_OPERATOR");
	lua_pushnumber(L, 17); lua_setfield(L, -2, "SCE_MODULA_BADSTR");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_COFFEESCRIPT_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_COFFEESCRIPT_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_COFFEESCRIPT_COMMENTLINE");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_COFFEESCRIPT_COMMENTDOC");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_COFFEESCRIPT_NUMBER");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_COFFEESCRIPT_WORD");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_COFFEESCRIPT_STRING");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_COFFEESCRIPT_CHARACTER");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_COFFEESCRIPT_UUID");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_COFFEESCRIPT_PREPROCESSOR");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_COFFEESCRIPT_OPERATOR");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_COFFEESCRIPT_IDENTIFIER");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_COFFEESCRIPT_STRINGEOL");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_COFFEESCRIPT_VERBATIM");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_COFFEESCRIPT_REGEX");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_COFFEESCRIPT_COMMENTLINEDOC");
	lua_pushnumber(L, 16); lua_setfield(L, -2, "SCE_COFFEESCRIPT_WORD2");
	lua_pushnumber(L, 17); lua_setfield(L, -2, "SCE_COFFEESCRIPT_COMMENTDOCKEYWORD");
	lua_pushnumber(L, 18); lua_setfield(L, -2, "SCE_COFFEESCRIPT_COMMENTDOCKEYWORDERROR");
	lua_pushnumber(L, 19); lua_setfield(L, -2, "SCE_COFFEESCRIPT_GLOBALCLASS");
	lua_pushnumber(L, 20); lua_setfield(L, -2, "SCE_COFFEESCRIPT_STRINGRAW");
	lua_pushnumber(L, 21); lua_setfield(L, -2, "SCE_COFFEESCRIPT_TRIPLEVERBATIM");
	lua_pushnumber(L, 22); lua_setfield(L, -2, "SCE_COFFEESCRIPT_COMMENTBLOCK");
	lua_pushnumber(L, 23); lua_setfield(L, -2, "SCE_COFFEESCRIPT_VERBOSE_REGEX");
	lua_pushnumber(L, 24); lua_setfield(L, -2, "SCE_COFFEESCRIPT_VERBOSE_REGEX_COMMENT");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_AVS_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_AVS_COMMENTBLOCK");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_AVS_COMMENTBLOCKN");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_AVS_COMMENTLINE");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_AVS_NUMBER");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_AVS_OPERATOR");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_AVS_IDENTIFIER");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_AVS_STRING");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_AVS_TRIPLESTRING");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_AVS_KEYWORD");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_AVS_FILTER");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_AVS_PLUGIN");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_AVS_FUNCTION");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_AVS_CLIPPROP");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_AVS_USERDFN");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_ECL_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_ECL_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_ECL_COMMENTLINE");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_ECL_NUMBER");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_ECL_STRING");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_ECL_WORD0");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_ECL_OPERATOR");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_ECL_CHARACTER");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_ECL_UUID");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_ECL_PREPROCESSOR");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_ECL_UNKNOWN");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_ECL_IDENTIFIER");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_ECL_STRINGEOL");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_ECL_VERBATIM");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_ECL_REGEX");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_ECL_COMMENTLINEDOC");
	lua_pushnumber(L, 16); lua_setfield(L, -2, "SCE_ECL_WORD1");
	lua_pushnumber(L, 17); lua_setfield(L, -2, "SCE_ECL_COMMENTDOCKEYWORD");
	lua_pushnumber(L, 18); lua_setfield(L, -2, "SCE_ECL_COMMENTDOCKEYWORDERROR");
	lua_pushnumber(L, 19); lua_setfield(L, -2, "SCE_ECL_WORD2");
	lua_pushnumber(L, 20); lua_setfield(L, -2, "SCE_ECL_WORD3");
	lua_pushnumber(L, 21); lua_setfield(L, -2, "SCE_ECL_WORD4");
	lua_pushnumber(L, 22); lua_setfield(L, -2, "SCE_ECL_WORD5");
	lua_pushnumber(L, 23); lua_setfield(L, -2, "SCE_ECL_COMMENTDOC");
	lua_pushnumber(L, 24); lua_setfield(L, -2, "SCE_ECL_ADDED");
	lua_pushnumber(L, 25); lua_setfield(L, -2, "SCE_ECL_DELETED");
	lua_pushnumber(L, 26); lua_setfield(L, -2, "SCE_ECL_CHANGED");
	lua_pushnumber(L, 27); lua_setfield(L, -2, "SCE_ECL_MOVED");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_OSCRIPT_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_OSCRIPT_LINE_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_OSCRIPT_BLOCK_COMMENT");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_OSCRIPT_DOC_COMMENT");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_OSCRIPT_PREPROCESSOR");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_OSCRIPT_NUMBER");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_OSCRIPT_SINGLEQUOTE_STRING");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_OSCRIPT_DOUBLEQUOTE_STRING");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_OSCRIPT_CONSTANT");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_OSCRIPT_IDENTIFIER");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_OSCRIPT_GLOBAL");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_OSCRIPT_KEYWORD");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_OSCRIPT_OPERATOR");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_OSCRIPT_LABEL");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_OSCRIPT_TYPE");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_OSCRIPT_FUNCTION");
	lua_pushnumber(L, 16); lua_setfield(L, -2, "SCE_OSCRIPT_OBJECT");
	lua_pushnumber(L, 17); lua_setfield(L, -2, "SCE_OSCRIPT_PROPERTY");
	lua_pushnumber(L, 18); lua_setfield(L, -2, "SCE_OSCRIPT_METHOD");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_VISUALPROLOG_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_VISUALPROLOG_KEY_MAJOR");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_VISUALPROLOG_KEY_MINOR");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_VISUALPROLOG_KEY_DIRECTIVE");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_VISUALPROLOG_COMMENT_BLOCK");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_VISUALPROLOG_COMMENT_LINE");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_VISUALPROLOG_COMMENT_KEY");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_VISUALPROLOG_COMMENT_KEY_ERROR");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_VISUALPROLOG_IDENTIFIER");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_VISUALPROLOG_VARIABLE");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_VISUALPROLOG_ANONYMOUS");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_VISUALPROLOG_NUMBER");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_VISUALPROLOG_OPERATOR");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_VISUALPROLOG_CHARACTER");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_VISUALPROLOG_CHARACTER_TOO_MANY");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_VISUALPROLOG_CHARACTER_ESCAPE_ERROR");
	lua_pushnumber(L, 16); lua_setfield(L, -2, "SCE_VISUALPROLOG_STRING");
	lua_pushnumber(L, 17); lua_setfield(L, -2, "SCE_VISUALPROLOG_STRING_ESCAPE");
	lua_pushnumber(L, 18); lua_setfield(L, -2, "SCE_VISUALPROLOG_STRING_ESCAPE_ERROR");
	lua_pushnumber(L, 19); lua_setfield(L, -2, "SCE_VISUALPROLOG_STRING_EOL_OPEN");
	lua_pushnumber(L, 20); lua_setfield(L, -2, "SCE_VISUALPROLOG_STRING_VERBATIM");
	lua_pushnumber(L, 21); lua_setfield(L, -2, "SCE_VISUALPROLOG_STRING_VERBATIM_SPECIAL");
	lua_pushnumber(L, 22); lua_setfield(L, -2, "SCE_VISUALPROLOG_STRING_VERBATIM_EOL");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_STTXT_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_STTXT_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_STTXT_COMMENTLINE");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_STTXT_KEYWORD");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_STTXT_TYPE");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_STTXT_FUNCTION");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_STTXT_FB");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_STTXT_NUMBER");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_STTXT_HEXNUMBER");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_STTXT_PRAGMA");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_STTXT_OPERATOR");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_STTXT_CHARACTER");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_STTXT_STRING1");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_STTXT_STRING2");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_STTXT_STRINGEOL");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_STTXT_IDENTIFIER");
	lua_pushnumber(L, 16); lua_setfield(L, -2, "SCE_STTXT_DATETIME");
	lua_pushnumber(L, 17); lua_setfield(L, -2, "SCE_STTXT_VARS");
	lua_pushnumber(L, 18); lua_setfield(L, -2, "SCE_STTXT_PRAGMAS");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_KVIRC_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_KVIRC_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_KVIRC_COMMENTBLOCK");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_KVIRC_STRING");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_KVIRC_WORD");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_KVIRC_KEYWORD");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_KVIRC_FUNCTION_KEYWORD");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_KVIRC_FUNCTION");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_KVIRC_VARIABLE");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_KVIRC_NUMBER");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_KVIRC_OPERATOR");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_KVIRC_STRING_FUNCTION");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_KVIRC_STRING_VARIABLE");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_RUST_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_RUST_COMMENTBLOCK");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_RUST_COMMENTLINE");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_RUST_COMMENTBLOCKDOC");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_RUST_COMMENTLINEDOC");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_RUST_NUMBER");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_RUST_WORD");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_RUST_WORD2");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_RUST_WORD3");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_RUST_WORD4");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_RUST_WORD5");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_RUST_WORD6");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_RUST_WORD7");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_RUST_STRING");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_RUST_STRINGR");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_RUST_CHARACTER");
	lua_pushnumber(L, 16); lua_setfield(L, -2, "SCE_RUST_OPERATOR");
	lua_pushnumber(L, 17); lua_setfield(L, -2, "SCE_RUST_IDENTIFIER");
	lua_pushnumber(L, 18); lua_setfield(L, -2, "SCE_RUST_LIFETIME");
	lua_pushnumber(L, 19); lua_setfield(L, -2, "SCE_RUST_MACRO");
	lua_pushnumber(L, 20); lua_setfield(L, -2, "SCE_RUST_LEXERROR");
	lua_pushnumber(L, 21); lua_setfield(L, -2, "SCE_RUST_BYTESTRING");
	lua_pushnumber(L, 22); lua_setfield(L, -2, "SCE_RUST_BYTESTRINGR");
	lua_pushnumber(L, 23); lua_setfield(L, -2, "SCE_RUST_BYTECHARACTER");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_DMAP_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_DMAP_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_DMAP_NUMBER");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_DMAP_STRING1");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_DMAP_STRING2");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_DMAP_STRINGEOL");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_DMAP_OPERATOR");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_DMAP_IDENTIFIER");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_DMAP_WORD");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_DMAP_WORD2");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_DMAP_WORD3");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_DMIS_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_DMIS_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_DMIS_STRING");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_DMIS_NUMBER");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_DMIS_KEYWORD");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_DMIS_MAJORWORD");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_DMIS_MINORWORD");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_DMIS_UNSUPPORTED_MAJOR");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_DMIS_UNSUPPORTED_MINOR");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_DMIS_LABEL");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_REG_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_REG_COMMENT");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_REG_VALUENAME");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_REG_STRING");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_REG_HEXDIGIT");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_REG_VALUETYPE");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_REG_ADDEDKEY");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_REG_DELETEDKEY");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_REG_ESCAPED");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_REG_KEYPATH_GUID");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_REG_STRING_GUID");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_REG_PARAMETER");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_REG_OPERATOR");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_BIBTEX_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_BIBTEX_ENTRY");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_BIBTEX_UNKNOWN_ENTRY");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_BIBTEX_KEY");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_BIBTEX_PARAMETER");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_BIBTEX_VALUE");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_BIBTEX_COMMENT");
	lua_pushnumber(L, 0); lua_setfield(L, -2, "SCE_HEX_DEFAULT");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SCE_HEX_RECSTART");
	lua_pushnumber(L, 2); lua_setfield(L, -2, "SCE_HEX_RECTYPE");
	lua_pushnumber(L, 3); lua_setfield(L, -2, "SCE_HEX_RECTYPE_UNKNOWN");
	lua_pushnumber(L, 4); lua_setfield(L, -2, "SCE_HEX_BYTECOUNT");
	lua_pushnumber(L, 5); lua_setfield(L, -2, "SCE_HEX_BYTECOUNT_WRONG");
	lua_pushnumber(L, 6); lua_setfield(L, -2, "SCE_HEX_NOADDRESS");
	lua_pushnumber(L, 7); lua_setfield(L, -2, "SCE_HEX_DATAADDRESS");
	lua_pushnumber(L, 8); lua_setfield(L, -2, "SCE_HEX_RECCOUNT");
	lua_pushnumber(L, 9); lua_setfield(L, -2, "SCE_HEX_STARTADDRESS");
	lua_pushnumber(L, 10); lua_setfield(L, -2, "SCE_HEX_ADDRESSFIELD_UNKNOWN");
	lua_pushnumber(L, 11); lua_setfield(L, -2, "SCE_HEX_EXTENDEDADDRESS");
	lua_pushnumber(L, 12); lua_setfield(L, -2, "SCE_HEX_DATA_ODD");
	lua_pushnumber(L, 13); lua_setfield(L, -2, "SCE_HEX_DATA_EVEN");
	lua_pushnumber(L, 14); lua_setfield(L, -2, "SCE_HEX_DATA_UNKNOWN");
	lua_pushnumber(L, 15); lua_setfield(L, -2, "SCE_HEX_DATA_EMPTY");
	lua_pushnumber(L, 16); lua_setfield(L, -2, "SCE_HEX_CHECKSUM");
	lua_pushnumber(L, 17); lua_setfield(L, -2, "SCE_HEX_CHECKSUM_WRONG");
	lua_pushnumber(L, 18); lua_setfield(L, -2, "SCE_HEX_GARBAGE");
	lua_pushnumber(L, 1); lua_setfield(L, -2, "SC_CP_DBCS");
	lua_pop(L, 1);
}
