#include "trigger.h"

#include "map.h"

// -----------------------------------------------------------------------------
// Private function declarations
// -----------------------------------------------------------------------------


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

// -----------------------------------------------------------------------------
// Private functions definitions
// -----------------------------------------------------------------------------