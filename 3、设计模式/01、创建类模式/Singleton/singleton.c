#include "singleton.h"
#include <stdlib.h>
//懒汉式单例类
USER_T *f_get_User_Instance(void)
{
    int ret = 0;
    static USER_T *user = NULL;
    if (user != NULL)
    {
        return user;
    }
    //lock
    user = f_Create_User("undefine", 0, "undefine", "undefine");
    if (user == NULL)
    {
        //unlock
        return NULL;
    }
    //unlock
    return user;
}
//饿汉
USER_T *f_get_User_Instance2(void)
{
    static int ret = -1;
    static USER_T user;

    //lock
    if (ret == 0)
    {
        //unlock
        return &user;
    }
    ret = f_Create_User_ex(&user, "undefine", 0, "undefine", "undefine");
    if (ret != 0)
    {
        //unlock
        return NULL;
    }
    //unlock
    return &user;
}