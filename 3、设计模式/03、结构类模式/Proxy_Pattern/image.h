#ifndef IMAGE_H
#define IMAGE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*display_func)(void *this_image);
typedef void (*load_func)(void *this_image,const char *file_path);

#define MAX_LEN 256

typedef struct _Image{
    const char file_path[MAX_LEN];
    void * info; // -> 还有别的信息
    display_func display;
    load_func  load;
}Image;

Image *CreateImage(const char * file_path);

#endif // IMAGE_H
