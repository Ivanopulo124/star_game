#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include "../models/Ship.h"
#include "../models/Asteroid.h"

class GameManager {
public:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool running;
    Ship ship;
    std::vector<Asteroid> asteroids;

    GameManager();
    ~GameManager();
    void run();
private:
    void handleInput();
    void update(float dt);
    void render();
};
