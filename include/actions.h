#ifndef STPRPG_ACTIONS_H
#define STPRPG_ACTIONS_H

#include "types.h"

enum ActionType {
    ACT_NONE,
    ACT_TELEPORT
};

struct ActionTeleport
{
    const Map *map;
    int x, y;
};

extern const struct ActionTeleport teleport1;
extern const struct ActionTeleport teleport2;

void action_teleport(ActionTeleport *action_teleport, Game *game);

#endif //STPRPG_ACTIONS_H
