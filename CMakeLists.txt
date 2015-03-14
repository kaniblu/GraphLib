cmake_minimum_required(VERSION 2.6)
project(GraphLib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(HEADER_FILES include/)
set(SOURCE_FILES src/)

include_directories(include/)

add_library(GraphLib SHARED ${SOURCE_FILES})

install(FILES include/* DESTINATION include)
install(TARGETS GraphLib
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)