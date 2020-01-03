#ifndef __HEADER_H__
#define __HEADER_H__

#include <string.h>

#define HELLOWORLD "helloworld"
#define INFO_TAG "INFO"
#define WARN_TAG "WARN"
#define ERROR_TAG "ERROR"

#define log_info(fmt, ...)                                                              \
    do                                                                                  \
    {                                                                                   \
        printf("%s:[%s:%s:%d]\n" fmt, INFO_TAG, __FILE__, __FUNCTION__, ##__VA_ARGS__); \
    } while (0)
#define log_warn(fmt, ...)                                                              \
    do                                                                                  \
    {                                                                                   \
        printf("%s:[%s:%s:%d]\n" fmt, WARN_TAG, __FILE__, __FUNCTION__, ##__VA_ARGS__); \
    } while (0)
#define log_error(fmt, ...)                                                              \
    do                                                                                   \
    {                                                                                    \
        printf("%s:[%s:%s:%d]\n" fmt, ERROR_TAG, __FUNCTION__, __LINE__, ##__VA_ARGS__); \
    } while (0)

typedef struct
{
    int i;
    char c;
    double d;
    float f;
} MY_STRUCT_T;

#endif //__HEADER_H__