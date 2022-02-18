#ifndef STPRPG_TRIGGER_H
#define STPRPG_TRIGGER_H

#include "types.h"
#include "actions.h"

struct Trigger {
    int map_x, map_y;
    ActionType on_enter_type;
    void *on_enter;
    ActionType on_exit_type;
    void *on_exit;
    ActionType on_action_type;
    void *on_action;
};

void get_triggers_at_xy(const Trigger **triggers, int x, int y, const Map *map);

void execute_trigger(ActionType actionType, const void *action, Game *game);

#endif //STPRPG_TRIGGER_H
