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
static void initialize(StateType leaving_state, void *character);

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
    // Reset entity's sprite data
    character = param_cm;
    state_params = character->state_params;
    character->frame = 0;
    const int num_frames =
            character->entity->sprite_size * character->entity->sprite_frames;
    set_character_sprite_id(character, character->direction * num_frames);
}

static void input(StateStack *state_stack)
{
    // Check if any arrow key was pressed and switch to move state if so
    if (key_tri_vert() || key_tri_horz())
    {
        change_state(character, &move_state);
    } else if (key_hit(KEY_A))
    {
        execute_action_triggers(character, character->state_params.game);
    }

}

static void update()
{
}
