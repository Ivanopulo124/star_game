#ifndef MY_APPLICATION_BULLET_H
#define MY_APPLICATION_BULLET_H

#include "raylib.h"

class Bullet {
public:
    Vector2 position;
    Vector2 velocity;

    void Update(float dt);
    void Draw();
};

#endif //MY_APPLICATION_BULLET_H
