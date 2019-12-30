#include "tv_power_off_command.h"

static void execute(power_off_command *this_command);

power_off_command *Create_power_off_command(MY_TV *tv)
{
    power_off_command * command;
    if(tv == NULL)
    {
        return NULL;
    }
    command = (power_off_command *)malloc(sizeof(power_off_command));
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
static void execute(power_off_command *this_command)
{
    if(this_command == NULL)
    {
        return;
    }
    this_command->tv->power_off(this_command->tv);
}
