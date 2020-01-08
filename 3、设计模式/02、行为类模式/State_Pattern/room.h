#ifndef ROOM_H
#define ROOM_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "freetimestate.h"
#include "checkinstate.h"
#include "bookedstate.h"

typedef struct _ROOM_T
{

    /*
     * 房间的三个状态
     */
    const FreeTimeState *freeTimeState; //空闲状态
    const CheckInState *checkInState;   //入住状态
    const BookState *bookedState;       //预订状态
    //end
    STATE_T *state;

    int (*bookRoom)(struct _ROOM_T *this_room);
    int (*unsubscribeRoom)(struct _ROOM_T *this_room);
    int (*checkInRoom)(struct _ROOM_T *this_room);
    int (*checkOutRoom)(struct _ROOM_T *this_room);

} ROOM_T;

ROOM_T *CreatRoom(void);

#endif // ROOM_H
