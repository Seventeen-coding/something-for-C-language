#ifndef TV_POWER_OFF_COMMAND_H
#define TV_POWER_OFF_COMMAND_H

#include "my_command.h"
#include "my_tv.h"

typedef struct _power_off_command{
    MY_COMMAND command;
    MY_TV *tv;
}power_off_command;

power_off_command *Create_power_off_command(MY_TV *tv);

#endif // TV_POWER_OFF_COMMAND_H
