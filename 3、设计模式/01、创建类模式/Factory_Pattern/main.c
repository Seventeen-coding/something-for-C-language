
/*
	这里可以写相关文件描述 协议等等信息
	如：
	按照C语言的语法 规范编程
	一个良好的书写规范决定一个程序的好坏
	源代码不仅仅给自己看有可能给别人看
*/

/*1、头文件*/
#include "main.h"

/*2、宏定义
#define TEMPLATE	XXXXXX
*/

/*3、结构体声明
typedef struct{
	int  xxx_xxx;
	char *xxx_xxx;
}TEMPLATE_T;
*/

/*4、函数和变量声明
int Template(TEMPLATE_T xxx_xxx );
*/
void f_Run(void);
void f_Before(void); //优化前
void f_After(void);  //优化后
/*5、函数实现区
int Template(TEMPLATE_T xxx_xxx )
{
	return 0;
}
*/

int main(void)
{
    f_Run();
    return 0;
}

void f_Run(void)
{
    f_Before();
    f_After();
}

void f_Before(void)
{
    log_info("before optimize\n");
    DUCK_T *duck = NULL;
    ANIMAL_T *animal = NULL;
    duck = f_Create_Duck("duck");
    if (duck == NULL)
        return;
    animal = &duck->animal;
    printf("name : %s\n", animal->name);
    animal->f_jump(animal);
    animal->f_fly(animal);
    animal->f_swim(animal);

}
void f_After(void)
{
    log_info("after optimize\n");
    AnimalFactory Factory;
    if (CreateAnimalFactory(&Factory) != 0)
    {
        return;
    }
    char animal_name[][10] = {"Cat", "Bird", "Duck", "mouse", "horse", "Dog"};
    log_info("animal_name count : %d \n", sizeof(animal_name) / (sizeof(char) * 10));
    for (int i = 0; i < sizeof(animal_name) / (sizeof(char) * 10); i++)
    {
        ANIMAL_T *animal;
        animal = (ANIMAL_T *)Factory.getAnimal(animal_name[i]);
        if (animal == NULL)
        {
            log_error("can not create %s\n", animal_name[i]);
            continue;
        }
        printf("name : %s\n", animal->name);
        animal->f_jump(animal);
        animal->f_fly(animal);
        animal->f_swim(animal);
        free(animal);
    }
}
