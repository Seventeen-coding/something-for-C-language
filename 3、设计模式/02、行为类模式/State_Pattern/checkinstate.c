#include "checkinstate.h"
#include "room.h"

static int _bookRoom(CheckInState *this_state, ROOM_T *this_room);
static int _unsubscribeRoom(CheckInState *this_state, ROOM_T *this_room);
static int _checkInRoom(CheckInState *this_state, ROOM_T *this_room);
static int _checkOutRoom(CheckInState *this_state, ROOM_T *this_room);

CheckInState *CreateCheckInState()
{
    CheckInState *checkinstate = (CheckInState *)malloc(sizeof(CheckInState));
    if (checkinstate == NULL)
    {
        return NULL;
    }

    memset(checkinstate, 0, sizeof(CheckInState));
    do
    {
        STATE_T *state = &checkinstate->state;
        if (inheritState(state) != 0)
        {
            break;
        }
        strcpy(checkinstate->state.name, "CHECKIN");
        checkinstate->state.bookRoom = (state_to_bookRoom_func)_bookRoom;
        checkinstate->state.unsubscribeRoom = (state_to_unsubscribeRoom_func)_unsubscribeRoom;
        checkinstate->state.checkInRoom = (state_to_checkInRoom_func)_checkInRoom;
        checkinstate->state.checkOutRoom = (state_to_checkOutRoom_func)_checkOutRoom;
        return checkinstate;
    } while (0);

    free(checkinstate);
    return NULL;
}

static int _bookRoom(CheckInState *this_state, ROOM_T *this_room)
{
    /*nothing to change*/
    printf("[current state : %s ]error->The room has already check in, can't reserve a room\n", this_state->state.name);
}

static int _unsubscribeRoom(CheckInState *this_state, ROOM_T *this_room)
{
    /*nothing to change*/
    printf("[current state : %s ]error->The room have descended, cannot unsubscribe room\n", this_state->state.name);
}

static int _checkInRoom(CheckInState *this_state, ROOM_T *this_room)
{
    /*nothing to change*/
    printf("[current state : %s ]error->The room has been checked in\n", this_state->state.name);
}

static int _checkOutRoom(CheckInState *this_state, ROOM_T *this_room)
{
    /*chechin state to check out room*/
    printf("[current state : %s ]Successful check-out\n", this_state->state.name);
    this_room->state = (STATE_T *)this_room->freeTimeState;
}
