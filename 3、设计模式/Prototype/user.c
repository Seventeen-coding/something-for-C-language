#include "user.h"

static void print_name(User *this_user);
static void print_age(User *this_user);
static void print_phone(User *this_user);
static void print_address(User *this_user);
static User *clone(User *this_user);
int CreatUser(User *user)
{
    if(user == NULL)
    {
        return -1;
    }
    //boy XXX
    user->print_address = print_address;
    user->print_age = print_age;
    user->print_name = print_name;
    user->print_phone = print_phone;
    user->clone = clone;
    return 0;
}

int CreatUserbyNameAgePhoneAddress(User *user, const char *name, unsigned char age, const char *phone, const char *address)
{
    if(CreatUser(user) != 0)
    {
        return -1;
    }
    user->age = age;
    if(name == NULL)
    {
        return -1;
    }
    strcpy(user->name,name);
    if(phone == NULL)
    {
        return -1;
    }
    strcpy(user->phone,phone);
    if(address == NULL)
    {
        return -1;
    }
    strcpy(user->address,address);
    return 0;
}

static void print_name(User *this_user)
{
    printf("user name is %s \n",this_user->name);
}
static void print_age(User *this_user)
{
    printf("user age is %d \n",this_user->age);
}
static void print_phone(User *this_user)
{
    printf("user phone is %s \n",this_user->phone);
}
static void print_address(User *this_user)
{
    printf("user address is %s \n",this_user->address);
}
static User *clone(User *this_user)
{
    User* clone_user = (User*)malloc(sizeof(User));
    if(clone_user == NULL)
    {
        return NULL;
    }
    memmove(clone_user, this_user, sizeof(User));
    return clone_user;
}
