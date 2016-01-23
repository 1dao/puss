-- glua_init.lua
-- 

local glua = __glua__

-- override methods
do
	local tree_model_get_value = glua.capis.gtk_tree_model_get_value
	glua.capis.gtk_tree_model_get_value = function(model, iter, column)
		local v = glua.gnew_uninit_value()
		tree_model_get_value(model, iter, column, v)
		return v()
	end
	glua.types.GtkTreeModel.get_value = glua.capis.gtk_tree_model_get_value
end

-- utils
do
	glua.list_methods = function(o)
		ks.log_debug('list methods, gtype name =', glua.gtype_name_from_instance(o) )
		local tp = glua.gtype_from_instance(o)
		if tp then
			local tp = glua.__gtypes__[tp]
			local keys = {}
			for k,v in pairs(tp) do table.insert(keys, k) end
			table.sort(keys)
			for _, k in ipairs(keys) do print('', k, tp[k]) end
		end
	end

	glua.list_properties = function(o)
		local gtypename = glua.gtype_name_from_instance(o)
		ks.log_debug('list properties, gtype name =', gtypename)
		local props = glua.gtype_list_properties(gtypename) or {}
		local keys = {}
		for _,p in pairs(props) do table.insert(keys, p:name()) end
		table.sort(keys)
		for _, k in ipairs(keys) do print('', k, o:get(k)) end
	end
end

