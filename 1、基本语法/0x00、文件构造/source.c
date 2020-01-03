/*请用文档编辑器编辑此文件*/

/*
*	按照C语言的语法 规范编程
*	一个良好的书写规范决定一个程序的好坏
*	源代码不仅仅给自己看有可能给别人看
*/

/*1、头文件*/
#include <stdio.h>
#include <string.h>
#include "header.h"

/*2、宏定义*/
//规范：宏定义一律用大写XXXX_XXXX
#define HW_LEN 10

/*3、结构体声明 .h文件*/
//规范：机构体习惯用XXX_t
typedef struct
{
    int len;
    char *string;
} str_t;
/*4、函数和变量声明*/
//规范：函数命名习惯用 Xxx_xxx 或者 XxxXxx等等
//规范：变量命名习惯用 xxx_xxx 或者 xxxXxx等等
void Call_helloworld(void);
char *str_helloworld = "hello world";

/*5、函数实现区*/
//规范：main放在第一个 或者 最后一个 方便程序入口
int main(void)
{
    Call_helloworld();
    return 0;
}

void Call_helloworld(void)
{
    log_info("%s\n",HELLOWORLD);
    log_error("%s\n",str_helloworld);
    log_warn("%s\n",HELLOWORLD);
}
