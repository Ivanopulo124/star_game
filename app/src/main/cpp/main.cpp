#include "raylib.h"
#include "game/Game.h"

int main() {
    InitWindow(800, 450, "Star Game");

    Game game;
    game.Init();

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();

        game.Update(dt);

        BeginDrawing();
        ClearBackground(BLACK);

        game.Draw();

        EndDrawing();
    }

    CloseWindow();
}