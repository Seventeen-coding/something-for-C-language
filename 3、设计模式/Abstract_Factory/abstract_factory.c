#include "abstract_factory.h"

static Animal * _getAnimal_func(const char *name);
static Plant * _getPlant_func(const char *name);


int CreateAbstractFactory(Abstract_Factory *factory)
{
    if(factory == NULL)
    {
        return -1;
    }
    factory->getAnimal = _getAnimal_func;
    factory->getPlant  = _getPlant_func;
    return 0;
}


static Animal * _getAnimal_func(const char *name)
{
    return NULL;
}
static Plant  * _getPlant_func(const char *name)
{
    return NULL;
}

