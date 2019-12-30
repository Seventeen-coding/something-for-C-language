
#include "singleton.h"
#include <stdio.h>


int main(void)
{
    run();
    return 0;
}

//test
//notice:对于单线程 单例模式不需要考虑线程之间的竞争
//       对于多线程 需要考虑同步同一时间拿到唯一一个对象
//       针对一次获取对象 分为 懒汉式 饿汉式
//       懒汉式   拿对象才生成
//       饿汉式   已经初始化好
void run()
{
    User *user = getUserInstance();  //noly one
    User *user2 = getUserInstance();
    printf("----------user1-----------\n");
    user->about(user);
    printf("----------user2-----------\n");
    user2->about(user2);
    //change user 1
    strcpy(user->address,"home");
    strcpy(user->phone,"17");
    printf("----------user2-----------\n");
    user2->about(user2);
    printf("---------------------\n");
}
