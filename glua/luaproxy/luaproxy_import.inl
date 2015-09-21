// NOTICE : generate by luaproxy_gen.lua

#include "luaproxy.h"
static LuaProxy* __lua_proxy__ = 0;
static void __lua_proxy_import__(LuaProxy* proxy) { __lua_proxy__=proxy; }

lua_State * lua_newstate(lua_Alloc f, void *ud) { return __lua_proxy__->_lua_newstate(f,ud); }
void lua_close(lua_State *L) { __lua_proxy__->_lua_close(L); }
lua_State * lua_newthread(lua_State *L) { return __lua_proxy__->_lua_newthread(L); }
lua_CFunction lua_atpanic(lua_State *L, lua_CFunction panicf) { return __lua_proxy__->_lua_atpanic(L,panicf); }
const lua_Number * lua_version(lua_State *L) { return __lua_proxy__->_lua_version(L); }
int lua_absindex(lua_State *L, int idx) { return __lua_proxy__->_lua_absindex(L,idx); }
int lua_gettop(lua_State *L) { return __lua_proxy__->_lua_gettop(L); }
void lua_settop(lua_State *L, int idx) { __lua_proxy__->_lua_settop(L,idx); }
void lua_pushvalue(lua_State *L, int idx) { __lua_proxy__->_lua_pushvalue(L,idx); }
void lua_rotate(lua_State *L, int idx, int n) { __lua_proxy__->_lua_rotate(L,idx,n); }
void lua_copy(lua_State *L, int fromidx, int toidx) { __lua_proxy__->_lua_copy(L,fromidx,toidx); }
int lua_checkstack(lua_State *L, int n) { return __lua_proxy__->_lua_checkstack(L,n); }
void lua_xmove(lua_State *from, lua_State *to, int n) { __lua_proxy__->_lua_xmove(from,to,n); }
int lua_isnumber(lua_State *L, int idx) { return __lua_proxy__->_lua_isnumber(L,idx); }
int lua_isstring(lua_State *L, int idx) { return __lua_proxy__->_lua_isstring(L,idx); }
int lua_iscfunction(lua_State *L, int idx) { return __lua_proxy__->_lua_iscfunction(L,idx); }
int lua_isinteger(lua_State *L, int idx) { return __lua_proxy__->_lua_isinteger(L,idx); }
int lua_isuserdata(lua_State *L, int idx) { return __lua_proxy__->_lua_isuserdata(L,idx); }
int lua_type(lua_State *L, int idx) { return __lua_proxy__->_lua_type(L,idx); }
const char     * lua_typename(lua_State *L, int tp) { return __lua_proxy__->_lua_typename(L,tp); }
lua_Number lua_tonumberx(lua_State *L, int idx, int *isnum) { return __lua_proxy__->_lua_tonumberx(L,idx,isnum); }
lua_Integer lua_tointegerx(lua_State *L, int idx, int *isnum) { return __lua_proxy__->_lua_tointegerx(L,idx,isnum); }
int lua_toboolean(lua_State *L, int idx) { return __lua_proxy__->_lua_toboolean(L,idx); }
const char     * lua_tolstring(lua_State *L, int idx, size_t *len) { return __lua_proxy__->_lua_tolstring(L,idx,len); }
size_t lua_rawlen(lua_State *L, int idx) { return __lua_proxy__->_lua_rawlen(L,idx); }
lua_CFunction lua_tocfunction(lua_State *L, int idx) { return __lua_proxy__->_lua_tocfunction(L,idx); }
void	       * lua_touserdata(lua_State *L, int idx) { return __lua_proxy__->_lua_touserdata(L,idx); }
lua_State      * lua_tothread(lua_State *L, int idx) { return __lua_proxy__->_lua_tothread(L,idx); }
const void     * lua_topointer(lua_State *L, int idx) { return __lua_proxy__->_lua_topointer(L,idx); }
void lua_arith(lua_State *L, int op) { __lua_proxy__->_lua_arith(L,op); }
int lua_rawequal(lua_State *L, int idx1, int idx2) { return __lua_proxy__->_lua_rawequal(L,idx1,idx2); }
int lua_compare(lua_State *L, int idx1, int idx2, int op) { return __lua_proxy__->_lua_compare(L,idx1,idx2,op); }
void lua_pushnil(lua_State *L) { __lua_proxy__->_lua_pushnil(L); }
void lua_pushnumber(lua_State *L, lua_Number n) { __lua_proxy__->_lua_pushnumber(L,n); }
void lua_pushinteger(lua_State *L, lua_Integer n) { __lua_proxy__->_lua_pushinteger(L,n); }
const char * lua_pushlstring(lua_State *L, const char *s, size_t len) { return __lua_proxy__->_lua_pushlstring(L,s,len); }
const char * lua_pushstring(lua_State *L, const char *s) { return __lua_proxy__->_lua_pushstring(L,s); }
const char * lua_pushvfstring(lua_State *L, const char *fmt, va_list argp) { return __lua_proxy__->_lua_pushvfstring(L,fmt,argp); }
const char * lua_pushfstring(lua_State *L, const char *fmt, ...) { return __lua_proxy__->_lua_pushfstring(L,fmt); }
void lua_pushcclosure(lua_State *L, lua_CFunction fn, int n) { __lua_proxy__->_lua_pushcclosure(L,fn,n); }
void lua_pushboolean(lua_State *L, int b) { __lua_proxy__->_lua_pushboolean(L,b); }
void lua_pushlightuserdata(lua_State *L, void *p) { __lua_proxy__->_lua_pushlightuserdata(L,p); }
int lua_pushthread(lua_State *L) { return __lua_proxy__->_lua_pushthread(L); }
int lua_getglobal(lua_State *L, const char *name) { return __lua_proxy__->_lua_getglobal(L,name); }
int lua_gettable(lua_State *L, int idx) { return __lua_proxy__->_lua_gettable(L,idx); }
int lua_getfield(lua_State *L, int idx, const char *k) { return __lua_proxy__->_lua_getfield(L,idx,k); }
int lua_geti(lua_State *L, int idx, lua_Integer n) { return __lua_proxy__->_lua_geti(L,idx,n); }
int lua_rawget(lua_State *L, int idx) { return __lua_proxy__->_lua_rawget(L,idx); }
int lua_rawgeti(lua_State *L, int idx, lua_Integer n) { return __lua_proxy__->_lua_rawgeti(L,idx,n); }
int lua_rawgetp(lua_State *L, int idx, const void *p) { return __lua_proxy__->_lua_rawgetp(L,idx,p); }
void lua_createtable(lua_State *L, int narr, int nrec) { __lua_proxy__->_lua_createtable(L,narr,nrec); }
void * lua_newuserdata(lua_State *L, size_t sz) { return __lua_proxy__->_lua_newuserdata(L,sz); }
int lua_getmetatable(lua_State *L, int objindex) { return __lua_proxy__->_lua_getmetatable(L,objindex); }
int lua_getuservalue(lua_State *L, int idx) { return __lua_proxy__->_lua_getuservalue(L,idx); }
void lua_setglobal(lua_State *L, const char *name) { __lua_proxy__->_lua_setglobal(L,name); }
void lua_settable(lua_State *L, int idx) { __lua_proxy__->_lua_settable(L,idx); }
void lua_setfield(lua_State *L, int idx, const char *k) { __lua_proxy__->_lua_setfield(L,idx,k); }
void lua_seti(lua_State *L, int idx, lua_Integer n) { __lua_proxy__->_lua_seti(L,idx,n); }
void lua_rawset(lua_State *L, int idx) { __lua_proxy__->_lua_rawset(L,idx); }
void lua_rawseti(lua_State *L, int idx, lua_Integer n) { __lua_proxy__->_lua_rawseti(L,idx,n); }
void lua_rawsetp(lua_State *L, int idx, const void *p) { __lua_proxy__->_lua_rawsetp(L,idx,p); }
int lua_setmetatable(lua_State *L, int objindex) { return __lua_proxy__->_lua_setmetatable(L,objindex); }
void lua_setuservalue(lua_State *L, int idx) { __lua_proxy__->_lua_setuservalue(L,idx); }
void lua_callk(lua_State *L, int nargs, int nresults, lua_KContext ctx, lua_KFunction k) { __lua_proxy__->_lua_callk(L,nargs,nresults,ctx,k); }
int lua_pcallk(lua_State *L, int nargs, int nresults, int errfunc, lua_KContext ctx, lua_KFunction k) { return __lua_proxy__->_lua_pcallk(L,nargs,nresults,errfunc,ctx,k); }
int lua_load(lua_State *L, lua_Reader reader, void *dt, const char *chunkname, const char *mode) { return __lua_proxy__->_lua_load(L,reader,dt,chunkname,mode); }
int lua_dump(lua_State *L, lua_Writer writer, void *data, int strip) { return __lua_proxy__->_lua_dump(L,writer,data,strip); }
int lua_yieldk(lua_State *L, int nresults, lua_KContext ctx, lua_KFunction k) { return __lua_proxy__->_lua_yieldk(L,nresults,ctx,k); }
int lua_resume(lua_State *L, lua_State *from, int narg) { return __lua_proxy__->_lua_resume(L,from,narg); }
int lua_status(lua_State *L) { return __lua_proxy__->_lua_status(L); }
int lua_isyieldable(lua_State *L) { return __lua_proxy__->_lua_isyieldable(L); }
int lua_gc(lua_State *L, int what, int data) { return __lua_proxy__->_lua_gc(L,what,data); }
int lua_error(lua_State *L) { return __lua_proxy__->_lua_error(L); }
int lua_next(lua_State *L, int idx) { return __lua_proxy__->_lua_next(L,idx); }
void lua_concat(lua_State *L, int n) { __lua_proxy__->_lua_concat(L,n); }
void lua_len(lua_State *L, int idx) { __lua_proxy__->_lua_len(L,idx); }
size_t lua_stringtonumber(lua_State *L, const char *s) { return __lua_proxy__->_lua_stringtonumber(L,s); }
lua_Alloc lua_getallocf(lua_State *L, void **ud) { return __lua_proxy__->_lua_getallocf(L,ud); }
void lua_setallocf(lua_State *L, lua_Alloc f, void *ud) { __lua_proxy__->_lua_setallocf(L,f,ud); }
int lua_getstack(lua_State *L, int level, lua_Debug *ar) { return __lua_proxy__->_lua_getstack(L,level,ar); }
int lua_getinfo(lua_State *L, const char *what, lua_Debug *ar) { return __lua_proxy__->_lua_getinfo(L,what,ar); }
const char * lua_getlocal(lua_State *L, const lua_Debug *ar, int n) { return __lua_proxy__->_lua_getlocal(L,ar,n); }
const char * lua_setlocal(lua_State *L, const lua_Debug *ar, int n) { return __lua_proxy__->_lua_setlocal(L,ar,n); }
const char * lua_getupvalue(lua_State *L, int funcindex, int n) { return __lua_proxy__->_lua_getupvalue(L,funcindex,n); }
const char * lua_setupvalue(lua_State *L, int funcindex, int n) { return __lua_proxy__->_lua_setupvalue(L,funcindex,n); }
void * lua_upvalueid(lua_State *L, int fidx, int n) { return __lua_proxy__->_lua_upvalueid(L,fidx,n); }
void lua_upvaluejoin(lua_State *L, int fidx1, int n1, int fidx2, int n2) { __lua_proxy__->_lua_upvaluejoin(L,fidx1,n1,fidx2,n2); }
void lua_sethook(lua_State *L, lua_Hook func, int mask, int count) { __lua_proxy__->_lua_sethook(L,func,mask,count); }
lua_Hook lua_gethook(lua_State *L) { return __lua_proxy__->_lua_gethook(L); }
int lua_gethookmask(lua_State *L) { return __lua_proxy__->_lua_gethookmask(L); }
int lua_gethookcount(lua_State *L) { return __lua_proxy__->_lua_gethookcount(L); }
void luaL_checkversion_(lua_State *L, lua_Number ver, size_t sz) { __lua_proxy__->_luaL_checkversion_(L,ver,sz); }
int luaL_getmetafield(lua_State *L, int obj, const char *e) { return __lua_proxy__->_luaL_getmetafield(L,obj,e); }
int luaL_callmeta(lua_State *L, int obj, const char *e) { return __lua_proxy__->_luaL_callmeta(L,obj,e); }
const char * luaL_tolstring(lua_State *L, int idx, size_t *len) { return __lua_proxy__->_luaL_tolstring(L,idx,len); }
int luaL_argerror(lua_State *L, int arg, const char *extramsg) { return __lua_proxy__->_luaL_argerror(L,arg,extramsg); }
const char * luaL_checklstring(lua_State *L, int arg, size_t *l) { return __lua_proxy__->_luaL_checklstring(L,arg,l); }
const char * luaL_optlstring(lua_State *L, int arg, const char *def, size_t *l) { return __lua_proxy__->_luaL_optlstring(L,arg,def,l); }
lua_Number luaL_checknumber(lua_State *L, int arg) { return __lua_proxy__->_luaL_checknumber(L,arg); }
lua_Number luaL_optnumber(lua_State *L, int arg, lua_Number def) { return __lua_proxy__->_luaL_optnumber(L,arg,def); }
lua_Integer luaL_checkinteger(lua_State *L, int arg) { return __lua_proxy__->_luaL_checkinteger(L,arg); }
lua_Integer luaL_optinteger(lua_State *L, int arg, lua_Integer def) { return __lua_proxy__->_luaL_optinteger(L,arg,def); }
void luaL_checkstack(lua_State *L, int sz, const char *msg) { __lua_proxy__->_luaL_checkstack(L,sz,msg); }
void luaL_checktype(lua_State *L, int arg, int t) { __lua_proxy__->_luaL_checktype(L,arg,t); }
void luaL_checkany(lua_State *L, int arg) { __lua_proxy__->_luaL_checkany(L,arg); }
int luaL_newmetatable(lua_State *L, const char *tname) { return __lua_proxy__->_luaL_newmetatable(L,tname); }
void luaL_setmetatable(lua_State *L, const char *tname) { __lua_proxy__->_luaL_setmetatable(L,tname); }
void * luaL_testudata(lua_State *L, int ud, const char *tname) { return __lua_proxy__->_luaL_testudata(L,ud,tname); }
void * luaL_checkudata(lua_State *L, int ud, const char *tname) { return __lua_proxy__->_luaL_checkudata(L,ud,tname); }
void luaL_where(lua_State *L, int lvl) { __lua_proxy__->_luaL_where(L,lvl); }
int luaL_error(lua_State *L, const char *fmt, ...) { return __lua_proxy__->_luaL_error(L,fmt); }
int luaL_checkoption(lua_State *L, int arg, const char *def, const char *const lst[]) { return __lua_proxy__->_luaL_checkoption(L,arg,def,lst); }
int luaL_fileresult(lua_State *L, int stat, const char *fname) { return __lua_proxy__->_luaL_fileresult(L,stat,fname); }
int luaL_execresult(lua_State *L, int stat) { return __lua_proxy__->_luaL_execresult(L,stat); }
int luaL_ref(lua_State *L, int t) { return __lua_proxy__->_luaL_ref(L,t); }
void luaL_unref(lua_State *L, int t, int ref) { __lua_proxy__->_luaL_unref(L,t,ref); }
int luaL_loadfilex(lua_State *L, const char *filename, const char *mode) { return __lua_proxy__->_luaL_loadfilex(L,filename,mode); }
int luaL_loadbufferx(lua_State *L, const char *buff, size_t sz, const char *name, const char *mode) { return __lua_proxy__->_luaL_loadbufferx(L,buff,sz,name,mode); }
int luaL_loadstring(lua_State *L, const char *s) { return __lua_proxy__->_luaL_loadstring(L,s); }
lua_State * luaL_newstate(void) { return __lua_proxy__->_luaL_newstate(); }
lua_Integer luaL_len(lua_State *L, int idx) { return __lua_proxy__->_luaL_len(L,idx); }
const char * luaL_gsub(lua_State *L, const char *s, const char *p, const char *r) { return __lua_proxy__->_luaL_gsub(L,s,p,r); }
void luaL_setfuncs(lua_State *L, const luaL_Reg *l, int nup) { __lua_proxy__->_luaL_setfuncs(L,l,nup); }
int luaL_getsubtable(lua_State *L, int idx, const char *fname) { return __lua_proxy__->_luaL_getsubtable(L,idx,fname); }
void luaL_traceback(lua_State *L, lua_State *L1, const char *msg, int level) { __lua_proxy__->_luaL_traceback(L,L1,msg,level); }
void luaL_requiref(lua_State *L, const char *modname, lua_CFunction openf, int glb) { __lua_proxy__->_luaL_requiref(L,modname,openf,glb); }
void luaL_buffinit(lua_State *L, luaL_Buffer *B) { __lua_proxy__->_luaL_buffinit(L,B); }
char * luaL_prepbuffsize(luaL_Buffer *B, size_t sz) { return __lua_proxy__->_luaL_prepbuffsize(B,sz); }
void luaL_addlstring(luaL_Buffer *B, const char *s, size_t l) { __lua_proxy__->_luaL_addlstring(B,s,l); }
void luaL_addstring(luaL_Buffer *B, const char *s) { __lua_proxy__->_luaL_addstring(B,s); }
void luaL_addvalue(luaL_Buffer *B) { __lua_proxy__->_luaL_addvalue(B); }
void luaL_pushresult(luaL_Buffer *B) { __lua_proxy__->_luaL_pushresult(B); }
void luaL_pushresultsize(luaL_Buffer *B, size_t sz) { __lua_proxy__->_luaL_pushresultsize(B,sz); }
char * luaL_buffinitsize(lua_State *L, luaL_Buffer *B, size_t sz) { return __lua_proxy__->_luaL_buffinitsize(L,B,sz); }
void luaL_pushmodule(lua_State *L, const char *modname, int sizehint) { __lua_proxy__->_luaL_pushmodule(L,modname,sizehint); }
void luaL_openlib(lua_State *L, const char *libname, const luaL_Reg *l, int nup) { __lua_proxy__->_luaL_openlib(L,libname,l,nup); }
int luaopen_base(lua_State *L) { return __lua_proxy__->_luaopen_base(L); }
int luaopen_coroutine(lua_State *L) { return __lua_proxy__->_luaopen_coroutine(L); }
int luaopen_table(lua_State *L) { return __lua_proxy__->_luaopen_table(L); }
int luaopen_io(lua_State *L) { return __lua_proxy__->_luaopen_io(L); }
int luaopen_os(lua_State *L) { return __lua_proxy__->_luaopen_os(L); }
int luaopen_string(lua_State *L) { return __lua_proxy__->_luaopen_string(L); }
int luaopen_utf8(lua_State *L) { return __lua_proxy__->_luaopen_utf8(L); }
int luaopen_bit32(lua_State *L) { return __lua_proxy__->_luaopen_bit32(L); }
int luaopen_math(lua_State *L) { return __lua_proxy__->_luaopen_math(L); }
int luaopen_debug(lua_State *L) { return __lua_proxy__->_luaopen_debug(L); }
int luaopen_package(lua_State *L) { return __lua_proxy__->_luaopen_package(L); }
void luaL_openlibs(lua_State *L) { __lua_proxy__->_luaL_openlibs(L); }
