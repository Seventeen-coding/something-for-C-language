#ifndef MY_TV_H
#define MY_TV_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*tv_power_on_func)(void *this_tv);
typedef void (*tv_power_off_func)(void *this_tv);
typedef void (*tv_channel_up_func)(void *this_tv);
typedef void (*tv_channel_down_func)(void *this_tv);
typedef void (*tv_volume_up_func)(void *this_tv);
typedef void (*tv_volume_down_func)(void *this_tv);

typedef struct _MY_TV{
    tv_power_on_func       power_on;
    tv_power_off_func      power_off;
    tv_channel_up_func     channel_up;
    tv_channel_down_func   channel_down;
    tv_volume_up_func      volume_up;
    tv_volume_down_func    volume_down;
    void *other_info;
    void *other_func;
}MY_TV;

MY_TV * Create_my_tv(void);

#endif // MY_TV_H
