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
static Character tann;
static Character npcs[2];

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
    // load Tann
    game.player = &tann;
    game.player->state = &wait_state;
    game.player->entity = &E_TANN;
    game.player->direction = DOWN;
    game.player->x = game.current_map->start_x;
    game.player->y = game.current_map->start_y;

    load_map(game.current_map, &game.camera);
    load_character(&tann, &tann, 0);
    load_character(&npcs[0], &game.current_map->npcs[0], 1);
    npcs[0].state = game.current_map->npcs[0].state;

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

void update()
{
    Camera *camera = &game.camera;
    const Map *map = game.current_map;

    update_tilemap(map, camera);
    update_camera(camera, &tann.entity);
    normalize_camera(camera, map);
    draw_character(&tann, camera);
    draw_character(&npcs[0], camera);
    tann.state->update();
    for (int i = 0; i < game.current_map->num_npcs; i++)
    {
        Character *npc = &game.current_map->npcs[i];
        npc->state->update();
        break;
    }
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
