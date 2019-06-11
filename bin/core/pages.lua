-- core.pages

local shotcuts = puss.import('core.shotcuts')

_pages = _pages or {}
_index = _index or setmetatable({}, {__mode='v'})

_dialog = _dialog or imgui.CreateFileDialog()
_dialog_opend = nil

local pages = _pages
local index = _index
local selected_page_label = nil
local next_active_page_label = nil

local TABSBAR_FLAGS = ( ImGuiTabBarFlags_Reorderable
	| ImGuiTabBarFlags_AutoSelectNewTabs
	| ImGuiTabBarFlags_FittingPolicyScroll
	)

shotcuts.register('page/save_all', 'Save all pages', 'S', true, true, false, false)
shotcuts.register('page/close_all', 'Close all pages', 'W', true, true, false, false)
shotcuts.register('page/open_workspace', 'open work space', 'O', true, true, false, false)

__exports.update = function()
	-- set active
	local active = next_active_page_label
	if active then
		next_active_page_label = nil
	end

	local dockspace_id = imgui.GetID('PussMainTabsBar');
    imgui.DockSpace(dockspace_id);

	for i=#pages,1,-1 do
		local page = pages[i]
		if not page.was_open then
			local destroy = page.module.tabs_page_destroy
			if destroy then imgui.protect_pcall(destroy, page) end
			index[page.label] = nil
			if selected_page_label==page.label then selected_page_label = nil end
			imgui.SetTabItemClosed(page.label)
			if i == #pages then
				local fp = pages[i-1]
				if fp then
					fp.sv:SetFocus(true)
					selected_page_label = fp.label
					next_active_page_label = fp.label
				end
			elseif pages[i+1] then
				pages[i+1].sv:SetFocus(true)
				selected_page_label = pages[i+1].label
				next_active_page_label = pages[i+1].label
			end
			table.remove(pages, i)
			break
		end
	end
	
	-- draw tabs
	local selected
	for i, page in ipairs(pages) do
    	imgui.SetNextWindowDockID(dockspace_id, ImGuiCond_Once);
		local label = page.label
		page.was_open = page.open
		local flags = 0
		if page.unsaved then flags = flags | ImGuiWindowFlags_UnsavedDocument end
		if active and label==active then 
			imgui.SetNextWindowFocus()
		end

		local visible = imgui.Begin(label, page.open, flags)
		if visible then
			local draw = page.module.tabs_page_draw
			if draw then imgui.protect_pcall(draw, page, active and label==active) end
		end
		page.is_visible = visible
		imgui.End()
	end
	
	-- close tabs
	for i, page in ipairs(pages) do
		if not page.open then
			local close = page.module.tabs_page_close
			if close then imgui.protect_pcall(close, page) end
		end
	end

	if shotcuts.is_pressed('page/save_all') then save_all() end
	if shotcuts.is_pressed('page/close_all') then close_all() end
	if shotcuts.is_pressed('page/close') then close() end
	if shotcuts.is_pressed('page/open_workspace') then 
		_dialog:choose_file_dialog(true)
		_dialog_opend = true
	elseif _dialog_opend then
		local filepath = _dialog:choose_file_dialog(false)
		if filepath and #filepath > 0 then
			_dialog_opend = nil
		end
	end
end

__exports.create = function(label, module)
	local page = index[label]
	if page then return page end
	local page = {label=label, module=module, was_open=true, open=true}
	table.insert(pages, page)
	index[label] = page
	return page
end

__exports.active = function(label)
	selected_page_label = label
	next_active_page_label = label
end

__exports.selected = function()
	return selected_page_label
end

__exports.lookup = function(label)
	return index[label]
end

__exports.save = function(check_only)
	local page = index[selected_page_label]
	if not page then return end
	local save = page.module.tabs_page_save
	if save then save(page) end
end

__exports.close = function()
	local page = index[selected_page_label]
	if not page then return end
	
	page.open = false
end

__exports.save_all = function(check_only)
	if not check_only then
		for _, page in ipairs(pages) do
			local save = page.module.tabs_page_save
			if save then save(page) end
		end
	end

	local all_saved = true
	for _, page in ipairs(pages) do
		if page.unsaved then
			all_saved = false
			break
		end
	end
	return all_saved
end

__exports.close_all = function()
	for i=#pages,1,-1 do
		local page = pages[i]
		if page.unsaved then
			local close = page.module.tabs_page_close
			if close then imgui.protect_pcall(close, page) end
			break
		end

		local destroy = page.module.tabs_page_destroy
		if destroy then imgui.protect_pcall(destroy, page) end
		index[page.label] = nil
		if selected_page_label==page.label then selected_page_label = nil end
		imgui.SetTabItemClosed(page.label)
		table.remove(pages, i)
	end
end

__exports.open_workspace = function()
	_dialog_opend = true
	return _dialog:choose_file_dialog(true)
end
