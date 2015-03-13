cmake_minimum_required(VERSION 2.6)
project(GraphLib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES)

add_library(GraphLib ${SOURCE_FILES})

INSTALL(FILES include/* DESTINATION include)