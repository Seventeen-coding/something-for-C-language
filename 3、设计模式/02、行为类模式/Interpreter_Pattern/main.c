
#include "interpreter.h"
#include <stdio.h>
#include "log_util.h"
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
    int ret = 0;
    int result;
    //test number_expression
    CALCULATOR_T *calculator = f_Get_Calculator_Instance();
    char *context = "100-10";
    result = calculator->result(context, &ret);
    if (ret != 0)
    {
        log_info("ret = %d\n",ret);
        return;
    }
    printf("%s = %d \n", context, result);
}
