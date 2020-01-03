#include "duck.h"

static void f_swim_func(ANIMAL_T *this);

DUCK_T *f_Create_Duck(const char *name)
{
    int ret = 0;
    DUCK_T *duck = (DUCK_T *)malloc(sizeof(DUCK_T));
    if (duck == NULL)
    {
        return NULL;
    }
    ret = f_Create_Duck_ex(duck, name);
    if (ret != 0)
    {
        free(duck);
        return NULL;
    }

    return duck;
}
int f_Create_Duck_ex(DUCK_T *duck, const char *name)
{
    int ret = 0;
    if (duck == NULL)
    {
        return -1;
    }

    memset(duck, 0, sizeof(DUCK_T));
    ANIMAL_T *animal = &duck->animal;
    ret = f_Create_ANIMAL_T_ex(animal, name);
    if (ret != 0)
    {
        return -2;
    }
    animal->f_swim = f_swim_func;
    strcpy(animal->name, "Duck");

    return 0;
}
static void f_swim_func(ANIMAL_T *this)
{
    //printf("%s : %s swim \n",__FILE__,this_duck->animal.name);
    printf("%s : %s swim \n", __FILE__, this->name);
}
