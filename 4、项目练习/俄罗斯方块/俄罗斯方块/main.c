
#include "game.h"
#include "util/log_util.h"
int main(int argc, char *argv[])
{
    int ret = 0;

    GAME_T *game = Get_Game();

    ret = game->run(game);
    while (1)
    {
    }
    return 0;
}
