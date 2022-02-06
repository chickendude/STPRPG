#ifndef STPRPG_STATES_H
#define STPRPG_STATES_H

#include "types.h"

void change_state(Character *character, const State *state);

extern const State wait_state;
extern const State move_state;
#endif //STPRPG_STATES_H
