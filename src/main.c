#include "raylib.h"
#include "window.h"
#include "tiles.h"

int main(void)
{

    InitWindow(SCREEN_W, SCREEN_H, "The Simulation");

    // 60 FPS ;)
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // Check for fullscreen
        checkFullscreen();

        int tile_rows = GetScreenHeight() / TILE_SIZE;
        int tile_cols = GetScreenWidth() / TILE_SIZE;

        BeginDrawing();
            ClearBackground(BLANK);
            draw_tiles(tile_rows, tile_cols);
        EndDrawing();
    }

    CloseWindow();

    return 0;
};
