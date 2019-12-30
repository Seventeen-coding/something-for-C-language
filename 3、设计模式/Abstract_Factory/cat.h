#ifndef CAT_H
#define CAT_H

#include "animal.h"

typedef struct _Cat
{
    Animal animal;
}Cat;

int CreateCat(Cat *cat);

#endif // CAT_H
