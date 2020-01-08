#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nonterminal_expression.h"

typedef struct _EXPRESSION_T
{
    NONTERMINAL_EXPRESSION_T parent;
    F_INTERPRET_T f_interpret;
} EXPRESSION_T;

int f_Create_Expression_ex(EXPRESSION_T *expression, ABSTRACT_EXPRESSION_T *left_exp,
                           ABSTRACT_EXPRESSION_T *right_exp);
EXPRESSION_T *f_Create_Expression(ABSTRACT_EXPRESSION_T *left_exp,
                                  ABSTRACT_EXPRESSION_T *right_exp);

#endif // EXPRESSION_H
