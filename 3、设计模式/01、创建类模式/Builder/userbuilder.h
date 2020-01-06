#ifndef USERBUILDER_H
#define USERBUILDER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"

typedef struct _UserBuilder
{
    USER_T user;
    struct _UserBuilder *(*f_name)(struct _UserBuilder *this_builder, const char *name);
    struct _UserBuilder *(*f_age)(struct _UserBuilder *this_builder, unsigned char age);
    struct _UserBuilder *(*f_phone)(struct _UserBuilder *this_builder, const char *phone);
    struct _UserBuilder *(*f_address)(struct _UserBuilder *this_builder, const char *address);
    USER_T *(*f_build)(struct _UserBuilder *this_builder);
} USER_BUILDER_T;

USER_BUILDER_T *f_Create_User_Builder();

#endif // USERBUILDER_H
