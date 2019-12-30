#ifndef USER_H
#define USER_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum _Level{
    UNDEFINE = -1,
    NORMAL_USER,
    VIP_USER,
    SUPER_VIP_USER
}Level;

typedef int (* Sign_up_fee_func)(void *this_user);
typedef int (* Discounts_func) (void *this_user);
typedef int (* Cost_func)(void *this_user);


typedef struct _User{
   char name[10];
   char account[10];
   char password[10];
   Level  level;
   //注册接口
   Sign_up_fee_func sign_up_fee;
   //优惠接口
   Discounts_func discounts;

   Cost_func  Cost;
}User;


User *Create_User(const char name[10],const char account[10],const char password[10],Level  level);

#endif // USER_H
