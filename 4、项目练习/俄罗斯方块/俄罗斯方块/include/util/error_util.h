#ifndef __ERROR_H__
#define __ERROR_H__

/*1、头文件*/
#include "log_util.h"
#include <string.h>

/*2、宏定义
#define ERROR	XXXXXX
*/

#define ERROR_CHECK_ENABLE
#ifndef ERROR_CHECK_ENABLE

#else
#define RETURN_ERROR (RETURN_ERROR_EX(function,value))
#define RETURN_ERROR_EX(error,value)	do{if(strcmp(__FUNCTION__,error_function_str))__LINE__-__LINE__}while(0)

#endif

/*
	3、结构体声明
*/

/*
	4、函数和变量声明
*/
extern char error_function_str[256] = {0};

#endif //__ERROR_H__
