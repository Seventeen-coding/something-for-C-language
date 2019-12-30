
#include "facade_pattern.h"
#include <stdio.h>

//客户无需理解media究竟是怎么做出来
//只需要对media提供的简单接口操作即可
//让客户include连头文件信息也尽量简单
//一句话，让调用者方便
int main(void)
{
    run();
    return 0;
}

//test
void run()
{
    Media_Interface *media_interface = get_media_interface();
    media_interface->play("hello.mp3");
    media_interface->play("hello.mkv");
    media_interface->play("hello.mp4");
    media_interface->play("hello.wma");
    media_interface->play("hello.avi");
    media_interface->play("hello.flv"); //unknow
    media_interface->play("hello");     //unknow

}
