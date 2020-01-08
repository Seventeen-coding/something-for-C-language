#ifndef USER_H
#define USER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum _Level
{
    UNDEFINE = -1,
    NORMAL_USER,
    VIP_USER,
    SUPER_VIP_USER
} Level;

typedef struct _USER_T
{
    char name[10];
    char account[10];
    char password[10];
    Level level;

    //注册接口
    int (*sign_up_fee)(struct _USER_T *this_user);
    //优惠接口
    int (*discounts)(struct _USER_T *this_user);
    int (*Cost)(struct _USER_T *this_user);

} USER_T;

USER_T *Create_User(const char name[10], const char account[10], const char password[10], Level level);

#endif // USER_H
