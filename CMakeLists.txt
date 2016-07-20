cmake_minimum_required(VERSION 2.6)

#place libraries ane exectuables in proper folders
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/bin")
set(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_dIR}/lib")

set(
  SOURCE 
  src/main.cpp 
  src/Core.cpp
  src/LineGraph.cpp
  src/MenuBar.cpp
  libs/gl3w/GL/gl3w.c
  imgui/imgui.cpp
  imgui/imgui_demo.cpp
  imgui/imgui_draw.cpp
  imgui/imgui_impl_glfw_gl3.cpp
  )

set(EXECUTABLE_NAME "utocity")
add_executable(${EXECUTABLE_NAME} ${SOURCE})
target_compile_features(${EXECUTABLE_NAME} PRIVATE cxx_range_for)

include_directories(libs/gl3w)
include_directories(inc/)
include_directories(imgui/)

find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIR})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})

find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
include_directories(${GLFW_INCLUDE_DIRS})

target_link_libraries(${EXECUTABLE_NAME} ${OPENGL_LIBRARIES} ${GLFW_LIBRARIES} dl)
