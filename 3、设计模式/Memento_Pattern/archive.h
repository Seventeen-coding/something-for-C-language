#ifndef ARCHIVE_H
#define ARCHIVE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int *(*getdata_func)(void *this_archive);

typedef struct {
    int data;   //->想象成一个对象
    getdata_func get;
}Archive;

Archive *Create_archive( int data);

#endif // ARCHIVE_H
