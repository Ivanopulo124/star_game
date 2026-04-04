#include "Bullet.h"
#include <cmath>

Bullet::Bullet(float px, float py, float ang) : x(px), y(py), angle(ang), speed(400) {}

void Bullet::update(float dt) {
    float rad = angle * M_PI / 180.0f;
    x += cos(rad) * speed * dt;
    y += sin(rad) * speed * dt;
}

void Bullet::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderDrawPoint(renderer, (int)x, (int)y);
}

float Bullet::getX() {
    return x;
}

float Bullet::getY() {
    return y;
}