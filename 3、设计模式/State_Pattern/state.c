#include "state.h"


int inheritState(State *state)
{
    if(state == NULL)
    {
        return -1;
    }

    strcpy(state->name,"UNKNOW");
    state->bookRoom = NULL;
    state->unsubscribeRoom = NULL;
    state->checkInRoom = NULL;
    state->checkOutRoom = NULL;

    return 0;
}
