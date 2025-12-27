#include "Keyboard.h"

#ifdef _WIN32
#include <windows.h>

HWND consoleWin = GetConsoleWindow();

short mapKeyToVk(Key k)
{
    #undef DELETE
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
        case Key::CAPSLOCK: return VK_CAPITAL;
        case Key::OS_KEY: return VK_LWIN;
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
        case Key::NUM_PERIOD: return VK_DECIMAL;
        case Key::NUM_LOCK: return VK_NUMLOCK;
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
        case Key::PRINT_SCREEN: return VK_SNAPSHOT;
        case Key::SCROLL_LOCK: return VK_SCROLL;
        case Key::PAUSE: return VK_PAUSE;
        case Key::INSERT: return VK_INSERT;
        case Key::HOME: return VK_HOME;
        case Key::PAGE_UP: return VK_PRIOR;
        case Key::DELETE: return VK_DELETE;
        case Key::END: return VK_END;
        case Key::PAGE_DOWN: return VK_NEXT;
        default: return UINT16_MAX;
    }
}

bool isKeyDown(Key k)
{
    HWND fgWindow = GetForegroundWindow();
    if (fgWindow == NULL || consoleWin == NULL || fgWindow != consoleWin) return false;
    return (GetAsyncKeyState(mapKeyToVk(k)) & 0x8000) != 0;
}
#endif

#ifdef __linux__
bool isKeyDown(Key k)
{
    // TODO: implement isKeyDown for Linux
    return false;
}
#endif

#ifdef __APPLE__
#include <ApplicationServices/ApplicationServices.h>
#include <Carbon/Carbon.h>

