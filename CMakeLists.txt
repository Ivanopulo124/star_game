cmake_minimum_required(VERSION 3.10)
project(star_game)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
        src/main.cpp
        src/models/Ship.cpp
        src/models/Bullet.cpp
        src/models/Asteroid.cpp
        src/game/GameManager.cpp
)

add_executable(star_game ${SOURCES})

find_package(PkgConfig REQUIRED)

pkg_check_modules(SDL2 REQUIRED sdl2)

pkg_check_modules(SDL2GFX REQUIRED SDL2_gfx)

target_include_directories(star_game PRIVATE
    ${SDL2_INCLUDE_DIRS}
    ${SDL2GFX_INCLUDE_DIRS}
    src
)

target_link_directories(star_game PRIVATE
    ${SDL2_LIBRARY_DIRS}
    ${SDL2GFX_LIBRARY_DIRS}
)

target_link_libraries(star_game
    ${SDL2_LIBRARIES}
    ${SDL2GFX_LIBRARIES}
)

target_compile_options(star_game PRIVATE
    ${SDL2_CFLAGS_OTHER}
    ${SDL2GFX_CFLAGS_OTHER}
)
