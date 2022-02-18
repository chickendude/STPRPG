#ifndef STPRPG_GAME_H
#define STPRPG_GAME_H

#include "types.h"
#include "camera.h"
#include "character.h"

struct Game {
    const Map *current_map;
    Camera camera;
    Character *player;
};

#endif //STPRPG_GAME_H
