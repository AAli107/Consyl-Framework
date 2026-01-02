#ifndef CONSOLE_H
#define CONSOLE_H

int enableANSI(); // will run on Windows to enable ANSI
void setConsoleTitle(const char* title);
void moveCursorTop();
void hideCursor();
void showCursor();

#endif