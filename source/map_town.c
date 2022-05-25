#include <tonc.h>

#include "map_town.h"

#include "actions.h"
#include "camera.h"
#include "character.h"
#include "character_states/states.h"
#include "sprite.h"
#include "game.h"
#include "map.h"
#include "state.h"

static Game game;
static Character chasqui;
static Character npcs[2];

// -----------------------------------------------------------------------------
// Private function declarations
// -----------------------------------------------------------------------------

// State definitions
static void initialize(StateType leaving_state, void *character);

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
    // load chasqui
    game.player = &chasqui;
    game.player->state = &wait_state;
    game.player->entity = &S_CHASQUI;
    game.player->direction = DOWN;
    game.player->x = game.current_map->start_x;
    game.player->y = game.current_map->start_y;

    load_map(game.current_map, &game.camera);
    load_character(&chasqui, &chasqui, 0);
    for (int i = 0; i < game.current_map->num_npcs; i++)
    {
        Character *npc = &npcs[i];
        load_character(npc, &game.current_map->npcs[i], i + 1);
        npc->state_params.game = &game;
        change_state(npc, &npc_stand_state);
//        npc->state->initialize(NONE, &esp);
    }

    chasqui.state_params.game = &game;
    change_state(&chasqui, &wait_state);
//    chasqui.state->initialize(NONE, &csp);

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

    update_camera(camera, &chasqui);
    normalize_camera(camera, map);
    update_tilemap(map, camera);
    set_character_pos(&chasqui, camera);
    chasqui.state->update();

    // Update NPCs
    for (int i = 0; i < game.current_map->num_npcs; i++)
    {
        Character *npc = &npcs[i];
        npc->state->update(npc, &game);
    }

    REG_BG0HOFS = camera->x;
    REG_BG1HOFS = camera->x;
    REG_BG2HOFS = camera->x;
    REG_BG0VOFS = camera->y;
    REG_BG1VOFS = camera->y;
    REG_BG2VOFS = camera->y;
}

void input(StateStack *state_stack)
{
    chasqui.state->input(NULL);
}

// -----------------------------------------------------------------------------
// Private functions definitions
// -----------------------------------------------------------------------------
