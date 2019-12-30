#ifndef STATE_H
#define STATE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum{
    STATE_OK,
    STATE_ERROR,
};

typedef int (*state_to_bookRoom_func)(void *this_state,void *this_room);
typedef int (*state_to_unsubscribeRoom_func)(void *this_state,void *this_room);
typedef int (*state_to_checkInRoom_func)(void *this_state,void *this_room);
typedef int (*state_to_checkOutRoom_func)(void *this_state,void *this_room);

typedef struct _State{
    char name[10];
    /**
     * @desc 预订房间
     * @return void
     */
    state_to_bookRoom_func bookRoom;

    /**
     * @desc 退订房间
     * @return void
     */
    state_to_unsubscribeRoom_func unsubscribeRoom;

    /**
     * @desc 入住
     * @return void
     */
    state_to_checkInRoom_func checkInRoom;

    /**
     * @desc 退房
     * @return void
     */
    state_to_checkOutRoom_func checkOutRoom;

}State;

int inheritState(State * state);

#endif // STATE_H
