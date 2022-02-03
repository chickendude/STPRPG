#ifndef STPRPG_TRACK_H
#define STPRPG_TRACK_H

#include "constants.h"
#include "types.h"

struct Map
{
    const char title[15];
    int start_x, start_y;
    int width, height;
    const unsigned char *tilemap;
};

void load_map(const Map *map, Camera *camera);

void update_tilemap(const Map *map, Camera *camera);

extern const Map* maps[NUM_MAPS];

extern const Map map_1;

#endif //STPRPG_TRACK_H
