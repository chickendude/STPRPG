#ifndef STPRPG_TRIGGER_H
#define STPRPG_TRIGGER_H

#include "types.h"

struct Trigger {
    int map_x, map_y;
    void *action;
};

extern const Trigger trigger_1, trigger_2;

#endif //STPRPG_TRIGGER_H
