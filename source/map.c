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
        0, 0,
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

void load_map(const Map *map, Camera *camera)
{
    // CBB = charblock base, where the tile sprites are stored. there are 4 CBB
    // SBB = screenblock base, where the tilemap is stored. there are 32 SBBs
    REG_BG0CNT = BG_CBB(0) | BG_SBB(30) | BG_PRIO(2) | BG_REG_32x32 | BG_4BPP;
//    REG_BG1CNT = BG_CBB(1) | BG_SBB(31) | BG_PRIO(3) | BG_REG_32x32 | BG_4BPP;
    memcpy32(tile_mem, tilesTiles, tilesTilesLen / 4);
    memcpy32(pal_bg_mem, tilesPal, 16);

//    memcpy32(tile_mem[1], ground_tilesTiles, ground_tilesTilesLen / 4);
//    memcpy32(&pal_bg_mem[3 * 16], ground_tilesPal, 16);

//    camera->x = (map->start_x << 4) - SCREEN_WIDTH / 2;
//    camera->y = (map->start_y << 4) - SCREEN_HEIGHT / 2;

    camera->x = 0;
    camera->y = 0;
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

//void update_tilemap(Map *map)
//{
//    Camera cam = ;
//    Camera prev_cam = ;
//    int bg_tiles_offset = map->width * map->height;
//    int map_left = cam.x >> 4;
//    int map_right = map_left + 15;
//    int map_top = cam.y >> 4;
//    int map_bottom = map_top + 10;
//
//    // Handle left and right edges
//    for (int y = 0; y < BG_HEIGHT_16; y++)
//    {
//        int map_y = map_top + y;
//        if (cam.x < prev_cam.x)
//            draw_tile(map_left, map_y, map);
//        else
//            draw_tile(map_right, map_y, map);
//    }
//
//    // Handle top and bottom edges
//    for (int x = 0; x < BG_WIDTH_16; x++)
//    {
//        int map_x = map_left + x;
//        if (cam.y < prev_cam.y)
//            draw_tile(map_x, map_top, map);
//        else
//            draw_tile(map_x, map_bottom, map);
//    }
//
//    // update prev cam: prev_camera = cam;
//}

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
