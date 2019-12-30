#include "userbuilder.h"

UserBuilder *_name(UserBuilder *this_builder, const char *name);
UserBuilder *_age(UserBuilder *this_builder, unsigned char age);
UserBuilder *_phone(UserBuilder *this_builder, const char *phone);
UserBuilder *_address(UserBuilder *this_builder, const char *address);
User *_build(UserBuilder *this_builder);

UserBuilder *CreatUserBuilder()
{
    UserBuilder static builder;
    memset(&builder,0,sizeof(UserBuilder));

    builder.name = _name;
    builder.age = _age;
    builder.phone = _phone;
    builder.address = _address;
    builder.build = _build;

    return &builder;
}
UserBuilder *_name(UserBuilder *this_builder , const char *name)
{
    if(name == NULL)
    {
        return this_builder;
    }
    strcpy(this_builder->user.name,name);
    return this_builder;
}
UserBuilder *_age(UserBuilder *this_builder, unsigned char age)
{
    this_builder->user.age = age;
    return this_builder;
}
UserBuilder *_phone(UserBuilder *this_builder, const char *phone)
{
    if(phone == NULL)
    {
        return this_builder;
    }
    strcpy(this_builder->user.phone,phone);
    return this_builder;
}
UserBuilder *_address(UserBuilder *this_builder, const char *address)
{
    if(address == NULL)
    {
        return this_builder;
    }
    strcpy(this_builder->user.address,address);
    return this_builder;
}
User *_build(UserBuilder *this_builder)
{
    if(CreatUser(&this_builder->user) != 0 )
    {
        return NULL;
    }
    User *user = (User *)malloc(sizeof(User));
    if( user == NULL)
    {
        return NULL;
    }
    memcpy(user,&this_builder->user,sizeof(User));
    return user;
}
