#include <tonc.h>
#include "map_town.h"

#include "camera.h"
#include "map.h"
#include "state.h"

// -----------------------------------------------------------------------------
// Private function declarations
// -----------------------------------------------------------------------------

// State definitions
static void initialize(StateType leaving_state, void *parameter);

static void input(StateStack *state_stack);

static void update();

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
    Camera camera;

    load_map(&map_1, &camera);

    vid_vsync();
    REG_DISPCNT = DCNT_MODE0 | DCNT_BG0 | DCNT_OBJ | DCNT_OBJ_1D;

    REG_BG0HOFS = 0;
    REG_BG0VOFS = 0;
}

void update()
{

}

void input(StateStack *state_stack)
{

}

// -----------------------------------------------------------------------------
// Private functions definitions
// -----------------------------------------------------------------------------