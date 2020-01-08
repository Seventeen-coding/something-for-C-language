#ifndef CONTEXT_H
#define CONTEXT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _CONTEXT_T
{
    char *input;
    int result;
} CONTEXT_T;

int f_Create_Expression_ex(CONTEXT_T *expression);
CONTEXT_T *f_Create_Expression(void);

#endif // CONTEXT_H
