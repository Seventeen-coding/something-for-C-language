#ifndef USER_H
#define USER_H

#include <stdio.h>
#include <string.h>

#ifndef MAX_LEN
#define MAX_LEN 256
#endif

typedef struct _USER_T
{
    char name[MAX_LEN];
    unsigned char age;
    char phone[MAX_LEN];
    char address[MAX_LEN];
    void (*f_print_name)(struct _USER_T *this_user);
    void (*f_print_age)(struct _USER_T *this_user);
    void (*f_print_phone)(struct _USER_T *this_user);
    void (*f_print_address)(struct _USER_T *this_user);
    void (*f_about)(struct _USER_T *this_user);
    struct _USER_T *(*f_clone)(struct _USER_T *this_user);
} USER_T;

USER_T *f_Creat_User(const char *name, unsigned char age, const char *phone, const char *address);
int f_Creat_User_ex(USER_T *USER_T, const char *name, unsigned char age, const char *phone, const char *address);

#endif // USER_H
