#ifndef BOOKEDSTATE_H
#define BOOKEDSTATE_H

#include "state.h"

typedef struct _BookState{
    State state;
}BookState;

BookState *CreateBookState(void);

#endif // BOOKEDSTATE_H
