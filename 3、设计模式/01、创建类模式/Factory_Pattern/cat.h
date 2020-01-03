#ifndef CAT_H
#define CAT_H

#include "animal.h"

typedef struct _CAT_T
{
    ANIMAL_T animal;
} CAT_T;

CAT_T *f_Create_Cat(const char *name);
int f_Create_Cat_ex(CAT_T *cat, const char *name);

#endif // CAT_H
