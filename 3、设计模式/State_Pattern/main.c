
#include "state_pattern.h"

int main(void)
{
    run();
    return 0;
}

//notice:取代if 或者 switch
//概念： this state to do something
// this room state to do XXX
void run()
{
    Room *room = CreatRoom();
    room->bookRoom(room);
    room->unsubscribeRoom(room);
    room->checkInRoom(room);
    room->checkOutRoom(room);
    room->checkOutRoom(room);
    room->checkInRoom(room);
    room->unsubscribeRoom(room);
    room->bookRoom(room);
}
