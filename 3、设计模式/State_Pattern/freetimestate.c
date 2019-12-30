#include "freetimestate.h"
#include "room.h"

static int _bookRoom(FreeTimeState *this_state,Room *this_room);
static int _unsubscribeRoom(FreeTimeState *this_state,Room *this_room);
static int _checkInRoom(FreeTimeState *this_state,Room *this_room);
static int _checkOutRoom(FreeTimeState *this_state,Room *this_room);

FreeTimeState *CreateFreeTimeState()
{
    FreeTimeState *freetimestate = (FreeTimeState *)malloc(sizeof(FreeTimeState));
    if(freetimestate == NULL)
    {
        return NULL;
    }

    memset(freetimestate , 0 ,sizeof(FreeTimeState));
    do {
        if(  inheritState(freetimestate)  != 0)
        {
            break;
        }
        strcpy(freetimestate->state.name,"FREETIME");
        freetimestate->state.bookRoom = _bookRoom;
        freetimestate->state.unsubscribeRoom = _unsubscribeRoom;
        freetimestate->state.checkInRoom = _checkInRoom;
        freetimestate->state.checkOutRoom = _checkOutRoom;
        return freetimestate;
    } while (0);

    free(freetimestate);
    return NULL;
}

static int _bookRoom(FreeTimeState *this_state,Room *this_room)
{
    /*free state to book Room*/
    printf("[current state : %s ]You have successfully made a reservation...\n",this_state->state.name);
    this_room->state = this_room->bookedState;
}

static int _unsubscribeRoom(FreeTimeState *this_state,Room *this_room)
{
    /*nothing to change*/
    printf("[current state : %s ]error->The room had reservation and check-in, cannot unsubscribe...\n",this_state->state.name);
}

static int _checkInRoom(FreeTimeState *this_state,Room *this_room)
{
    /*free state to checkIn Room*/
    printf("[current state : %s ]You have successfully entered...\n",this_state->state.name);
    this_room->state = this_room->checkInState;
}

static int _checkOutRoom(FreeTimeState *this_state,Room *this_room)
{
    /*nothing to change*/
    printf("[current state : %s ]error->No reservation and check in the room, can't check out...\n",this_state->state.name);
}

