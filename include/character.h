#ifndef STPRPG_CHARACTER_H
#define STPRPG_CHARACTER_H

#include "sprite.h"
#include "types.h"

struct Character
{
    const Sprite *entity;
    const State *state;
    int x, y;
    SpriteDirection direction;
    // Optional fields (should be set to zero/filled in automatically)
    int frame, frame_counter;
    OBJ_ATTR *oam;
};

void draw_character(const Character *character, const Camera *camera);

void load_character(Character *character_dst, const Character *character_src, int oam_index);

void move_character(Character *character, int dx, int dy, const Map *map);

void
set_character_sprite_id(const Character *character, unsigned int sprite_id);

#endif //STPRPG_CHARACTER_H
