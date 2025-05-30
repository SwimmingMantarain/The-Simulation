#include "raylib.h"

#define TILE_SIZE 32 // 32 pixels

void draw_tile(int x, int y) {
    Color color = {61, 91, 74, 255};
    DrawRectangle(x, y, TILE_SIZE, TILE_SIZE, color);
    DrawRectangleLines(x, y, TILE_SIZE, TILE_SIZE, BLACK);
};

void draw_tiles(int tile_rows, int tile_cols) {
    // Rows
    for (int i = 0; i <= tile_rows; i++) {
        // Cols
        for (int j = 0; j < tile_cols; j++) {
            draw_tile(j * TILE_SIZE, i * TILE_SIZE);
        };
    };
};
