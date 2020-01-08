
#include "state_pattern.h"

void run();
int main(void)
{
    run();
    return 0;
}

void run()
{
    ROOM_T *room = CreatRoom();
    room->bookRoom(room);
    room->unsubscribeRoom(room);
    room->checkInRoom(room);
    room->checkOutRoom(room);
    room->checkOutRoom(room);
    room->checkInRoom(room);
    room->unsubscribeRoom(room);
    room->bookRoom(room);
}
