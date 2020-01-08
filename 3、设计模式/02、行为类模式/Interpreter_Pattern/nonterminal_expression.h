#ifndef NONTERMINAL_EXPRESSION_H
#define NONTERMINAL_EXPRESSION_H

#include "abstract_expression.h"

typedef struct _NONTERMINAL_EXPRESSION_T
{
    ABSTRACT_EXPRESSION_T *left_exp;
    ABSTRACT_EXPRESSION_T *right_exp;
    ABSTRACT_EXPRESSION_T parent;
    F_INTERPRET_T f_interpret;
} NONTERMINAL_EXPRESSION_T;

int f_Create_Nonterminal_Expression_ex(NONTERMINAL_EXPRESSION_T *expression, ABSTRACT_EXPRESSION_T *left_exp,
                                       ABSTRACT_EXPRESSION_T *right_exp);

#endif // NONTERMINAL_EXPRESSION_H
