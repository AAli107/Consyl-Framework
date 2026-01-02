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
