#include "character_states/states.h"

#include "character.h"
#include "game.h"
#include "state.h"


// -----------------------------------------------------------------------------
// Private function declarations
// -----------------------------------------------------------------------------
static void initialize(StateType leaving_state, void *character);

static void input(StateStack *state_stack);

static void update(Character *player, Game *game);

// External declaration
const State npc_move_state = {&initialize, &update, &input};

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
    set_character_sprite_id(npc, npc->direction * 16);
}

static void input(StateStack *state_stack)
{
}

static void update(Character *npc, Game *game)
{
    if (npc == NULL) return;

    move_character(npc, 1, 1, game->current_map);

    set_character_pos(npc, &game->camera);
    if (game->player->y > npc->y)
        npc->oam->attr2 |= ATTR2_PRIO(3);
    else
        npc->oam->attr2 &= ~ATTR2_PRIO_MASK;
}
