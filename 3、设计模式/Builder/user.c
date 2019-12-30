#include "user.h"

void print_name(User *this_user);
void print_age(User *this_user);
void print_phone(User *this_user);
void print_address(User *this_user);

int CreatUser(User *user)
{
    if(user == NULL)
    {
        return -1;
    }
    user->print_address = print_address;
    user->print_age = print_age;
    user->print_name = print_name;
    user->print_phone = print_phone;
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

void print_name(User *this_user)
{
    printf("user name is %s \n",this_user->name);
}
void print_age(User *this_user)
{
    printf("user age is %d \n",this_user->age);
}
void print_phone(User *this_user)
{
    printf("user phone is %s \n",this_user->phone);
}
void print_address(User *this_user)
{
    printf("user address is %s \n",this_user->address);
}
