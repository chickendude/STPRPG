#include <tonc.h>

#include "camera.h"
#include "constants.h"
#include "map.h"
#include "entity.h"

// -----------------------------------------------------------------------------
// Private function declarations
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Public function definitions
// -----------------------------------------------------------------------------

void update_camera(Camera *camera, Entity *player)
{
    int x = player->x + TILE_SIZE / 2;
    int y = player->y + TILE_SIZE / 2;

    x -= SCREEN_WIDTH / 2;
    if (camera->x - x > 15) x = camera->x - 15;
    if (camera->x - x < -15) x = camera->x + 15;
    y -= SCREEN_HEIGHT / 2;
    if (camera->y - y > 15) y = camera->y - 15;
    if (camera->y - y < -15) y = camera->y + 15;
    camera->x = x;
    camera->y = y;
}

void normalize_camera(Camera *camera, const Map *map)
{
    int right_edge = (map->width * TILE_SIZE) - SCREEN_WIDTH;
    int bottom_edge = (map->height * TILE_SIZE) - SCREEN_HEIGHT;

    if (camera->x < 0) camera->x = 0;
    if (camera->y < 0) camera->y = 0;
    if (camera->x > right_edge) camera->x = right_edge;
    if (camera->y > bottom_edge) camera->y = bottom_edge;
}
// -----------------------------------------------------------------------------
// Private functions definitions
// -----------------------------------------------------------------------------