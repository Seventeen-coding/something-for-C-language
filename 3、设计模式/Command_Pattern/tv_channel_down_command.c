#include "tv_channel_down_command.h"

static void execute(channel_down_command *this_command);


channel_down_command *Create_channel_down_command(MY_TV *tv)
{
    channel_down_command * command;
    if(tv == NULL)
    {
        return NULL;
    }
    command = (channel_down_command *)malloc(sizeof(channel_down_command));
    do{
        if(inherit_my_command(command) != 0)
        {
            break;
        }
        command->tv = tv;
        command->command.execute = execute;
        return command;
    }while(0);

    free(command);
    return NULL;
}
static void execute(channel_down_command *this_command)
{
    if(this_command == NULL)
    {
        return;
    }
    this_command->tv->channel_down(this_command->tv);
}
