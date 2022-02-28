#include "character_states/states.h"

#include "character.h"
#include "game.h"
#include "state.h"

static CharacterStateParam state_params;

// -----------------------------------------------------------------------------
// Private function declarations
// -----------------------------------------------------------------------------
static void initialize(StateType leaving_state, void *parameter);

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
void initialize(StateType leaving_state, void *param_cm)
{
    state_params = *(CharacterStateParam *) param_cm;

    // Reset entity's sprite data
    Character *character = state_params.character;
    character->frame = 0;
    set_character_sprite_id(character, character->direction * 16);
}

static void input(StateStack *state_stack)
{
}

static void update(Character *npc, Game *game)
{
    if (npc == NULL) return;

    set_character_pos(npc, &game->camera);
    if (game->player->y > npc->y)
        npc->oam->attr2 |= ATTR2_PRIO(3);
    else
        npc->oam->attr2 &= ~ATTR2_PRIO_MASK;
}
