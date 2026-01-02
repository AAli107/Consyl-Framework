#include "AsciiPixel.h"

#include <sstream>

AsciiPixel::AsciiPixel() : 
    pixelChar(0), 
    fgColor(Color(255, 255, 255)),
    bgColor(Color(0, 0, 0))
{}

AsciiPixel::AsciiPixel(char pixelChar) : 
    pixelChar(pixelChar), 
    fgColor(Color(255, 255, 255)),
    bgColor(Color(0, 0, 0))
{}

AsciiPixel::AsciiPixel(char pixelChar, Color fgColor) : 
    pixelChar(pixelChar), 
    fgColor(fgColor),
    bgColor(Color(0, 0, 0))
{}

AsciiPixel::AsciiPixel(char pixelChar, Color fgColor, Color bgColor) : 
    pixelChar(pixelChar), 
    fgColor(fgColor),
    bgColor(bgColor)
{}

char cleanOutChar(char c)
{
    static constexpr size_t blacklistLen = 4;
    static constexpr char charBlacklist[blacklistLen] = {'\0','\t','\b','\n'};
    return ([](char c2) -> bool {
        for (size_t i = 0; i < blacklistLen; i++)
            if (c2 == charBlacklist[i]) return true;
        return false;
    })(c) ? ' ' : c;
}

std::string AsciiPixel::toString() const
{
    std::ostringstream oss;
    oss << "\x1b[38;2;" << (int)fgColor.r << ";" << (int)fgColor.g << ";" << (int)fgColor.b
        << ";48;2;" << (int)bgColor.r << ";" << (int)bgColor.g << ";" << (int)bgColor.b << "m"
        << cleanOutChar(pixelChar) << "\x1b[0m";
    return oss.str();
}
