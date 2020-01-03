
#include "Factory_Pattern.h"

static ANIMAL_T *_getAnimal(const char *name);

int CreateAnimalFactory(AnimalFactory *Factory)
{
    if (Factory == NULL)
    {
        return -1;
    }
    Factory->getAnimal = _getAnimal;

    return 0;
}

static ANIMAL_T *_getAnimal(const char *name)
{
    if (strcmp(name, "Cat") == 0)
    {
        CAT_T *cat = f_Create_Cat("undefine");
        if (cat == NULL)
        {
            return NULL;
        }
        return &cat->animal;
    }

    if (strcmp(name, "Duck") == 0)
    {
        DUCK_T *duck = f_Create_Duck("undefine");
        if (duck == NULL)
        {
            return NULL;
        }
        return &duck->animal;
    }

    if (strcmp(name, "Bird") == 0)
    {
        BIRD_T *bird = f_Create_Bird("undefine");
        if (bird == NULL)
        {
            return NULL;
        }
        return &bird->animal;
    }

    return NULL;
}
