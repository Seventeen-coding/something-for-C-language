
#include "Factory_Pattern.h"

static Animal *_getAnimal(const char *name);

int CreateAnimalFactory(AnimalFactory *Factory)
{
    if(Factory == NULL)
    {
        return -1;
    }
    Factory->getAnimal =_getAnimal;

    return 0;
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


