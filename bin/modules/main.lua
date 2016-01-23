-- puss.lua
-- 

local genv_metatable = {}

-- init
do
	local glua = __glua__
	local g_capis = glua.capis

	-- load gobject enums
	local g_enums = {}
	for etype, values in pairs(glua.enums) do
		for k,v in pairs(values) do g_enums[k]=v end
	end

	-- load sci enums
	local gsci_enums = __gsci__.enums

	-- glua metatable
	genv_metatable.__index = function(t,k) return rawget(g_capis,k) or rawget(g_enums,k) or rawget(gsci_enums,k) end
end

setmetatable( _ENV, genv_metatable )

local root_path, args = ...

function puss_do_module_script(module_script_filename)
	local script = g_file_get_content( string.format('%s/modules/%s', root_path, module_script_filename) )
	local f, e = load(script, module_script_filename)
	if f then return f() end
	error( string.format('puss_do_module_script(%s) failed: %s!', module_script_filename, e) )
end

function puss_fetch_root_path()
	return root_path
end

function puss_fetch_args()
	return args
end

puss_do_module_script('glua_init.lua')

puss_do_module_script('puss/puss.lua')

