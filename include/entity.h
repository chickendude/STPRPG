#ifndef STPRPG_ENTITY_H
#define STPRPG_ENTITY_H

#include <tonc.h>
#include "types.h"

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
    EntitySprite *sprite;
    // optional values (they will get overwritten upon loading
    int x, y, frame, frame_counter;
    EntityDirection direction;
    OBJ_ATTR *oam;
};

void
load_entity(Entity *entity, const EntitySprite *sprite, int oam_index,
            int x, int y);

void draw_entity(const Entity *entity, const Camera *camera);

void set_entity_sprite_id(const Entity *entity, unsigned int sprite_id);

extern const EntitySprite ES_TANN;

#endif //STPRPG_ENTITY_H
