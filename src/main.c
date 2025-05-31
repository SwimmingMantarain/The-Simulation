#include "raylib.h"
#include "window.h"
#include "world.h"

int main(void)
{

    InitWindow(SCREEN_W, SCREEN_H, "The Simulation");

    // 60 FPS ;)
    SetTargetFPS(60);

    Rectangle player = { 0, 0, 32, 32 };

    Camera2D camera = { 0 };
    camera.target = (Vector2){ player.x, player.y };
    camera.offset = (Vector2){ SCREEN_W / 2, SCREEN_H / 2 };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    World world = create_world();

    while (!WindowShouldClose())
    {
        // Check for fullscreen
        checkFullscreen();

        if (IsKeyDown(KEY_D)) player.x += 5;
        else if (IsKeyDown(KEY_A)) player.x -= 5;
        else if (IsKeyDown(KEY_W)) player.y -= 5;
        else if (IsKeyDown(KEY_S)) player.y += 5;

        camera.target = (Vector2){ player.x, player.y };

        // --------------------------------------
        // DRAW
        // --------------------------------------

        BeginDrawing();
            ClearBackground(BLANK);

            BeginMode2D(camera);
                DrawRectangle(player.x, player.y, player.width, player.height, GREEN);
            EndMode2D();
        EndDrawing();
    }

    CloseWindow();

    return 0;
};
