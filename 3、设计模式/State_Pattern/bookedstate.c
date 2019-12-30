#include "bookedstate.h"
#include "room.h"

static int _bookRoom(BookState *this_state,Room *this_room);
static int _unsubscribeRoom(BookState *this_state,Room *this_room);
static int _checkInRoom(BookState *this_state,Room *this_room);
static int _checkOutRoom(BookState *this_state,Room *this_room);

BookState *CreateBookState()
{
    BookState *bookstate = (BookState *)malloc(sizeof(BookState));
    if(bookstate == NULL)
    {
        return NULL;
    }

    memset(bookstate , 0 ,sizeof(BookState));
    do {
        if(  inheritState((State *)bookstate)  != 0)
        {
            break;
        }
        strcpy(bookstate->state.name,"BOOKED");
        bookstate->state.bookRoom =(state_to_bookRoom_func) _bookRoom;
        bookstate->state.unsubscribeRoom = (state_to_unsubscribeRoom_func)_unsubscribeRoom;
        bookstate->state.checkInRoom = (state_to_checkInRoom_func)_checkInRoom;
        bookstate->state.checkOutRoom = (state_to_checkOutRoom_func)_checkOutRoom;
        return bookstate;
    } while (0);

    free(bookstate);
    return NULL;
}

static int _bookRoom(BookState *this_state,Room *this_room)
{
    BookState *state = this_state;
    /*nothing to change*/
    printf("[current state : %s ]error->The room has been reserved...\n",this_state->state.name);
}

static int _unsubscribeRoom(BookState *this_state,Room *this_room)
{
    BookState *state = this_state;
    /*BOOKED state to do _unsubscribeRoom*/
    printf("[current state : %s ]Unsubscribe success, welcome to you next time...\n",this_state->state.name);
    this_room->state = this_room->freeTimeState;
}

static int _checkInRoom(BookState *this_state,Room *this_room)
{
    BookState *state = this_state;
    /*BOOKED state to do _checkInRoom*/
    printf("[current state : %s ]In success...\n",this_state->state.name);
    this_room->state =(State *) this_room->checkOutRoom;
}

static int _checkOutRoom(BookState *this_state,Room *this_room)
{
    BookState *state = this_state;
    /*nothing to change*/
    printf("[current state : %s ]error->The room reservation for has not checked in...\n",this_state->state.name);
}

