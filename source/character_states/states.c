#include <tonc.h>

#include "character_states/states.h"

#include "character.h"
#include "constants.h"
#include "state.h"

static CharacterStateParam state_params;
// -----------------------------------------------------------------------------
// Private function declarations
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Public function definitions
// -----------------------------------------------------------------------------
void change_state(CharacterStateParam params, const State *state)
{
    // TODO: Call exit function
    state_params = params;
    state_params.character->state = state;
    state->initialize(0, &state_params);
}


// -----------------------------------------------------------------------------
// Private functions definitions
// -----------------------------------------------------------------------------
