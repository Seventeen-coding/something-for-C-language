#ifndef TERMINAL_EXPRESSION_H
#define TERMINAL_EXPRESSION_H

#include "abstract_expression.h"

typedef struct _TERMINAL_EXPRESSION_T
{
    ABSTRACT_EXPRESSION_T parent;
    F_INTERPRET_T f_interpret;
} TERMINAL_EXPRESSION_T;

int f_Create_Terminal_Expression_ex(TERMINAL_EXPRESSION_T *expression);

#endif // TERMINAL_EXPRESSION_H
