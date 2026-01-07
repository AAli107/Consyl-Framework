#ifndef CONSOLE_H
#define CONSOLE_H

#include "../math/Color.h"

int enableANSI(); // will run on Windows to enable ANSI
void setConsoleTitle(const char* title);
void moveCursorTop();
void hideCursor();
void showCursor();
void setBackgroundColor(const Color& c);

#endif