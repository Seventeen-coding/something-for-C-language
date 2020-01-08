#ifndef CHATROOM_H
#define CHATROOM_H

#include "user.h"

typedef struct _CHATROOM_T
{
   USER_T *user_list[10];

   int (*join)(struct _CHATROOM_T *this_Chatroom, USER_T *user);

   int (*notify)(struct _CHATROOM_T *this_Chatroom, USER_T *user, const char *msg);

} CHATROOM_T;

CHATROOM_T *f_Create_Chatroom(void);

#endif // CHATROOM_H
