-- default.lua

local function puss_args_match(key)
	for i,v in ipairs(puss._args) do
		local r = v:match(key)
		if r then return r end
	end
end

-- MUST load before other plugins load who use imgui
_ENV.imgui = puss.load_plugin(puss_args_match('--opengl') and 'puss_imgui_glfw' or 'puss_imgui')
imgui.set_error_handle(puss.logerr_handle())

function __main__()
	local app_module_name = puss_args_match('^%-%-main%s*=%s*([%._%w]+)%s*$') or 'core.app'
	local app = puss.import(app_module_name)
	app.init()
	while app.update() do
		imgui.WaitEventsTimeout()
	end
	app.uninit()
end

