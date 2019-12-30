#ifndef ROOM_H
#define ROOM_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "freetimestate.h"
#include "checkinstate.h"
#include "bookedstate.h"

typedef int (*bookRoom_func)(void *this_room);
typedef int (*unsubscribeRoom_func)(void *this_room);
typedef int (*checkInRoom_func)(void *this_room);
typedef int (*checkOutRoom_func)(void *this_room);

typedef struct _Room{

    /*
     * 房间的三个状态
     */
    const FreeTimeState *freeTimeState;    //空闲状态
    const CheckInState  *checkInState;     //入住状态
    const BookState     *bookedState;      //预订状态
    //end
    State *state;
    /**
     * @desc 预订房间
     * @return void
     */
    bookRoom_func bookRoom;

    /**
     * @desc 退订房间
     * @return void
     */
    unsubscribeRoom_func unsubscribeRoom;

    /**
     * @desc 入住
     * @return void
     */
    checkInRoom_func checkInRoom;

    /**
     * @desc 退房
     * @return void
     */
    checkOutRoom_func checkOutRoom;

}Room;

Room *CreatRoom(void);

#endif // ROOM_H
