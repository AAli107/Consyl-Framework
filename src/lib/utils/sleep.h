#ifndef SLEEP_H
#define SLEEP_H

#ifdef LINUX
#include <unistd.h>
#endif
#ifdef _WIN32
#include <windows.h>
#endif
void sleep_ms(int milliseconds);
void sleep_us(long long microseconds);
#endif