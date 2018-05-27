-- console.lua

_output = _output or {}
_outbuf = _outbuf or imgui.CreateByteArray(32*1024)
_inbuf = _inbuf or imgui.CreateByteArray(4*1024, 'print("hello console") -- press Ctrl+Enter or KP_Enter run script')

local output = _output
local outbuf = _outbuf
local inbuf = _inbuf
local output_changed = false
local output_max_line = 4096

local function output_stack_push(line)
	line = tostring(line)
	if #output > output_max_line then
		table.remove(output, 1)
	end
	table.insert(output, line)
	output_changed = true
end

local function console_execute(input)
	output_stack_push(string.format('> %s', input))
	local f, e = load(input, input, 't')
	if f then return f() end
	output_stack_push(string.format('[ERR] %s', e))
end

puss._print = puss._print or _G.print
local raw_print = puss._print

local function console_log(...)
	local txt = {}
	local n = select('#', ...)
	for i=1, n do
		local v = select(i, ...)
		table.insert(txt, tostring(v))
	end
	output_stack_push(table.concat(txt, ' '))
end

_G.print = function(...)
	console_log(...)
	raw_print(...)
end

__exports.log = console_log

local function output_to_outbuf()
	local max = #outbuf
	local size = 0
	local removes = 0
	for i=#output,1,-1 do
		size = size + #output[i] + 1
		if size > max then
			removes = i + 1
			break
		end
	end
	if removes > 0 then
		table.move(output, removes+1, #output, 1)
		for i=1,removes do
			table.remove(output)
		end
	end
	local pos = 0
	for i,v in ipairs(output) do
		pos = outbuf:strcpy(pos, v, true)
	end
end

local CONSOLE_OUTPUT_NAME = '##ConsoleOutput'
local CONSOLE_OUTPUT_FLAGS = ImGuiInputTextFlags_ReadOnly | ImGuiInputTextFlags_NoUndoRedo | ImGuiInputTextFlags_NoUndoRedo

local function console_update()
	if output_changed then output_to_outbuf() end
	imgui.InputTextMultiline(CONSOLE_OUTPUT_NAME, outbuf, -1, -128, CONSOLE_OUTPUT_FLAGS)
	if output_changed then
		output_changed = false
		imgui.BeginChild(imgui.GetID(CONSOLE_OUTPUT_NAME))
			imgui.SetScrollY(imgui.GetScrollMaxY())
		imgui.EndChild()
	end
	imgui.Separator()

	local active, reclaim_focus = false, false
	if imgui.InputTextMultiline('##ConsoleInput', inbuf, -1, -1, ImGuiInputTextFlags_EnterReturnsTrue | ImGuiInputTextFlags_AllowTabInput) then
		reclaim_focus = true
		active = true
	elseif imgui.IsItemActive() then
		active = imgui.IsShortcutPressed(PUSS_IMGUI_KEY_KP_ENTER)
	end
	if active then puss.trace_pcall(console_execute, inbuf:str()) end
	if reclaim_focus then imgui.SetKeyboardFocusHere(-1) end
end

__exports.update = function(show)
	local res = false
	imgui.SetNextWindowSize(520, 600, ImGuiCond_FirstUseEver)
	res, show = imgui.Begin("Console", show, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse)
	if res then console_update() end
	imgui.End()
	return show
end

