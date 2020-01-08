#include "media.h"
#include "play_mp4.h"

//由于MP3就是play_func类型所以不需要适配器
static int play_mp3(Media *this_media, decode_type type, const char *path);
//专门针对mp4种类型作转换
static int play_adapter_mp4(Media *this_media, decode_type type, const char *path);


int CreatMedia(Media *media,decode_type type)
{
    if(media == NULL)
    {
        return -1;
    }

    switch(type)
    {
    case MP3:
        media->play = (play_func)play_mp3;
        break;
    case MP4:
        //由于类型不对 无法匹配
        //media->play = play_mp4;
        media->play = (play_func)play_adapter_mp4;
        break;
    default:
        printf("unknow type \n");
        return -1;
    }
    return 0;
}


static int play_mp3(Media *this_media, decode_type type, const char *path)
{
    if(this_media == NULL || type != MP3 || path == NULL)
    {
        return -1;
    }
    printf("play %s \n",path);
    return 0;
}


static int play_adapter_mp4(Media *this_media, decode_type type, const char *path)
{
    if(this_media == NULL || type != MP4 || path == NULL)
    {
        return -1;
    }
    play_mp4(path);
    return 0;
}


