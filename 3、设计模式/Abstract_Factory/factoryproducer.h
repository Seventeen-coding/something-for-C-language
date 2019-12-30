#ifndef FACTORYPRODUCER_H
#define FACTORYPRODUCER_H

#include "animal_factory.h"
#include "plant_factory.h"

Abstract_Factory *getFactory(const char *name);

#endif // FACTORYPRODUCER_H
