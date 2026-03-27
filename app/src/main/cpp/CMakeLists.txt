cmake_minimum_required(VERSION 3.22)

project("myapplication")

set(CMAKE_CXX_STANDARD 17)

set(PLATFORM Android)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(raylib)

add_library(native-lib SHARED
    main.cpp
)

target_link_libraries(native-lib
    raylib
    android
    log
    GLESv2
)