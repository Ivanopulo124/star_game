#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include "Bullet.h"

class Ship {
    float x, y;
    float angle;

public:
    std::vector<Bullet> bullets;
    Ship(float px, float py);
    void rotate(float delta);
    void shoot();
    void update(float dt);
    void render(SDL_Renderer* renderer);
    std::vector<Bullet>* getBullets();
};