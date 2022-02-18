#ifndef STPRPG_TRIGGER_H
#define STPRPG_TRIGGER_H

#include "types.h"

struct Trigger {
    int map_x, map_y;
    void *action;
};

void get_triggers_at_xy(const Trigger **triggers, int x, int y, const Map *map);

#endif //STPRPG_TRIGGER_H
