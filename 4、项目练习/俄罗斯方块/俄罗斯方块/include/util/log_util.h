#ifndef __LOG_UTIL_H__
#define __LOG_UTIL_H__

/*1、头文件*/
#include <stdio.h>

/*2、宏定义*/
#define LOG_ENABLE
#define BREAKPOINT_ENABLE

#define PRINT_TAG(x) printf("%s:[ %s: %s : %d ]", x, __FILE__, __FUNCTION__, __LINE__)

#ifndef LOG_ENABLE
#define INFO_TAG "INFO"
#define WARN_TAG "WARN"
#define ERROR_TAG "ERROR"
#define log_info(...)
#define log_warn(...)
#define log_error(...)
#else
//   1      2      4
// INFO | WARN | ERROR
#define ERROR_DEBUG 4
#define WARN_DEBUG 2
#define INFO_DEBUG 1
#define DEBUG_LEVEL (ERROR_DEBUG | WARN_DEBUG | INFO_DEBUG)

#define INFO_TAG "INFO"
#define WARN_TAG "WARN"
#define ERROR_TAG "ERROR"

#define log_info(...)                      \
    do                                     \
    {                                      \
        if (DEBUG_LEVEL & INFO_DEBUG == 0) \
        {                                  \
            break;                         \
        }                                  \
        PRINT_TAG(INFO_TAG);               \
        printf(__VA_ARGS__);               \
    } while (0)

#define log_warn(...)                      \
    do                                     \
    {                                      \
        if (DEBUG_LEVEL & WARN_DEBUG == 0) \
        {                                  \
            break;                         \
        }                                  \
        PRINT_TAG(WARN_TAG);               \
        printf(__VA_ARGS__);               \
    } while (0)

#define log_error(...)                      \
    do                                      \
    {                                       \
        if (DEBUG_LEVEL & ERROR_DEBUG == 0) \
        {                                   \
            break;                          \
        }                                   \
        PRINT_TAG(ERROR_TAG);               \
        printf(__VA_ARGS__);                \
    } while (0)
#endif //LOG_ENABLE

#ifndef BREAKPOINT_ENABLE
#define BREAKPOINT_TAG
#define break_point(...)
#else
#define BREAKPOINT_TAG "break point"
#define break_point(...)           \
    do                             \
    {                              \
        PRINT_TAG(BREAKPOINT_TAG); \
        printf(__VA_ARGS__);       \
        printf("\n");              \
    } while (0)
#endif //BREAKPOINT_ENABLE

/*
	3、结构体声明
*/
/*
	4、函数和变量声明
*/
#endif //__LOG_UTIL_H__
