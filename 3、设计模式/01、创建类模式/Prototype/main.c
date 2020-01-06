
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
#include <stdio.h>
#include "main.h"

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
void f_Run(void);
void f_Before(void); //优化前
void f_After(void);  //优化后
/*5、函数实现区
int Template(TEMPLATE_T xxx_xxx )
{
	return 0;
}
*/

int main(void)
{
    f_Run();
    return 0;
}

void f_Run(void)
{
    f_Before();
    f_After();
}

void f_Before(void)
{
    log_info("-------f_Before optimize-----------\n");
}
void f_After(void)
{
    log_info("-------f_After optimize-----------\n");
    log_info("-------user1-----------\n");
    USER_T user;
    if (f_Creat_User_ex(&user, "seventeen", 17, "119", "I don't know") != 0)
    {
        return;
    }
    user.f_about(&user);
    log_info("-------user2-----------\n");
    USER_T *user2 = user.f_clone(&user);
    if (user2 == NULL)
    {
        return;
    }
    user2->f_about(user2);
}
