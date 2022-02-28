#include "character_states/states.h"

#include "character.h"
#include "constants.h"
#include "state.h"
#include "trigger.h"

static CharacterStateParam state_params;
static Character *character;

// -----------------------------------------------------------------------------
// Private function declarations
// -----------------------------------------------------------------------------
static void initialize(StateType leaving_state, void *parameter);

static void input(StateStack *state_stack);

static void update();

// External declaration
const State wait_state = {&initialize, &update, &input};

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
    character = state_params.character;
    character->frame = 0;
    set_character_sprite_id(character, character->direction * 16);
}

static void input(StateStack *state_stack)
{
    // Check if any arrow key was pressed and switch to move state if so
    if (key_tri_vert() || key_tri_horz())
    {
        change_state(state_params, &move_state);
    } else if (key_hit(KEY_A))
    {
        execute_action_triggers(character, state_params.game);
    }

}

static void update()
{
}
