#include "Asteroid.h"

void Asteroid::Update(float dt) {
    position.x += velocity.x * dt;
    position.y += velocity.y * dt;
}

void Asteroid::Draw() {
    DrawCircleV(position, 5, GRAY);
}