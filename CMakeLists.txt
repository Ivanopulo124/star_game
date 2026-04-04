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

include_directories(/usr/include/SDL2)
include_directories(src)

target_link_libraries(star_game SDL2 SDL2_gfx)