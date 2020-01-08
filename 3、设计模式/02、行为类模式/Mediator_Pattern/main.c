
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
    printf("-------f_Before optimize-----------\n");
    USER_T *robert = f_Create_User("Robert");
    USER_T *john = f_Create_User("John");
    USER_T *seventeen = f_Create_User("seventeen");
    USER_T *Tim = f_Create_User("Tim");
    //随着用户增多越复杂
    printf(" ------------robert introduce---------\n");
    robert->sendmsg1(robert, john, "Hi! my name is robert!");
    robert->sendmsg1(robert, seventeen, "Hi! my name is robert!");
    robert->sendmsg1(robert, Tim, "Hi! my name is robert!");
    printf(" ------------john introduce---------\n");
    john->sendmsg1(john, john, "Hi! my name is john!");
    john->sendmsg1(john, seventeen, "Hi! my name is john!");
    john->sendmsg1(john, Tim, "Hi! my name is john!");
}
void f_After(void)
{
    printf("-------f_After optimize-----------\n");
    USER_T *robert = f_Create_User("Robert");
    USER_T *john = f_Create_User("John");
    USER_T *seventeen = f_Create_User("seventeen");
    USER_T *Tim = f_Create_User("Tim");

    //把消息给到中介让它去处理
    //对于发送、接受 、中介  都有权过滤消息
    CHATROOM_T *chatroom = f_Create_Chatroom();
    if (chatroom->join(chatroom, robert) != 0)
        return;
    if (chatroom->join(chatroom, john) != 0)
        return;
    if (chatroom->join(chatroom, seventeen) != 0)
        return;
    if (chatroom->join(chatroom, Tim) != 0)
        return;

    printf(" ------------seventeen introduce---------\n");
    chatroom->notify(chatroom, seventeen, "hi! my name is seventeen!");
    printf(" ------------Tim introduce---------\n");
    chatroom->notify(chatroom, Tim, "hi! my name is Tim!");
}
