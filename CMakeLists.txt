cmake_minimum_required(VERSION 2.8)

project (lglfw)

add_subdirectory(deps/glfw)
include_directories(deps/glfw/include)

add_library(lglfw MODULE src/lglfw.c glfw)

set_target_properties(lglfw PROPERTIES OUTPUT_NAME "lglfw")
set_target_properties(lglfw PROPERTIES PREFIX "")

if(APPLE)
  # set(CMAKE_SHARED_MODULE_CREATE_C_FLAGS
  #   "${CMAKE_SHARED_MODULE_CREATE_C_FLAGS} -flat_namespace -undefined suppress"
  # )
  execute_process(COMMAND which luajit OUTPUT_VARIABLE LUAJIT)
  set(CMAKE_SHARED_MODULE_CREATE_C_FLAGS
    "${CMAKE_SHARED_MODULE_CREATE_C_FLAGS} -bundle_loader ${LUAJIT}"
  )
endif()

if(WIN32)
  add_definitions(-DLUA_BUILD_AS_DLL -DLUA_LIB)
endif()

target_link_libraries(lglfw ${GLFW_LIBRARIES})
