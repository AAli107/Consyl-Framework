#ifndef ASCIIPIXEL_H
#define ASCIIPIXEL_H

#include "../math/Color.h"

struct AsciiPixel
{
public:
    char pixelChar = 0;
    Color color = Color(255, 255, 255);

    AsciiPixel();
    AsciiPixel(char pixelChar);
    AsciiPixel(char pixelChar, Color color);
};

#endif