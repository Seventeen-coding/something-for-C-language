
#include "terminal_util.h"

int main(void)
{
    HideTheCursor();
    // ClearConsoleToColors(15, 1);
    // ClearConsole();
    // gotoXY(1, 1);
    // SetColor(14);
    // printf("This is a test...\n");
    // Sleep(5000);
    // ShowTheCursor();
    // SetColorAndBackground(15, 12);
    // ConPrint("This is also a test...\n", 23);
    // SetColorAndBackground(1, 7);
    // ConPrintAt(22, 15, "This is also a test...\n", 23);
    // gotoXY(0, 24);
    // SetColorAndBackground(7, 1);
    ClearConsoleToColors(15, 1);
    ClearConsole();
    char *test = "#";
    int x = 143, y = 43, h = 1, w = 1;
    for (int m = 0; m <= y; m++)
        for (int n = 0; n <= x; n++)
        {
            if (n == 0 || m == 0 || m == y || n == x)
            {
                for (int j = 0; j < w; j++)
                    for (int i = 0; i < h; i++)
                    {
                        ConPrintAt(n + j, m + i, test, strlen(test));
                    }
            }
            // printf(" %d %d ", n, m);
        }
    while (1)
        ;

    return 0;
}