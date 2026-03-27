#include "Asteroid.h"
#include <SDL2/SDL2_gfxPrimitives.h>

Asteroid::Asteroid(float px, float py, float pvx, float pvy, float r)
    : x(px), y(py), vx(pvx), vy(pvy), radius(r) {}

void Asteroid::update(float dt) {
    x += vx * dt;
    y += vy * dt;
}

void Asteroid::render(SDL_Renderer* renderer) {
    filledCircleRGBA(renderer, (int) x, (int) y, (int) radius, 100, 100, 100, 255);
}