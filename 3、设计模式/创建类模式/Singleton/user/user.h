#ifndef __USER_H__
#define __USER_H__

/*1、头文件*/
#include <stdio.h>
#include <string.h>

/*2、宏定义
#define USER	XXXXXX
*/

#ifndef MAX_LEN
#define MAX_LEN 256
#endif

/*3、结构体声明
typedef struct{
	int  xxx_xxx;
	char *xxx_xxx;
}USER_T;
*/

typedef struct _User
{
    char name[MAX_LEN];
    unsigned char age;
    char phone[MAX_LEN];
    char address[MAX_LEN];
    void (*fp_print_name)(struct _User *this);
    void (*fp_print_age)(struct _User *this);
    void (*fp_print_phone)(struct _User *this);
    void (*fp_print_address)(struct _User *this);
    void (*fp_about)(struct _User *this);
} USER_T;

/*4、函数和变量声明
int f_USER(USER_T xxx_xxx );
*/

USER_T* f_Create_User( const char *name, unsigned char age, const char *phone, const char *address);
int f_Create_User_ex(USER_T *user, const char *name, unsigned char age, const char *phone, const char *address);

#endif //__USER_H__
