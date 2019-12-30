#ifndef TV_CHANNEL_UP_COMMAND_H
#define TV_CHANNEL_UP_COMMAND_H

#include "my_command.h"
#include "my_tv.h"

typedef struct _channel_up_command{
    MY_COMMAND command;
    MY_TV *tv;
}channel_up_command;

channel_up_command *Create_channel_up_command(MY_TV *tv);

#endif // TV_CHANNEL_UP_COMMAND_H
