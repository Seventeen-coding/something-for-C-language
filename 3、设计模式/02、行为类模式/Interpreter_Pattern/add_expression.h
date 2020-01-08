#ifndef ADD_EXPRESSION_H
#define ADD_EXPRESSION_H

#include "nonterminal_expression.h"
#include "number_expression.h"

typedef struct _ADD_EXPRESSION_T
{
    char *left_context;
    NONTERMINAL_EXPRESSION_T parent;
    F_INTERPRET_T f_interpret;
} ADD_EXPRESSION_T;

ADD_EXPRESSION_T *f_Create_Add_Expression(ABSTRACT_EXPRESSION_T *left_exp,
                                          ABSTRACT_EXPRESSION_T *right_exp);
int f_Create_Add_Expression_ex(ADD_EXPRESSION_T *expression, ABSTRACT_EXPRESSION_T *left_exp,
                               ABSTRACT_EXPRESSION_T *right_exp);
#endif // ADD_EXPRESSION_H
