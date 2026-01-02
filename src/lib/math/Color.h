#ifndef COLOR_H
#define COLOR_H

struct Color {
public:
    unsigned char r, g, b;

    Color();
    Color(unsigned char r, unsigned char g, unsigned char b);
    Color(int r, int g, int b);
    Color(float r, float g, float b);
    Color(double r, double g, double b);
};

#endif