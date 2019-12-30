#ifndef USER_H
#define USER_H

#include <stdio.h>
#include <string.h>

#include "boy.h"

#ifndef MAX_LEN
#define MAX_LEN 256
#endif

typedef void (*print_name_func)(void *this_user);
typedef void (*print_age_func)(void *this_user);
typedef void (*print_phone_func)(void *this_user);
typedef void (*print_address_func)(void *this_user);
typedef struct _User *(*user_clone_func)(void *this_user);

typedef struct _User{
    Boy   boy;
    char  name[MAX_LEN];
    unsigned char  age;
    char phone[MAX_LEN];
    char address[MAX_LEN];
    print_name_func print_name;
    print_age_func  print_age;
    print_phone_func    print_phone;
    print_address_func  print_address;
    user_clone_func clone;
}User;

int CreatUser(User *user);
int CreatUserbyNameAgePhoneAddress(User *user,const char *name, unsigned char  age,const char *phone,const char *address);


#endif // USER_H
