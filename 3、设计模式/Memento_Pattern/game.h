#ifndef GAME_H
#define GAME_H

#include "archive.h"

typedef int (*save_func)(void *this_game);
typedef int (*load_func)(void *this_game,int index);

typedef int (*add_archive_func)(void *this_archive_list[10],Archive *arch);
typedef Archive *(*get_archive_func)(void *this_archive_list[10],int index);

typedef int (*setdata_func)(void *this_game,int data);

typedef struct {
    //存档模块 list可以成为一个对象
    Archive *archive_list[10];
    add_archive_func add_archive;
    get_archive_func get_archive;

    //游戏模块
    int data;           //->游戏里面一个状态
    setdata_func setdata;
    save_func save;
    load_func load;
}Game;

Game *Create_Game(void);

#endif // GAME_H
