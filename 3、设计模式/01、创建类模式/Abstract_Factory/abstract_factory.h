#ifndef ABSTRACT_FACTORY_H
#define ABSTRACT_FACTORY_H

#include "animal.h"
#include "plant.h"

typedef struct _ABSTRACT_FACTORY_T
{
    ANIMAL_T *(*f_getAnimal)(const char *name);
    PLANT_T *(*f_getPlant)(const char *name);
} ABSTRACT_FACTORY_T;

ABSTRACT_FACTORY_T *f_Create_Abstract_Factory(void);
int f_Create_Abstract_Factory_ex(ABSTRACT_FACTORY_T *factory);

#endif // ABSTRACT_FACTORY_H
