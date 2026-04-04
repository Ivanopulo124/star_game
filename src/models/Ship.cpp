#include "Ship.h"
#include <cmath>

Ship::Ship(float px, float py) : x {px}, y {py}, angle {0} {}

std::vector<Bullet>* Ship::getBullets() {
    return &this->bullets;
}

void Ship::rotate(float delta) {
    angle += delta;
}

void Ship::shoot() {
    bullets.emplace_back(x, y, angle);
}

void Ship::update(float dt) {
    for (auto &b : bullets) b.update(dt);
}

void Ship::render(SDL_Renderer* renderer) {
    // print triangle for ship
    //todo: make ship look more like x-wing
    float rad = angle * M_PI / 180.0f;
    int x1 = x + cos(rad) * 20;
    int y1 = y + sin(rad) * 20;
    int x2 = x + cos(rad + 2.5f) * 20;
    int y2 = y + sin(rad + 2.5f) * 20;
    int x3 = x + cos(rad - 2.5f) * 20;
    int y3 = y + sin(rad - 2.5f) * 20;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
    SDL_RenderDrawLine(renderer, x2, y2, x3, y3);
    SDL_RenderDrawLine(renderer, x3, y3, x1, y1);

    for (auto &b : bullets) b.render(renderer);
}