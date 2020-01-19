#include "game_config.h"
#include <stdio.h>

GAME_CONFIG_T *f_Create_Game_Config(void)
{
    GAME_CONFIG_T *config = malloc(sizeof(GAME_CONFIG_T));
    if (config == NULL)
    {
        return NULL;
    }
    return config;
}
int f_Create_Game_Config_ex(GAME_CONFIG_T *config)
{

    return 0;
}