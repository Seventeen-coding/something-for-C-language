#ifndef DUCK_H
#define DUCK_H

#include "animal.h"

typedef struct _DUCK
{
    ANIMAL_T animal;
} DUCK_T;

DUCK_T *f_Create_Duck(const char *name);
int f_Create_Duck_ex(DUCK_T *duck, const char *name);
#endif // DUCK_H
