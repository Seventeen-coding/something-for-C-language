/*
	这里可以写相关文件描述 协议等等信息
	如：
	按照C语言的语法 规范编程
	一个良好的书写规范决定一个程序的好坏
	源代码不仅仅给自己看有可能给别人看
*/

/*1、头文件*/
#include "calculator.h"
#include "expression.h"
/*2、宏定义
#define TEMPLATE	XXXXXX
*/

/*3、结构体声明
typedef struct{
	int  xxx_xxx;
	char *xxx_xxx;
}TEMPLATE_T;
*/

/*4、函数和变量声明
int Template(TEMPLATE_T xxx_xxx );
*/
static CALCULATOR_T *f_Create_Calculator(void);
static int f_Create_Calculator_ex(CALCULATOR_T *calculator);
static int result(const char *context, int *interpret_result);
static int check_grammar(const char *context);
/*5、函数实现区
int Template(TEMPLATE_T xxx_xxx )
{
	return 0;
}
*/
static CALCULATOR_T *f_Create_Calculator(void)
{
    CALCULATOR_T *calculator = (CALCULATOR_T *)malloc(sizeof(calculator));
    if (calculator == NULL)
    {
        return NULL;
    }
    if (f_Create_Calculator_ex(calculator) != 0)
    {
        free(calculator);
        return NULL;
    }
    return calculator;
}
static int f_Create_Calculator_ex(CALCULATOR_T *calculator)
{
    if (calculator == NULL)
    {
        return -1;
    }
    calculator->result = result;
    return 0;
}
// int Parser()
int result(const char *context, int *interpret_result)
{
    int result = 0;
    if (context == NULL)
    {
        if (interpret_result != NULL)
        {
            *interpret_result = -1;
        }
        return 0;
    }
    //检查语法
    if (check_grammar(context) != 0)
    {
        if (interpret_result != NULL)
        {
            *interpret_result = -2;
        }
        return 0;
    }

    //优化数据

    //分析
    EXPRESSION_T *expression = f_Create_Expression(NULL, NULL);
    return expression->f_interpret(expression, context, interpret_result);
}
CALCULATOR_T *f_Get_Calculator_Instance(void)
{
    static CALCULATOR_T *calculator = NULL;
    if (calculator != NULL)
    {
        return calculator;
    }

    calculator = f_Create_Calculator();
    return calculator;
}

static int check_grammar(const char *context)
{
    if (context == NULL)
    {
        return -1;
    }
    for (int i = 0, j = i + 1; i < strlen(context); i++)
    {
        if (j = '\0')
        {
            break;
        }

        switch (context[i])
        {
        case '0' ... '9':
        {
        }
        break;
        case '+':
        case '-':
        case '*':
        case '/':
        {
        }
        break;
        default:
            return -2;
        }
    }
    return 0;
}