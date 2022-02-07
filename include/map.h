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

/**
 * Moves the map to be centered around the (x,y) pixel location provided.
 * \n\n
 * Note: This redraws the entire tilemap to the screen. You will probably only
 * want to use this if you are moving more than a tile at a time, such as when
 * jumping from one location in the map to another.
 *
 * @param map The map whose data should be used.
 * @param camera The camera to use.
 * @param map_x The x position (in pixels) to jump to.
 * @param map_y The y position (in pixels) to jump to.
 */
void goto_map_pixel(const Map *map, Camera *camera, int map_x, int map_y);

/**
 * Moves the map to be centered around the tile pointed to by the provided x/y
 * coordinates.
 * \n\n
 * This uses the tilemap coordinates rather than pixel coordinates.
 * \n\n
 * Note: This redraws the entire tilemap to the screen. You will probably only
 * want to use this if you are moving more than a tile at a time, such as when
 * jumping from one location in the map to another.
 *
 * @param map The map whose data should be used.
 * @param camera The camera to use.
 * @param map_x The x position (in tiles) to jump to.
 * @param map_y The y position (in tiles) to jump to.
 */
void goto_map_tile(const Map *map, Camera *camera, int map_x, int map_y);

void load_map(const Map *map, Camera *camera);

void update_tilemap(const Map *map, Camera *camera);

void handle_map_collision(const Map *map, Entity *entity);

extern const Map* maps[NUM_MAPS];

extern const Map map_1;

#endif //STPRPG_TRACK_H
