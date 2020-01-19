#ifndef GAME_DEBUG_H
#define GAME_DEBUG_H

/*
        这部分相当重要  在运行时我们调试可以用gdb 等调试工具
        设计这个调试模式主要是为了让几个开发人员协调调试
        显示有用的信息，由于对于别人模块程序可能会陌生
        一个调试模式的好坏几乎可以影响整个程序开发的进度
*/
#include <stdio.h>

#define  GAME_BASE_DEBUG(...)  printf(__VA_ARGS__)
#define  GAME_MAP(...) GAME_BASE_DEBUG("<"GMAE_MAP_HEAD" >"__VA_ARGS__)

#endif // GAME_DEBUG_H