static CGKeyCode mapKeyToMacKeycode(Key k)
{
    switch (k) {
        case Key::A: return kVK_ANSI_A;
        case Key::B: return kVK_ANSI_B;
        case Key::C: return kVK_ANSI_C;
        case Key::D: return kVK_ANSI_D;
        case Key::E: return kVK_ANSI_E;
        case Key::F: return kVK_ANSI_F;
        case Key::G: return kVK_ANSI_G;
        case Key::H: return kVK_ANSI_H;
        case Key::I: return kVK_ANSI_I;
        case Key::J: return kVK_ANSI_J;
        case Key::K: return kVK_ANSI_K;
        case Key::L: return kVK_ANSI_L;
        case Key::M: return kVK_ANSI_M;
        case Key::N: return kVK_ANSI_N;
        case Key::O: return kVK_ANSI_O;
        case Key::P: return kVK_ANSI_P;
        case Key::Q: return kVK_ANSI_Q;
        case Key::R: return kVK_ANSI_R;
        case Key::S: return kVK_ANSI_S;
        case Key::T: return kVK_ANSI_T;
        case Key::U: return kVK_ANSI_U;
        case Key::V: return kVK_ANSI_V;
        case Key::W: return kVK_ANSI_W;
        case Key::X: return kVK_ANSI_X;
        case Key::Y: return kVK_ANSI_Y;
        case Key::Z: return kVK_ANSI_Z;
        case Key::DIGIT_0: return kVK_ANSI_0;
        case Key::DIGIT_1: return kVK_ANSI_1;
        case Key::DIGIT_2: return kVK_ANSI_2;
        case Key::DIGIT_3: return kVK_ANSI_3;
        case Key::DIGIT_4: return kVK_ANSI_4;
        case Key::DIGIT_5: return kVK_ANSI_5;
        case Key::DIGIT_6: return kVK_ANSI_6;
        case Key::DIGIT_7: return kVK_ANSI_7;
        case Key::DIGIT_8: return kVK_ANSI_8;
        case Key::DIGIT_9: return kVK_ANSI_9;
        case Key::SPACE: return kVK_Space;
        case Key::ENTER: return kVK_Return;
        case Key::ESCAPE: return kVK_Escape;
        case Key::TAB: return kVK_Tab;
        case Key::BACKSPACE: return kVK_Delete;
        case Key::CAPSLOCK: return kVK_CapsLock;
        case Key::LEFT: return kVK_LeftArrow;
        case Key::RIGHT: return kVK_RightArrow;
        case Key::UP: return kVK_UpArrow;
        case Key::DOWN: return kVK_DownArrow;
        case Key::F1: return kVK_F1;
        case Key::F2: return kVK_F2;
        case Key::F3: return kVK_F3;
        case Key::F4: return kVK_F4;
        case Key::F5: return kVK_F5;
        case Key::F6: return kVK_F6;
        case Key::F7: return kVK_F7;
        case Key::F8: return kVK_F8;
        case Key::F9: return kVK_F9;
        case Key::F10: return kVK_F10;
        case Key::F11: return kVK_F11;
        case Key::F12: return kVK_F12;
        case Key::MINUS: return kVK_ANSI_Minus;
        case Key::EQUAL: return kVK_ANSI_Equal;
        case Key::COMMA: return kVK_ANSI_Comma;
        case Key::PERIOD: return kVK_ANSI_Period;
        case Key::SLASH: return kVK_ANSI_Slash;
        case Key::SEMICOLON: return kVK_ANSI_Semicolon;
        case Key::APOSTROPHE: return kVK_ANSI_Quote;
        case Key::GRAVE: return kVK_ANSI_Grave;
        case Key::L_BRACKET: return kVK_ANSI_LeftBracket;
        case Key::R_BRACKET: return kVK_ANSI_RightBracket;
        case Key::BACKSLASH: return kVK_ANSI_Backslash;
        case Key::L_SHIFT:
        case Key::R_SHIFT: return kVK_Shift;
        case Key::L_CTRL:
        case Key::R_CTRL: return kVK_Control;
        case Key::L_ALT:
        case Key::R_ALT: return kVK_Option;
        case Key::OS_KEY: return kVK_Command;
        case Key::INSERT: return kVK_Help;//closest mac equivalent
        case Key::HOME: return kVK_Home;
        case Key::END: return kVK_End;
        case Key::PAGE_UP: return kVK_PageUp;
        case Key::PAGE_DOWN: return kVK_PageDown;
        case Key::DELETE: return kVK_ForwardDelete;// NOT Backspace
        case Key::NUM_0: return kVK_ANSI_Keypad0;
        case Key::NUM_1: return kVK_ANSI_Keypad1;
        case Key::NUM_2: return kVK_ANSI_Keypad2;
        case Key::NUM_3: return kVK_ANSI_Keypad3;
        case Key::NUM_4: return kVK_ANSI_Keypad4;
        case Key::NUM_5: return kVK_ANSI_Keypad5;
        case Key::NUM_6: return kVK_ANSI_Keypad6;
        case Key::NUM_7: return kVK_ANSI_Keypad7;
        case Key::NUM_8: return kVK_ANSI_Keypad8;
        case Key::NUM_9: return kVK_ANSI_Keypad9;
        case Key::NUM_ADD: return kVK_ANSI_KeypadPlus;
        case Key::NUM_SUBTRACT: return kVK_ANSI_KeypadMinus;
        case Key::NUM_MULTIPLY: return kVK_ANSI_KeypadMultiply;
        case Key::NUM_DIVIDE: return kVK_ANSI_KeypadDivide;
        case Key::NUM_PERIOD: return kVK_ANSI_KeypadDecimal;
        // No Mac Equivalents; //
        case Key::NUM_LOCK: return UINT16_MAX;
        case Key::PRINT_SCREEN: return UINT16_MAX;
        case Key::SCROLL_LOCK: return UINT16_MAX;
        case Key::PAUSE: return UINT16_MAX;
        default: return UINT16_MAX;
    }
}

static bool isAppFocused() { //crude implementation for such a barebones program :p
    ProcessSerialNumber psn;
    if (GetFrontProcess(&psn) != noErr)
        return false;
    CFStringRef frontAppName = nullptr;
    if (CopyProcessName(&psn, &frontAppName) != noErr)
        return false;

    bool finCheck =
        CFStringCompare(frontAppName, CFSTR("Terminal"), 0) == kCFCompareEqualTo;
    CFRelease(frontAppName);
    return finCheck;
}

bool isKeyDown(Key k)
{   
    if (!isAppFocused())
        return false;
    
    CGKeyCode code = mapKeyToMacKeycode(k);
    if (code == UINT16_MAX) return false;

    /*Check both combined session state and the HID system state;
    some macOS versions/ environments give different results from each source,
    so OR-ing them improves reliability across setups.*/
    bool down_combined = CGEventSourceKeyState(kCGEventSourceStateCombinedSessionState, code);
    bool down_hid = CGEventSourceKeyState(kCGEventSourceStateHIDSystemState, code);
    
    return down_combined || down_hid;
}
#endif