#ifndef STPRPG_STATES_H
#define STPRPG_STATES_H

#include "types.h"

/**
 * Parameters passed into the player/npc state machine.\n
 * \n
 * Contains a pointer to the character whose state it belongs to as well as
 * the current game.
 */
typedef struct CharacterStateParam
{
    Game *game;
    int param1;
    int param2;
    int param3;
} CharacterStateParam;

void change_state(Character *character, const State *state);

extern const State move_state;
/**
 * Moves the NPC in a certain direction a certain number of frames.
 *
 * State params:\n
 *  param1: dx\n
 *  param2: dy\n
 *  param3: frames
 */
extern const State npc_move_state;
extern const State npc_stand_state;
extern const State wait_state;
#endif //STPRPG_STATES_H
