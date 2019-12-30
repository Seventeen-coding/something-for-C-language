#ifndef USER_H
#define USER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef const char *(*getname_func)(void * this_user);
typedef int (*setname_func)(void * this_user,char *name);

//第一种方法 消息直接发送给指定user
typedef int (*sendmsg_func1)(void * this_user,void * send_to_user,char *msg);
typedef int (*receivemsg_func1)(void * this_user,char *msg);

#define NAME_LEN 20

typedef struct {
    char name[NAME_LEN];
    getname_func getname;
    setname_func setname;

    sendmsg_func1 sendmsg1;
    receivemsg_func1 receivemsg1;

}USER;

USER *create_User(const char * name);

#endif // USER_H
