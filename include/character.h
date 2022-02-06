#ifndef STPRPG_CHARACTER_H
#define STPRPG_CHARACTER_H

#include "entity.h"
#include "types.h"

struct Character
{
    Entity entity;
    const State *state;
};

void load_character(Character *character, const EntitySprite *sprite,
                    int oam_index, int x, int y);

#endif //STPRPG_CHARACTER_H
