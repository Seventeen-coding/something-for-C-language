#ifndef USER_H
#define USER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NAME_LEN 20

typedef struct _USER_T
{
    char name[NAME_LEN];

    const char *(*getname)(struct _USER_T *this_user);
    int (*setname)(struct _USER_T *this_user, char *name);

    int (*sendmsg1)(struct _USER_T *this_user, struct _USER_T *send_to_user, const char *msg);
    int (*receivemsg1)(struct _USER_T *this_user,const char *msg);

} USER_T;

USER_T *f_Create_User(const char *name);

#endif // USER_H
