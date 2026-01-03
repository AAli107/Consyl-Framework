#include "Color.h"

#include <algorithm>
#include <cmath>
#include <sstream>

Color::Color() : r(0), g(0), b(0) {}

Color::Color(unsigned char r, unsigned char g, unsigned char b)
    : r(r), g(g), b(b)
{}

Color::Color(int r, int g, int b) : 
    r(static_cast<unsigned char>(std::clamp(r, 0, 255))),
    g(static_cast<unsigned char>(std::clamp(g, 0, 255))),
    b(static_cast<unsigned char>(std::clamp(b, 0, 255)))
{}

Color::Color(float r, float g, float b) : 
    r(static_cast<unsigned char>(std::clamp(static_cast<int>(std::round(r * 255.0f)), 0, 255))),
    g(static_cast<unsigned char>(std::clamp(static_cast<int>(std::round(g * 255.0f)), 0, 255))),
    b(static_cast<unsigned char>(std::clamp(static_cast<int>(std::round(b * 255.0f)), 0, 255)))
{}

Color::Color(double r, double g, double b) : 
    r(static_cast<unsigned char>(std::clamp(static_cast<int>(std::round(r * 255.0)), 0, 255))),
    g(static_cast<unsigned char>(std::clamp(static_cast<int>(std::round(g * 255.0)), 0, 255))),
    b(static_cast<unsigned char>(std::clamp(static_cast<int>(std::round(b * 255.0)), 0, 255)))
{}

Color Color::invert() const
{ return Color(255 - r, 255 - g, 255 - b); }

Color Color::diff(const Color &c) const
{ return Color(abs(r - c.r), abs(g - c.g), abs(b - c.b)); }

Color Color::scale(const float v) const
{
    return Color(
        static_cast<unsigned char>(std::clamp(static_cast<int>(std::round(r * v)), 0, 255)),
        static_cast<unsigned char>(std::clamp(static_cast<int>(std::round(g * v)), 0, 255)),
        static_cast<unsigned char>(std::clamp(static_cast<int>(std::round(b * v)), 0, 255))
    ); 
}

Vec3 Color::normalized() const
{ return Vec3(r / 255.0, g / 255.0, b / 255.0); }

Color Color::setSaturation(const float v) const
{
    float rf = r / 255.0f;
    float gf = g / 255.0f;
    float bf = b / 255.0f;

    float gray = 0.299f * rf + 0.587f * gf + 0.114f * bf;
    
    return Color(std::lerp(gray, rf, v), std::lerp(gray, gf, v), std::lerp(gray, bf, v));
}

std::string Color::toString() const
{
    std::ostringstream oss;
    oss << "<" << r << ", " << g  << ", " << b << ">";
    return oss.str();
}

Color::operator std::string()
{ return toString(); }

Color::operator Vec3()
{ return Vec3(r, g, b); }

Color operator+(const Color &a, const Color &b)
{ return Color(a.r + b.r, a.g + b.g, a.b + b.b); }

Color operator-(const Color &a, const Color &b)
{ return Color(a.r - b.r, a.g - b.g, a.b - b.b); }

Color operator*(const Color &a, const Color &b)
{ return Color(a.r * b.r, a.g * b.g, a.b * b.b); }

Color operator/(const Color &a, const Color &b)
{ return Color(a.r / b.r, a.g / b.g, a.b / b.b); }

void operator+=(Color &a, const Color &b)
{ a = Color(a.r + b.r, a.g + b.g, a.b + b.b); }

void operator-=(Color &a, const Color &b)
{ a = Color(a.r - b.r, a.g - b.g, a.b - b.b); }

void operator*=(Color &a, const Color &b)
{ a = Color(a.r * b.r, a.g * b.g, a.b * b.b); }

void operator/=(Color &a, const Color &b)
{ a = Color(a.r / b.r, a.g / b.g, a.b / b.b); }