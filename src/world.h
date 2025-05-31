#ifndef WORLD_H
#define WORLD_H
#include "hashmap.h"

typedef struct {
    struct hashmap *map;
} World;

World create_world();

#endif
