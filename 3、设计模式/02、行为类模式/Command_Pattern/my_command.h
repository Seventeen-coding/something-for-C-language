#ifndef MY_COMMAND_H
#define MY_COMMAND_H

#include <stdio.h>

typedef struct _MY_COMMAND_T
{
    void (*f_execute)(void *this_command);
} MY_COMMAND_T;

int inherit_my_command(MY_COMMAND_T *command);

#endif // MY_COMMAND_H
