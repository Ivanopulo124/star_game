#ifndef MY_APPLICATION_PLAYER_H
#define MY_APPLICATION_PLAYER_H

#pragma once
#include "raylib.h"

class Player {
public:
    Vector2 position;
    float rotation = 0.0f;

    void Update(Vector2 inputDir);
    void Draw();
};

#endif //MY_APPLICATION_PLAYER_H
