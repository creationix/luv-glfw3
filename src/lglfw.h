#ifndef LGLFW_H
#define LGLFW_H

#include <lua.h>
#include <lauxlib.h>
#include <GLFW/glfw3.h>

#if LUA_VERSION_NUM < 502
# define lua_rawlen lua_objlen
/* lua_...uservalue: Something very different, but it should get the job done */
# define lua_getuservalue lua_getfenv
# define lua_setuservalue lua_setfenv
# define luaL_newlib(L,l) (lua_newtable(L), luaL_register(L,NULL,l))
# define luaL_setfuncs(L,l,n) (assert(n==0), luaL_register(L,NULL,l))
# define lua_resume(L,F,n) lua_resume(L,n)
#endif


LUALIB_API int luaopen_lglfw(lua_State *L);

#endif
