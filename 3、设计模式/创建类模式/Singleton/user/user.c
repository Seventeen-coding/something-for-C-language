/*
	这里可以写相关文件描述 协议等等信息
	如：
	按照C语言的语法 规范编程
	一个良好的书写规范决定一个程序的好坏
	源代码不仅仅给自己看有可能给别人看
*/

/*1、头文件*/
#include "user.h"
#include <stdlib.h>
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
static void f_print_name(USER_T *this);
static void f_print_age(USER_T *this);
static void f_print_phone(USER_T *this);
static void f_print_address(USER_T *this);
static void f_about(USER_T *this);
/*5、函数实现区
int Template(TEMPLATE_T xxx_xxx )
{
	return 0;
}
*/
USER_T* f_Create_User( const char *name, unsigned char age, const char *phone, const char *address)
{
    int ret = 0;
    USER_T *user = NULL;
    user = (USER_T *)malloc(sizeof(USER_T));
    if (user == NULL)
    {
        return NULL;
    }
    ret = f_Create_User_ex(user, name, age, phone, address);
    if (ret != 0)
    {
        free(user);
        return NULL;
    }

    return user;
}
int f_Create_User_ex(USER_T *this, const char *name, unsigned char age, const char *phone, const char *address)
{
    if (this == NULL)
    {
        return -1;
    }
    this->age = age;
    if (name == NULL)
    {
        return -2;
    }
    strcpy(this->name, name);
    if (phone == NULL)
    {
        return -3;
    }
    strcpy(this->phone, phone);
    if (address == NULL)
    {
        return -4;
    }
    strcpy(this->address, address);

    this->fp_print_address = f_print_address;
    this->fp_print_age = f_print_age;
    this->fp_print_name = f_print_name;
    this->fp_print_phone = f_print_phone;
    this->fp_about = f_about;
    return 0;
}

static void f_print_name(USER_T *this)
{
    printf("USER_T name is %s \n", this->name);
}
static void f_print_age(USER_T *this)
{
    printf("USER_T age is %d \n", this->age);
}
static void f_print_phone(USER_T *this)
{
    printf("USER_T phone is %s \n", this->phone);
}
static void f_print_address(USER_T *this)
{
    printf("USER_T address is %s \n", this->address);
}
static void f_about(USER_T *this)
{
    this->fp_print_name(this);
    this->fp_print_age(this);
    this->fp_print_phone(this);
    this->fp_print_address(this);
}
