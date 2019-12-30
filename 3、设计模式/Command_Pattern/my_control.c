#include "my_control.h"

static void power_on(My_Control *this_control);
static void power_off(My_Control *this_control);
static void channel_up(My_Control *this_control);
static void channel_down(My_Control *this_control);
static void volume_up(My_Control *this_control);
static void volume_down(My_Control *this_control);

static int set_command(My_Control *this_control, MY_COMMAND **this_control_command, MY_COMMAND *set_command);
My_Control *Create_control()
{
    My_Control * control;

    control = (My_Control *) malloc(sizeof(My_Control));

    if(control == NULL)
    {
        return NULL;
    }
    memset(control,0,sizeof(MY_COMMAND));
    do {
        control->channel_down = channel_down;
        control->channel_up = channel_up;
        control->volume_down = volume_down;
        control->volume_up = volume_up;
        control->power_off = power_off;
        control->power_on = power_on;
        control->set_command = set_command;
        return control;
    }while(0);

    free (control);
    return NULL;

}

static void power_on(My_Control *this_control)
{
    if(this_control == NULL || this_control->power_on_command == NULL)
    {
        return ;
    }
    this_control->power_on_command->execute(this_control->power_on_command);
}
static void power_off(My_Control *this_control)
{
    if(this_control == NULL || this_control->power_off_command == NULL)
    {
        return ;
    }
    this_control->power_off_command->execute(this_control->power_off_command);
}

static void channel_up(My_Control *this_control)
{
    if(this_control == NULL || this_control->channel_up_command == NULL)
    {
        return ;
    }
    this_control->channel_up_command->execute(this_control->channel_up_command);
}

static void channel_down(My_Control *this_control)
{
    if(this_control == NULL || this_control->channel_down_command == NULL)
    {
        return ;
    }
    this_control->channel_down_command->execute(this_control->channel_down_command);
}

static void volume_up(My_Control *this_control)
{
    if(this_control == NULL || this_control->volume_up_command == NULL)
    {
        return ;
    }
    this_control->volume_up_command->execute(this_control->volume_up_command);
}

static void volume_down(My_Control *this_control)
{
    if(this_control == NULL || this_control->volume_down_command == NULL)
    {
        return ;
    }
    this_control->volume_down_command->execute(this_control->volume_down_command);
}

static int set_command(My_Control *this_control,MY_COMMAND **this_control_command,MY_COMMAND *set_command)
{
    if(this_control == NULL || this_control_command == NULL || set_command == NULL )
    {
        return -1;
    }

    *this_control_command = set_command;

    return 0;
}
