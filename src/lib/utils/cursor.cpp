#include "cursor.h"
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

void moveCursorTop()
{
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE) return;

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) return;

    COORD topLeft = { 0, 0 };
    SetConsoleCursorPosition(hConsole, topLeft);
#else
    std::cout << "\033[H";
#endif
}

void hideCursor()
{
    #ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE) return;

    CONSOLE_CURSOR_INFO info;
    if (GetConsoleCursorInfo(hConsole, &info)) {
        info.bVisible = FALSE;
        SetConsoleCursorInfo(hConsole, &info);
    }
#else
    std::cout << "\033[?25l" << std::flush;
#endif
}

void showCursor()
{
    #ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE) return;

    CONSOLE_CURSOR_INFO info;
    if (GetConsoleCursorInfo(hConsole, &info)) {
        info.bVisible = TRUE;
        SetConsoleCursorInfo(hConsole, &info);
    }
#else
    std::cout << "\033[?25h" << std::flush;
#endif
}
