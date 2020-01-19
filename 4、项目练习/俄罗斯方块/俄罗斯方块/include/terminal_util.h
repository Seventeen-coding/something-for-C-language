#ifndef _TERMINAL_UTIL_H_
#define _TERMINAL_UTIL_H_
#include <stdio.h>
#include <windows.h>
#include <conio.h> //引用

void ConPrint(char *CharBuffer, int len);
void ConPrintAt(int x, int y, char *CharBuffer, int len);
void ClearConsole(void);
void ClearConsoleToColors(int ForgC, int BackC);
void SetColorAndBackground(int ForgC, int BackC);
void SetColor(int ForgC);
void ShowTheCursor(void);
//隐藏光标
void HideTheCursor();
//移动光标到指定位置
void gotoXY(int x, int y);

#endif // _TERMINAL_UTIL_H_
