#include "lglfw.h"

static int lglfwPollEvents(lua_State *L) {
  glfwPollEvents();
  return 0;
}

// static const luaL_Reg lglfw_functions2[] = {
//   {"PollEvents", lglfwPollEvents},
// };

LUALIB_API int luaopen_lglfw(lua_State *L) {
  printf("WHAT!\n");
  lua_newtable(L);
  lua_pushcfunction(L, lglfwPollEvents);
  lua_setfield(L, -2, "PollEvents");
  return 1;
}
