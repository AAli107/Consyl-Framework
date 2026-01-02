#include "AsciiPixel.h"

#include <sstream>

AsciiPixel::AsciiPixel() : 
    pixelChar(0), 
    fgColor(Color(255, 255, 255)),
    bgColor(Color(0, 0, 0))
{}

AsciiPixel::AsciiPixel(char pixelChar, Color fgColor, Color bgColor) : 
    pixelChar(pixelChar), 
    fgColor(fgColor),
    bgColor(bgColor)
{}

std::string AsciiPixel::toString()
{
    std::ostringstream oss;
    oss << "\x1b[38;2;" << fgColor.r << ";" << fgColor.g << ";" << fgColor.b
        << ";48;2;" << bgColor.r << ";" << bgColor.g << ";" << bgColor.b << "m"
        << pixelChar << "\x1b[0m\n";
    return oss.str();
}
