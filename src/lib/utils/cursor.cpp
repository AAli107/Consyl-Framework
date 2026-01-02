#include "cursor.h"
#include <iostream>

void moveCursorTop()
{ std::cout << "\033[H"; }

void hideCursor()
{ std::cout << "\033[?25l" << std::flush; }

void showCursor()
{ std::cout << "\033[?25h" << std::flush; }
