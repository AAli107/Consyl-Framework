#ifndef COLOR_H
#define COLOR_H

#include "Vec3.h"

struct Color {
public:
    unsigned char r, g, b;

    Color();
    Color(unsigned char r, unsigned char g, unsigned char b);
    Color(int r, int g, int b);
    Color(float r, float g, float b);
    Color(double r, double g, double b);

    Color invert() const;
    Color diff(const Color& c) const;

    operator Vec3();
};

Color operator+(const Color& a, const Color& b);
Color operator-(const Color& a, const Color& b);
Color operator*(const Color& a, const Color& b);
Color operator/(const Color& a, const Color& b);
void operator+=(Color& a, const Color& b);
void operator-=(Color& a, const Color& b);
void operator*=(Color& a, const Color& b);
void operator/=(Color& a, const Color& b);

#endif