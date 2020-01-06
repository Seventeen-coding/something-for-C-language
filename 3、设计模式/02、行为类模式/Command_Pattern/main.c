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
    MY_TV *tv = Create_my_tv();

    MY_COMMAND_T *channel_down_command = (MY_COMMAND_T *)Create_channel_down_command(tv);
    MY_COMMAND_T *channel_up_command = (MY_COMMAND_T *)Create_channel_up_command(tv);
    MY_COMMAND_T *volume_down_command = (MY_COMMAND_T *)Create_volume_down_command(tv);
    MY_COMMAND_T *volume_up_command = (MY_COMMAND_T *)Create_volume_up_command(tv);
    MY_COMMAND_T *power_off_command = (MY_COMMAND_T *)Create_power_off_command(tv);
    MY_COMMAND_T *power_on_command = (MY_COMMAND_T *)Create_power_on_command(tv);

    My_Control *control = Create_control();

    if (tv == NULL || channel_down_command == NULL || channel_up_command == NULL || volume_down_command == NULL || volume_up_command == NULL || power_off_command == NULL || power_on_command == NULL || control == NULL)
    {
        return;
    }

    control->set_command(control, &control->channel_down_command, channel_down_command);
    control->set_command(control, &control->channel_up_command, channel_up_command);
    control->set_command(control, &control->volume_down_command, volume_down_command);
    control->set_command(control, &control->volume_up_command, volume_up_command);
    control->set_command(control, &control->power_off_command, power_off_command);
    control->set_command(control, &control->power_on_command, power_on_command);

    control->power_on(control);
    control->power_off(control);
    control->channel_down(control);
    control->channel_up(control);
    control->volume_down(control);
    control->volume_up(control);

    return;
}
