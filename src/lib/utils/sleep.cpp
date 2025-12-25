#include "sleep.h"
#include <cstdint>
#include <chrono>
#include <thread>

void sleep_ms(int milliseconds)
{
#if defined(__linux__) || defined(__APPLE__)
    usleep(milliseconds * 1000);
#elif defined(_WIN32)
    Sleep(milliseconds);
#else
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
#endif
}

void sleep_us(long long microseconds)
{
#ifdef _WIN32
    std::this_thread::sleep_for(std::chrono::microseconds(microseconds));
#elif defined(__linux__) || defined(__APPLE__)
    usleep(microseconds);
#else
    std::this_thread::sleep_for(std::chrono::microseconds(microseconds));
#endif
}
