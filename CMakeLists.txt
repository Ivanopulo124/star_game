cmake_minimum_required(VERSION 3.10)
project(star_game)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    src/main.cpp
    src/Ship.cpp
    src/Bullet.cpp
    src/Asteroid.cpp
    src/GameManager.cpp
)

add_executable(star_game ${SOURCES})

find_package(PkgConfig REQUIRED)

# SDL2
pkg_check_modules(SDL2 REQUIRED sdl2)
# SDL2_gfx
pkg_check_modules(SDL2GFX REQUIRED SDL2_gfx)

# include paths
target_include_directories(star_game PRIVATE
    ${SDL2_INCLUDE_DIRS}
    ${SDL2GFX_INCLUDE_DIRS}
    src
)

target_link_directories(star_game PRIVATE
    ${SDL2_LIBRARY_DIRS}
    ${SDL2GFX_LIBRARY_DIRS}
)

# link libs
target_link_libraries(star_game
    ${SDL2_LIBRARIES}
    ${SDL2GFX_LIBRARIES}
)

# нужно для mac/linux
target_compile_options(star_game PRIVATE
    ${SDL2_CFLAGS_OTHER}
    ${SDL2GFX_CFLAGS_OTHER}
)
