#include "game.h"

static int _save_func(GAME_T *this_game);
static int _load_func(GAME_T *this_game, int index);

static int _add_archive_func(ARCHIVE_T *this_archive_list[10], ARCHIVE_T *arch);
static ARCHIVE_T *_get_archive_func(ARCHIVE_T *this_archive_list[10], int index);

static int _setdata_func(GAME_T *this_game, int data);

GAME_T *f_Create_Game(void)
{
    GAME_T *game = (GAME_T *)malloc(sizeof(GAME_T));
    if (game == NULL)
    {
        return NULL;
    }
    memset(game, 0, sizeof(GAME_T));
    do
    {
        game->save = _save_func;
        game->load = _load_func;
        game->add_archive = _add_archive_func;
        game->get_archive = _get_archive_func;

        game->setdata = _setdata_func;
        return game;
    } while (0);
    free(game);
    return NULL;
}

static int _save_func(GAME_T *this_game)
{
    if (this_game == NULL)
    {
        return -1;
    }
    ARCHIVE_T *archive = f_Create_Archive(this_game->data);
    return _add_archive_func(this_game->archive_list, archive);
}

static int _load_func(GAME_T *this_game, int index)
{
    if (this_game == NULL)
    {
        return -1;
    }
    if (this_game->archive_list[index] == NULL)
    {
        return -2;
    }
    return _setdata_func(this_game, this_game->archive_list[index]->data);
}

static int _add_archive_func(ARCHIVE_T *this_archive_list[10], ARCHIVE_T *arch)
{
    if (this_archive_list == NULL)
    {
        return -1;
    }
    int i;
    for (i = 0; i < 10; i++)
    {
        if (this_archive_list[i] == NULL)
        {
            this_archive_list[i] = arch;
            return 0;
        }
        else if (this_archive_list[i] == arch)
        {
            return -3;
        }
    }
    return -2;
}

static ARCHIVE_T *_get_archive_func(ARCHIVE_T *this_archive_list[10], int index)
{
    if (this_archive_list == NULL || index > 10 || index < 0)
    {
        return NULL;
    }
    return this_archive_list[index];
}

static int _setdata_func(GAME_T *this_game, int data)
{
    if (this_game == NULL)
    {
        return -1;
    }
    this_game->data = data;
    return 0;
}
