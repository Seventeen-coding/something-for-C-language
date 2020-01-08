#ifndef FREETIMESTATE_H
#define FREETIMESTATE_H

#include "state.h"

typedef struct _FreeTimeState{
    STATE_T state;
}FreeTimeState;

FreeTimeState *CreateFreeTimeState(void);

#endif // FREETIMESTATE_H
