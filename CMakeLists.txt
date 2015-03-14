cmake_minimum_required(VERSION 2.6)
project(GraphLib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(HEADER_FILES include/graph.h include/graph_algorithm.h)
set(SOURCE_FILES src/graph.cpp)

include_directories(include/)

add_library(graphlib SHARED ${SOURCE_FILES})
set_target_properties(graphlib PROPERTIES LINKER_LANGUAGE C)

install(FILES ${HEADER_FILES} DESTINATION include)
install(TARGETS graphlib
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)
