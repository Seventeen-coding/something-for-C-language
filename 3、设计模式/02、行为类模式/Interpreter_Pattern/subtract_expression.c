#include "subtract_expression.h"

static int interpret(const char *str, int *interpret_result);

static number_expression *num_exp = NULL;

subtract_expression *Create_subtract_expression()
{
    subtract_expression *expression;

    expression = (subtract_expression *) malloc(sizeof(subtract_expression));

    if(expression == NULL)
    {
        return NULL;
    }
    memset(expression, 0 , sizeof(subtract_expression));

    do
    {
        expression->exp.interpret = (interpret_func)interpret;
        expression->exp.interpret_result = 0;   //OK

        if(num_exp == NULL)
        {
            num_exp = Create_number_expression();
            if( num_exp == NULL)
            {
                break;
            }

        }

        return expression;
    }while(0);

    free(expression);
    return NULL;
}

static int interpret(const char *str,int *interpret_result)
{
    char str_tmp[256];
    if(str == NULL)
    {
        *interpret_result = -1;
        return 0;
    }
    strcpy(str_tmp,str);
    //检查语法 start

    //检查语法 end
    int result1 = 0 ;
    int result2 = 0;

    result1 = num_exp->exp.interpret(strtok(str_tmp,"-"),&num_exp->exp.interpret_result);
    if(num_exp->exp.interpret_result != 0)
    {
        *interpret_result = -2;
        return 0;
    }

    result2 = num_exp->exp.interpret(strtok(NULL,"-"),&num_exp->exp.interpret_result);
    if(num_exp->exp.interpret_result != 0)
    {
        *interpret_result = -3;
        return 0;
    }
    *interpret_result = 0;
    return result1 - result2;
}
