#ifndef CHECKINSTATE_H
#define CHECKINSTATE_H

#include "state.h"

typedef struct _CheckInState{
    State state;
}CheckInState;

CheckInState *CreateCheckInState(void);

#endif // CHECKINSTATE_H
