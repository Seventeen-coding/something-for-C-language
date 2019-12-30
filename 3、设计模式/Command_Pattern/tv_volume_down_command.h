#ifndef TV_VOLUME_DOWN_COMMAND_H
#define TV_VOLUME_DOWN_COMMAND_H

#include "my_command.h"
#include "my_tv.h"

typedef struct _volume_down_command{
    MY_COMMAND command;
    MY_TV *tv;
}volume_down_command;

volume_down_command *Create_volume_down_command(MY_TV *tv);



#endif // TV_VOLUME_DOWN_COMMAND_H
