#ifndef NUMBER_EXPRESSION_H
#define NUMBER_EXPRESSION_H

#include "terminal_expression.h"

typedef struct _NUMBER_EXPRESSION_T
{
    TERMINAL_EXPRESSION_T parent;
    F_INTERPRET_T f_interpret;
} NUMBER_EXPRESSION_T;

int f_Create_Number_Expression_ex(NUMBER_EXPRESSION_T *expression);
NUMBER_EXPRESSION_T *f_Create_Number_Expression(void);

#endif // NUMBER_EXPRESSION_H
