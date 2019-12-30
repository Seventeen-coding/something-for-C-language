#ifndef TV_VOLUME_UP_COMMAND_H
#define TV_VOLUME_UP_COMMAND_H


#include "my_command.h"
#include "my_tv.h"

typedef struct _volume_up_command{
    MY_COMMAND command;
    MY_TV *tv;
}volume_up_command;

volume_up_command *Create_volume_up_command(MY_TV *tv);


#endif // TV_VOLUME_UP_COMMAND_H
