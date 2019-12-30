#ifndef MY_COMMAND_H
#define MY_COMMAND_H

#include <stdio.h>

typedef  void (*execute_func)(void * this_command);

typedef struct _my_command{
    execute_func execute;
}MY_COMMAND;

int inherit_my_command(MY_COMMAND * command);

#endif // MY_COMMAND_H
