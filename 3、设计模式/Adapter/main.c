
#include "adapter.h"
#include <stdio.h>

void run();

int main(void)
{
    run();
    return 0;
}

//两种方案
//1修改原来play_mp4 ,如果有其他函数依赖就会出错
//2提供新的接口play_adapter_mp4  在原有的基础上改变传参方式 -> 这个就是适配器
//test
void run()
{
    Media mp3_player;
    if(CreatMedia(&mp3_player,MP3) != 0)
    {
        return;
    }
    //调用的 play_mp3
    mp3_player.play(&mp3_player,MP3,"hello.mp3");
    Media mp4_player;
    if(CreatMedia(&mp4_player,MP4) != 0)
    {
        return;
    }
    //调用的 适配器play_adapter_mp4
    mp4_player.play(&mp3_player,MP4,"hello.mp4");

    //not support type
    Media mkv_player;
    if(CreatMedia(&mkv_player,MKV) != 0)
    {
        return;
    }
    //MKV
    mkv_player.play(&mkv_player,MKV,"hello.mkv");
    return;
}
