#include <tonc.h>

#include "entity.h"

#include "camera.h"
#include "map.h"

// Sprite data
#include "tann.h"

const EntitySprite ES_TANN = {&tannTiles, tannTilesLen};

const Entity E_TANN = {&ES_TANN};

// -----------------------------------------------------------------------------
// Private function declarations
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Public function definitions
// -----------------------------------------------------------------------------
void
load_entity(Entity *entity, const EntitySprite *sprite, int oam_index, int x,
            int y)
{
    // Load entity sprites
    memcpy32(tile_mem[4], sprite->data, sprite->data_len / 4);
    memcpy32(pal_obj_mem, tannPal, tannPalLen / 4);

    // Load entity's initial coordinates
    entity->x = x;
    entity->y = y;
    entity->oam = &obj_mem[oam_index];

    obj_set_attr(entity->oam,
                 ATTR0_4BPP | ATTR0_SQUARE | y,
                 ATTR1_SIZE_16x16 | x,
                 ATTR2_PALBANK(0) | ATTR2_PRIO(2) | 0
    );

}

void draw_entity(const Entity *entity, const Camera *camera)
{
    obj_set_pos(entity->oam, entity->x - camera->x, entity->y - camera->y);
}

void move_entity(Entity *entity, int dx, int dy, const Map *map)
{
    // Move horizontally
    if (is_tile_passable(entity, dx, 0, map))
    {
        entity->x += dx;
    } else
    {
        // Move over one tile (TILE_SIZE) and shift left 2 pixels (align entity
        // to tile edge if they bumped into a tile)
        entity->x = ((entity->x + dx) & 0xFFF0) + (TILE_SIZE - ENTITY_MARGIN_H);
        if (dx > 0)
        {
            entity->x -= ENTITY_WIDTH;
        }

        // Help player around corners if the up/down button isn't being pressed
        if (dy == 0)
        {
            int y_offset = entity->y & 0xF;
            if (y_offset < 8 && is_tile_passable(entity, dx, -y_offset, map))
                entity->y--;
            else if (y_offset < 8 &&
                     is_tile_passable(entity, dx, ENTITY_HEIGHT - y_offset,
                                      map))
                entity->y++;
        }
    }

    // Move vertically
    if (is_tile_passable(entity, 0, dy, map))
    {
        entity->y += dy;
    } else
    {
        entity->y = (entity->y + dy) & 0xFFF0;
        if (dy < 0)
        {
            entity->y += ENTITY_HEIGHT;
        }

        // Help player around corners if left/right button isn't being pressed
        if (dx == 0)
        {
            int x_offset = entity->x & 0xF;
            if (x_offset < 12 && is_tile_passable(entity, -x_offset, dy, map))
                entity->x--;
            else if (x_offset > 4 &&
                     is_tile_passable(entity, TILE_SIZE - x_offset, dy, map))
                entity->x++;
        }
    }

    // Prioritize left/right-facing sprites
    if (dx < 0) entity->direction = LEFT;
    else if (dx > 0) entity->direction = RIGHT;
    else if (dy < 0) entity->direction = UP;
    else if (dy > 0) entity->direction = DOWN;
}

void set_entity_sprite_id(const Entity *entity, unsigned int sprite_id)
{
    int attr2 = entity->oam->attr2 & ~ATTR2_ID_MASK;
    entity->oam->attr2 = attr2 | sprite_id;

}

// -----------------------------------------------------------------------------
// Private functions definitions
// -----------------------------------------------------------------------------