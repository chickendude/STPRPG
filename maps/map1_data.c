#include "map1.h"

#include "character.h"
#include "map.h"
#include "character_states/states.h"
#include "trigger.h"

#define NUM_NPCS 2
#define NUM_TRIGGERS 3

const Trigger map_1_triggers[NUM_TRIGGERS] = {
        {5,  5,
                ACT_TELEPORT, &teleport2,
                ACT_NONE, NULL,
                ACT_NONE, NULL},
        {6,  5,
                ACT_NONE, NULL,
                ACT_NONE, NULL,
                ACT_TELEPORT, &teleport2},
        {28, 5,
                ACT_TELEPORT, &teleport1,
                ACT_NONE, NULL,
                ACT_NONE, NULL},
};

const Character npcs[NUM_NPCS] = {
        {
                &E_TANN,
                &npc_stand_state
        },
        {
                &E_TANN,
                &npc_stand_state
        }
};

const Map map_1 = {
        "Kelwyd",
        0, 0,
        MAP1_WIDTH, MAP1_HEIGHT,
        NUM_TRIGGERS,
        &map_1_triggers,
        NUM_NPCS,
        &npcs,
        map1_tilemap
};
