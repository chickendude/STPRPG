#include <tonc.h>

#include "character_states/states.h"

#include "actions.h"
#include "character.h"
#include "constants.h"
#include "map.h"
#include "state.h"
#include "trigger.h"

static CharacterStateParam *state_params;
static Character *character;
static Entity *entity;
static Camera *camera;
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
static void initialize(StateType leaving_state, void *parameter)
{
    state_params = parameter;
    camera = state_params->camera;
    character = state_params->character;
    map = state_params->map;
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
        change_state(*state_params, &wait_state);
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

        // Help player around corners
        int y_offset = entity->y & 0xF;
        if (y_offset < 8 && is_tile_passable(entity, dx, -y_offset, map))
            entity->y--;
        else if (y_offset < 8 &&
                 is_tile_passable(entity, dx, ENTITY_HEIGHT - y_offset, map))
            entity->y++;
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

        // Help player around corners
        int x_offset = entity->x & 0xF;
        if (x_offset < 12 && is_tile_passable(entity, -x_offset, dy, map))
            entity->x--;
        else if (x_offset > 4 &&
                 is_tile_passable(entity, TILE_SIZE - x_offset, dy, map))
            entity->x++;
    }

    // Prioritize left/right-facing sprites
    if (dx < 0) entity->direction = LEFT;
    else if (dx > 0) entity->direction = RIGHT;
    else if (dy < 0) entity->direction = UP;
    else if (dy > 0) entity->direction = DOWN;

    for (int i = 0; i < map->num_triggers; i++)
    {
        const Trigger *trigger = &map->triggers[i];
        int m_x = trigger->map_x << 4;
        int m_y = trigger->map_y << 4;
        int m_w = TILE_SIZE;
        int m_h = TILE_SIZE;
        int e_x = entity->x + ENTITY_MARGIN_H;
        int e_y = entity->y + (TILE_SIZE - ENTITY_HEIGHT);
        int e_h = ENTITY_HEIGHT;
        int e_w = ENTITY_WIDTH;
        if (e_x < m_x + m_w &&
            e_x + e_w > m_x &&
            e_y < m_y + m_h &&
            e_y + e_h > m_y)
        {
           action_teleport(trigger->action, camera, entity);
        }
    }


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
