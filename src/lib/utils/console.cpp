#include "console.h"

#include <iostream>

#ifdef _WIN32
#include <windows.h>
int enableANSI()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) {
        std::cerr << "Failed to get std output handle.\n";
        return 1;
    }

    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode)) {
        std::cerr << "Failed to get the current console mode.\n";
        return 1;
    }

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(hOut, dwMode)) {
        std::cerr << "Failed to set console mode.\n";
        return 1;
    }

    return 0;
}
#else
int enableANSI() { return 0; } // Should do nothing since non-windows platforms should already have ANSI enabled by default
#endif

void setConsoleTitle(const char* title)
{ std::cout << "\033]0;" << title << "\007"; }