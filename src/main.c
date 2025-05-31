#include "raylib.h"
#include "window.h"
#include "world.h"

int main(void)
{

    InitWindow(SCREEN_W, SCREEN_H, "The Simulation");

    // 60 FPS ;)
    SetTargetFPS(60);

    int world_x = 0;
    int world_y = 0;

    Camera2D camera = { 0 };
    camera.target = (Vector2){ world_x, world_y };
    camera.offset = (Vector2){ SCREEN_W / 2, SCREEN_H / 2 };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    while (!WindowShouldClose())
    {
        // Check for fullscreen
        checkFullscreen();

        if (IsKeyDown(KEY_D)) world_x += 5;
        else if (IsKeyDown(KEY_A)) world_x -= 5;
        else if (IsKeyDown(KEY_W)) world_y -= 5;
        else if (IsKeyDown(KEY_S)) world_y += 5;

        camera.target = (Vector2){ world_x, world_y };

        // --------------------------------------
        // DRAW
        // --------------------------------------

        BeginDrawing();
            ClearBackground(BLANK);

            BeginMode2D(camera);
                draw_square();
            EndMode2D();

            DrawCircle(50, 100, 5.0, MAROON);
        EndDrawing();
    }

    CloseWindow();

    return 0;
};
