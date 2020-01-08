#include "add_expression.h"
#include "log_util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int interpret(ADD_EXPRESSION_T *this, const char *str, int *interpret_result);
static int expression_grammar(const char *str);

int f_Create_Add_Expression_ex(ADD_EXPRESSION_T *expression, ABSTRACT_EXPRESSION_T *left_exp,
                               ABSTRACT_EXPRESSION_T *right_exp)
{
    if (expression == NULL)
    {
        return -1;
    }

    {
        NONTERMINAL_EXPRESSION_T *nonterminal_exp = &expression->parent;
        if (expression->f_interpret == NULL)
        {
            expression->f_interpret = (F_INTERPRET_T)interpret;
        }
        nonterminal_exp->f_interpret = expression->f_interpret;
        if (f_Create_Nonterminal_Expression_ex(nonterminal_exp, left_exp, right_exp) != 0)
        {
            return -2;
        }
    }
    return 0;
}
ADD_EXPRESSION_T *f_Create_Add_Expression(ABSTRACT_EXPRESSION_T *left_exp,
                                          ABSTRACT_EXPRESSION_T *right_exp)
{
    ADD_EXPRESSION_T *expression;

    expression = (ADD_EXPRESSION_T *)malloc(sizeof(ADD_EXPRESSION_T));
    if (expression == NULL)
    {
        return NULL;
    }
    memset(expression, 0, sizeof(ADD_EXPRESSION_T));
    if (f_Create_Add_Expression_ex(expression, left_exp, right_exp) != 0)
    {
        free(expression);
        return NULL;
    }

    return expression;
}

static int interpret(ADD_EXPRESSION_T *this, const char *str, int *interpret_result)
{
    if (this == NULL || str == NULL)
    {
        if (interpret_result != NULL)
        {
            *interpret_result = -1;
        }
        return 0;
    }
    NONTERMINAL_EXPRESSION_T *expression = &this->parent;
    return expression->left_exp->f_interpret(expression->left_exp, str, interpret_result) + expression->right_exp->f_interpret(expression->right_exp, str, interpret_result);
}