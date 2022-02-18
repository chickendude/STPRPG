#ifndef STPRPG_CONSTANTS_H
#define STPRPG_CONSTANTS_H

#include <tonc.h>

/**
 * The number of 16x16 tiles that will cover the whole width of the map + one
 * extra for scrolling.
 *
 * A GBA background can fit 32 8x8 tiles, since we are using 16x16 tiles we can
 * only fit 16 in it.
 */
#define BG_WIDTH_16 16

/**
 * The number of 16x16 tiles that will cover the height of the map with one
 * extra so that it shows up when scrolling.
 *
 * 160 / 8 = 20 tiles, but each entry is 16x16 so that's 10 tiles. We draw one
 * extra for scrolling.
 */
#define BG_HEIGHT_16 11

/**
 * The tile id of the first tile that a player cannot walk through.
 */
#define BLOCKING_TILE_START 3

/**
 * The height of an entity. The sprite is 16x16 but we may want the collision
 * box to be smaller than that.
 */
#define ENTITY_HEIGHT 6

/**
 * The width of an entity. The sprite is 16x16 but we may want the collision
 * box to be smaller than that.
 */
#define ENTITY_WIDTH 12

/**
 * Entity's horizontal margin.
 *
 * This is how many pixels there are on either side of an entity's sprite.
 */
#define ENTITY_MARGIN_H ((TILE_SIZE - ENTITY_WIDTH) / 2)

/**
 * The maximum number of triggers the player can be standing on at once.
 */
#define MAX_TRIGGERS 4

/**
 * The maximum number of maps that can be in the game.
 */
#define NUM_MAPS 1

/**
 * The number of pixels to move when running.
 *
 * The default speed otherwise is one pixel per frame.
 */
#define RUNNING_SPEED 6

/**
 * The size (in pixels) per tile.
 */
#define TILE_SIZE 16

#endif //STPRPG_CONSTANTS_H
