#ifndef MEDIA_PALYER_H
#define MEDIA_PALYER_H

#include "play_format.h"
#include <stdlib.h>
#include <string.h>
typedef enum _media_type{
    AVI,
    MKV,
    MP4,
    MP3,
    WMA,
    UNKNOW
}media_type;

typedef void (*play_func)(const char *path);

typedef struct _media_interface{
    play_func   play;
    //不单单播放 还有别的
    void   *    func3;
    void   *    func4;
    void   *    func5;
}Media_Interface;


Media_Interface *get_media_interface();

#endif // MEDIA_PALYER_H
