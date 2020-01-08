
#include "bridge.h"

void run();
//notice : 考虑适配器模式 加 桥接模式一起使用效果更好
//意图：将抽象部分与实现部分分离，使它们都可以独立的变化。
//主要解决：在有多种可能会变化的情况下，用继承会造成类爆炸问题，扩展起来不灵活。
//          因为继承时候也需要指定对应接口 因此加重了继承传入参数
int main(void)
{
    run();
    return 0;
}

//test
void run()
{
    Media mp3_media;
    if(CreatMedia(&mp3_media,play_mp3_adaper) != 0)
    {
        return ;
    }
    mp3_media.play(&mp3_media,"hello.mp3");
    Media mp4_media;
    if(CreatMedia(&mp4_media,play_mp4_adaper) != 0)
    {
        return ;
    }
    mp4_media.play(&mp4_media,"hello.mp4");

    return ;
}
