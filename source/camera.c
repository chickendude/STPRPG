#include <tonc.h>

#include "camera.h"

// -----------------------------------------------------------------------------
// Private function declarations
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Public function definitions
// -----------------------------------------------------------------------------

void update_camera(Camera *camera, int x, int y)
{
    x -= SCREEN_WIDTH / 2;
    if (camera->x - x > 15) x = camera->x - 15;
    if (camera->x - x < -15) x = camera->x + 15;
    y = SCREEN_HEIGHT / 2;
    if (camera->y - y > 15) y = camera->y - 15;
    if (camera->y - y < -15) y = camera->y + 15;
    camera->x = x;
    camera->y = y;
}

// -----------------------------------------------------------------------------
// Private functions definitions
// -----------------------------------------------------------------------------