#ifndef STPRPG_ACTIONS_H
#define STPRPG_ACTIONS_H

#include "types.h"

struct ActionTeleport
{
    const Map *map;
    int x, y;
};

extern struct ActionTeleport teleport1;
extern struct ActionTeleport teleport2;

void action_teleport(ActionTeleport *action_teleport, Camera *camera, Entity *entity);

#endif //STPRPG_ACTIONS_H
