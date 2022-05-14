cmake_minimum_required(VERSION 3.10)
set (CMAKE_CXX_STANDARD 17)

project(mapbox_gl_native)

add_executable(mapbox_gl_native example/main.cpp mapgl/map.cpp)
