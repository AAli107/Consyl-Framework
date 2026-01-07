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
    Color scale(const float v) const;
    Vec3 normalized() const;
    Color setSaturation(const float v) const;

    std::string toString() const;
    operator std::string();
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
bool operator==(const Color& a, const Color& b);

static const Color BLACK        (0, 0, 0);
static const Color WHITE        (255, 255, 255);
static const Color RED          (255, 0, 0);
static const Color GREEN        (0, 255, 0);
static const Color BLUE         (0, 0, 255);
static const Color YELLOW       (255, 255, 0);
static const Color MAGENTA      (255, 0, 255);
static const Color CYAN         (0, 255, 255);
static const Color DARK_GRAY    (80, 80, 80);
static const Color LIGHT_GRAY   (192, 192, 192);
static const Color DARK_RED     (128, 0, 0);
static const Color DARK_GREEN   (0, 128, 0);
static const Color DARK_BLUE    (0, 0, 128);
static const Color DARK_YELLOW  (128, 128, 0);
static const Color DARK_MAGENTA (128, 0, 128);
static const Color DARK_CYAN    (0, 128, 128);

#endif