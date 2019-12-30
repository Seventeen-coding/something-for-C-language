#include "game.h"

static int _save_func(Game *this_game);
static int _load_func(Game *this_game, int index);

static int _add_archive_func(Archive *this_archive_list[10],Archive *arch);
static Archive *_get_archive_func(Archive *this_archive_list[10],int index);

static int _setdata_func(Game *this_game,int data);

Game *Create_Game()
{
    Game *game = (Game *)malloc(sizeof(Game));
    if(game == NULL)
    {
        return NULL;
    }
    memset(game , 0 , sizeof(Game));
    do{
        game->save = _save_func;
        game->load = _load_func;
        game->add_archive = _add_archive_func;
        game->get_archive = _get_archive_func;

        game->setdata = _setdata_func;
        return game;
    }while(0);
    free(game);
    return NULL;
}

static int _save_func(Game *this_game)
{
    if(this_game == NULL)
    {
        return -1;
    }
    Archive *archive = Create_archive(this_game->data);
    return _add_archive_func(this_game->archive_list,archive);
}

static int _load_func(Game *this_game,int index)
{
    if(this_game == NULL)
    {
        return -1;
    }
    if(this_game->archive_list[index] == NULL)
    {
        return -2;
    }
    return _setdata_func(this_game,this_game->archive_list[index]->data);
}

static int _add_archive_func(Archive *this_archive_list[10],Archive *arch)
{
    if(this_archive_list == NULL)
    {
        return -1;
    }
    int i ;
    for(i = 0 ;i < 10 ; i++)
    {
        if(this_archive_list[i] == NULL)
        {
            this_archive_list[i] = arch;
            return 0;
        }
        else if( this_archive_list[i] ==  arch )
        {
            return -3;
        }
    }
    return -2;
}

static Archive *_get_archive_func(Archive *this_archive_list[10],int index)
{
    if(this_archive_list == NULL || index > 10 || index < 0)
    {
        return NULL;
    }
    return this_archive_list[index];
}

static int _setdata_func(Game *this_game,int data)
{
    if(this_game == NULL)
    {
        return -1;
    }
    this_game->data = data;
    return 0;
}
