#ifndef CHATROOM_H
#define CHATROOM_H

#include "user.h"

typedef int (*join_func)(void *this_Chatroom,USER *user);

typedef int (*notify_func)(void *this_Chatroom,USER *user,const char *msg);

typedef struct {
   USER *user_list[10];
   join_func join;
   notify_func notify;
}Chatroom;

Chatroom *Create_Chatroom(void);

#endif // CHATROOM_H
