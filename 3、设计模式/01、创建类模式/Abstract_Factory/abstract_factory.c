#include "abstract_factory.h"

static ANIMAL_T *f_getAnimal_func(const char *name);
static PLANT_T *f_getPlant_func(const char *name);
ABSTRACT_FACTORY_T *f_Create_Abstract_Factory(void)
{
    ABSTRACT_FACTORY_T *factory = (ABSTRACT_FACTORY_T *)malloc(sizeof(ABSTRACT_FACTORY_T));
    if (factory == NULL)
    {
        return NULL;
    }
    if (f_Create_Abstract_Factory_ex(factory) != 0)
    {
        free(factory);
        return NULL;
    }
    return factory;
}
int f_Create_Abstract_Factory_ex(ABSTRACT_FACTORY_T *factory)
{
    if (factory == NULL)
    {
        return -1;
    }
    factory->f_getAnimal = f_getAnimal_func;
    factory->f_getPlant = f_getPlant_func;
    return 0;
}

static ANIMAL_T *f_getAnimal_func(const char *name)
{
    return NULL;
}
static PLANT_T *f_getPlant_func(const char *name)
{
    return NULL;
}
