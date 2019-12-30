#ifndef USERBUILDER_H
#define USERBUILDER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"


typedef struct _UserBuilder *(*name_func)(struct _UserBuilder *this_builder,const char *name);
typedef struct _UserBuilder *(*age_func)(struct _UserBuilder *this_builder,unsigned char age);
typedef struct _UserBuilder *(*phone_func)(struct _UserBuilder *this_builder,const char *phone);
typedef struct _UserBuilder *(*address_func)(struct _UserBuilder *this_builder,const char *address);
typedef User *(*build_func)();

typedef struct _UserBuilder {
    User         user;
    name_func    name;
    age_func     age;
    phone_func   phone;
    address_func address;
    build_func   build;
}UserBuilder;


UserBuilder *CreatUserBuilder();

#endif // USERBUILDER_H
