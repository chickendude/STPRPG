#ifndef STPRPG_ENTITY_H
#define STPRPG_ENTITY_H

#include <tonc.h>
#include "types.h"

// Note: The code to calculate the sprite id relies on this order
enum EntityDirection
{
    DOWN, UP, LEFT, RIGHT
};

struct EntitySprite
{
    const unsigned int *data;
    const int data_len;
};

struct Entity
{
    const EntitySprite *sprite;
};

extern const Entity E_TANN;
extern const EntitySprite ES_TANN;

#endif //STPRPG_ENTITY_H
