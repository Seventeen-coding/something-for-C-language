#ifndef FACTORYPRODUCER_H
#define FACTORYPRODUCER_H

#include "animal_factory.h"
#include "plant_factory.h"

ABSTRACT_FACTORY_T *f_getFactory(const char *name);

#endif // FACTORYPRODUCER_H
