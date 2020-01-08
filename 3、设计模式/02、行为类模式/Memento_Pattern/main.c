
#include "memento.h"

void run();

int main(void)
{
    run();
    return 0;
}

//test
void run()
{
    GAME_T *game = f_Create_Game();
    //playing
    game->setdata(game, 1);
    game->save(game);
    game->setdata(game, 2);
    game->save(game);
    game->setdata(game, 3);
    game->save(game);
    game->setdata(game, 4);
    game->save(game);
    game->setdata(game, 5);
    game->save(game);

    int index = 3;
    game->load(game, index);
    printf("data %d \n", game->data);
    index = 0;
    game->load(game, index);
    printf("data %d \n", game->data);
}
