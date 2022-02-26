#include "actions.h"
#include "entity.h"
#include "game.h"
#include "map.h"

const ActionTeleport teleport1 = {&map_1, 5, 6};
const ActionTeleport teleport2 = {&map_1, 28, 6};
// -----------------------------------------------------------------------------
// Private function declarations
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Public function definitions
// -----------------------------------------------------------------------------

void
action_teleport(ActionTeleport *action_teleport, Game *game)
{
    Character *character = &game->player;
    int x = action_teleport->x;
    int y = action_teleport->y;
    character->x = x << 4;
    character->y = y << 4;
    goto_map_tile(action_teleport->map, &game->camera, x, y);
}

// -----------------------------------------------------------------------------
// Private functions definitions
// -----------------------------------------------------------------------------