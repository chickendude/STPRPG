#include <tonc.h>

#include "map_town.h"

#include "actions.h"
#include "camera.h"
#include "character.h"
#include "character_states/states.h"
#include "entity.h"
#include "game.h"
#include "map.h"
#include "state.h"

static Game game;
Character tann;

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

    oam_init(obj_mem, 128);

    game.current_map = &map_1;
    game.player = &tann;

    load_map(game.current_map, &game.camera);
    load_character(&tann, &ES_TANN, 0, 20, 20);

    CharacterStateParam esp = {&tann, &game};
    change_state(esp, &wait_state);
//    tann.state->initialize(NONE, &tann);

    vid_vsync();
    REG_DISPCNT = DCNT_MODE0 |
                  DCNT_BG0 | DCNT_BG1 | DCNT_BG2 |
                  DCNT_OBJ | DCNT_OBJ_1D;

    REG_BG0HOFS = 0;
    REG_BG0VOFS = 0;
}

int frame = 0;

void update()
{
    Camera *camera = &game.camera;
    const Map *map = game.current_map;

    update_tilemap(map, camera);
    update_camera(camera, &tann.entity);
    normalize_camera(camera, map);
    draw_entity(&tann.entity, camera);
    tann.state->update();
//    is_tile_passable(&tann.entity, map);
    REG_BG0HOFS = camera->x;
    REG_BG1HOFS = camera->x;
    REG_BG2HOFS = camera->x;
    REG_BG0VOFS = camera->y;
    REG_BG1VOFS = camera->y;
    REG_BG2VOFS = camera->y;
}

void input(StateStack *state_stack)
{
    tann.state->input(NULL);
}

// -----------------------------------------------------------------------------
// Private functions definitions
// -----------------------------------------------------------------------------
