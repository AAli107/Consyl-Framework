#include "console.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <iostream>
#endif

void setConsoleTitle(const char* title)
{
    #ifdef _WIN32
        SetConsoleTitleA(title);
    #else
        std::cout << "\033]0;" << title << "\007";
    #endif
}