#include "freetimestate.h"
#include "room.h"

static int _bookRoom(FreeTimeState *this_state, ROOM_T *this_room);
static int _unsubscribeRoom(FreeTimeState *this_state, ROOM_T *this_room);
static int _checkInRoom(FreeTimeState *this_state, ROOM_T *this_room);
static int _checkOutRoom(FreeTimeState *this_state, ROOM_T *this_room);

FreeTimeState *CreateFreeTimeState()
{
    FreeTimeState *freetimestate = (FreeTimeState *)malloc(sizeof(FreeTimeState));
    if (freetimestate == NULL)
    {
        return NULL;
    }

    memset(freetimestate, 0, sizeof(FreeTimeState));
    do
    {
        STATE_T *state = &freetimestate->state;
        if (inheritState(state) != 0)
        {
            break;
        }
        strcpy(freetimestate->state.name, "FREETIME");
        freetimestate->state.bookRoom = (state_to_bookRoom_func)_bookRoom;
        freetimestate->state.unsubscribeRoom = (state_to_unsubscribeRoom_func)_unsubscribeRoom;
        freetimestate->state.checkInRoom = (state_to_checkInRoom_func)_checkInRoom;
        freetimestate->state.checkOutRoom = (state_to_checkOutRoom_func)_checkOutRoom;
        return freetimestate;
    } while (0);

    free(freetimestate);
    return NULL;
}

static int _bookRoom(FreeTimeState *this_state, ROOM_T *this_room)
{
    /*free state to book Room*/
    printf("[current state : %s ]You have successfully made a reservation...\n", this_state->state.name);
    this_room->state = (STATE_T *)this_room->bookedState;
}

static int _unsubscribeRoom(FreeTimeState *this_state, ROOM_T *this_room)
{
    /*nothing to change*/
    printf("[current state : %s ]error->The room had reservation and check-in, cannot unsubscribe...\n", this_state->state.name);
}

static int _checkInRoom(FreeTimeState *this_state, ROOM_T *this_room)
{
    /*free state to checkIn Room*/
    printf("[current state : %s ]You have successfully entered...\n", this_state->state.name);
    this_room->state = (STATE_T *)this_room->checkInState;
}

static int _checkOutRoom(FreeTimeState *this_state, ROOM_T *this_room)
{
    /*nothing to change*/
    printf("[current state : %s ]error->No reservation and check in the room, can't check out...\n", this_state->state.name);
}
