#include "tv_channel_up_command.h"

static void execute(channel_up_command *this_command);


channel_up_command *Create_channel_up_command(MY_TV *tv)
{
    channel_up_command * command;
    if(tv == NULL)
    {
        return NULL;
    }
    command = (channel_up_command *)malloc(sizeof(channel_up_command));
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
static void execute(channel_up_command *this_command)
{
    if(this_command == NULL)
    {
        return;
    }
    this_command->tv->channel_up(this_command->tv);
}
