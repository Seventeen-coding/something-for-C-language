#include "singleton.h"

//懒汉式单例类
User *getUserInstance()
{
    static User *user = NULL;
    if(user != NULL)
    {
        return user;
    }
    //lock
    user =(User *) malloc(sizeof(User));
    CreatUserbyNameAgePhoneAddress(user,"undefine",0,"undefine","undefine");
    //unlock

    return user;
}


