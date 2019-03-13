-- core.thread_files

local diskfs = puss.import('core.diskfs')

local fkeys = {}	-- { filename_or_dirname : true }
local files = {}	-- { filepath : { keyX : weightX } }
local sorted_files = {}	-- array[filepath]

local function do_build(parent, path_keys)
	-- print('build', parent)
	local fs, ds = puss.file_list(parent, true)
	for _, f in ipairs(fs) do
		local fk = f:lower()
		fkeys[fk] = true

		local file_keys = {}
		for i,dk in pairs(path_keys) do file_keys[dk]=1 end
		file_keys[fk] = 10000
		files[parent..'/'..f] = file_keys
	end
	for _, d in ipairs(ds) do
		local dk = d:lower()
		fkeys[dk] = (fkeys[dk] or 0) + 1
		table.insert(path_keys, dk)
		do_build(parent..'/'..d, path_keys)
		table.remove(path_keys)
	end
end

_G.search_indexes_rebuild = function(root_folders)
	print('rebuild index start')
	fkeys, files, sorted_files = {}, {}, {}
	if root_folders then
		for i,v in ipairs(root_folders) do
			print('  rebuild index:', v)
			do_build(v, {})
		end
	end
	print('rebuild index finished')
	-- for k in pairs(files) do print(k) end
	for k in pairs(files) do table.insert(sorted_files, k) end
	table.sort(sorted_files)
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

local function do_file_search(search_key)
	local all_keys = {}	-- [ {key1=true, key2=true, ...}, ... ]
	for key in search_key:gmatch('%S+') do
		key = key:lower()
		local keys = {}
		for k in pairs(fkeys) do
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

_G.search_file = function(search_key)
	-- print('search start: ', search_key)
	local res = do_file_search(search_key)
	-- print('search', search_key, #res)
	return search_key, res
end

local function do_search_in_file(filepath, search_key)
	local n = 0
	local res
	for line in io.lines(filepath) do
		n = n + 1
		if line:find(search_key) then
			res = res or {}
			table.insert(res, n)
			table.insert(res, line)
		end
	end
	return res
end

local current_search_task

local function do_text_search(search_key)
	local thread_self = puss.async_task_self()
	current_search_task = thread_self
	for _, filepath in ipairs(sorted_files) do
		local ok, res = puss.trace_pcall(do_search_in_file, filepath, search_key)
		if current_search_task~=thread_self then break end
		if ok and res then puss.thread_notify('core.search', 'on_search_result', search_key, filepath, res) end
		puss.async_task_sleep(1)
	end
	return res
end

_G.search_text = function(search_key)
	-- print('search start: ', search_key)
	puss.async_service_run(do_text_search, search_key)
end
