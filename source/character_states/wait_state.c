#include "character_states/states.h"

#include "character.h"
#include "constants.h"
#include "state.h"

static Character *character;
static Entity *entity;

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
void initialize(StateType leaving_state, void *param_character)
{
    character = param_character;
    entity = &character->entity;
    entity->frame = 0;
    entity->oam->attr2 = entity->direction * 16;
}

static void input(StateStack *state_stack)
{
    // Check if any arrow key was pressed and switch to move state if so
    if (key_tri_vert() || key_tri_horz())
    {
        change_state(character, &move_state);
    }
}

static void update()
{
}
