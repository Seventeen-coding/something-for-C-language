#include "plant_factory.h"

static Plant *_getPlant(const char *name);

int CreatePlantFactory(PlantFactory *factory)
{
    if(factory == NULL)
    {
        return -1;
    }
    memset(factory , 0, sizeof(PlantFactory));
    do
    {
        Abstract_Factory *abstract_factory =( Abstract_Factory  *) factory;
        if(CreateAbstractFactory(abstract_factory) != 0)
        {
            break;
        }
        abstract_factory->getPlant =(getPlant_func) _getPlant;

        return 0;
    }while(0);

    return -1;
}


static Plant *_getPlant(const char *name)
{
    Plant *plant;

    if(strcmp(name,"Pea") == 0)
    {
        plant =(Plant *)malloc(sizeof(Pea));
        if(plant == NULL)
        {
            return NULL;
        }
        if(CreatePea((Pea *)plant) != 0)
        {
            free(plant);
            return NULL;
        }
        return plant;
    }

    if(strcmp(name,"SunFlower") == 0)
    {
        plant =(Plant *)malloc(sizeof(SunFlower));
        if(plant == NULL)
        {
            return NULL;
        }
        if(CreateSunFlower((SunFlower *)plant) != 0)
        {
            free(plant);
            return NULL;
        }
        return plant;
    }


    return NULL;
}


