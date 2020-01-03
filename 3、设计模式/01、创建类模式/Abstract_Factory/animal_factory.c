
#include "animal_factory.h"
#include <stdlib.h>

static ANIMAL_T *f_getAnimal(const char *name);
int f_Create_Animal_Factory_ex(ANIMAL_FACTORY_T *animal_factory)
{
    if (animal_factory == NULL)
    {
        return -1;
    }
    ABSTRACT_FACTORY_T *factory = &animal_factory->factory;
    if (f_Create_Abstract_Factory_ex(factory) != 0)
    {
        return -2;
    }
    factory->f_getAnimal = f_getAnimal;
    return 0;
}
ANIMAL_FACTORY_T *f_Create_Animal_Factory(void)
{
    ANIMAL_FACTORY_T *factory = (ANIMAL_FACTORY_T *)malloc(sizeof(ANIMAL_FACTORY_T));
    if (factory == NULL)
    {
        return NULL;
    }
    if (f_Create_Animal_Factory_ex(factory) != 0)
    {
        free(factory);
        return NULL;
    }
    return factory;
}

static ANIMAL_T *f_getAnimal(const char *name)
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
