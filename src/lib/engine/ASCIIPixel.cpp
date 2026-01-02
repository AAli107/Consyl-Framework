#include "ASCIIPixel.h"

ASCIIPixel::ASCIIPixel() : 
    pixelChar(0), 
    fgColor(Color(255, 255, 255)),
    bgColor(Color(0, 0, 0))
{}

ASCIIPixel::ASCIIPixel(char pixelChar, Color fgColor, Color bgColor) : 
    pixelChar(pixelChar), 
    fgColor(fgColor),
    bgColor(bgColor)
{}
