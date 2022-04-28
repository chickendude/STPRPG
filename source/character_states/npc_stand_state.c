#include "character_states/states.h"

#include "character.h"
#include "game.h"
#include "mathtools.h"
#include "state.h"


// -----------------------------------------------------------------------------
// Private function declarations
// -----------------------------------------------------------------------------
static void initialize(StateType leaving_state, void *character);

static void input(StateStack *state_stack);

static void update(Character *player, Game *game);

// External declaration
const State npc_stand_state = {&initialize, &update, &input};

// -----------------------------------------------------------------------------
// Public function definitions
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Private functions definitions
// -----------------------------------------------------------------------------
void initialize(StateType leaving_state, void *character)
{
    // Cast parameters to CharacterStateParam
    Character *npc = (Character *) character;

    // Reset entity's sprite data
    npc->frame = 0;
    npc->frame_counter = random(128);
    set_character_sprite_id(character, npc->direction * 16);
}

static void input(StateStack *state_stack)
{
}

static void update(Character *npc, Game *game)
{
    if (npc == NULL) return;

    if (++npc->frame_counter % 128 == 0)
    {
        npc->state_params.game = game;
        // dx
        npc->state_params.param1 = random(2) * 2 - 1;
        // dy
        npc->state_params.param2 = random(2) * 2 - 1;
        // num frames
        npc->state_params.param3 = random(32) + 1;
        change_state(npc, &npc_move_state);
    }

    set_character_pos(npc, &game->camera);
    update_character_priority(game->player, npc);
}
