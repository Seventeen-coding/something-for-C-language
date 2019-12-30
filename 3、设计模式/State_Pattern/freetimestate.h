#ifndef FREETIMESTATE_H
#define FREETIMESTATE_H

#include "state.h"

typedef struct _FreeTimeState{
    State state;
}FreeTimeState;

FreeTimeState *CreateFreeTimeState(void);

#endif // FREETIMESTATE_H
