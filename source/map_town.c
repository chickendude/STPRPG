#include <tonc.h>

#include "map_town.h"

#include "camera.h"
#include "map.h"
#include "player.h"
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
    tann.oam = &obj_mem[0];
    load_player(&tann, 10, 20);

    vid_vsync();
    REG_DISPCNT = DCNT_MODE0 | DCNT_BG0 | DCNT_OBJ | DCNT_OBJ_1D;

    REG_BG0HOFS = 0;
    REG_BG0VOFS = 0;
}

int frame = 0;

void update()
{
    if ((frame++ & 0x0f) == 0)
    {
        int attr2 = obj_mem[0].attr2;
        int id = (attr2 & ATTR2_ID_MASK) + 4;
        if (id >= 4 * 4) id = 0;
        obj_mem[0].attr2 = attr2 & ~ATTR2_ID_MASK | id;
    }

    update_tilemap(map, &camera);
    update_camera(&camera, &tann);
    normalize_camera(&camera, map);
    draw_player(&tann, &camera);
    REG_BG0HOFS = camera.x;
    REG_BG0VOFS = camera.y;
}

void input(StateStack *state_stack)
{
    int speed = key_is_down(KEY_A) ? RUNNING_SPEED : 1;
    tann.x += key_tri_horz() * speed;
    tann.y += key_tri_vert() * speed;
}

// -----------------------------------------------------------------------------
// Private functions definitions
// -----------------------------------------------------------------------------
