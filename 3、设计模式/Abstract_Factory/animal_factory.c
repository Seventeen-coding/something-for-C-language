#include "animal_factory.h"

static Animal *_getAnimal(const char *name);

int CreateAnimalFactory(AnimalFactory *factory)
{
    if(factory == NULL)
    {
        return -1;
    }
    memset(factory , 0, sizeof(AnimalFactory));
    do
    {
        Abstract_Factory *abstract_factory =( Abstract_Factory  *) factory;
        if(CreateAbstractFactory(abstract_factory) != 0)
        {
            break;
        }
        abstract_factory->getAnimal =(getAnimal_func) _getAnimal;

        return 0;
    }while(0);

    return -1;
}


static Animal *_getAnimal(const char *name)
{
    Animal *animal;

    if(strcmp(name,"Cat") == 0)
    {
        animal =(Animal *)malloc(sizeof(Cat));
        if(animal == NULL)
        {
            return NULL;
        }
        if(CreateCat((Cat *)animal) != 0)
        {
            free(animal);
            return NULL;
        }
        return animal;
    }

    if(strcmp(name,"Duck") == 0)
    {
        animal =(Animal *)malloc(sizeof(Duck));
        if(animal == NULL)
        {
            return NULL;
        }
        if(CreateDuck((Duck *)animal) != 0)
        {
            free(animal);
            return NULL;
        }
        return animal;
    }


    if(strcmp(name,"Bird") == 0)
    {
        animal =(Animal *)malloc(sizeof(Bird));
        if(animal == NULL)
        {
            return NULL;
        }
        if(CreateBird((Bird *)animal) != 0)
        {
            free(animal);
            return NULL;
        }
        return animal;
    }


    return NULL;
}


