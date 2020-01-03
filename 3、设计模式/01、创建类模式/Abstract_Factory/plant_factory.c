#include "plant_factory.h"

static PLANT_T *f_getPlant(const char *name);
int f_Create_Plant_Factory_ex(PLANT_FACTORY_T *plant_factory)
{
    if (plant_factory == NULL)
    {
        return -1;
    }
    memset(plant_factory, 0, sizeof(PLANT_FACTORY_T));

    ABSTRACT_FACTORY_T *abstract_factory = (ABSTRACT_FACTORY_T *)&plant_factory->factory;
    if (f_Create_Abstract_Factory_ex(abstract_factory) != 0)
    {
        return -2;
    }
    abstract_factory->f_getPlant = f_getPlant;

    return 0;
}
PLANT_FACTORY_T *f_Create_Plant_Factory(void)
{
    PLANT_FACTORY_T *factory = (PLANT_FACTORY_T *)malloc(sizeof(PLANT_FACTORY_T));
    if (factory == NULL)
    {
        return NULL;
    }

    if (f_Create_Plant_Factory_ex(factory) != 0)
    {
        free(factory);
        return NULL;
    }
    return factory;
}

static PLANT_T *f_getPlant(const char *name)
{
    PLANT_T *plant;

    if (strcmp(name, "Pea") == 0)
    {
        PEA_T *pea = f_Create_Pea("undefine");
        if (pea == NULL)
        {
            return NULL;
        }
        return &pea->plant;
    }

    if (strcmp(name, "SunFlower") == 0)
    {
        SUNFLOWER_T *sunflower = f_Create_SunFlower("undefine");
        if (sunflower == NULL)
        {
            return NULL;
        }
        return &sunflower->plant;
    }
    return NULL;
}
