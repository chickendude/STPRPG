#include "character_states/states.h"

#include "character.h"
#include "state.h"

static CharacterStateParam state_params;

// -----------------------------------------------------------------------------
// Private function declarations
// -----------------------------------------------------------------------------
static void initialize(StateType leaving_state, void *parameter);

static void input(StateStack *state_stack);

static void update();

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

static void update()
{
}
