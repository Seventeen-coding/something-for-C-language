
#include "game.h"
#include "terminal_util.h"
#include "util/log_util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int f_load(GAME_T *this, GAME_CONFIG_T *config, GAME_BACKGROUND_T *background);
// static int
static int f_run(GAME_T *this);
static int f_stop(GAME_T *this);
static int f_exit(GAME_T *this);
static int key_callback(char arg);
static GAME_T *f_Create_Game(GAME_CONFIG_T *config, GAME_BACKGROUND_T *background);
static int f_Create_Game_ex(GAME_T *game, GAME_CONFIG_T *config, GAME_BACKGROUND_T *background);

GAME_T *Get_Game(void)
{
    static GAME_T *game = NULL;
    if (game != NULL)
    {
        return game;
    }
    GAME_CONFIG_T *config = f_Create_Game_Config();
    
    GAME_BACKGROUND_T *backgrund = f_Create_Game_Background();
    
    game = f_Create_Game(config, backgrund);

    if (game == NULL)
    {
        return NULL;
    }
    return game;
}

static GAME_T *f_Create_Game(GAME_CONFIG_T *config, GAME_BACKGROUND_T *background)
{
    GAME_T *game = (GAME_T *)malloc(sizeof(GAME_T));
    if (game == NULL)
    {
        return NULL;
    }
    memset(game, 0, sizeof(GAME_T));
    if (f_Create_Game_ex(game, config, background) != 0)
    {
        free(game);
        return NULL;
    }
    return game;
}
static int f_Create_Game_ex(GAME_T *game, GAME_CONFIG_T *config, GAME_BACKGROUND_T *background)
{
    if (game == NULL || config == NULL || background == NULL)
    {
        return -1;
    }

    game->config = config;
    game->run = f_run;
    game->stop = f_stop;
    game->load = f_load;
    game->exit = f_exit;

    game->load(game, config, background);
    game->focus = &background->window;
    return 0;
}

static int f_load(GAME_T *this, GAME_CONFIG_T *config, GAME_BACKGROUND_T *background)
{
    this->config = config;
    this->background = background;

    this->game_util = Get_Game_Util();

    this->game_util->register_key_callback(this->game_util, key_callback);

    return 0;
}
static int f_run(GAME_T *this)
{
    HideTheCursor();
    ClearConsoleToColors(FOREGROUND_RED | FOREGROUND_GREEN, FOREGROUND_BLUE);
    ClearConsole();
    SetColorAndBackground(FOREGROUND_RED | FOREGROUND_GREEN, FOREGROUND_BLUE);
    
    GAME_BACKGROUND_T *background = this->background;
    if (this->background == NULL)
    {
        return -1;
    }

    TERMINAL_WINDOW_T *window = &background->window;
    window->show(window);
    return 0;
}
static int f_stop(GAME_T *this)
{
    return 0;
}
static int f_exit(GAME_T *this)
{
    return 0;
}

static int key_callback(char arg)
{
    // printf("%c", arg);
    GAME_T *game = Get_Game();
    int ret = game->focus->msg(game->focus, arg);
    return ret;
}