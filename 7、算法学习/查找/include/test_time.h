
#ifndef _TEST_TIME_H_
#define _TEST_TIME_H_

#if defined(WIN32) || defined(_WIN64)
#include <windows.h>
#include <stdio.h>

#define TEST_TIME(x)                             \
    {                                            \
        DWORD start, stop;                       \
        start = GetTickCount();                  \
        x;                                       \
        stop = GetTickCount();                   \
        printf("time: %lld ms\n", stop - start); \
    }

#elif defined(UNIX) || defined(LINUX)
#include <stream.h>
#include <sys/time.h>
#include <sys/file.h>
#endif

#endif //_TEST_TIME_H_