#include "Game.h"
#include "raylib.h"
#include <raymath.h>
#include <cmath>

void Game::Init() {
    player.position = {
            GetScreenWidth() / 2.0f,
            GetScreenHeight() / 2.0f
    };
}

void Game::Update(float dt) {
    if (gameOver) return;

    Vector2 joystickCenter = {100, (float) GetScreenHeight() - 100};
    float radius = 80;

    Vector2 inputDir = {0, 0};

    if (IsGestureDetected(0)) {
        Vector2 touch = GetTouchPosition(0);

        if (CheckCollisionPointCircle(touch, joystickCenter, radius)) {
            inputDir = Vector2Normalize(Vector2Subtract(touch, joystickCenter));
        }
    }

    player.Update(inputDir);
    Vector2 shootButton = {(float) GetScreenWidth() - 100, (float) GetScreenHeight() - 100};

    if (IsGestureDetected(0)) {
        Vector2 touch = GetTouchPosition(0);

        if (CheckCollisionPointCircle(touch, shootButton, 60)) {
            Bullet b;
            b.position = player.position;

            b.velocity = {
                    cosf(player.rotation) * 400,
                    sinf(player.rotation) * 400
            };

            bullets.push_back(b);
        }
    }

    for (auto &b : bullets) {
        b.Update(dt);
    }

    asteroidSpawnTimer += dt;

    if (asteroidSpawnTimer > 1.5f) {
        asteroidSpawnTimer = 0.0f;
        SpawnAsteroid();
    }

    for (auto &a : asteroids) {
        a.Update(dt);
    }

    for (int i = 0; i < bullets.size(); i++) {
        for (int j = 0; j < asteroids.size(); j++) {

            if (CheckCollisionCircles(
                    bullets[i].position, 5,
                    asteroids[j].position, 20
            )) {
                bullets.erase(bullets.begin() + i);
                asteroids.erase(asteroids.begin() + j);
                i--;
                break;
            }
        }
    }

    for (auto &a : asteroids) {
        if (CheckCollisionCircles(
                player.position, 20,
                a.position, 20
        )) {
            gameOver = true;
        }
    }
}

void Game::Draw() {
    player.Draw();

    for (auto &b : bullets) {
        b.Draw();
    }

    for (auto &a : asteroids) {
        a.Draw();
    }

    Vector2 joystickCenter = {100, (float) GetScreenHeight() - 100};
    DrawCircleV(joystickCenter, 80, DARKGRAY);
    DrawCircleV(joystickCenter, 30, GRAY);

    Vector2 shootButton = {(float) GetScreenWidth() - 100, (float) GetScreenHeight() - 100};
    DrawCircleV(shootButton, 60, RED);

    if (gameOver) {
        DrawText("GAME OVER", (float) GetScreenWidth()/2 - 100, 50, 30, RED);
    }
}

void Game::SpawnAsteroid() {
    Asteroid a;

    int side = GetRandomValue(0, 3);

    if (side == 0) {
        a.position = { (float) GetRandomValue(0, (float) GetScreenWidth()), 0 };
    } else if (side == 1) {
        a.position = { (float) GetRandomValue(0, (float) GetScreenWidth()), (float) GetScreenHeight() };
    } else if (side == 2) {
        a.position = { 0, (float) GetRandomValue(0, (float) GetScreenHeight()) };
    } else {
        a.position = { (float) GetScreenWidth(), (float) GetRandomValue(0, (float) GetScreenHeight()) };
    }

    Vector2 dir = Vector2Normalize(Vector2Subtract(player.position, a.position));

    a.velocity = {
            dir.x * 100,
            dir.y * 100
    };

    asteroids.push_back(a);
}