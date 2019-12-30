
#include "flyweight.h"
#include <stdio.h>

void run();

//共享
int main(void)
{
    run();
    return 0;
}

//test
void run()
{
    Media_Player * player1;
    player1 = create_media_player(createtheme("skin1","font1"));
    Media_Player * player2;
    player2 = create_media_player(createtheme("skin2","font2"));
    Media_Player * player3;
    player3 = create_media_player(createtheme("skin3","font3"));
    if(player1 == NULL || player2 == NULL || player3 == NULL)
    {
        return ;
    }
    player1->media_interface->about(player1);
    player2->media_interface->about(player2);
    player3->media_interface->about(player3);

    player1->media_interface->play(player1,"helloworld.avi");
    player2->media_interface->play(player2,"helloworld.mkv");
    player3->media_interface->play(player3,"helloworld.mp4");
}
