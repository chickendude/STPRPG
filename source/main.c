#include <tonc.h>

#include "map_town.h"
#include "state.h"

// TODO: Add replace_state() function
// TODO: Create CharacterState struct so that characters can have a state
//  system unique to their needs.

//---------------------------------------------------------------------------------
// Program entry point
//---------------------------------------------------------------------------------
int main(void) {
//---------------------------------------------------------------------------------
    StateStack state_stack;
    state_stack.index = 0;
    state_stack.states[0] = &map_town_state;

    const State *cur_state = state_stack.states[state_stack.index];
    cur_state->initialize(NONE, NULL);

    int i = 0;
    while (i >= 0)
    {
        cur_state = state_stack.states[state_stack.index];

        vid_vsync();
        cur_state->update();

        key_poll();
        cur_state->input(&state_stack);
    }
    return 0;
}
