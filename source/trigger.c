#include "trigger.h"

#include "entity.h"
#include "game.h"
#include "map.h"

// -----------------------------------------------------------------------------
// Private function declarations
// -----------------------------------------------------------------------------
void
execute_trigger(const ActionType action_type, const void *action, Game *game);

// -----------------------------------------------------------------------------
// Public function definitions
// -----------------------------------------------------------------------------
void get_triggers_at_xy(const Trigger **triggers, int x, int y, const Map *map)
{
    int trigger_index = 0;

    // Check if there are any triggers in map
    for (int i = 0; i < map->num_triggers; i++)
    {
        const Trigger *trigger = &map->triggers[i];
        int m_x = trigger->map_x << 4;
        int m_y = trigger->map_y << 4;
        int m_w = TILE_SIZE;
        int m_h = TILE_SIZE;
        int e_x = x + ENTITY_MARGIN_H;
        int e_y = y + (TILE_SIZE - ENTITY_HEIGHT);
        int e_h = ENTITY_HEIGHT;
        int e_w = ENTITY_WIDTH;

        // Check if entity and trigger collide
        if (e_x < m_x + m_w &&
            e_x + e_w > m_x &&
            e_y < m_y + m_h &&
            e_y + e_h > m_y)
        {
            triggers[trigger_index++] = trigger;

            // If we've reached the max triggers allowed, stop processing more
            if (trigger_index == MAX_TRIGGERS) break;
        }
    }
}

void execute_enter_exit_triggers(const Trigger **pre_triggers,
                                 const Trigger **post_triggers, Game *game)
{
    // Check if user entered trigger tile
    for (int i = 0; i < MAX_TRIGGERS; i++)
    {
        const Trigger *trigger = post_triggers[i];
        bool was_on_trigger = false;
        for (int j = 0; j < MAX_TRIGGERS; j++)
        {
            was_on_trigger |= trigger == pre_triggers[j];
        }
        if (!was_on_trigger)
        {
            execute_trigger(trigger->on_enter_type, trigger->on_enter, game);
        }
    }

    // Check if user exited trigger tile
    for (int i = 0; i < MAX_TRIGGERS; i++)
    {
        const Trigger *trigger = pre_triggers[i];
        bool still_on_trigger = false;
        for (int j = 0; j < MAX_TRIGGERS; j++)
        {
            still_on_trigger |= trigger == post_triggers[j];
        }
        if (!still_on_trigger)
        {
            execute_trigger(trigger->on_exit_type, trigger->on_exit, game);
        }
    }
}

void execute_action_triggers(Entity *entity, Game *game)
{
    const Trigger *triggers[MAX_TRIGGERS] = {NULL, NULL, NULL, NULL};
    int dy = 0;
    int dx = 0;

    switch (entity->direction)
    {
        case DOWN:
            dy = 1;
            break;
        case UP:
            dy = -1;
            break;
        case RIGHT:
            dx = 1;
            break;
        case LEFT:
            dx = -1;
            break;
    }

    get_triggers_at_xy(triggers, entity->x + dx, entity->y + dy,
                       game->current_map);

    // TODO: Only execute first trigger found?
    for (int i = 0; i < MAX_TRIGGERS; i++)
    {
        const Trigger *trigger = triggers[i];
        if (trigger == NULL) break;

        execute_trigger(trigger->on_action_type, trigger->on_action, game);
    }

}

// -----------------------------------------------------------------------------
// Private functions definitions
// -----------------------------------------------------------------------------
void
execute_trigger(const ActionType action_type, const void *action, Game *game)
{
    if (action_type == ACT_NONE || action == NULL) return;

    switch (action_type)
    {
        case ACT_TELEPORT:
            action_teleport(action, game);
            break;
        default:
            break;
    }
}

