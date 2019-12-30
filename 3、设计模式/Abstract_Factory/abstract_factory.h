#ifndef ABSTRACT_FACTORY_H
#define ABSTRACT_FACTORY_H

#include "animal.h"
#include "plant.h"

typedef   Animal *(* getAnimal_func)(const char *name);
typedef   Plant *(* getPlant_func)(const char *name);


typedef struct _Abstract_Factory{
    getAnimal_func getAnimal;
    getPlant_func getPlant;
}Abstract_Factory;

int CreateAbstractFactory(Abstract_Factory  *factory);


#endif // ABSTRACT_FACTORY_H
