#ifndef STPRPG_ENTITY_H
#define STPRPG_ENTITY_H

#include "types.h"

struct Entity
{
    const unsigned int *sprite_data;
    const int sprite_data_len;
    int x, y;
    OBJ_ATTR *oam;
};

void load_entity(Entity *entity, int oam_index, int x, int y);

void draw_entity(const Entity *entity, const Camera *camera);

extern Entity tann;

#endif //STPRPG_ENTITY_H
