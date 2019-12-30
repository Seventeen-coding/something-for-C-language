#ifndef TV_POWER_ON_COMMAND_H
#define TV_POWER_ON_COMMAND_H

#include "my_command.h"
#include "my_tv.h"

typedef struct _power_on_command{
    MY_COMMAND command;
    MY_TV *tv;
}power_on_command;

power_on_command *Create_power_on_command(MY_TV *tv);


#endif // TV_POWER_ON_COMMAND_H
