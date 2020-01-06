#include "my_command.h"

static void f_execute(MY_COMMAND_T * this_command);

int inherit_my_command(MY_COMMAND_T *command)
{
    if(command == NULL)
    {
        return -1;
    }

    command->f_execute = f_execute;
    return 0;
}

static void f_execute(MY_COMMAND_T * this_command)
{
    /*nothing to do*/
}
