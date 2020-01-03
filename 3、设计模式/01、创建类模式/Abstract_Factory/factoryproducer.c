#include "factoryproducer.h"

ABSTRACT_FACTORY_T *f_getFactory(const char *name)
{
    if (strcmp(name, "Animal") == 0)
    {
        ANIMAL_FACTORY_T *animal_factory;
        animal_factory = f_Create_Animal_Factory();
        return animal_factory == NULL ? NULL : &animal_factory->factory;
    }
    else if (strcmp(name, "Plant") == 0)
    {
        PLANT_FACTORY_T *plant_factory;
        plant_factory = f_Create_Plant_Factory();
        return plant_factory == NULL ? NULL : &plant_factory->factory;
    }

    return NULL;
}
