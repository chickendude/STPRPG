#include "actions.h"
#include "entity.h"
#include "map.h"
#include "maps.h"

struct ActionTeleport teleport1 = {&map_1, 5, 5};
struct ActionTeleport teleport2 = {&map_1, 28, 6};
// -----------------------------------------------------------------------------
// Private function declarations
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Public function definitions
// -----------------------------------------------------------------------------

void
action_teleport(ActionTeleport *action_teleport, Camera *camera, Entity *entity)
{
    int x = action_teleport->x;
    int y = action_teleport->y;
    entity->x = x << 4;
    entity->y = y << 4;
    goto_map_tile(action_teleport->map, camera, x, y);
}

// -----------------------------------------------------------------------------
// Private functions definitions
// -----------------------------------------------------------------------------