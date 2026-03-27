#pragma once
#include <SDL2/SDL.h>

class Asteroid {
public:
    float x, y;
    float vx, vy;
    float radius;

    Asteroid(float px, float py, float pvx, float pvy, float r);
    void update(float dt);
    void render(SDL_Renderer* renderer);

    bool checkCollision(float px, float py) {
        float dx = x - px;
        float dy = y - py;
        return (dx*dx + dy*dy) <= radius * radius;
    }
};