#ifndef SYMBOL_EXPRESSION_H
#define SYMBOL_EXPRESSION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nonterminal_expression.h"
typedef struct _SYMBOL_EXPRESSION_T
{
    NONTERMINAL_EXPRESSION_T parent;
    F_INTERPRET_T f_interpret;
} SYMBOL_EXPRESSION_T;

int f_Create_Symbol_Expression_ex(SYMBOL_EXPRESSION_T *expression, ABSTRACT_EXPRESSION_T *left_exp,
                                  ABSTRACT_EXPRESSION_T *right_exp);
SYMBOL_EXPRESSION_T *f_Create_Symbol_Expression(ABSTRACT_EXPRESSION_T *left_exp,
                                                ABSTRACT_EXPRESSION_T *right_exp);

#endif // SYMBOL_EXPRESSION_H
