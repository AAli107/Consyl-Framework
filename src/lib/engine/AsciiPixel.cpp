#include "AsciiPixel.h"

#include <sstream>

AsciiPixel::AsciiPixel() : 
    pixelChar(0), 
    color(Color(255, 255, 255))
{}

AsciiPixel::AsciiPixel(char pixelChar) : 
    pixelChar(pixelChar), 
    color(Color(255, 255, 255))
{}

AsciiPixel::AsciiPixel(char pixelChar, Color fgColor) : 
    pixelChar(pixelChar), 
    color(fgColor)
{}
