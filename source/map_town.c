#include <tonc.h>
#include "map_town.h"

#include "camera.h"
#include "map.h"
#include "state.h"

static Camera camera;
const static Map *map;

// -----------------------------------------------------------------------------
// Private function declarations
// -----------------------------------------------------------------------------

// State definitions
static void initialize(StateType leaving_state, void *parameter);

static void input(StateStack *state_stack);

static void update();

// Private functions
void limit_camera_bounds();

// -----------------------------------------------------------------------------
// Public variable definitions
// -----------------------------------------------------------------------------
const State map_town_state = {
        &initialize,
        &update,
        &input
};

// -----------------------------------------------------------------------------
// Public function definitions
// -----------------------------------------------------------------------------

void initialize(StateType leaving_state, void *parameter)
{
    // Turn off display while we load/prepare everything
    REG_DISPCNT = 0;

    map = &map_1;

    load_map(map, &camera);

    vid_vsync();
    REG_DISPCNT = DCNT_MODE0 | DCNT_BG0 | DCNT_OBJ | DCNT_OBJ_1D;

    REG_BG0HOFS = 0;
    REG_BG0VOFS = 0;
}

void update()
{
    update_tilemap(map, &camera);
    REG_BG0HOFS = camera.x;
    REG_BG0VOFS = camera.y;
}

void input(StateStack *state_stack)
{
    camera.x += key_tri_horz();
    camera.y += key_tri_vert();
    limit_camera_bounds();
}

// -----------------------------------------------------------------------------
// Private functions definitions
// -----------------------------------------------------------------------------

void limit_camera_bounds()
{
    int right_edge = (map->width * TILE_SIZE) - SCREEN_WIDTH;
    int bottom_edge = (map->height * TILE_SIZE) - SCREEN_HEIGHT;

    if (camera.x < 0) camera.x = 0;
    if (camera.y < 0) camera.y = 0;
    if (camera.x > right_edge) camera.x = right_edge;
    if (camera.y > bottom_edge) camera.y = bottom_edge;
}