#include <tonc.h>
#include "map.h"

#include "camera.h"
#include "constants.h"
// sprite data
#include "tiles.h"
// tilemap data
#include "maps.h"

const Map map_1 = {
        "Kelwyd",
        14, 7,
        MAP1_WIDTH, MAP1_HEIGHT,
        map1_tilemap
};
// -----------------------------------------------------------------------------
// Private function declarations
// -----------------------------------------------------------------------------

void draw_tile(int x, int y, const Map *map);

// -----------------------------------------------------------------------------
// Public function definitions
// -----------------------------------------------------------------------------

void goto_map_pixel(const Map *map, Camera *camera, int map_x, int map_y)
{
    camera->x = map_x - SCREEN_WIDTH / 2;
    camera->y = map_y - SCREEN_HEIGHT / 2;
    normalize_camera(camera, map);

    int x, y;
    int start_x = camera->x >> 4;
    int start_y = camera->y >> 4;
    for (y = start_y; y < BG_HEIGHT_16 + start_y; y++)
    {
        for (x = start_x; x < BG_WIDTH_16 + start_x; x++)
        {
            draw_tile(x, y, map);
        }
    }
}

void goto_map_tile(const Map *map, Camera *camera, int map_x, int map_y)
{
    goto_map_pixel(map, camera, map_x << 4, map_y << 4);
}

void load_map(const Map *map, Camera *camera)
{
    // CBB = charblock base, where the tile sprites are stored. there are 4 CBB
    // SBB = screenblock base, where the tilemap is stored. there are 32 SBBs
    REG_BG0CNT = BG_CBB(0) | BG_SBB(30) | BG_PRIO(2) | BG_REG_32x32 | BG_4BPP;
    memcpy32(tile_mem, tilesTiles, tilesTilesLen / 4);
    memcpy32(pal_bg_mem, tilesPal, 16);

    goto_map_tile(map, camera, map->start_x, map->start_y);
}

// TODO: Move this into a Game struct or something
Camera prev_cam = {1, 1};

void update_tilemap(const Map *map, Camera *camera)
{
    Camera cam = *camera;
    int map_left = cam.x >> 4;
    int map_right = map_left + 15;
    int map_top = cam.y >> 4;
    int map_bottom = map_top + 10;

    // Handle left and right edges
    for (int y = 0; y < BG_HEIGHT_16; y++)
    {
        int map_y = map_top + y;
        if (cam.x < prev_cam.x)
            draw_tile(map_left, map_y, map);
        else
            draw_tile(map_right, map_y, map);
    }

    // Handle top and bottom edges
    for (int x = 0; x < BG_WIDTH_16; x++)
    {
        int map_x = map_left + x;
        if (cam.y < prev_cam.y)
            draw_tile(map_x, map_top, map);
        else
            draw_tile(map_x, map_bottom, map);
    }

    prev_cam = cam;
}

// -----------------------------------------------------------------------------
// Private functions definitions
// -----------------------------------------------------------------------------

void draw_tile(int x, int y, const Map *map)
{
    int offset = y * map->width + x;
    int map_tile_id = (map->tilemap[offset] << 2);

    x = (x & 15) * 2;
    y = (y & 15) * 32 * 2;

    // Load tiles into the screen block
    se_mem[30][y + x] = map_tile_id;
    se_mem[30][y + x + 1] = map_tile_id + 1;
    se_mem[30][y + 32 + x] = map_tile_id + 2;
    se_mem[30][y + 32 + x + 1] = map_tile_id + 3;
}
