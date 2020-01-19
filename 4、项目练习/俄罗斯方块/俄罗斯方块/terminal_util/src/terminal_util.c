#include "terminal_util.h"

void gotoXY(int x, int y)
{
    //Initialize the coordinates
    COORD coord = {x, y};
    //Set the position
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void HideTheCursor()
{
    CONSOLE_CURSOR_INFO cciCursor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    if (GetConsoleCursorInfo(hStdOut, &cciCursor))
    {
        cciCursor.bVisible = FALSE;
        SetConsoleCursorInfo(hStdOut, &cciCursor);
    }
}

//This will clear the console while setting the forground and
//background colors.
void ClearConsoleToColors(int ForgC, int BackC)
{
    WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
    //Get the handle to the current output buffer...
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    //This is used to reset the carat/cursor to the top left.
    COORD coord = {0, 0};
    //A return value... indicating how many chars were written
    //not used but we need to capture this since it will be
    //written anyway (passing NULL causes an access violation).
    DWORD count;

    //This is a structure containing all of the console info
    // it is used here to find the size of the console.
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    //Here we will set the current color
    SetConsoleTextAttribute(hStdOut, wColor);
    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        //This fills the buffer with a given character (in this case 32=space).
        FillConsoleOutputCharacter(hStdOut, (TCHAR)32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);

        FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
        //This will set our cursor position for the next print statement.
        SetConsoleCursorPosition(hStdOut, coord);
    }
}

//This will clear the console.
void ClearConsole()
{
    //Get the handle to the current output buffer...
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    //This is used to reset the carat/cursor to the top left.
    COORD coord = {0, 0};
    //A return value... indicating how many chars were written
    //   not used but we need to capture this since it will be
    //   written anyway (passing NULL causes an access violation).
    DWORD count;
    //This is a structure containing all of the console info
    // it is used here to find the size of the console.
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    //Here we will set the current color
    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        //This fills the buffer with a given character (in this case 32=space).
        FillConsoleOutputCharacter(hStdOut, (TCHAR)32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
        FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
        //This will set our cursor position for the next print statement.
        SetConsoleCursorPosition(hStdOut, coord);
    }
}

//This will set the forground color for printing in a console window.
void SetColor(int ForgC)
{
    WORD wColor;
    //We will need this handle to get the current background attribute
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    //We use csbi for the wAttributes word.
    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        //Mask out all but the background attribute, and add in the forgournd color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}

//This will set the forground and background color for printing in a console window.
void SetColorAndBackground(int ForgC, int BackC)
{
    WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}

//Direct console output
void ConPrint(char *CharBuffer, int len)
{
    DWORD count;
    WriteConsole(GetStdHandle(STD_OUTPUT_HANDLE), CharBuffer, len, &count, NULL);
}

//Direct Console output at a particular coordinate.
void ConPrintAt(int x, int y, char *CharBuffer, int len)
{
    DWORD count;
    COORD coord = {x, y};
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hStdOut, coord);
    WriteConsole(hStdOut, CharBuffer, len, &count, NULL);
    HideTheCursor();
}

//Shows the console cursor
void ShowTheCursor()
{
    CONSOLE_CURSOR_INFO cciCursor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    if (GetConsoleCursorInfo(hStdOut, &cciCursor))
    {
        cciCursor.bVisible = TRUE;
        SetConsoleCursorInfo(hStdOut, &cciCursor);
    }
}
