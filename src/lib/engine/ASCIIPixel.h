#ifndef ASCIIPIXEL_H
#define ASCIIPIXEL_H

#include "../math/Color.h"

struct ASCIIPixel
{
public:
    char pixelChar = 0;
    Color fgColor = Color(255, 255, 255);
    Color bgColor = Color(0, 0, 0);

    ASCIIPixel();
    ASCIIPixel(char pixelChar, Color fgColor, Color bgColor);
};

#endif