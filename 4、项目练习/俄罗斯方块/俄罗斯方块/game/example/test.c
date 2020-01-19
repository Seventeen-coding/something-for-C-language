
#include "game.h"
#include "util/log_util.h"
int main(int argc, char *argv[])
{
    int ret = 0;
    GAME_CONFIG_T *config = f_Create_Game_Config();
    GAME_T *game = f_Create_Game(config);

    ret = game->run(game);
    log_info("ret %d \n", ret);
    return 0;
}
