-- luaproxy_gen.lua
-- 

local function pasre_header(gen, fname)
	local s = ''
	for line in io.lines(fname) do
		local decl
		if s:len() > 0 then
			line = line:match('^%s*(.-)%s*$')
			decl = s .. ' ' .. line
		else
			decl = line:match('^%s*LUA%w*_API%s+(.-)%s*$')
		end

		if decl then
			local ret, name, args = decl:match('^%s*(.-)%s*%(%s*(.-)%)%s*%((.-)%)%s*;')
			if ret then
				s = ''
				local anames = {}
				if args~='void' then
					local ass = args .. ','
					for av in ass:gmatch('.-([%w_]+)[%s%[%]]*,') do
						table.insert(anames, av)
					end
				end
				gen(ret, name, args, anames)
			else
				s = decl	-- need more
			end
		else
			s = ''
		end
	end
end

local apis = {}

local function gen_api(ret, name, args, anames)
	table.insert(apis, {ret, name, args, anames})
end

pasre_header(gen_api, '../3rd/lua53/lua.h')
pasre_header(gen_api, '../3rd/lua53/lauxlib.h')
pasre_header(gen_api, '../3rd/lua53/lualib.h')

do
	local output = io.open('luaproxy.h', 'w')
	output:write('// NOTICE : generate by luaproxy_gen.lua\n\n')
	output:write('#ifndef _LUA_PROXY_INC_DECL_H__\n')
	output:write('#define _LUA_PROXY_INC_DECL_H__\n\n')
	output:write('typedef struct _LuaProxy {\n')
	output:write('	int     __lua_proxy_inited__;\n')
	for _,v in ipairs(apis) do
		local ret, name, args, anames = table.unpack(v)
		output:write( string.format('  %-16s(*_%s)(%s);\n', ret, name, args) )
	end
	output:write('} LuaProxy;\n\n')
	output:write('#endif//_LUA_PROXY_INC_DECL_H__\n')
	output:close()
end

do
	local output = io.open('luaproxy_export.inl', 'w')
	output:write('// NOTICE : generate by luaproxy_gen.lua\n\n')
	output:write('#include "luaproxy.h"\n')
	output:write([===[
static LuaProxy* __lua_proxy_export__(void) {
	static LuaProxy _proxy = {0};
	if( _proxy.__lua_proxy_inited__==0 ) {
		_proxy.__lua_proxy_inited__ = 1;

		#ifndef LUA_COMPAT_MODULE
			#define luaL_pushmodule	NULL
			#define luaL_openlib	NULL
		#endif
	]===])

	for _,v in ipairs(apis) do
		local ret, name, args, anames = table.unpack(v)
		output:write('		_proxy._' .. name .. ' = ' .. name .. ';\n')
	end

	output:write([===[
	}
	return &_proxy;
}
]===])

	output:close()
end

do
	local output = io.open('luaproxy_import.inl', 'w')
	output:write('// NOTICE : generate by luaproxy_gen.lua\n\n')
	output:write('#include "luaproxy.h"\n')
	output:write('static LuaProxy* __lua_proxy__ = 0;\n')
	output:write('static void __lua_proxy_import__(LuaProxy* proxy) { __lua_proxy__=proxy; }\n\n')
	for _,v in ipairs(apis) do
		local ret, name, args, anames = table.unpack(v)
		output:write(ret .. ' ' .. name .. '(' .. args .. ') {')
			if ret~='void' then output:write(' return') end
			output:write(' __lua_proxy__->_' .. name .. '(' .. table.concat(anames, ',') .. '); ')
		output:write('}\n')
	end
	output:close()
end



