#include <tonc.h>

#include "character_states/states.h"

#include "character.h"
#include "state.h"

// -----------------------------------------------------------------------------
// Private function declarations
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Public function definitions
// -----------------------------------------------------------------------------
void change_state(Character *character, const State *state)
{
    // TODO: Call exit function
    character->state = state;
    state->initialize(0, character);
}


// -----------------------------------------------------------------------------
// Private functions definitions
// -----------------------------------------------------------------------------
