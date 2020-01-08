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
#include "expression.h"
#include "number_expression.h"
#include "symbol_expression.h"
#include "abstract_expression.h"
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
static int interpret(EXPRESSION_T *this, const char *str, int *interpret_result);
static int expression_grammar(const char *str);
/*5、函数实现区
int Template(TEMPLATE_T xxx_xxx )
{
	return 0;
}
*/

int f_Create_Expression_ex(EXPRESSION_T *expression, ABSTRACT_EXPRESSION_T *left_exp,
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
EXPRESSION_T *f_Create_Expression(ABSTRACT_EXPRESSION_T *left_exp,
                                  ABSTRACT_EXPRESSION_T *right_exp)
{
    EXPRESSION_T *expression;

    expression = (EXPRESSION_T *)malloc(sizeof(EXPRESSION_T));
    if (expression == NULL)
    {
        return NULL;
    }
    memset(expression, 0, sizeof(EXPRESSION_T));
    if (f_Create_Expression_ex(expression, left_exp, right_exp) != 0)
    {
        free(expression);
        return NULL;
    }

    return expression;
}

static int interpret(EXPRESSION_T *this, const char *context, int *interpret_result)
{
    int result = 0;

    if (this == NULL || context == NULL)
    {
        if (interpret_result != NULL)
        {
            *interpret_result = -1;
        }
        return 0;
    }
    break_point("context %s len %d ", context, strlen(context));
    //分析
    for (int i = 0; i < strlen(context); i++)
    {
        if (result != 0 || *interpret_result != 0)
        {
            break;
        }
        switch (context[i])
        {
        case '0' ... '9':
        {
            if (i == strlen(context) - 1)
            {
                break_point("%d:%s", i, context);
                NUMBER_EXPRESSION_T *num_exp = f_Create_Number_Expression();
                result = num_exp->f_interpret(num_exp, context, interpret_result);
            }
        }
        break;
        case '+':
        case '-':
        case '*':
        case '/':
        {
            NUMBER_EXPRESSION_T *num_exp = f_Create_Number_Expression();
            if (num_exp == NULL)
            {
                if (interpret_result != NULL)
                {
                    *interpret_result = -2;
                }
                return 0;
            }
            ABSTRACT_EXPRESSION_T *left_exp = &num_exp->parent.parent;
            ABSTRACT_EXPRESSION_T *right_exp = &this->parent.parent;
            SYMBOL_EXPRESSION_T *symbol_exp = f_Create_Symbol_Expression(left_exp, right_exp);
            result = symbol_exp->f_interpret(symbol_exp, &context[i + 1], interpret_result);
            break_point("result:%d ", result);
        }
        break;
        case '(':
        case ')':
        {
            NUMBER_EXPRESSION_T *num_exp = f_Create_Number_Expression();
            if (num_exp == NULL)
            {
                if (interpret_result != NULL)
                {
                    *interpret_result = -3;
                }
                return 0;
            }
            ABSTRACT_EXPRESSION_T *left_exp = &num_exp->parent.parent;
            ABSTRACT_EXPRESSION_T *right_exp = &this->parent.parent;
            SYMBOL_EXPRESSION_T *symbol_exp = f_Create_Symbol_Expression(left_exp, right_exp);
            symbol_exp->f_interpret(symbol_exp, &context[i], interpret_result);
        }
        break;
        default:
            if (interpret_result != NULL)
            {
                *interpret_result = -4;
            }
            return 0;
        }
    }
    break_point(" ");
    return result;
}