#ifndef MEDIA_H
#define MEDIA_H

#include <stdio.h>

typedef enum {
    MP3,
    MP4,           //新增支持
    MKV,            //不支持
    MAX_COUNT
}decode_type;

typedef int (*play_func)(void *this_media,decode_type type,const char *path);

typedef struct _Media{
    play_func play;
}Media;

int CreatMedia(Media *media,decode_type type);

#endif // MEDIA_H
