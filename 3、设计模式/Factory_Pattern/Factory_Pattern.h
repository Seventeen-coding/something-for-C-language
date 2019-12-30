
#ifndef _FACTORY_PATTERN_H_
#define _FACTORY_PATTERN_H_


#include "cat.h"
#include "bird.h"
#include "duck.h"

typedef   Animal *(* getAnimal_func)(const char *name);


typedef struct _AnimalFactory
{
    getAnimal_func getAnimal;
}AnimalFactory;

int CreateAnimalFactory(AnimalFactory *Factory);

void run();


#endif //_FACTORY_PATTERN_H_
