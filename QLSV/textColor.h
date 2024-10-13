#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

#ifndef TEXTCOLOR_H_INCLUDED
#define TEXTCOLOR_H_INCLUDED

void set_color(const char *color)
{
    char cmd[512];
    sprintf(cmd, "echo|set /p=\"\e[%sm\"", color);
    system(cmd);
}

void set_color_sc(int code)
{
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, code);
}

// a background && b characters
// int X = a * 16 + b;
// 0 = Black       8 = Gray
// 1 = Blue        9 = Light Blue
// 2 = Green       10 A = Light Green
// 3 = Aqua        11 B = Light Aqua
// 4 = Red         12 C = Light Red
// 5 = Purple      13 D = Light Purple
// 6 = Yellow      14 E = Light Yellow
// 7 = White       15 F = Bright White

#endif // TEXTCOLOR_H_INCLUDED

// set_color_sc(9);
// set_color("01;31");