
#include "factoryproducer.h"
#include <stdio.h>


void run();

int main(void)
{
    run();
    return 0;
}

//test
void run()
{
    Abstract_Factory *factory;
    factory = getFactory("Animal");
    if(factory == NULL )
    {
        return ;
    }
    Animal *animal;

    animal = (Animal *)factory->getAnimal("Cat");
    printf("name : %s\n",animal->name);
    animal->jump(animal);
    animal->fly(animal);
    animal->swim(animal);
    free(animal);

    animal = (Animal *)factory->getAnimal("Bird");
    printf("name : %s\n",animal->name);
    animal->jump(animal);
    animal->fly(animal);
    animal->swim(animal);
    free(animal);

    animal = (Animal *)factory->getAnimal("Duck");
    printf("name : %s\n",animal->name);
    animal->jump(animal);
    animal->fly(animal);
    animal->swim(animal);
    free(animal);

    free (factory);

    factory = getFactory("Plant");
    if(factory == NULL )
    {
        return ;
    }

    Plant *plant;

    plant = (Plant *)factory->getPlant("Pea");
    if(plant == NULL )
    {
        return ;
    }
    printf("name : %s\n",plant->name);
    plant->pf_pea(plant);
    plant->pf_flower(plant);
    free(plant);


    plant = (Plant *)factory->getPlant("SunFlower");
    if(plant == NULL )
    {
        return ;
    }
    printf("name : %s\n",plant->name);
    plant->pf_pea(plant);
    plant->pf_flower(plant);
    free(plant);

    free (factory);
}
