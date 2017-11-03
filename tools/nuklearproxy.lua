-- nuklearproxy.lua

local table_insert = table.insert
local table_concat = table.concat

local function parse_macro_segs(header)
	local signs = {}
	local keys = {'if', 'ifdef', 'ifndef', 'elif', 'else', 'endif'}
	for _, k in ipairs(keys) do signs[k] = true end

	local segs = {}
	local seg, lines = false, {}
	for line in header:gmatch('[^\r\n]+') do
		line = line:match('^%s*(.-)%s*$')
		local sign = line:match('^#%s*(%w+)')
		if signs[sign] then
			table_insert(segs, {seg, lines})
			seg, lines = line, {}
		else
			table_insert(lines, line)
		end
	end
	table_insert(segs, {seg, lines})
	return segs
end

local function erase_empty_segs(segs)
	local function mark_once()
		local changed = false
		local s, n = 1, 0
		for i, v in ipairs(segs) do
			local seg, syms = table.unpack(v)
			if (not seg) or seg:match('^#%s*endif') then
				if s and n==0 then
					changed = true
					for x=s,i-1 do segs[x][1] = nil end
					s, n = false, 0
					v[1] = (#syms > 0) and '' or nil
				end
			elseif seg:match('^#%s*if') then
				s, n = i, #syms
			else
				n = n + #syms
			end
		end
		return changed
	end

	while mark_once() do
		for i=#segs,1,-1 do
			if segs[i][1]==nil then table.remove(segs, i) end
		end
	end
end

local function pasre_apis(apis, segs)
	local index = {}
	for _, segv in ipairs(segs) do
		local seg, lines = table.unpack(segv)
		local syms = {}
		for _, line in ipairs(lines) do
			local ret, name, args = line:match('^%s*NK_API%s+(.+)%s+([_%w]+)%s*(%b())%s*;%s*$')
			if name and (index[name]==nil) then
				index[name] = true
				table_insert(syms, {ret, name, args})
			end
		end
		table_insert(apis, {seg, syms})
	end

	erase_empty_segs(apis)
end

local function parse_enums(enums, segs)
	for _, segv in ipairs(segs) do
		local seg, lines = table.unpack(segv)
		local syms = {}
		local cxt = table_concat(lines, '\n')
		for block in cxt:gmatch('enum%s+[_%w]*%s*(%b{})%s*;') do
			block = block:gsub('%b()', ' ')
			for line in block:gmatch('[%s{]*(.-)%s*[,}]') do
				local enum = line:match('^([nN][kK]_[_%w]+)%s*')
				if enum then table_insert(syms, enum) end
			end
		end
		table_insert(enums, {seg, syms})
	end

	erase_empty_segs(enums)
end

function main()
	local out = vlua.match_arg('^%-out=(.+)$') or '.'
	local lines = {}
	do
		local fname = vlua.match_arg('^%-src=(.+)$') or 'nuklear.h'
		for line in io.lines(fname) do
			-- #endif /* NK_NUKLEAR_H_ */
			table_insert(lines, line)
			if line:match('^%s*#%s*endif%s+/%*%s*NK_NUKLEAR_H_%s*%*/') then
				table_insert(lines, '')
				break
			end
		end
	end

	local header = table_concat(lines, '\n')
	header = header:gsub('/%*.-%*/', ' ')	-- remove comment

	local apis = {}
	local enums = {}
	do
		local segs = parse_macro_segs(header)
		pasre_apis(apis, segs)
		parse_enums(enums, segs)
	end

	local function generate_file(filename, cb)
		local output_lines = {}

		local function writeln(...)
			local line = table_concat({...})
			table_insert(output_lines, line)
		end

		cb(writeln)

		local f = io.open(filename, 'w')
		f:write( table_concat(output_lines, '\n') )
		f:close()
	end

	generate_file(vlua.filename_format(out..'/'..'nuklear.h'), function(writeln)
		writeln('// NOTICE : generate by nuklearproxy.lua')
		writeln()
		writeln('#define NK_INCLUDE_FIXED_TYPES')
		writeln('#define NK_INCLUDE_STANDARD_IO')
		writeln('#define NK_INCLUDE_STANDARD_VARARGS')
		writeln('#define NK_INCLUDE_DEFAULT_ALLOCATOR')
		writeln('#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT')
		writeln('#define NK_INCLUDE_FONT_BAKING')
		writeln('#define NK_INCLUDE_DEFAULT_FONT')
		writeln(header)
		writeln()
		writeln('#ifndef __INC_NUKLEAR_PROXY_H__')
		writeln('#define __INC_NUKLEAR_PROXY_H__')
		writeln()
		writeln('#include "puss_module.h"')
		writeln()
		writeln('PUSS_DECLS_BEGIN')
		writeln()
		writeln('typedef struct _NuklearProxy {')

		for _, segv in ipairs(apis) do
			local seg, syms = table.unpack(segv)
			local inc = seg and seg:match('^#%s*ifdef%s*NK_INCLUDE_.*')
			for _,v in ipairs(syms) do
				local ret, name, args = table.unpack(v)
				if inc then
					writeln(inc)
					writeln('  ', string.format('%-24s (*%s) %s;', ret, name, args))
					writeln('#else')
					writeln('  ', string.format('%-24s (*%s) %s; /* keep pos */', 'void*', name, '()'))
					writeln('#endif')
				else
					writeln(string.format('  %-24s (*%s) %s;', ret, name, args))
				end
			end
		end

		writeln('} NuklearProxy;')
		writeln()
		writeln('#ifndef _NUKLEARPROXY_NOT_USE_SYMBOL_MACROS')
		writeln('	#ifndef __nuklear_proxy__')
		writeln('		#error "need define __nuklear_proxy__(sym) first"')
		writeln('	#endif')

		for _, segv in ipairs(apis) do
			local seg, syms = table.unpack(segv)
			for _,v in ipairs(syms) do
				local ret, name, args = table.unpack(v)
				writeln('	#define ' .. name .. '	__nuklear_proxy__(' .. name .. ')')
			end
		end

		writeln('#endif//_NUKLEARPROXY_NOT_USE_SYMBOL_MACROS')
		writeln()
		writeln('PUSS_DECLS_END')
		writeln()
		writeln('#endif//__INC_NUKLEAR_PROXY_H__')
		writeln()
	end)

	generate_file(vlua.filename_format(out..'/'..'nuklear.symbols'), function(writeln)
		for _, segv in ipairs(apis) do
			local seg, syms = table.unpack(segv)
			if seg then
				if seg:match('^#%s*ifndef%s*NK_NUKLEAR_H_') then
					writeln('#ifdef __NUKLEARPROXY_SYMBOL')
				else
					writeln(seg)
				end
			end
			for _,v in ipairs(syms) do
				local ret, name, args = table.unpack(v)
				writeln('__NUKLEARPROXY_SYMBOL(', name, ')')
			end
		end
	end)

	generate_file(vlua.filename_format(out..'/'..'nuklear.enums'), function(writeln)
		for _, segv in ipairs(enums) do
			local seg, syms = table.unpack(segv)
			if seg then
				if seg:match('^#%s*ifndef%s*NK_NUKLEAR_H_') then
					writeln('#ifdef __NUKLEARPROXY_ENUM')
				else
					writeln(seg)
				end
			end
			for _,v in ipairs(syms) do
				writeln('__NUKLEARPROXY_ENUM(', v, ')')
			end
		end
	end)
end

