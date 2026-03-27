cmake_minimum_required(VERSION 3.10)
project(MiniAsteroids)

set(CMAKE_CXX_STANDARD 17)
set(SRC_FILES
        Ship.cpp Ship.h
        Bullet.cpp Bullet.h
        Asteroid.cpp Asteroid.h
        GameManager.cpp GameManager.h
        main.cpp
)

add_library(asteroids SHARED ${SRC_FILES})
find_library(log-lib log)

# SDL2 (Android) — нужно подключить SDL2 NDK package
target_include_directories(asteroids PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(asteroids ${SDL2_LIBRARIES} ${log-lib})