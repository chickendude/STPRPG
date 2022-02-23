#ifndef STPRPG_TRIGGER_H
#define STPRPG_TRIGGER_H

#include "types.h"
#include "actions.h"

struct Trigger
{
    int map_x, map_y;
    ActionType on_enter_type;
    void *on_enter;
    ActionType on_exit_type;
    void *on_exit;
    ActionType on_action_type;
    void *on_action;
};

/**
 * Loads the triggers at the the x, y location into the pointer array passed
 * in.
 *
 * @param triggers A pointer-pointer which should be a pointer to an array of
 * trigger pointers. It should be large enough to contain MAX_TRIGGERS.
 * @param x The x location (in pixels) to check.
 * @param y The y location (in pixels) to check.
 * @param map The map who's pointers should be searched.
 */
void get_triggers_at_xy(const Trigger **triggers, int x, int y, const Map *map);

/**
 * Runs on_enter and on_exit triggers.
 *
 * @param pre_triggers List of triggers on tile before player moved.
 * @param post_triggers List of triggers on tile after player moved.
 * @param game Main Game object.
 */
void execute_enter_exit_triggers(const Trigger **pre_triggers,
                               const Trigger **post_triggers, Game *game);

#endif //STPRPG_TRIGGER_H
