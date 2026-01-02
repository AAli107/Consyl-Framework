#ifndef GFX_H
#define GFX_H

#include "../math/Vec2.h"
#include "AsciiPixel.h"

#define GFX_WIDTH 115
#define GFX_HEIGHT 60

class Gfx {
private:
    AsciiPixel drawBuffer[GFX_WIDTH][GFX_HEIGHT] = {0};
public:
    Color backgroundColor = Color(0, 0, 0);

    void render();
    void setPixel(int x, int y, AsciiPixel c);
    void setPixel(const Vec2 v, AsciiPixel c);
    AsciiPixel getPixel(int x, int y) const;
    AsciiPixel getPixel(const Vec2 v) const;
    void drawRect(int x, int y, int w, int h, AsciiPixel outerC, AsciiPixel innerC);
    void drawRect(int x, int y, int w, int h, AsciiPixel c);
    void drawRect(const Vec2 v, const Vec2 d, AsciiPixel outerC, AsciiPixel innerC);
    void drawRect(const Vec2 v, const Vec2 d, AsciiPixel c);
    void drawText(int x, int y, const std::string str);
    void drawText(const Vec2 v, const std::string str);
    void drawLine(int x0, int y0, int x1, int y1, AsciiPixel c);
    void drawLine(const Vec2 v0, const Vec2 v1, AsciiPixel c);
    void drawCircle(int x, int y, int radius, AsciiPixel outerC, AsciiPixel innerC);
    void drawCircle(int x, int y, int radius, AsciiPixel c);
    void drawCircle(const Vec2 v, int radius, AsciiPixel outerC, AsciiPixel innerC);
    void drawCircle(const Vec2 v, int radius, AsciiPixel c);
    void drawTri(int x0, int y0, int x1, int y1, int x2, int y2, AsciiPixel outerC, AsciiPixel innerC);
    void drawTri(int x0, int y0, int x1, int y1, int x2, int y2, AsciiPixel c);
    void drawTri(const Vec2 v0, const Vec2 v1, const Vec2 v2, AsciiPixel outerC, AsciiPixel innerC);
    void drawTri(const Vec2 v0, const Vec2 v1, const Vec2 v2, AsciiPixel c);
    void drawQuad(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3, AsciiPixel outerC, AsciiPixel innerC);
    void drawQuad(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3, AsciiPixel c);
    void drawQuad(const Vec2 v0, const Vec2 v1, const Vec2 v2, const Vec2 v3, AsciiPixel outerC, AsciiPixel innerC);
    void drawQuad(const Vec2 v0, const Vec2 v1, const Vec2 v2, const Vec2 v3, AsciiPixel c);
};

#endif