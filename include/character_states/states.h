#ifndef STPRPG_STATES_H
#define STPRPG_STATES_H

#include "types.h"

void change_state(Character *character, const Map *map, const State *state);

typedef struct CharacterMap
{
    Character *character;
    const Map *map;
} CharacterMap;

extern const State wait_state;
extern const State move_state;
#endif //STPRPG_STATES_H
