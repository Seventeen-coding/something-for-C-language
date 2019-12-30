#ifndef TV_CHANNEL_DOWN_H
#define TV_CHANNEL_DOWN_H

#include "my_command.h"
#include "my_tv.h"

typedef struct _channel_down_command{
    MY_COMMAND command;
    MY_TV *tv;
}channel_down_command;

channel_down_command *Create_channel_down_command(MY_TV *tv);

#endif // TV_CHANNEL_DOWN_H
