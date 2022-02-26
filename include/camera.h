#ifndef LAUGURPIL_CAMERA_H
#define LAUGURPIL_CAMERA_H

#include "types.h"

struct Camera {
    signed int x, y;
};

/**
 * Make sure camera fits within the map boundaries.
 *
 * This just ensures that the camera doesn't go lower than 0,0 or extend beyond
 * the width/height of the map.
 *
 * @param camera Camera object to normalize.
 * @param map The map the camera needs to fit within.
 */
void normalize_camera(Camera *camera, const Map *map);

/**
 * Centers the camera around the player.
 *
 * @param camera The camera to update.
 * @param player The player to focus on.
 */
void update_camera(Camera *camera, Character *player);

#endif //LAUGURPIL_CAMERA_H
