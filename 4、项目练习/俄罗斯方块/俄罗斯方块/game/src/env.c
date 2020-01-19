
#include "env.h"

void env_config()
{
    int x=(GetSystemMetrics(SM_CXSCREEN)-1000),y=GetSystemMetrics(SM_CYSCREEN);
    system("title 【俄罗斯方块】V1.0");
    system("mode con:cols=100 lines=30");
    //MoveWindow(GetForegroundWindow(),x/2,(y/5),x,y,1);
    system("cls");
    HideTheCursor();
}

