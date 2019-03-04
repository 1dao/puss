-- miniline.lua

-- print('miniline.lua init', ...)

local response_queue = ...

if response_queue then
	local key_index = {}	-- { filename_or_dirname : true }
	local files = {}	-- [ filepath : { keyX : weightX } ]

	local function do_build(parent, path_keys)
		-- print('build', parent)
		local fs, ds = puss.file_list(parent, true)
		for _, f in ipairs(fs) do
			local fk = f:lower()
			key_index[fk] = true

			local file_keys = {}
			for i,dk in pairs(path_keys) do file_keys[dk]=1 end
			file_keys[fk] = 10000
			files[parent..'/'..f] = file_keys
		end
		for _, d in ipairs(ds) do
			local dk = d:lower()
			key_index[dk] = (key_index[dk] or 0) + 1
			table.insert(path_keys, dk)
			do_build(parent..'/'..d, path_keys)
			table.remove(path_keys)
		end
	end

	_G.rebuild_search_indexes = function(root_folders)
		print('rebuild index start')
		key_index, files = {}, {}
		if root_folders then
			for i,v in ipairs(root_folders) do
				print('  rebuild index:', v)
				do_build(v, {})
			end
		end
		print('rebuild index finished')
		-- for k in pairs(files) do print(k) end
	end

	local function fetch_weight_in_file_keys(file_keys, keys)
		local weight = 0
		for k, w in pairs(file_keys) do
			if keys[k] then
				-- print('   match', k, w, keys[k])
				weight = weight + w
			end
		end
		return weight
	end

	local function do_search(search_key)
		local all_keys = {}	-- [ {key1=true, key2=true, ...}, ... ]
		for key in search_key:gmatch('%S+') do
			key = key:lower()
			local keys = {}
			for k in pairs(key_index) do
				if k:find(key, 1, true) then
					keys[k] = true
				end
			end
			if next(keys)==nil then return {} end
			-- print('ss key:', key); for k in pairs(keys) do print('  =>', k) end
			table.insert(all_keys, keys)
		end

		local matches = {}
		-- local search_max = 10
		local ts = os.time()
		for filepath, file_keys in pairs(files) do
			-- search_max = search_max - 1; if search_max <= 0 then break end;
			if (os.time() - ts) > 5 then break end
			--print('match', filepath, file_keys, #all_keys)
			local weight = 0
			for _, keys in ipairs(all_keys) do
				local w = fetch_weight_in_file_keys(file_keys, keys)
				-- print('match', #keys, #file_keys, filepath)
				if w==0 then
					weight = 0
					break
				end
				weight = weight + w
			end
			--print('got', filepath, weight)
			if weight > 0 then
				table.insert(matches, {filepath, weight})
			end
		end

		table.sort(matches, function(a,b)
			local wa, wb = a[2], b[2]
			if wa > wb then return true end
			if wa < wb then return false end
			return a[1] < b[1]
		end)
		local res = {}
		for i=1,64 do
			local v = matches[i]
			if not v then break end
			res[i] = v[1]
		end
		return res
	end

	_G.search = function(search_key)
		-- print('search start: ', search_key)
		local res = do_search(search_key)
		-- print('search', search_key, #res)
		response_queue:push(search_key, res)
	end

	repeat
		-- idle
	until puss.thread_wait()

	return print('miniline thread quit!')
end

-- miniline main thread

local shotcuts = puss.import('core.shotcuts')
local filebrowser = puss.import('core.filebrowser')
local docs = puss.import('core.docs')

local open = false
local input_buf = imgui.CreateByteArray(512)
local cursor = 1
local results = {}

response_queue = puss.queue_create()
local thread = puss.thread_create('puss.trace_dofile', string.format('%s/core/miniline.lua', puss._path), nil, response_queue)

shotcuts.register('miniline/open', 'Open Miniline', 'P', true, false, false, false)

local MINILINE_FLAGS = ( ImGuiWindowFlags_NoMove
	| ImGuiWindowFlags_NoDocking
	| ImGuiWindowFlags_NoTitleBar
	| ImGuiWindowFlags_NoResize
	| ImGuiWindowFlags_AlwaysAutoResize
	| ImGuiWindowFlags_NoSavedSettings
	| ImGuiWindowFlags_NoNav
	)

local check_refresh_index
do
	local last_index_ver

	check_refresh_index = function()
		local ver, folders = filebrowser.check_fetch_folders(last_index_ver)
		-- print(last_index_ver, ver)
		last_index_ver = ver
		if folders then thread:post('rebuild_search_indexes', folders) end
	end
end

local function draw_miniline()
	if imgui.IsShortcutPressed(PUSS_IMGUI_KEY_ESCAPE) then open = false end
	imgui.PushItemWidth(480)
	if imgui.InputText('##input', input_buf) then
		local str = input_buf:str()
		-- print('start search', str)
		thread:post('search', str)
	end
	imgui.SetItemDefaultFocus()
	imgui.PopItemWidth()

	if imgui.IsShortcutPressed(PUSS_IMGUI_KEY_UP) then
		if cursor > 1 then cursor = cursor - 1 end
	end
	if imgui.IsShortcutPressed(PUSS_IMGUI_KEY_DOWN) then
		if cursor < #results then cursor = cursor + 1 end
	end

	local sel
	if imgui.IsShortcutPressed(PUSS_IMGUI_KEY_ENTER) then
		sel = cursor
	end
	for i=1,24 do
		local r = results[i]
		if not r then break end
		if i==cursor then
			imgui.PushStyleColor(ImGuiCol_Text,1,1,0,1)
		else
			imgui.PushStyleColor(ImGuiCol_Text,0.5,0.5,0.5,1)
		end
		if imgui.Selectable(r) then
			print(r, i, sel)
			sel = i
		end
		imgui.PopStyleColor()
	end

	if sel then
		local target = results[sel]
		open, cursor = false, 1
		input_buf:strcpy('')
		if target then docs.open(target) end
	end
end

local function on_thread_response()
	local key, res = response_queue:pop()
	if key then results = res or {} end
end

__exports.update = function(x, y, w, h)
	puss.trace_pcall(on_thread_response)
	local press_ok = false
	if not open then
		if not shotcuts.is_pressed('miniline/open') then return end
		press_ok = 1
		results = {}
	end

	check_refresh_index()

	local show
	imgui.SetNextWindowPos(x + w - 520, y + 60, ImGuiCond_Always)
	show, open = imgui.Begin('##miniline', true, MINILINE_FLAGS)
	if show then
		if press_ok then
			imgui.SetWindowFocus()
			imgui.SetKeyboardFocusHere()
		else
			if not imgui.IsWindowFocused(ImGuiFocusedFlags_RootAndChildWindows) then
				open = false
			end
		end
		draw_miniline()
	end
    imgui.End()
end
