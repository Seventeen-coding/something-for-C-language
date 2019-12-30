
#include "Factory_Pattern.h"
#include <stdio.h>


int main(void)
{
    run();
    return 0;
}

//test
void run()
{
    AnimalFactory Factory;
    if(CreateAnimalFactory(&Factory) != 0 )
    {
        return ;
    }
    Animal *animal;

    animal = (Animal *)Factory.getAnimal("Cat");
    printf("name : %s\n",animal->name);
    animal->jump(animal);
    animal->fly(animal);
    animal->swim(animal);
    free(animal);

    animal = (Animal *)Factory.getAnimal("Bird");
    printf("name : %s\n",animal->name);
    animal->jump(animal);
    animal->fly(animal);
    animal->swim(animal);
    free(animal);

    animal = (Animal *)Factory.getAnimal("Duck");
    printf("name : %s\n",animal->name);
    animal->jump(animal);
    animal->fly(animal);
    animal->swim(animal);
    free(animal);
}
