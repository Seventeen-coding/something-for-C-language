#include "bird.h"

static void f_fly_func(ANIMAL_T *this);

BIRD_T *f_Create_Bird(const char *name)
{
    int ret = 0;
    BIRD_T *bird = (BIRD_T *)malloc(sizeof(BIRD_T));
    if (bird == NULL)
    {
        return NULL;
    }
    ret = f_Create_Bird_ex(bird, name);
    if (ret != 0)
    {
        free(bird);
        return NULL;
    }


    return bird;
}
int f_Create_Bird_ex(BIRD_T *bird, const char *name)
{
    int ret = 0;
    if (bird == NULL)
    {
        return -1;
    }

    memset(bird, 0, sizeof(BIRD_T));
    ANIMAL_T *animal = &bird->animal;
    ret = f_Create_Animal_ex(animal, name);
    if (ret != 0)
    {
        return -2;
    }

    animal->f_fly = f_fly_func;
    strcpy(animal->name, "Bird");

    return 0;
}

static void f_fly_func(ANIMAL_T *this)
{
    printf("%s : Bird fly \n", __FILE__);
}
