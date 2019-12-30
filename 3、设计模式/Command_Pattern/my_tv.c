#include "my_tv.h"

static void tv_power_on(MY_TV *this_tv);
static void tv_power_off(MY_TV *this_tv);
static void tv_channel_up(MY_TV *this_tv);
static void tv_channel_down(MY_TV *this_tv);
static void tv_volume_up(MY_TV *this_tv);
static void tv_volume_down(MY_TV *this_tv);


MY_TV * Create_my_tv(void)
{
    MY_TV *tv;
    tv =(MY_TV *)malloc(sizeof(MY_TV));
    if(tv == NULL)
    {
        return NULL;
    }
    memset(tv, 0, sizeof(MY_TV));
    do{
        tv->power_off    = tv_power_off;
        tv->power_on     = tv_power_on;
        tv->channel_up   = tv_channel_up;
        tv->channel_down = tv_channel_down;
        tv->volume_up    = tv_volume_up;
        tv->volume_down  = tv_volume_down;
        return tv;
    }while(0);
    free (tv);
    return NULL;
}

static void tv_power_on(MY_TV *this_tv)
{
    printf("%s\n",__FUNCTION__);
}

static void tv_power_off(MY_TV *this_tv)
{
    printf("%s\n",__FUNCTION__);
}

static void tv_channel_up(MY_TV *this_tv)
{
    printf("%s\n",__FUNCTION__);
}

static void tv_channel_down(MY_TV *this_tv)
{
    printf("%s\n",__FUNCTION__);
}
static void tv_volume_up(MY_TV *this_tv)
{
    printf("%s\n",__FUNCTION__);
}

static void tv_volume_down(MY_TV *this_tv)
{
    printf("%s\n",__FUNCTION__);
}
