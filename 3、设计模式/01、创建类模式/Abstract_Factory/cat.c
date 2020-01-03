#include "cat.h"

static void f_jump_func(ANIMAL_T *this);

CAT_T *f_Create_Cat(const char *name)
{
    int ret = 0;
    CAT_T *cat = (CAT_T *)malloc(sizeof(CAT_T));
    if (cat == NULL)
    {
        return NULL;
    }
    ret = f_Create_Cat_ex(cat, name);
    if (ret != 0)
    {
        free(cat);
        return NULL;
    }
    return cat;
}

int f_Create_Cat_ex(CAT_T *cat, const char *name)
{
    int ret = 0;
    if (cat == NULL)
    {
        return -1;
    }

    memset(cat, 0, sizeof(CAT_T));
    ANIMAL_T *animal = (ANIMAL_T *)&cat->animal;
    ret = f_Create_Animal_ex(animal, name);
    if (ret != 0)
    {
        return -2;
    }
    animal->f_jump = f_jump_func;
    strcpy(animal->name, "Cat");

    return 0;
}
static void f_jump_func(ANIMAL_T *this)
{
    printf("%s : cat jump \n", __FILE__);
}
