#include <tonc.h>

#include "character_states/states.h"

#include "character.h"
#include "constants.h"
#include "state.h"

static Character *character;
static Entity *entity;

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
void initialize(StateType leaving_state, void *param_character)
{
    character = param_character;
    entity = &character->entity;
    entity->frame = 0;
}

static void input(StateStack *state_stack)
{
    int x = key_tri_horz();
    int y = key_tri_vert();
    if (x == 0 && y == 0)
    {
        change_state(character, &wait_state);
        return;
    }

    int speed = key_is_down(KEY_A) ? RUNNING_SPEED : 1;
    entity->x += x * speed;
    entity->y += y * speed;
    if (x == -1) entity->direction = LEFT;
    else if (x == 1) entity->direction = RIGHT;
    else if (y == -1) entity->direction = UP;
    else if (y == 1) entity->direction = DOWN;
    // TODO: Otherwise it takes a couple frames to update the player's direction
    entity->oam->attr2 = entity->frame + entity->direction * 16;
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
        int attr2 = entity->oam->attr2;
        entity->oam->attr2 = (attr2 & ~ATTR2_ID_MASK) |
                             entity->frame + entity->direction * 16;
    }
}
