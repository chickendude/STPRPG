#include "character.h"

#include "entity.h"
#include "character_states/states.h"

// -----------------------------------------------------------------------------
// Private function declarations
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Public function definitions
// -----------------------------------------------------------------------------

void load_character(Character *character, const EntitySprite *sprite,
                    int oam_index, int x, int y)
{
//    character->state = &wait_state;
    load_entity(&character->entity, sprite, oam_index, x, y);
}

// -----------------------------------------------------------------------------
// Private functions definitions
// -----------------------------------------------------------------------------