#ifndef BOOKEDSTATE_H
#define BOOKEDSTATE_H

#include "state.h"

typedef struct _BookState{
    STATE_T state;
}BookState;

BookState *CreateBookState(void);

#endif // BOOKEDSTATE_H
