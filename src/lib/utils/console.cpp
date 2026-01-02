#include "console.h"

#include <iostream>

void setConsoleTitle(const char* title)
{ std::cout << "\033]0;" << title << "\007"; }