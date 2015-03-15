cmake_minimum_required(VERSION 3.1)
project(GraphLib CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(HEADER_FILES include/graphlib/graph.h include/graphlib/graph_algorithms.h include/graphlib.h)
set(SOURCE_FILES src/graph.cpp)

include_directories(include/)

add_library(graphlib SHARED ${SOURCE_FILES})

install(FILES ${HEADER_FILES} DESTINATION include)
install(TARGETS graphlib
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)
