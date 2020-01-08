#include "room.h"

static int _bookRoom(ROOM_T *this_room);
static int _unsubscribeRoom(ROOM_T *this_room);
static int _checkInRoom(ROOM_T *this_room);
static int _checkOutRoom(ROOM_T *this_room);

ROOM_T *CreatRoom(void)
{
    ROOM_T *this_room = (ROOM_T *)malloc(sizeof(ROOM_T));
    if (this_room == NULL)
    {
        return NULL;
    }

    memset(this_room, 0, sizeof(ROOM_T));

    do
    {
        this_room->freeTimeState = CreateFreeTimeState();
        this_room->checkInState = CreateCheckInState();
        this_room->bookedState = CreateBookState();
        this_room->bookRoom = _bookRoom;
        this_room->unsubscribeRoom = _unsubscribeRoom;
        this_room->checkInRoom = _checkInRoom;
        this_room->checkOutRoom = _checkOutRoom;
        this_room->state = (STATE_T *)this_room->freeTimeState;
        return this_room;
    } while (0);

    free(this_room);
    return NULL;
}

static int _bookRoom(ROOM_T *this_room)
{
    /*common code*/

    /*common code end*/

    this_room->state->bookRoom(this_room->state, this_room);
    /*common code*/

    /*common code end*/
}
static int _unsubscribeRoom(ROOM_T *this_room)
{
    /*common code*/

    /*common code end*/
    this_room->state->unsubscribeRoom(this_room->state, this_room);
    /*common code*/

    /*common code end*/
}
static int _checkInRoom(ROOM_T *this_room)
{
    /*common code*/

    /*common code end*/
    this_room->state->checkInRoom(this_room->state, this_room);
    /*common code*/

    /*common code end*/
}
static int _checkOutRoom(ROOM_T *this_room)
{
    /*common code*/

    /*common code end*/
    this_room->state->checkOutRoom(this_room->state, this_room);
    /*common code*/

    /*common code end*/
}
