/*
	这里可以写相关文件描述 协议等等信息
	如：
	按照C语言的语法 规范编程
	一个良好的书写规范决定一个程序的好坏
	源代码不仅仅给自己看有可能给别人看
*/

/*1、头文件*/
#include <stdio.h>
#include <string.h>
#include "symbol_expression.h"
#include "add_expression.h"
#include "subtract_expression.h"

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
static int interpret(SYMBOL_EXPRESSION_T *this, const char *str, int *interpret_result);
/*5、函数实现区
int Template(TEMPLATE_T xxx_xxx )
{
	return 0;
}
*/

int f_Create_Symbol_Expression_ex(SYMBOL_EXPRESSION_T *expression, ABSTRACT_EXPRESSION_T *left_exp,
                                  ABSTRACT_EXPRESSION_T *right_exp)
{
    if (expression == NULL)
    {
        return -1;
    }

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
    return 0;
}

SYMBOL_EXPRESSION_T *f_Create_Symbol_Expression(ABSTRACT_EXPRESSION_T *left_exp,
                                                ABSTRACT_EXPRESSION_T *right_exp)
{
    SYMBOL_EXPRESSION_T *expression;

    expression = (SYMBOL_EXPRESSION_T *)malloc(sizeof(SYMBOL_EXPRESSION_T));
    if (expression == NULL)
    {
        return NULL;
    }
    memset(expression, 0, sizeof(SYMBOL_EXPRESSION_T));
    if (f_Create_Symbol_Expression_ex(expression, left_exp, right_exp) != 0)
    {
        free(expression);
        return NULL;
    }

    return expression;
}

static int interpret(SYMBOL_EXPRESSION_T *this, const char *str, int *interpret_result)
{
    char str_tmp[256];
    if (this == NULL || str == NULL)
    {
        if (interpret_result != NULL)
        {
            *interpret_result = -1;
        }
        return 0;
    }

    strcpy(str_tmp, str);
    //检查语法 start
    for (int i = 0; i < strlen(str); i++)
    {
        switch (str[i])
        {
        case '+':
        {
            ADD_EXPRESSION_T *exp = f_Create_Add_Expression(this->parent.left_exp, this->parent.right_exp);
            exp->f_interpret(exp, str, interpret_result);
        }
        break;
        case '-':
        {
            SUBTRACT_EXPRESSION_T *exp = f_Create_Subtract_Expression(this->parent.left_exp, this->parent.right_exp);
            exp->f_interpret(exp, str, interpret_result);
        }
        break;
        case ' ':
        {
        }
        break;
        default:
            if (interpret_result != NULL)
            {
                *interpret_result = -2;
            }
            return 0;
        }
        break;
    }
    //检查语法 end

    //优化
    {

    }
    //解释
    {
    }

    int result1 = 0;
    int result2 = 0;

    if (interpret_result != NULL)
    {
        *interpret_result = 0;
    }
    return result1 + result2;
}
