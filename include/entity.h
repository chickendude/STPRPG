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
    // optional values (they will get overwritten upon loading
    int x, y, frame, frame_counter;
    EntityDirection direction;
    OBJ_ATTR *oam;
};

void
load_entity(Entity *entity, const EntitySprite *sprite, int oam_index,
            int x, int y);

void draw_entity(const Entity *entity, const Camera *camera);

void move_entity(Entity *entity, int dx, int dy, const Map *map);

void set_entity_sprite_id(const Entity *entity, unsigned int sprite_id);

extern const Entity E_TANN;
extern const EntitySprite ES_TANN;

#endif //STPRPG_ENTITY_H
