#include "character.h"

#include "camera.h"
#include "character_states/states.h"
#include "sprite.h"
#include "map.h"

// Sprite data
#include "tann.h"

// -----------------------------------------------------------------------------
// Private function declarations
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Public function definitions
// -----------------------------------------------------------------------------

void draw_character(const Character *character, const Camera *camera)
{
    int x = character->x - camera->x;
    int y = character->y - camera->y;

    // Check if character is offscreen
    if (x < -16 || y < -16 || x > 240 || y > 160)
    {
        x = -16;
        y = -16;
    }
    obj_set_pos(character->oam, x, y);
}

void load_character(Character *character_dst, const Character *character_src,
                    int oam_index)
{
//    character->state = &wait_state;
    const Sprite *sprite = character_src->entity;
    // Load sprite sprites
    memcpy32(tile_mem[4], sprite->data, sprite->data_len / 4);
    memcpy32(pal_obj_mem, tannPal, tannPalLen / 4);

    *character_dst = *character_src;

    character_dst->x *= 16;
    character_dst->y *= 16;

    character_dst->oam = &obj_mem[oam_index];

    obj_set_attr(character_dst->oam,
                 ATTR0_4BPP | ATTR0_SQUARE | character_dst->y,
                 ATTR1_SIZE_16x16 | character_dst->x,
                 ATTR2_PALBANK(0) | ATTR2_PRIO(2) | 0
    );
}

void move_character(Character *character, int dx, int dy, const Map *map)
{
    // Move horizontally
    if (is_tile_passable(character, dx, 0, map))
    {
        character->x += dx;
    } else
    {
        // Move over one tile (TILE_SIZE) and shift left 2 pixels (align entity
        // to tile edge if they bumped into a tile)
        character->x =
                ((character->x + dx) & 0xFFF0) + (TILE_SIZE - ENTITY_MARGIN_H);
        if (dx > 0)
        {
            character->x -= ENTITY_WIDTH;
        }

        // Help player around corners if the up/down button isn't being pressed
        if (dy == 0)
        {
            int y_offset = character->y & 0xF;
            if (y_offset < 8 && is_tile_passable(character, dx, -y_offset, map))
                character->y--;
            else if (y_offset < 8 &&
                     is_tile_passable(character, dx, ENTITY_HEIGHT - y_offset,
                                      map))
                character->y++;
        }
    }

    // Move vertically
    if (is_tile_passable(character, 0, dy, map))
    {
        character->y += dy;
    } else
    {
        character->y = (character->y + dy) & 0xFFF0;
        if (dy < 0)
        {
            character->y += ENTITY_HEIGHT;
        }

        // Help player around corners if left/right button isn't being pressed
        if (dx == 0)
        {
            int x_offset = character->x & 0xF;
            if (x_offset < 12 &&
                is_tile_passable(character, -x_offset, dy, map))
                character->x--;
            else if (x_offset > 4 &&
                     is_tile_passable(character, TILE_SIZE - x_offset, dy, map))
                character->x++;
        }
    }

    // Prioritize left/right-facing sprites
    if (dx < 0) character->direction = LEFT;
    else if (dx > 0) character->direction = RIGHT;
    else if (dy < 0) character->direction = UP;
    else if (dy > 0) character->direction = DOWN;
}

void set_character_sprite_id(const Character *character, unsigned int sprite_id)
{
    int attr2 = character->oam->attr2 & ~ATTR2_ID_MASK;
    character->oam->attr2 = attr2 | sprite_id;

}

// -----------------------------------------------------------------------------
// Private functions definitions
// -----------------------------------------------------------------------------