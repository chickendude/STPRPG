#include <tonc.h>

#include "player.h"

#include "camera.h"

// Sprite data
#include "tann.h"

Player tann = {0 * 16, 10, "Tann"};

// -----------------------------------------------------------------------------
// Private function declarations
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Public function definitions
// -----------------------------------------------------------------------------
void load_player(Player *player, int x, int y)
{
    oam_init(obj_mem, 128);
    // Load Car sprites
    memcpy32(tile_mem[4], tannTiles, tannTilesLen / 4);
    memcpy32(pal_obj_mem, tannPal, tannPalLen / 4);

    // Load player's initial coordinates
    player->x = x;
    player->y = y;

    obj_set_attr(player->oam,
                 ATTR0_4BPP | ATTR0_SQUARE | y,
                 ATTR1_SIZE_16x16 | x,
                 ATTR2_PALBANK(0) | player->sprite_id
    );

}

void draw_player(const Player *player, const Camera *camera)
{
    obj_set_pos(player->oam, player->x - camera->x, player->y - camera->y);
}


// -----------------------------------------------------------------------------
// Private functions definitions
// -----------------------------------------------------------------------------