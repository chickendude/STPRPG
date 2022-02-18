#include <tonc.h>

#include "character_states/states.h"

#include "actions.h"
#include "character.h"
#include "constants.h"
#include "game.h"
#include "map.h"
#include "state.h"
#include "trigger.h"

static CharacterStateParam *state_params;
static Game *game;
static Character *character;

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
    game = state_params->game;
    character = state_params->character;
    character->entity.frame = 0;
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

    const Trigger *pre_triggers[MAX_TRIGGERS] = {NULL, NULL, NULL, NULL};
    const Trigger *post_triggers[MAX_TRIGGERS] = {NULL, NULL, NULL, NULL};

    Entity *entity = &character->entity;
    get_triggers_at_xy(pre_triggers, entity->x, entity->y, game->current_map);
    move_entity(entity, dx, dy, game->current_map);
    get_triggers_at_xy(post_triggers, entity->x, entity->y, game->current_map);

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

    // TODO: Otherwise it takes a couple frames to update the player's direction
    set_entity_sprite_id(entity, entity->frame + entity->direction * 16);
}

static void update()
{
    Entity *entity = &character->entity;
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
