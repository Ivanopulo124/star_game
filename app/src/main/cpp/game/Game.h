#ifndef MY_APPLICATION_GAME_H
#define MY_APPLICATION_GAME_H

#include "Player.h"
#include "Bullet.h"
#include "Asteroid.h"
#include <vector>
#include <raymath.h>

class Game {
public:
    void Init();
    void Update(float dt);
    void Draw();

private:
    Player player;

    std::vector<Bullet> bullets;
    std::vector<Asteroid> asteroids;

    float asteroidSpawnTimer = 0.0f;

    bool gameOver = false;

    void SpawnAsteroid();
};

#endif //MY_APPLICATION_GAME_H
