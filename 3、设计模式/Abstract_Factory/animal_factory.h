#ifndef ANIMAL_FACTORY_H
#define ANIMAL_FACTORY_H


#include "cat.h"
#include "bird.h"
#include "duck.h"

#include "abstract_factory.h"

typedef struct _AnimalFactory
{
    getAnimal_func getAnimal;
}AnimalFactory;

int CreateAnimalFactory(AnimalFactory *factory);




#endif // ANIMAL_FACTORY_H
