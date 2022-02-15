#include <tonc.h>
#include "map.h"

#include "camera.h"
#include "constants.h"
#include "entity.h"
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
    REG_BG0CNT = BG_CBB(0) | BG_SBB(29) | BG_PRIO(3) | BG_REG_32x32 | BG_4BPP;
    REG_BG1CNT = BG_CBB(0) | BG_SBB(30) | BG_PRIO(2) | BG_REG_32x32 | BG_4BPP;
    REG_BG2CNT = BG_CBB(0) | BG_SBB(31) | BG_PRIO(0) | BG_REG_32x32 | BG_4BPP;
    memcpy32((int *) MEM_VRAM + 32, tilesTiles, tilesTilesLen / 4);
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

bool is_tile_passable(Entity *entity, int x_off, int y_off, const Map *map)
{
    int x1 = entity->x + ENTITY_MARGIN_H + x_off;
    int y1 = entity->y + (16 - ENTITY_HEIGHT) + y_off;
    int x2 = x1 + ENTITY_WIDTH - 1;
    int y2 = y1 + ENTITY_HEIGHT - 1;

    const unsigned char *collision_map =
            map->tilemap + map->width * map->height;
    int map_x1 = x1 / 16;
    int map_x2 = x2 / 16;
    int map_y1 = y1 / 16;
    int map_y2 = y2 / 16;
    int tile1 = collision_map[map_y1 * map->width + map_x1];
    int tile2 = collision_map[map_y1 * map->width + map_x2];
    int tile3 = collision_map[map_y2 * map->width + map_x1];
    int tile4 = collision_map[map_y2 * map->width + map_x2];

    return tile1 < BLOCKING_TILE_START && tile2 < BLOCKING_TILE_START &&
           tile3 < BLOCKING_TILE_START && tile4 < BLOCKING_TILE_START;
}

// -----------------------------------------------------------------------------
// Private functions definitions
// -----------------------------------------------------------------------------

void draw_tile(int x, int y, const Map *map)
{
    int map_size = map->width * map->height;
    int tile_index = y * map->width + x;

    x = (x & 15) * 2;
    y = (y & 15) * 32 * 2;

    for (int i = 0; i < 3; i++)
    {
        int map_tile_id = (map->tilemap[map_size * i + tile_index] << 2);

        // Load tiles into the screen block
        se_mem[29 + i][y + x] = map_tile_id;
        se_mem[29 + i][y + x + 1] = map_tile_id + 1;
        se_mem[29 + i][y + 32 + x] = map_tile_id + 2;
        se_mem[29 + i][y + 32 + x + 1] = map_tile_id + 3;
    }
}
