
#include "mediator.h"

void run();

int main(void)
{
    run();
    return 0;
}

//test
//中介者模式 ： 广播消息、
//何时使用：多个类相互耦合，形成了网状结构。
//如何解决：将上述网状结构分离为星型结构。

void run()
{
    USER *robert = create_User("Robert");
    USER *john = create_User("John");
    USER *seventeen = create_User("seventeen");
    USER *Tim = create_User("Tim");
    //随着用户增多越复杂
    printf(" ------------robert introduce---------\n");
    robert->sendmsg1(robert,john,"Hi! my name is robert!");
    robert->sendmsg1(robert,seventeen,"Hi! my name is robert!");
    robert->sendmsg1(robert,Tim,"Hi! my name is robert!");
    printf(" ------------john introduce---------\n");
    john->sendmsg1(robert,john,"Hi! my name is john!");
    john->sendmsg1(robert,seventeen,"Hi! my name is john!");
    john->sendmsg1(robert,Tim,"Hi! my name is john!");

    //把消息给到中介让它去处理
    //对于发送、接受 、中介  都有权过滤消息
    Chatroom *chatroom = Create_Chatroom();
    if(chatroom->join(chatroom,robert) != 0 )         return;
    if(chatroom->join(chatroom,john) != 0 )         return;
    if(chatroom->join(chatroom,seventeen) != 0 )         return;
    if(chatroom->join(chatroom,Tim) != 0 )         return;

    printf(" ------------seventeen introduce---------\n");
    chatroom->notify(chatroom,seventeen,"hi! my name is seventeen!");
    printf(" ------------Tim introduce---------\n");
    chatroom->notify(chatroom,Tim,"hi! my name is Tim!");

}
