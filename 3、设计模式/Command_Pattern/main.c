
#include "command_Pattern.h"
#include <stdio.h>

void run();

int main(void)
{
    run();
    return 0;
}

//test
//把逻辑和操作分离
//例如：
//遥控器->发送命令->电视
//遥控器只负责操作 逻辑不管
//电视只管逻辑 不负责操作
//而中间就命令 就是建立他们两个之间的关系
//作用： 调用者只操作"遥控器"接口即可无需关心他们实现
void run()
{
    MY_TV *tv = Create_my_tv();

    MY_COMMAND *channel_down_command = (MY_COMMAND *)Create_channel_down_command(tv);
    MY_COMMAND *channel_up_command   = (MY_COMMAND *)Create_channel_up_command(tv);
    MY_COMMAND *volume_down_command  = (MY_COMMAND *)Create_volume_down_command(tv);
    MY_COMMAND *volume_up_command    = (MY_COMMAND *)Create_volume_up_command(tv);
    MY_COMMAND *power_off_command    = (MY_COMMAND *)Create_power_off_command(tv);
    MY_COMMAND *power_on_command     = (MY_COMMAND *)Create_power_on_command(tv);

    My_Control *control = Create_control();

    if(tv  == NULL || channel_down_command  == NULL || channel_up_command  == NULL || volume_down_command  == NULL || volume_up_command  == NULL || power_off_command  == NULL || power_on_command  == NULL || control == NULL)
    {
        return;
    }

    control->set_command(control,&control->channel_down_command,channel_down_command);
    control->set_command(control,&control->channel_up_command,channel_up_command);
    control->set_command(control,&control->volume_down_command,volume_down_command);
    control->set_command(control,&control->volume_up_command,volume_up_command);
    control->set_command(control,&control->power_off_command,power_off_command);
    control->set_command(control,&control->power_on_command,power_on_command);


    control->power_on(control);
    control->power_off(control);
    control->channel_down(control);
    control->channel_up(control);
    control->volume_down(control);
    control->volume_up(control);

    return;
}
