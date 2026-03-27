#include "Bullet.h"

void Bullet::Update(float dt) {
    position.x += velocity.x * dt;
    position.y += velocity.y * dt;
}

void Bullet::Draw() {
    DrawCircleV(position, 5, YELLOW);
}