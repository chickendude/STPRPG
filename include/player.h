#ifndef STPRPG_PLAYER_H
#define STPRPG_PLAYER_H

#include "types.h"

struct Player {
    int sprite_id;
    int x, y;
    int hp;
    char* name[10];
    OBJ_ATTR *oam;
};

void load_player(Player *player, int x, int y);
void draw_player(const Player *player, const Camera *camera);

extern Player tann;

#endif //STPRPG_PLAYER_H
