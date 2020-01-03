#ifndef ANIMAL_FACTORY_H
#define ANIMAL_FACTORY_H

#include "cat.h"
#include "bird.h"
#include "duck.h"

#include "abstract_factory.h"

typedef struct _ANIMAL_FACTORY_T
{
   ABSTRACT_FACTORY_T factory;
} ANIMAL_FACTORY_T;

int f_Create_Animal_Factory_ex(ANIMAL_FACTORY_T *factory);
ANIMAL_FACTORY_T * f_Create_Animal_Factory(void);

#endif // ANIMAL_FACTORY_H
