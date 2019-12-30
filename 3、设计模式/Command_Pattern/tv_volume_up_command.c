#include "tv_volume_up_command.h"


static void execute(volume_up_command *this_command);

volume_up_command *Create_volume_up_command(MY_TV *tv)
{
    volume_up_command * command;
    if(tv == NULL)
    {
        return NULL;
    }
    command = (volume_up_command *)malloc(sizeof(volume_up_command));
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
static void execute(volume_up_command *this_command)
{
    if(this_command == NULL)
    {
        return;
    }
    this_command->tv->volume_up(this_command->tv);
}
