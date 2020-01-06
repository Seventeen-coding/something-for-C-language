#include "user.h"
#include <stdlib.h>

static void f_print_name(USER_T *this);
static void f_print_age(USER_T *this);
static void f_print_phone(USER_T *this);
static void f_print_address(USER_T *this);
static void f_about(USER_T *this);
static USER_T *f_clone(USER_T *this_user);

USER_T *f_Creat_User(const char *name, unsigned char age, const char *phone, const char *address)
{
    USER_T *user = (USER_T *)malloc(sizeof(USER_T));
    if (user == NULL)
    {
        return NULL;
    }
    if (f_Creat_User_ex(user, name, age, phone, address) != 0)
    {
        free(user);
        return NULL;
    }

    return user;
}
int f_Creat_User_ex(USER_T *user, const char *name, unsigned char age, const char *phone, const char *address)
{
    if (user == NULL)
    {
        return -1;
    }
    user->age = age;
    if (name == NULL)
    {
        return -2;
    }
    strcpy(user->name, name);
    if (phone == NULL)
    {
        return -3;
    }
    strcpy(user->phone, phone);
    if (address == NULL)
    {
        return -4;
    }
    strcpy(user->address, address);

    user->f_print_address = f_print_address;
    user->f_print_age = f_print_age;
    user->f_print_name = f_print_name;
    user->f_print_phone = f_print_phone;
    user->f_about = f_about;
    user->f_clone = f_clone;
    return 0;
}
static void f_print_name(USER_T *this)
{
    printf("user name is %s \n", this->name);
}
static void f_print_age(USER_T *this)
{
    printf("user age is %d \n", this->age);
}
static void f_print_phone(USER_T *this)
{
    printf("user phone is %s \n", this->phone);
}
static void f_print_address(USER_T *this)
{
    printf("user address is %s \n", this->address);
}
static void f_about(USER_T *this)
{
    if (this == NULL)
    {
        return;
    }
    this->f_print_name(this);
    this->f_print_age(this);
    this->f_print_phone(this);
    this->f_print_address(this);
}

static USER_T *f_clone(USER_T *this_user)
{
    USER_T *clone_user = (USER_T *)malloc(sizeof(USER_T));
    if (clone_user == NULL)
    {
        return NULL;
    }
    memmove(clone_user, this_user, sizeof(USER_T));
    return clone_user;
}
