#ifndef ARCHIVE_H
#define ARCHIVE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _ARCHIVE_T
{
    int data; //->想象成一个对象
    int *(*get)(struct _ARCHIVE_T *this_archive);
} ARCHIVE_T;

ARCHIVE_T *f_Create_Archive(int data);

#endif // ARCHIVE_H
