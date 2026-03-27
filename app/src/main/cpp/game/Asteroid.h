#ifndef MY_APPLICATION_ASTEROID_H
#define MY_APPLICATION_ASTEROID_H

#include "raylib.h"

class Asteroid {
public:
    Vector2 position;
    Vector2 velocity;

    void Update(float dt);
    void Draw();
};

#endif //MY_APPLICATION_ASTEROID_H
