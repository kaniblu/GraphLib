cmake_minimum_required(VERSION 2.8)
project(GraphLib CXX)

set(CMAKE_LEGACY_CYGWIN_WIN32 0) # Remove when CMake >= 2.8.4 is required
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES src/graph.cpp)

include_directories(include/)

add_library(graphlib SHARED ${SOURCE_FILES})

install(FILES include/graphlib.h DESTINATION include)
install(DIRECTORY include/graphlib DESTINATION include)
install(TARGETS graphlib
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)
