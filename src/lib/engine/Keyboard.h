#pragma once

#include <cstdint>

enum class Key : uint16_t {
    
    A, B, C, D, E, F, G, H, I, J, K, L, M,
    N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
    
    DIGIT_0, DIGIT_1, DIGIT_2, DIGIT_3, DIGIT_4,
    DIGIT_5, DIGIT_6, DIGIT_7, DIGIT_8, DIGIT_9,
    
    LEFT, RIGHT, UP, DOWN,
    
    L_SHIFT, R_SHIFT, L_CTRL, R_CTRL, L_ALT, R_ALT,
    
    SPACE, ENTER, ESCAPE, TAB, BACKSPACE,
    
    F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
    
    NUM_0, NUM_1, NUM_2, NUM_3, NUM_4, NUM_5, NUM_6, NUM_7, NUM_8, NUM_9,
    NUM_ADD, NUM_SUBTRACT, NUM_MULTIPLY, NUM_DIVIDE,
    
    MINUS, EQUAL, L_BRACKET, R_BRACKET, BACKSLASH, SEMICOLON, APOSTROPHE, GRAVE, COMMA, PERIOD, SLASH,
    
    COUNT // This is just in case if we wanna get the length of this enum :P
};


#ifdef _WIN32
#include <windows.h>
#include <vector>

static short mapKeyToVk(Key k) {
    switch (k) {
        case Key::A: return 'A';
        case Key::B: return 'B';
        case Key::C: return 'C';
        case Key::D: return 'D';
        case Key::E: return 'E';
        case Key::F: return 'F';
        case Key::G: return 'G';
        case Key::H: return 'H';
        case Key::I: return 'I';
        case Key::J: return 'J';
        case Key::K: return 'K';
        case Key::L: return 'L';
        case Key::M: return 'M';
        case Key::N: return 'N';
        case Key::O: return 'O';
        case Key::P: return 'P';
        case Key::Q: return 'Q';
        case Key::R: return 'R';
        case Key::S: return 'S';
        case Key::T: return 'T';
        case Key::U: return 'U';
        case Key::V: return 'V';
        case Key::W: return 'W';
        case Key::X: return 'X';
        case Key::Y: return 'Y';
        case Key::Z: return 'Z';
        case Key::DIGIT_0: return '0';
        case Key::DIGIT_1: return '1';
        case Key::DIGIT_2: return '2';
        case Key::DIGIT_3: return '3';
        case Key::DIGIT_4: return '4';
        case Key::DIGIT_5: return '5';
        case Key::DIGIT_6: return '6';
        case Key::DIGIT_7: return '7';
        case Key::DIGIT_8: return '8';
        case Key::DIGIT_9: return '9';
        case Key::L_SHIFT: return VK_LSHIFT;
        case Key::R_SHIFT: return VK_RSHIFT;
        case Key::L_CTRL: return VK_LCONTROL;
        case Key::R_CTRL: return VK_RCONTROL;
        case Key::L_ALT: return VK_LMENU;
        case Key::R_ALT: return VK_RMENU;
        case Key::SPACE: return VK_SPACE;
        case Key::ENTER: return VK_RETURN;
        case Key::ESCAPE: return VK_ESCAPE;
        case Key::TAB: return VK_TAB;
        case Key::BACKSPACE: return VK_BACK;
        case Key::LEFT: return VK_LEFT;
        case Key::RIGHT: return VK_RIGHT;
        case Key::UP: return VK_UP;
        case Key::DOWN: return VK_DOWN;
        case Key::F1: return VK_F1;
        case Key::F2: return VK_F2;
        case Key::F3: return VK_F3;
        case Key::F4: return VK_F4;
        case Key::F5: return VK_F5;
        case Key::F6: return VK_F6;
        case Key::F7: return VK_F7;
        case Key::F8: return VK_F8;
        case Key::F9: return VK_F9;
        case Key::F10: return VK_F10;
        case Key::F11: return VK_F11;
        case Key::F12: return VK_F12;
        case Key::NUM_0: return VK_NUMPAD0;
        case Key::NUM_1: return VK_NUMPAD1;
        case Key::NUM_2: return VK_NUMPAD2;
        case Key::NUM_3: return VK_NUMPAD3;
        case Key::NUM_4: return VK_NUMPAD4;
        case Key::NUM_5: return VK_NUMPAD5;
        case Key::NUM_6: return VK_NUMPAD6;
        case Key::NUM_7: return VK_NUMPAD7;
        case Key::NUM_8: return VK_NUMPAD8;
        case Key::NUM_9: return VK_NUMPAD9;
        case Key::NUM_ADD: return VK_ADD;
        case Key::NUM_SUBTRACT: return VK_SUBTRACT;
        case Key::NUM_MULTIPLY: return VK_MULTIPLY;
        case Key::NUM_DIVIDE: return VK_DIVIDE;
        case Key::MINUS: return VK_OEM_MINUS;
        case Key::EQUAL: return VK_OEM_PLUS;
        case Key::L_BRACKET: return VK_OEM_4;
        case Key::R_BRACKET: return VK_OEM_6;
        case Key::BACKSLASH: return VK_OEM_5;
        case Key::SEMICOLON: return VK_OEM_1;
        case Key::APOSTROPHE: return VK_OEM_7;
        case Key::GRAVE: return VK_OEM_3;
        case Key::COMMA: return VK_OEM_COMMA;
        case Key::PERIOD: return VK_OEM_PERIOD;
        case Key::SLASH: return VK_OEM_2;
        default: return 0;
    }
}

bool isKeyDown(Key k) {
    HWND fg = GetForegroundWindow();
    HWND cw = GetConsoleWindow();
    if (!(fg != NULL && cw != NULL && fg == cw)) return false;
    return (GetAsyncKeyState(mapKeyToVk(k)) & 0x8000) != 0;
}

#endif