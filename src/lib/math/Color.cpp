#include "Color.h"

#include <cstdint>
#include <algorithm>
#include <cmath>

Color::Color() : r(0), g(0), b(0) {}

Color::Color(unsigned char r, unsigned char g, unsigned char b)
    : r(r), g(g), b(b) {}

Color::Color(int r, int g, int b) : 
    r(static_cast<std::uint8_t>(std::clamp(r, 0, 255))),
    g(static_cast<std::uint8_t>(std::clamp(g, 0, 255))),
    b(static_cast<std::uint8_t>(std::clamp(b, 0, 255))) {}

Color::Color(float r, float g, float b) : 
    r(static_cast<std::uint8_t>(std::clamp(int(std::lround(r * 255.0f)), 0, 255))),
    g(static_cast<std::uint8_t>(std::clamp(int(std::lround(g * 255.0f)), 0, 255))),
    b(static_cast<std::uint8_t>(std::clamp(int(std::lround(b * 255.0f)), 0, 255))) {}

Color::Color(double r, double g, double b) : 
    r(static_cast<std::uint8_t>(std::clamp(int(std::lround(r * 255.0)), 0, 255))),
    g(static_cast<std::uint8_t>(std::clamp(int(std::lround(g * 255.0)), 0, 255))),
    b(static_cast<std::uint8_t>(std::clamp(int(std::lround(b * 255.0)), 0, 255))) {}

Color Color::invert() const
{ return Color(255 - r, 255 - g, 255 - b); }

Color Color::diff(const Color &c) const
{ return Color(abs(r - c.r), abs(g - c.g), abs(b - c.b)); }

Color Color::scale(const float &v) const
{ return Color((r / 255.0f) * v, (g / 255.0f) * v, (b / 255.0f) * v); }

Vec3 Color::normalized() const
{ return Vec3(r / 255.0, g / 255.0, b / 255.0); }

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