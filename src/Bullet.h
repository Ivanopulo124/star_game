#pragma once
#include <SDL2/SDL.h>

class Bullet {
public:
    float x, y;
    float angle;
    float speed;

    Bullet(float px, float py, float ang);
    void update(float dt);
    void render(SDL_Renderer* renderer);
    float getX();
    float getY();
};