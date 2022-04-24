#ifndef STPRPG_CHARACTER_H
#define STPRPG_CHARACTER_H

#include "sprite.h"
#include "character_states/states.h"
#include "types.h"

struct Character
{
    const Sprite *entity;
    const State *state;
    int x, y;
    SpriteDirection direction;
    // Optional fields (should be set to zero/filled in automatically)
    CharacterStateParam state_params;
    int frame, frame_counter;
    OBJ_ATTR *oam;
};

void load_character(Character *character_dst, const Character *character_src, int oam_index);

void move_character(Character *character, int dx, int dy, const Map *map);

void
set_character_sprite_id(const Character *character, unsigned int sprite_id);

/**
 * Updates the character's position on screen according to character and camera
 * position.
 *
 * @param character Character whose position should be set.
 * @param camera The game's camera, used to calculate position on screen.
 */
void set_character_pos(const Character *character, const Camera *camera);

/**
 * Updates the character's animation frame count and advances to the next frame
 * if needed.
 *
 * @param character Character you want to animate.
 */
void update_animation(Character *character)

#endif //STPRPG_CHARACTER_H
