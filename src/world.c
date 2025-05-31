#include "raylib.h"
#include <stddef.h>
#include <stdlib.h>

#define CHUNK_SIZE 32 // 32 tiles
#define MAX_LOADED_CHUNKS 128 // for now
#define TILE_SIZE 32 // 32 pixels

typedef struct {
    Color color;
} Tile;

typedef struct {
    int x, y; // Chunk coords in the world
    Tile tiles[CHUNK_SIZE][CHUNK_SIZE];
} Chunk;

typedef struct {
    Chunk* loaded_chunks[MAX_LOADED_CHUNKS];
    int num_loaded;
} World;

Chunk* find_chunk(World* world, int chunk_x, int chunk_y) {
    for (int i = 0; i < world->num_loaded; i++) {
        if (world->loaded_chunks[i]->x == chunk_x && world->loaded_chunks[i]->y == chunk_y) {
            return world->loaded_chunks[i];
        }
    }

    return NULL;
}

Chunk* load_chunk(World* world, int chunk_x, int chunk_y) {
    Chunk* chunk = find_chunk(world, chunk_x, chunk_y);
    if (chunk) return chunk;
    if (world->num_loaded >= MAX_LOADED_CHUNKS) return NULL; // Out of space

    chunk = malloc(sizeof(Chunk));
    chunk->x = chunk_x;
    chunk->y = chunk_y;

    world->loaded_chunks[world->num_loaded++] = chunk;
    return chunk;
}

void draw_square() {
    DrawRectangle(0, 0, TILE_SIZE, TILE_SIZE, GREEN);
}
