#ifndef STPRPG_SPRITE_H
#define STPRPG_SPRITE_H

#include <tonc.h>
#include "types.h"

// Note: The code to calculate the sprite id relies on this order
enum SpriteDirection
{
    DOWN, UP, LEFT, RIGHT
};

struct Sprite
{
    const unsigned int *data;
    const int data_len;
};

extern const Sprite S_TANN;

#endif //STPRPG_SPRITE_H
