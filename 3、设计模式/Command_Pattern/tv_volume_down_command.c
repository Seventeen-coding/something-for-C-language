#include "tv_volume_down_command.h"

static void execute(volume_down_command *this_command);

volume_down_command *Create_volume_down_command(MY_TV *tv)
{
    volume_down_command * command;
    if(tv == NULL)
    {
        return NULL;
    }
    command = (volume_down_command *)malloc(sizeof(volume_down_command));
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
static void execute(volume_down_command *this_command)
{
    if(this_command == NULL)
    {
        return;
    }
    this_command->tv->volume_down(this_command->tv);
}
