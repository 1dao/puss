-- app.lua

local docs = puss.import('core.docs')
local console = puss.import('core.console')

local show_imgui_demos = false
local show_tabs_demo = false
local show_console_window = false

_pages = _pages or { last_index=0 }
_index = _index or setmetatable({}, {__mode='v'})
local pages = _pages
local index = _index

local function create_page(id, label, draw)
	if not id then
		id = pages.last_index + 1
		pages.last_index = id
	end
	local page = index[id]
	if page then return page end 
	local page = {id=id, label=label, draw=draw, show=true}
	table.insert(pages, page)
	index[id] = page
	return page
end

local function demo_page(page)
	imgui.Text(page.label)
	imgui.Text(string.format('DemoPage: %s %s', page, page.draw))
end

local function main_menu()
	local active
	if not imgui.BeginMenuBar() then return end
    if imgui.BeginMenu('File') then
    	if imgui.MenuItem('Test Add Tab') then create_page(nil, 'Page ' .. (#pages + 1), demo_page) end
    	if imgui.MenuItem('New page') then docs.new_page() end
    	if imgui.MenuItem('Open app.lua') then docs.open(puss._path .. '/core/app.lua') end
    	if imgui.MenuItem('Open console.lua') then docs.open(puss._path .. '/core/console.lua') end
        imgui.EndMenu()
    end
    if imgui.BeginMenu('Help') then
    	active, show_imgui_demos = imgui.MenuItem('ImGUI Demos', nil, show_imgui_demos)
		active, show_tabs_demo = imgui.MenuItem('Tabs Demo', nil, show_tabs_demo)
    	active, show_console_window = imgui.MenuItem('Conosle', nil, show_console_window)
    	imgui.Separator()
    	if imgui.MenuItem('Reload') then
	    	docs = puss.import('core.app', true)
	    	docs = puss.import('core.docs', true)
    		console = puss.import('core.console', true)
    	end
        imgui.EndMenu()
    end
    imgui.EndMenuBar()
end

local function tabs_bar()
    imgui.BeginTabBar("PussMainTabsBar", ImGuiTabBarFlags_SizingPolicyFit)
	for i, page in ipairs(pages) do
	    local active
		active, page.show = imgui.TabItem(page.label, page.show)
		if active then
			puss.trace_pcall(page.draw, page)
		end
	end
	imgui.EndTabBar()
end

local function main_window()
	local flags = ( ImGuiWindowFlags_NoTitleBar
		| ImGuiWindowFlags_NoResize
		| ImGuiWindowFlags_NoMove
		| ImGuiWindowFlags_NoCollapse
		| ImGuiWindowFlags_NoSavedSettings
		| ImGuiWindowFlags_MenuBar
		| ImGuiWindowFlags_NoBringToFrontOnFocus
		)
	imgui.SetNextWindowPos(0, 0)
	imgui.SetNextWindowSize(imgui.GetIODisplaySize())
	imgui.Begin("PussMainWindow", nil, flags)
	main_menu()
	tabs_bar()
	imgui.End()
end

local function source_editor_main()
	main_window()
	if show_imgui_demos then
		show_imgui_demos = imgui.ShowDemoWindow(show_imgui_demos)
	end
	if show_tabs_demo then
		show_tabs_demo = imgui.ShowTabsDemo('Tabs Demo', show_tabs_demo)
	end
	if show_console_window then
		show_console_window = console.update(show_console_window)
	end
end

__exports.create_page = create_page

__exports.lookup_page = function(id)
	return index[id]
end

__main = source_editor_main

__exports.main = function()
	local w = imgui.ImGuiCreateGLFW("Puss - Editor", 1024, 768)
	while imgui.ImGuiUpdate(w, __main) do
		imgui.ImGuiRender(w)
	end
	imgui.ImGuiDestroy(w)
end

