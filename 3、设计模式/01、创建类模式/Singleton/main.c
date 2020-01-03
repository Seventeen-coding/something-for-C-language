/*
	这里可以写相关文件描述 协议等等信息
	如：
	按照C语言的语法 规范编程
	一个良好的书写规范决定一个程序的好坏
	源代码不仅仅给自己看有可能给别人看
*/

/*1、头文件*/
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
    log_info("before optimize\n");
    USER_T *user = f_Create_User("seventeen", 17, "183xxxxxxxx", "home");
    USER_T *user2 = f_Create_User("seventeen", 17, "183xxxxxxxx", "home");
    user->fp_about(user);
    user2->fp_about(user2);
    
}
void f_After(void)
{
    log_info("after optimize\n");
    //懒汉模式
    {
        USER_T *user = NULL;
        USER_T *user2 = NULL;
        user = f_get_User_Instance();
        user2 = f_get_User_Instance();
        if (user == NULL || user2 == NULL)
        {
            return;
        }
        printf("----------user1-----------\n");
        user->fp_about(user);
        printf("----------user2-----------\n");
        user2->fp_about(user2);
        //change user 1
        strcpy(user->address, "home");
        strcpy(user->phone, "17");
        printf("----------user2-----------\n");
        user2->fp_about(user2);
        printf("---------------------\n");
    }
    //饿汉模式
    {
        USER_T *user = NULL;
        USER_T *user2 = NULL;
        user = f_get_User_Instance2();
        user2 = f_get_User_Instance2();
        if (user == NULL || user2 == NULL)
        {
            return;
        }
        printf("----------user1-----------\n");
        user->fp_about(user);
        printf("----------user2-----------\n");
        user2->fp_about(user2);
        //change user 1
        strcpy(user->address, "home");
        strcpy(user->phone, "17");
        printf("----------user2-----------\n");
        user2->fp_about(user2);
        printf("---------------------\n");
    }
}