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

include_directories(/usr/include/SDL2)
include_directories(src)

target_link_libraries(star_game SDL2 SDL2_gfx)