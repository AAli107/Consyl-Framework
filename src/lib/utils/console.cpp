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

void moveCursorTop()
{ std::cout << "\033[H"; }

void hideCursor()
{ std::cout << "\033[?25l" << std::flush; }

void showCursor()
{ std::cout << "\033[?25h" << std::flush; }

void setBackgroundColor(const Color& c)
{ std::cout << "\x1b[48;2;" << int(c.r) << ";" << int(c.g) << ";" << int(c.b) << "m"; }

void setConsoleColor(int index, const std::string hexRgb)
{
    int start = (hexRgb.size() == 7 && hexRgb[0] == '#') ? 1 : (hexRgb.size() == 6) ? 0 : -1;
    if (start < 0) return;

    for (int i = start; i < start + 6; ++i)
        if (!std::isxdigit(static_cast<unsigned char>(hexRgb[i]))) return;

    std::cout << "\x1b]4;" << index << ";rgb:"
        << hexRgb.substr(start    , 2) << "/"
        << hexRgb.substr(start + 2, 2) << "/"
        << hexRgb.substr(start + 4, 2)
        << "\x07" << std::flush;
}
