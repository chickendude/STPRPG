#include <tonc.h>

#include "entity.h"

#include "camera.h"

// Sprite data
#include "tann.h"

const EntitySprite ES_TANN = {&tannTiles, tannTilesLen};

// -----------------------------------------------------------------------------
// Private function declarations
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Public function definitions
// -----------------------------------------------------------------------------
void
load_entity(Entity *entity, const EntitySprite *sprite, int oam_index, int x, int y)
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
                 ATTR2_PALBANK(0) | 0
    );

}

void draw_entity(const Entity *entity, const Camera *camera)
{
    obj_set_pos(entity->oam, entity->x - camera->x, entity->y - camera->y);
}


// -----------------------------------------------------------------------------
// Private functions definitions
// -----------------------------------------------------------------------------