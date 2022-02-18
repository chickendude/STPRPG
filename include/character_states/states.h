#ifndef STPRPG_STATES_H
#define STPRPG_STATES_H

#include "types.h"

typedef struct CharacterStateParam
{
    Character *character;
    Game *game;
} CharacterStateParam;

void change_state(CharacterStateParam csp, const State *state);

extern const State wait_state;
extern const State move_state;
#endif //STPRPG_STATES_H
