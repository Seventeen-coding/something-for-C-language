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
    log_info("f_Before optimize\n");
    log_info("===============user1=============== \n");
    USER_T user;
    if (f_Creat_User_ex(&user, "seventeen", 17, "183xxxxxxxx", "hello world") != 0)
    {
        log_error("user create fail\n");
        return;
    }
    user.f_about(&user);

    log_info("===============user2=============== \n");
    USER_T *user2 = f_Creat_User("seventeen", 17, "183xxxxxxxx", "hello world");
    if (user2 == NULL)
    {
        log_error("user2 create fail\n");
        return;
    }
    user2->f_about(user2);
    free(user2);
    return;
}
void f_After(void)
{
    log_info("f_After optimize\n");
    printf("===============user3=============== \n");
    USER_BUILDER_T *builder = f_Create_User_Builder();
    USER_T *user3 = builder->f_address(builder, "world6")->f_age(builder, 18)->f_phone(builder, "120")->f_name(builder, "seventeen")->f_build(builder);
    user3->f_about(user3);
    printf("===============user4=============== \n");
    builder = f_Create_User_Builder();
    builder = builder->f_phone(builder, "120");
    builder = builder->f_address(builder, "world6")->f_age(builder, 18);
    builder = builder->f_name(builder, "seventeen");
    USER_T *user4 = builder->f_build(builder);
    user4->f_about(user4);
    return;
}
