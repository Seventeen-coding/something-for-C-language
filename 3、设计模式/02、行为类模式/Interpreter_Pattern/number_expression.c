#include "number_expression.h"


static int interpret(const char *str,int *interpret_result);
//static int add_node_to_list(struct number_expression_node *this_list_head_node,struct number_expression_node * node);

number_expression *Create_number_expression()
{
    number_expression *expression;
    expression = (number_expression *) malloc(sizeof(number_expression));

    if(expression == NULL)
    {
        return NULL;
    }
    memset(expression, 0 , sizeof(number_expression));

    do
    {
      //  expression->number_list_head_node = NULL;
        expression->exp.interpret = (interpret_func)interpret;
        expression->exp.interpret_result = 0;   //OK
        return expression;
    }while(0);

    free(expression);
    return NULL;
}


static int interpret(const char *str,int *interpret_result)
{
    *interpret_result = 0;
    return atoi(str);
}
