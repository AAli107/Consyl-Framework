#pragma once

#include <cstdint>

enum class Key : uint16_t {
    
    A, B, C, D, E, F, G, H, I, J, K, L, M,
    N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
    
    DIGIT_0, DIGIT_1, DIGIT_2, DIGIT_3, DIGIT_4,
    DIGIT_5, DIGIT_6, DIGIT_7, DIGIT_8, DIGIT_9,
    
    LEFT, RIGHT, UP, DOWN,
    
    L_SHIFT, R_SHIFT, L_CTRL, R_CTRL, L_ALT, R_ALT,
    
    SPACE, ENTER, ESCAPE, TAB, BACKSPACE, CAPSLOCK, OS_KEY,
    
    F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
    
    NUM_0, NUM_1, NUM_2, NUM_3, NUM_4, NUM_5, NUM_6, NUM_7, NUM_8, NUM_9,
    NUM_ADD, NUM_SUBTRACT, NUM_MULTIPLY, NUM_DIVIDE, NUM_PERIOD,
    
    MINUS, EQUAL, L_BRACKET, R_BRACKET, BACKSLASH, SEMICOLON, APOSTROPHE, GRAVE, COMMA, PERIOD, SLASH,

    PRINT_SCREEN, SCROLL_LOCK, PAUSE, INSERT, HOME, PAGE_UP, DELETE, END, PAGE_DOWN,
    
    COUNT // This is just in case if we wanna get the length of this enum :P
};


#ifdef _WIN32
bool isKeyDown(Key k);
#endif

#ifdef __linux__
// TODO: Make it work on Linux
bool isKeyDown(Key k);
#endif

#ifdef __APPLE__
// TODO: Make it work on Mac
bool isKeyDown(Key k);
#endif