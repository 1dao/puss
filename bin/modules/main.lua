-- puss.lua
-- 

local global_env = _ENV
local global_env_metatable = {}

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
	global_env_metatable.__index = function(t,k) return rawget(g_capis,k) or rawget(g_enums,k) or rawget(gsci_enums,k) end
end

setmetatable( global_env, global_env_metatable )

local root_path, args = ...

function puss_fetch_root_path()
	return root_path
end

function puss_fetch_args()
	return args
end

local function puss_do_script(module_script_filename, env)
	local script = g_file_get_content( string.format('%s/modules/%s', root_path, module_script_filename) )
	local f, e = load(script, module_script_filename, 'bt', env or global_env)
	if f then return f() end
	error( string.format('puss_do_script(%s) failed: %s!', module_script_filename, e) )
end

local modules = {}

function puss_load_module(module_name)
	local m = modules[module_name]
	if not m then
		local module_env_metatable = { __module_name__ = module_name }
		m = {}
		setmetatable(m, module_env_metatable)
		modules[module_name] = m

		module_env_metatable.__index = function(t,k)
			return rawget(module_env_metatable,k) or global_env[k]
		end

		module_env_metatable.dofile = function(fname)
			puss_do_script( string.format('%s/%s', module_name, fname), m )
		end

		m.dofile( string.format('%s.lua', module_name) )
	end
	return m
end

puss_do_script('glua_init.lua')

puss_load_module('puss')

