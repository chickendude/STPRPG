#ifndef STPRPG_GAME_H
#define STPRPG_GAME_H

#include "types.h"
#include "camera.h"

struct Game {
    const Map *current_map;
    Camera camera;
};

#endif //STPRPG_GAME_H
