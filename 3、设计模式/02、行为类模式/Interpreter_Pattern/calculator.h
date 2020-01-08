#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

/*1、头文件*/

/*2、宏定义
#define CALCULATOR	XXXXXX
*/

/*3、结构体声明
typedef struct{
	int  xxx_xxx;
	char *xxx_xxx;
}CALCULATOR_T;
*/
typedef struct _CALCULATOR_T
{
	int (*result)(const char *str, int *interpret_result);
} CALCULATOR_T;
/*4、函数和变量声明
int Template(CALCULATOR_T xxx_xxx );
*/
CALCULATOR_T *f_Get_Calculator_Instance(void);
#endif //__CALCULATOR_H__