#ifndef PLANT_FACTORY_H
#define PLANT_FACTORY_H

#include "pea.h"
#include "sunflower.h"
#include "abstract_factory.h"

typedef struct _PLANT_FACTORY_T
{
    ABSTRACT_FACTORY_T factory;
} PLANT_FACTORY_T;

PLANT_FACTORY_T *f_Create_Plant_Factory(void);
int f_Create_Plant_Factory_ex(PLANT_FACTORY_T *factory);

#endif // PLANT_FACTORY_H
