cmake_minimum_required(VERSION 3.25)

project(easyx)

add_library(easyx INTERFACE)

target_include_directories(easyx
  INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(easyx
  INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/VC2015/x64/EasyXa.lib
)