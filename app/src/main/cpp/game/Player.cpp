#include "Player.h"
#include <math.h>
#include <raymath.h>

void Player::Update(Vector2 inputDir) {
    if (inputDir.x != 0 || inputDir.y != 0) {
        rotation = atan2f(inputDir.y, inputDir.x);
    }
}

void Player::Draw() {
    DrawCircleV(position, 20, BLUE);

    Vector2 dir = {
            cosf(rotation) * 30,
            sinf(rotation) * 30
    };

    DrawLineV(position, Vector2Add(position, dir), WHITE);
}