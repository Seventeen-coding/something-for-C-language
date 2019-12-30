#ifndef PLANT_FACTORY_H
#define PLANT_FACTORY_H


#include "pea.h"
#include "sunflower.h"

#include "abstract_factory.h"

typedef struct _PlantFactory
{
    getPlant_func getPlant;
}PlantFactory;

int CreatePlantFactory(PlantFactory *factory);


#endif // PLANT_FACTORY_H
