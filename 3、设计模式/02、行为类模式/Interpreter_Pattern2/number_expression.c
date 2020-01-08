#include "number_expression.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int interpret(NUMBER_EXPRESSION_T *exp, const char *str, int *interpret_result);

int f_Create_Number_Expression_ex(NUMBER_EXPRESSION_T *expression)
{
    if (expression == NULL)
    {
        return -1;
    }

    TERMINAL_EXPRESSION_T *terminal_exp = &expression->parent;
    if (expression->f_interpret == NULL)
    {
        expression->f_interpret = (F_INTERPRET_T)interpret;
    }
    terminal_exp->f_interpret = expression->f_interpret;
    if (f_Create_Terminal_Expression_ex(terminal_exp))
    {
        return -2;
    }

    return 0;
}
NUMBER_EXPRESSION_T *f_Create_Number_Expression(void)
{
    NUMBER_EXPRESSION_T *expression;
    expression = (NUMBER_EXPRESSION_T *)malloc(sizeof(NUMBER_EXPRESSION_T));

    if (expression == NULL)
    {
        return NULL;
    }
    memset(expression, 0, sizeof(NUMBER_EXPRESSION_T));
    if (f_Create_Number_Expression_ex(expression) != 0)
    {
        free(expression);
        return NULL;
    }
    return expression;
}
NUMBER_EXPRESSION_T *f_Get_Number_Expression_Instance(void)
{
    static NUMBER_EXPRESSION_T *instance = NULL;
    if (instance != NULL)
    {
        return instance;
    }
    instance = f_Create_Number_Expression();
    return instance;
}

static int interpret(NUMBER_EXPRESSION_T *exp, const char *str, int *interpret_result)
{
    if (str == NULL)
    {
        if (interpret_result != NULL)
        {
            *interpret_result = -1;
        }
        return 0;
    }

    if (interpret_result != NULL)
    {
        *interpret_result = atoi(str) < 0 ? -2 : 0;
    }

    return atoi(str);
}
