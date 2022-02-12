#include "character_states/states.h"

#include "character.h"
#include "constants.h"
#include "state.h"

static Character *character;
static Entity *entity;
static const Map *map;

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
    CharacterMap *cm = param_cm;
    character = cm->character;
    map = cm->map;
    entity = &character->entity;
    entity->frame = 0;
    set_entity_sprite_id(entity, entity->direction * 16);
}

static void input(StateStack *state_stack)
{
    // Check if any arrow key was pressed and switch to move state if so
    if (key_tri_vert() || key_tri_horz())
    {
        change_state(character, map, &move_state);
    }
}

static void update()
{
}
