#include "room.h"

static int _bookRoom(Room *this_room);
static int _unsubscribeRoom(Room *this_room);
static int _checkInRoom(Room *this_room);
static int _checkOutRoom(Room *this_room);

Room *CreatRoom(void)
{
    Room *this_room = (Room *)malloc(sizeof(Room));
    if(this_room == NULL)
    {
        return NULL;
    }

    memset(this_room,0,sizeof(Room));

    do{
        this_room->freeTimeState = CreateFreeTimeState();
        this_room->checkInState =  CreateCheckInState();
        this_room->bookedState =   CreateBookState();
        this_room->bookRoom        = _bookRoom;
        this_room->unsubscribeRoom = _unsubscribeRoom;
        this_room->checkInRoom     = _checkInRoom;
        this_room->checkOutRoom    = _checkOutRoom;
        this_room->state = this_room->freeTimeState;
        return this_room;
    }while(0);

    free(this_room);
    return NULL;
}

static int _bookRoom(Room *this_room)
{
    /*common code*/

    /*common code end*/

    this_room->state->bookRoom(this_room->state,this_room);
    /*common code*/

    /*common code end*/

}
static int _unsubscribeRoom(Room *this_room)
{
    /*common code*/

    /*common code end*/
    this_room->state->unsubscribeRoom(this_room->state,this_room);
    /*common code*/

    /*common code end*/
}
static int _checkInRoom(Room *this_room)
{
    /*common code*/

    /*common code end*/
    this_room->state->checkInRoom(this_room->state,this_room);
    /*common code*/

    /*common code end*/
}
static int _checkOutRoom(Room *this_room)
{
    /*common code*/

    /*common code end*/
    this_room->state->checkOutRoom(this_room->state,this_room);
    /*common code*/

    /*common code end*/

}
