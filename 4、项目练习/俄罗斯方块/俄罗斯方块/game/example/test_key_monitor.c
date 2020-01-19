#include "game_util.h"
#include <stdio.h>
#include <stdlib.h>
int callback(char key);

GAME_UTIL_T *game_util = NULL;
int main(void)
{
    game_util = f_Create_Game_Util();
    if (game_util == NULL)
    {
        return -1;
    }
    game_util->run_key_monitor(game_util, callback);
    Sleep(1);
    game_util->run_key_monitor(game_util, callback);
    Sleep(1);
    game_util->run_key_monitor(game_util, callback);
    while (1)
        ;
    return 0;
}
int callback(char key)
{
    printf("%c \n", key);
    if (key == 'q')
    {
        return -1;
    }
    return 0;
}