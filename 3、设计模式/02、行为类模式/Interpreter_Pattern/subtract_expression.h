#ifndef SUBTRACT_EXPRESSION_H
#define SUBTRACT_EXPRESSION_H

#include "nonterminal_expression.h"

typedef struct _SUBTRACT_EXPRESSION_T
{
    NONTERMINAL_EXPRESSION_T parent;
    F_INTERPRET_T f_interpret;
} SUBTRACT_EXPRESSION_T;

SUBTRACT_EXPRESSION_T *f_Create_Subtract_Expression(ABSTRACT_EXPRESSION_T *left_exp,
                                                    ABSTRACT_EXPRESSION_T *right_exp);
int f_Create_Subtract_Expression_ex(SUBTRACT_EXPRESSION_T *expression, ABSTRACT_EXPRESSION_T *left_exp,
                                    ABSTRACT_EXPRESSION_T *right_exps);
SUBTRACT_EXPRESSION_T *f_Get_Sub_Expression_Instance(void);
#endif // SUBTRACT_EXPRESSION_H
