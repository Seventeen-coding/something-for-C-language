
/*1、头文件*/
#include <stdio.h>
#include <string.h>
#include "terminal_expression.h"

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
static int f_Interpret(TERMINAL_EXPRESSION_T *this, const char *str, int *interpret_result);
/*5、函数实现区
int Template(TEMPLATE_T xxx_xxx )
{
	return 0;
}
*/
int f_Create_Terminal_Expression_ex(TERMINAL_EXPRESSION_T *expression)
{
    if (expression == NULL)
    {
        return -1;
    }
    ABSTRACT_EXPRESSION_T *abstract_expression = &expression->parent;
    if (f_Create_Abstract_Expression_ex(abstract_expression) != 0)
    {
        return -2;
    }
    abstract_expression->f_interpret = (F_INTERPRET_T)f_Interpret;
    return 0;
}

static int f_Interpret(TERMINAL_EXPRESSION_T *this, const char *str, int *interpret_result)
{
    printf("请在子类重写该函数");
    return 0;
}