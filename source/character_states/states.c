#include <tonc.h>

#include "character_states/states.h"

#include "character.h"
#include "constants.h"
#include "state.h"

static CharacterMap cm;
// -----------------------------------------------------------------------------
// Private function declarations
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Public function definitions
// -----------------------------------------------------------------------------
void change_state(Character *character, const Map *map, const State *state)
{
    // TODO: Call exit function
    character->state = state;
    cm.character = character;
    cm.map = map;
    state->initialize(0, &cm);
}


// -----------------------------------------------------------------------------
// Private functions definitions
// -----------------------------------------------------------------------------
