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
void update_camera(Camera *camera, int x, int y);

#endif //LAUGURPIL_CAMERA_H
