#include "raylib.h"
#include <stddef.h>
#include <stdint.h>
#include "hashmap.h"

#define CHUNK_SIZE 32 // 32 tiles
#define TILE_SIZE 32 // 32 pixels
#define RENDER_DIST 10 // 10 chunks from player

typedef struct {
    Color color;
} Tile;

typedef struct {
    int x, y; // Chunk coords in the world
    Tile tiles[CHUNK_SIZE][CHUNK_SIZE];
} Chunk;

typedef struct {
    struct hashmap *map;
} World;

uint64_t chunk_hash(const void *item, uint64_t seed0, uint64_t seed1) {
    const Chunk *chunk = item;
    return hashmap_sip(&chunk->x, sizeof(chunk->x), seed0, seed1) ^ hashmap_sip(&chunk->y, sizeof(chunk->y), seed0, seed1);
}

int chunk_compare(const void *a, const void *b, void *udata) {
    const Chunk *ua = a;
    const Chunk *ub = b;
    return (ua->x == ub->x) && (ua->y == ub->y);
}

World create_world() {
    World world = {
        hashmap_new(sizeof(Chunk), 0, 0, 0, chunk_hash, chunk_compare, NULL, NULL)
    };
    return world;
}
