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
    Color(const std::string hex);
    Color(const char* hex);

    Color invert() const;
    Color diff(const Color& c) const;
    Color scale(const float v) const;
    Vec3 normalized() const;
    Color setSaturation(const float v) const;
    std::string getHexColor() const;

    int asInt() const;
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

static const Color BLACK        =   "#000000";
static const Color WHITE        =   "#ffffff";
static const Color RED          =   "#ff0000";
static const Color GREEN        =   "#00ff00";
static const Color BLUE         =   "#0000ff";
static const Color YELLOW       =   "#ffff00";
static const Color MAGENTA      =   "#ff00ff";
static const Color CYAN         =   "#00ffff";
static const Color DARK_GRAY    =   "#808080";
static const Color LIGHT_GRAY   =   "#c0c0c0";
static const Color DARK_RED     =   "#800000";
static const Color DARK_GREEN   =   "#008000";
static const Color DARK_BLUE    =   "#000080";
static const Color DARK_YELLOW  =   "#808000";
static const Color DARK_MAGENTA =   "#800080";
static const Color DARK_CYAN    =   "#008080";

#endif