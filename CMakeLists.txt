cmake_minimum_required(VERSION 3.10)
set (CMAKE_CXX_STANDARD 17)

project(mapbox_gl_native  VERSION 1.0.1 DESCRIPTION "example mapbox library")

add_executable(mapbox_gl_test mapgl/test/main.cpp mapgl/src/map.cpp)

add_library(mapglib SHARED mapgl/src/map.cpp)
set_target_properties(mapglib PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(mapglib PROPERTIES SOVERSION 1)
set_target_properties(mapglib PROPERTIES PUBLIC_HEADER mapgl/include/map.h)
include(GNUInstallDirs)
install(TARGETS mapglib
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

include_directories(mapgl/include)
