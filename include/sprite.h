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
    const int sprite_size; // Number of tiles in the sprite
    const int sprite_frames; // Number of frames in the sprite animation
};

extern const Sprite S_CHASQUI;
extern const Sprite S_TANN;

#endif //STPRPG_SPRITE_H
