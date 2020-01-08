#ifndef PROXY_IMAGE_H
#define PROXY_IMAGE_H

#include "image.h"


typedef struct _proxy_image{
    Image *image;
    const char file_path[MAX_LEN];
    display_func display;
}Proxy_Image;

Proxy_Image *CreateProxy_Image(const char * file_path);

#endif // PROXY_IMAGE_H
