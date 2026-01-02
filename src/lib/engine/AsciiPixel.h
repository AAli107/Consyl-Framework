#ifndef ASCIIPIXEL_H
#define ASCIIPIXEL_H

#include "../math/Color.h"

struct AsciiPixel
{
public:
    char pixelChar = 0;
    Color fgColor = Color(255, 255, 255);
    Color bgColor = Color(0, 0, 0);

    AsciiPixel();
    AsciiPixel(char pixelChar, Color fgColor, Color bgColor);

    std::string toString();
};

#endif