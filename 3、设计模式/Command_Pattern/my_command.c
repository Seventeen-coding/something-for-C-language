#include "my_command.h"

static void _execute(MY_COMMAND * this_command);

int inherit_my_command(MY_COMMAND *command)
{
    if(command == NULL)
    {
        return -1;
    }

    command->execute = _execute;
    return 0;
}

static void _execute(MY_COMMAND * this_command)
{
    /*nothing to do*/
}
