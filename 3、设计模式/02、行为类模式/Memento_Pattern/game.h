#ifndef GAME_H
#define GAME_H

#include "archive.h"

typedef struct _GAME_T
{
    //存档模块 list可以成为一个对象
    ARCHIVE_T *archive_list[10];
    int (*add_archive)(ARCHIVE_T *this_archive_list[10], ARCHIVE_T *arch);
    ARCHIVE_T *(*get_archive)(ARCHIVE_T *this_archive_list[10], int index);

    //游戏模块
    int data; //->游戏里面一个状态
    int (*setdata)(struct _GAME_T *this_game, int data);
    int (*save)(struct _GAME_T *this_game);
    int (*load)(struct _GAME_T *this_game, int index);

} GAME_T;

GAME_T *f_Create_Game(void);

#endif // GAME_H
