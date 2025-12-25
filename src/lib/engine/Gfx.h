#ifndef GFX_H
#define GFX_H

#include "../math/Vec2.h"

#define GFX_WIDTH 115
#define GFX_HEIGHT 60

class Gfx {
private:
    char drawBuffer[GFX_WIDTH][GFX_HEIGHT] = {0};
public:
    void render();
    void setPixel(int x, int y, char c);
    void setPixel(const Vec2 v, char c);
    char getPixel(int x, int y) const;
    char getPixel(const Vec2 v) const;
    void drawRect(int x, int y, int w, int h, char outerC, char innerC);
    void drawRect(int x, int y, int w, int h, char c);
    void drawRect(const Vec2 v, const Vec2 d, char outerC, char innerC);
    void drawRect(const Vec2 v, const Vec2 d, char c);
    void drawText(int x, int y, std::string str);
    void drawText(const Vec2 v, std::string str);
    void drawLine(int x0, int y0, int x1, int y1, char c);
    void drawLine(const Vec2 v0, const Vec2 v1, char c);
    void drawCircle(int x, int y, int radius, char outerC, char innerC);
    void drawCircle(int x, int y, int radius, char c);
    void drawCircle(const Vec2 v, int radius, char outerC, char innerC);
    void drawCircle(const Vec2 v, int radius, char c);
};

#endif