#ifndef MY_CONTROL_H
#define MY_CONTROL_H

#include "my_command.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef void (*power_on_func)(void *this_control);
typedef void (*power_off_func)(void *this_control);
typedef void (*channel_up_func)(void *this_control);
typedef void (*channel_down_func)(void *this_control);
typedef void (*volume_up_func)(void *this_control);
typedef void (*volume_down_func)(void *this_control);

typedef void (power_key_func)(void *this_control);

typedef int (*set_command_func)(void *this_control,MY_COMMAND **this_control_command,MY_COMMAND *set_command);


//命令可以多种方法关联
//第一种创建时关联 ->命令越多关联越多，传入参数越多
//第二种外部接口设置 ->由于业务已知，因此每种业务配置一种命令也是符合逻辑
typedef struct _my_control{
    power_on_func       power_on;
    power_off_func      power_off;
    channel_up_func     channel_up;
    channel_down_func   channel_down;
    volume_up_func      volume_up;
    volume_down_func    volume_down;
    //假如设计成
    //注意 关联 和 控制函数没有关系 关联只是和command 关联
    //power_key_handle_func 该如何？

    //command
    MY_COMMAND *power_on_command;
    MY_COMMAND *power_off_command;
    MY_COMMAND *channel_up_command;
    MY_COMMAND *channel_down_command;
    MY_COMMAND *volume_up_command;
    MY_COMMAND *volume_down_command;



    //set_command
#if 0
    set_command_func set_power_on_command;
    set_command_func set_power_off_command;
    set_command_func set_channel_up_command;
    set_command_func set_channel_down_command;
    set_command_func set_volume_up_command;
    set_command_func set_volume_down_command;
#endif
    //嫌麻烦就这样关联
    set_command_func set_command;

}My_Control;

My_Control *Create_control(void);

#endif // MY_CONTROL_H
