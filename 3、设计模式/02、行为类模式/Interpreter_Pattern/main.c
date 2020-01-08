
#include "interpreter.h"
#include <stdio.h>

void run();

//解释器  给一段内容 分析 然后输出预期结果
int main(void)
{
    run();
    return 0;
}

//test
//做个加减法解释器
void run()
{
    //test number_expression

    number_expression *num_exp = Create_number_expression();
    if(num_exp == NULL)
    {
        return;
    }
    int result = 0;
    int num = num_exp->exp.interpret("10",&result);

    if(result != 0)
    {
        printf("expression error\n");
    }
    printf("num : %d \n",num);

    add_expression *add_exp = Create_add_expression();
    if(add_exp == NULL)
    {
        return;
    }
    num = add_exp->exp.interpret("10 + 402",&result);
    if(result != 0)
    {
        printf("expression error\n");
    }
    printf("num : %d \n",num);


    subtract_expression *sub_exp = Create_subtract_expression();
    if(sub_exp == NULL)
    {
        return;
    }
    num = sub_exp->exp.interpret("10 - 402",&result);
    if(result != 0)
    {
        printf("expression error\n");
    }
    printf("num : %d \n",num);
}
