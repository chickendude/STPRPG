#include <tonc.h>

#include "character_states/states.h"

#include "character.h"
#include "constants.h"
#include "map.h"
#include "state.h"

static Character *character;
static Entity *entity;
static const Map *map;

// -----------------------------------------------------------------------------
// Private function declarations
// -----------------------------------------------------------------------------
static void initialize(StateType leaving_state, void *parameter);

static void input(StateStack *state_stack);

static void update();

// External declaration
const State move_state = {&initialize, &update, &input};

// -----------------------------------------------------------------------------
// Public function definitions
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Private functions definitions
// -----------------------------------------------------------------------------
static void initialize(StateType leaving_state, void *param_cm)
{
    CharacterMap *cm = param_cm;
    character = cm->character;
    map = cm->map;
    entity = &character->entity;
    entity->frame = 0;
}

static void input(StateStack *state_stack)
{
    int speed = key_is_down(KEY_A) ? RUNNING_SPEED : 1;
    int dx = key_tri_horz() * speed;
    int dy = key_tri_vert() * speed;

    // Check if keys were released
    if (dx == 0 && dy == 0)
    {
        change_state(character, map, &wait_state);
        return;
    }

    // Move horizontally
    if (is_tile_passable(entity, dx, 0, map))
    {
        entity->x += dx;
    } else
    {
        // Move over one tile (TILE_SIZE) and shift left 2 pixels
        // (ENTITY_MARGIN_H)
        entity->x = ((entity->x + dx) & 0xFFF0) + (TILE_SIZE - ENTITY_MARGIN_H);
        if (dx > 0)
        {
            entity->x -= ENTITY_WIDTH;
        }
    }

    // Move vertically
    if (is_tile_passable(entity, 0, dy, map))
    {
        entity->y += dy;
    } else
    {
        entity->y = (entity->y + dy) & 0xFFF0;
        if (dy < 0)
        {
            entity->y += ENTITY_HEIGHT;
        }
    }

    // Prioritize left/right-facing sprites
    if (dx < 0) entity->direction = LEFT;
    else if (dx > 0) entity->direction = RIGHT;
    else if (dy < 0) entity->direction = UP;
    else if (dy > 0) entity->direction = DOWN;
    // TODO: Otherwise it takes a couple frames to update the player's direction
    set_entity_sprite_id(entity, entity->frame + entity->direction * 16);
}

static void update()
{
    if (entity->frame_counter++ >= 10)
    {
        entity->frame_counter = 0;

        // Show next frame (each sprite has 4 8x8 sections)
        entity->frame += 4;

        // Check if frame wrapped around
        if (entity->frame >= 4 * 4) entity->frame = 0;

        // Point OAM to correct sprite id
        set_entity_sprite_id(entity, entity->frame + entity->direction * 16);
    }
}
