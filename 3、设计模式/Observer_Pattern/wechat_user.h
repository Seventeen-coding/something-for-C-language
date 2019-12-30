#ifndef WECHAT_USER_H
#define WECHAT_USER_H

#include "observer.h"

typedef struct _Wechat_user{
    char name[256];
    Observer observer;
}Wechat_user;

Wechat_user *Create_Wechat_user(const char *name);

#endif // WECHAT_USER_H
