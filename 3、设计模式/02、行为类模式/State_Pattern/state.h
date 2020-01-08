
#ifndef STATE_H
#define STATE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum
{
    STATE_OK,
    STATE_ERROR,
};

typedef struct _STATE_T
{
    char name[10];
    int (*bookRoom)(struct _STATE_T *this_state, void *this_room);
    int (*unsubscribeRoom)(struct _STATE_T *this_state, void *this_room);
    int (*checkInRoom)(struct _STATE_T *this_state, void *this_room);
    int (*checkOutRoom)(struct _STATE_T *this_state, void *this_room);
} STATE_T;

typedef int (*state_to_bookRoom_func)(STATE_T *this_state, void *this_room);
typedef int (*state_to_unsubscribeRoom_func)(STATE_T *this_state, void *this_room);
typedef int (*state_to_checkInRoom_func)(STATE_T *this_state, void *this_room);
typedef int (*state_to_checkOutRoom_func)(STATE_T *this_state, void *this_room);

int inheritState(STATE_T *state);

#endif // STATE_H
