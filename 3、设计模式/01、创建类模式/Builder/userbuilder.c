#include "userbuilder.h"
#include <stdlib.h>
#include <string.h>

USER_BUILDER_T *f_name(USER_BUILDER_T *this_builder, const char *name);
USER_BUILDER_T *f_age(USER_BUILDER_T *this_builder, unsigned char age);
USER_BUILDER_T *f_phone(USER_BUILDER_T *this_builder, const char *phone);
USER_BUILDER_T *f_address(USER_BUILDER_T *this_builder, const char *address);
USER_T *f_build(USER_BUILDER_T *this_builder);

USER_BUILDER_T *f_Create_User_Builder()
{
    static USER_BUILDER_T builder;
    memset(&builder, 0, sizeof(USER_BUILDER_T));
    USER_T user = {
        .name = "undefine",
        .age = 0,
        .phone = "",
        .address = ""};
    memcpy(&builder.user, &user, sizeof(USER_T));
    builder.f_name = f_name;
    builder.f_age = f_age;
    builder.f_phone = f_phone;
    builder.f_address = f_address;
    builder.f_build = f_build;

    return &builder;
}
USER_BUILDER_T *f_name(USER_BUILDER_T *this_builder, const char *name)
{
    if (name == NULL)
    {
        return this_builder;
    }
    strcpy(this_builder->user.name, name);
    return this_builder;
}
USER_BUILDER_T *f_age(USER_BUILDER_T *this_builder, unsigned char age)
{
    this_builder->user.age = age;
    return this_builder;
}
USER_BUILDER_T *f_phone(USER_BUILDER_T *this_builder, const char *phone)
{
    if (phone == NULL)
    {
        return this_builder;
    }
    strcpy(this_builder->user.phone, phone);
    return this_builder;
}
USER_BUILDER_T *f_address(USER_BUILDER_T *this_builder, const char *address)
{
    if (address == NULL)
    {
        return this_builder;
    }
    strcpy(this_builder->user.address, address);
    return this_builder;
}
USER_T *f_build(USER_BUILDER_T *this_builder)
{
    USER_T *user = &this_builder->user;
    if (f_Creat_User_ex(user, user->name, user->age, user->phone, user->address) != 0)
    {
        return NULL;
    }
    user = (USER_T *)malloc(sizeof(USER_T));
    if (user == NULL)
    {
        return NULL;
    }
    memcpy(user, &this_builder->user, sizeof(USER_T));
    return user;
}
