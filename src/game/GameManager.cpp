#include "GameManager.h"
#include <cmath>
#include <cstdlib>

GameManager::GameManager() : running(true), ship(400, 300) {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Mini Asteroids", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    for(int i=0;i<5;i++){
        asteroids.emplace_back(rand()%800, rand()%600, (rand()%100-50)/50.0f*100, (rand()%100-50)/50.0f*100, 30);
    }
}

GameManager::~GameManager() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void GameManager::run() {
    Uint32 lastTime = SDL_GetTicks();
    while(running) {
        Uint32 current = SDL_GetTicks();
        float dt = (current - lastTime)/1000.0f;
        lastTime = current;

        handleInput();
        update(dt);
        render();
        SDL_Delay(16);
    }
}

void GameManager::handleInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)){
        if (event.type == SDL_QUIT) running = false;
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_LEFT: ship.rotate(-10); break;
                case SDLK_RIGHT: ship.rotate(10); break;
                case SDLK_SPACE: ship.shoot(); break;
            }
        }
    }
}

void GameManager::update(float dt) {
    ship.update(dt);

    for (size_t i = 0; i < asteroids.size(); i++) {
        asteroids[i].update(dt);

        for (size_t j = 0; j < ship.getBullets()->size(); j++) {
            if (asteroids[i].checkCollision(ship.bullets[j].x, ship.bullets[j].y)) {
                ship.getBullets()->erase(ship.getBullets()->begin() + j);

                if (asteroids[i].radius > 10) {
                    float r = asteroids[i].radius / 2;
                    float vx = asteroids[i].vx;
                    float vy = asteroids[i].vy;
                    asteroids.push_back(Asteroid(asteroids[i].x, asteroids[i].y, -vy, vx, r));
                    asteroids.push_back(Asteroid(asteroids[i].x, asteroids[i].y, vy, -vx, r));
                }
                asteroids.erase(asteroids.begin() + i);
                asteroids.emplace_back(rand()%800, rand()%600, (rand()%100-50)/50.0f*100, (rand()%100-50)/50.0f*100, 30);
                i--;
                break;
            }
        }
    }
}

void GameManager::render() {
    SDL_SetRenderDrawColor(renderer, 0,0,0,255);
    SDL_RenderClear(renderer);
    ship.render(renderer);
    for (auto &a : asteroids) a.render(renderer);
    SDL_RenderPresent(renderer);
}
