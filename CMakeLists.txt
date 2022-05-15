cmake_minimum_required(VERSION 3.10)
set (CMAKE_CXX_STANDARD 17)

project(mapbox_gl_native  VERSION 1.0.1 DESCRIPTION "example mapbox library")

add_executable(mapbox_gl_test mapgl/test/main.cpp mapgl/src/map.cpp)

message("env variable JAVA_INC : $ENV{JAVA_INC}")

# java binding
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY binding/java)
add_library(mapbjava SHARED mapgl/src/mapbox_java.cpp mapgl/src/map.cpp)
include_directories(SYSTEM $ENV{JAVA_INC} $ENV{JAVA_INC}/linux)
include_directories(mapgl/include)

#install(TARGETS mapbjava LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

# mapgl/src/map.cpp
 