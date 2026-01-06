#include "Gfx.h"
#include <sstream>
#include <iostream>
#include <cstring>
#include <cmath>
#include <stdint.h>
#include <algorithm>

#include "../utils/console.h"

char cleanOutChar(char c)
{
    static constexpr size_t blacklistLen = 4;
    static constexpr char charBlacklist[blacklistLen] = {'\0','\t','\b','\n'};
    return ([](char c2) -> bool {
        for (size_t i = 0; i < blacklistLen; i++)
            if (c2 == charBlacklist[i]) return true;
        return false;
    })(c) ? ' ' : c;
}

void Gfx::render()
{
    hideCursor();
    moveCursorTop();

    setBackgroundColor(backgroundColor);

    std::string out;
    out.reserve(GFX_WIDTH * GFX_HEIGHT * 12);
    
    Color lastColor = Color(0, 0, 0);
    bool firstPixel = true;

    for (size_t y = 0; y < GFX_HEIGHT; y++)
    {
        for (size_t x = 0; x < GFX_WIDTH; x++)
        {
            const AsciiPixel &pix = drawBuffer[x][y];

            if (firstPixel || pix.color != lastColor)
            {
                firstPixel = false;
                lastColor = pix.color;

                out += "\x1b[38;2;" + 
                    std::to_string((int)pix.color.r) + ";" + 
                    std::to_string((int)pix.color.g) + ";" + 
                    std::to_string((int)pix.color.b) + "m";
            }

            out.push_back(cleanOutChar(pix.pixelChar));
            out.push_back(' ');
        }

        out.push_back('\n');
    }

    std::fill(&drawBuffer[0][0],
              &drawBuffer[0][0] + GFX_WIDTH * GFX_HEIGHT,
              AsciiPixel{});

    std::cout << out;
}

void Gfx::setPixel(int x, int y, AsciiPixel c)
{
    if (x < 0 || x >= GFX_WIDTH || y < 0 || y >= GFX_HEIGHT) return;
    drawBuffer[x][y] = c;
}

void Gfx::setPixel(const Vec2 v, AsciiPixel c) { setPixel((int)v.x, (int)v.y, c); }

AsciiPixel Gfx::getPixel(int x, int y) const
{
    if (x < 0 || x >= GFX_WIDTH || y < 0 || y >= GFX_HEIGHT) return 0;
    return drawBuffer[x][y];
}

AsciiPixel Gfx::getPixel(const Vec2 v) const { return getPixel((int)v.x, (int)v.y); }

void Gfx::drawRect(int x, int y, int w, int h, AsciiPixel outerC, AsciiPixel innerC, bool isScreenSpace = false)
{
    for (size_t dy = y; dy < y+h; dy++)
    {
        for (size_t dx = x; dx < x+w; dx++)
        {
            if (dx < 0 || dx >= GFX_WIDTH || dy < 0 || dy >= GFX_HEIGHT) continue;
            AsciiPixel c = dx == x || dx == (x+w)-1 || dy == y || dy == (y+h)-1 ? outerC : innerC;
            setPixel(dx, dy, c);
        }
    }
}

void Gfx::drawRect(int x, int y, int w, int h, AsciiPixel c, bool isScreenSpace = false)
{ drawRect(x, y, w, h, c, c, isScreenSpace); }

void Gfx::drawRect(const Vec2 v, const Vec2 d, AsciiPixel outerC, AsciiPixel innerC, bool isScreenSpace = false)
{ drawRect((int)v.x, (int)v.y, (int)d.x, (int)d.y, outerC, innerC, isScreenSpace); }

void Gfx::drawRect(const Vec2 v, const Vec2 d, AsciiPixel c, bool isScreenSpace = false)
{ drawRect((int)v.x, (int)v.y, (int)d.x, (int)d.y, c, c, isScreenSpace); }

void Gfx::drawText(int x, int y, const std::string str, Color color, bool isScreenSpace = true)
{
    int charX = x;
    int charY = y;

    for (char c : str)
    {
        switch (c)
        {
        case '\n':
            charX = x;
            charY++;
            continue;

        case '\t':
            charX = ((charX / 4) + 1) * 4;
            continue;
        }

        if (charX >= 0 && charX < GFX_WIDTH &&
            charY >= 0 && charY < GFX_HEIGHT)
        {
            setPixel(charX, charY, AsciiPixel(c, color));
        }

        charX++;
    }
}

void Gfx::drawText(const Vec2 v, std::string str, Color color, bool isScreenSpace = true)
{ drawText((int)v.x, (int)v.y, str, color, isScreenSpace); }

void Gfx::drawText(int x, int y, const std::string str, bool isScreenSpace = true)
{ drawText(x, y, str, Color(1.0f, 1.0f, 1.0f), isScreenSpace); }

void Gfx::drawText(const Vec2 v, std::string str, bool isScreenSpace = true)
{ drawText((int)v.x, (int)v.y, str, Color(1.0f, 1.0f, 1.0f), isScreenSpace); }

void Gfx::drawLine(int x0, int y0, int x1, int y1, AsciiPixel c, bool isScreenSpace = false)
{
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2, e2;

    for (;;)
    {
        setPixel(x0, y0, c);

        if (x0 == x1 && y0 == y1)
            break;

        e2 = err;

        if (e2 > -dx)
        {
            err -= dy;
            x0 += sx;
        }

        if (e2 < dy)
        {
            err += dx;
            y0 += sy;
        }
    }
}

void Gfx::drawLine(const Vec2 v0, const Vec2 v1, AsciiPixel c, bool isScreenSpace = false)
{ drawLine((int)v0.x, (int)v0.y, (int)v1.x, (int)v1.y, c, isScreenSpace); }

void Gfx::drawCircle(int x, int y, int radius, AsciiPixel outerC, AsciiPixel innerC, bool isScreenSpace = false)
{
    for (int dy = y - radius; dy <= y + radius; dy++)
    {
        for (int dx = x - radius; dx <= x + radius; dx++)
        {
            double dist = Vec2(dx, dy).distance(Vec2(x, y));

            if (dist > radius + 0.5) continue;

            setPixel(dx, dy, std::abs(dist - radius) < 0.5 ? outerC : innerC);
        }
    }
}

void Gfx::drawCircle(int x, int y, int radius, AsciiPixel c, bool isScreenSpace = false)
{ drawCircle(x, y, radius, c, c, isScreenSpace); }

void Gfx::drawCircle(const Vec2 v, int radius, AsciiPixel outerC, AsciiPixel innerC, bool isScreenSpace = false)
{ drawCircle((int)v.x, (int)v.y, radius, outerC, innerC, isScreenSpace); }

void Gfx::drawCircle(const Vec2 v, int radius, AsciiPixel c, bool isScreenSpace = false)
{ drawCircle((int)v.x, (int)v.y, radius, c, c, isScreenSpace); }

void Gfx::drawTri(int x0, int y0, int x1, int y1, int x2, int y2, AsciiPixel outerC, AsciiPixel innerC, bool isScreenSpace = false)
{
    static auto edgeFunc = [](int x0, int y0, int x1, int y1, int x, int y) -> int64_t 
    { return int64_t(x - x0) * int64_t(y1 - y0) - int64_t(y - y0) * int64_t(x1 - x0); };

    int minX = std::min({ x0, x1, x2 });
    int maxX = std::max({ x0, x1, x2 });
    int minY = std::min({ y0, y1, y2 });
    int maxY = std::max({ y0, y1, y2 });

    if (minX < 0) minX = 0;
    if (minY < 0) minY = 0;
    if (maxX >= GFX_WIDTH) maxX = GFX_WIDTH - 1;
    if (maxY >= GFX_HEIGHT) maxY = GFX_HEIGHT - 1;

    int64_t area = edgeFunc(x0, y0, x1, y1, x2, y2);
    if (area == 0) {
        drawLine(x0, y0, x1, y1, outerC, isScreenSpace);
        drawLine(x1, y1, x2, y2, outerC, isScreenSpace);
        drawLine(x2, y2, x0, y0, outerC, isScreenSpace);
        return;
    }

    for (int y = minY; y <= maxY; ++y) {
        for (int x = minX; x <= maxX; ++x) {
            int64_t w0 = edgeFunc(x1, y1, x2, y2, x, y);
            int64_t w1 = edgeFunc(x2, y2, x0, y0, x, y);
            int64_t w2 = edgeFunc(x0, y0, x1, y1, x, y);

            if ((w0 == 0 || ((w0 > 0) == (area > 0))) &&
                (w1 == 0 || ((w1 > 0) == (area > 0))) &&
                (w2 == 0 || ((w2 > 0) == (area > 0)))) {
                setPixel(x, y, innerC);
            }
        }
    }

    drawLine(x0, y0, x1, y1, outerC, isScreenSpace);
    drawLine(x1, y1, x2, y2, outerC, isScreenSpace);
    drawLine(x2, y2, x0, y0, outerC, isScreenSpace);
}

void Gfx::drawTri(int x0, int y0, int x1, int y1, int x2, int y2, AsciiPixel c, bool isScreenSpace = false)
{ drawTri(x0, y0, x1, y1, x2, y2, c, c, isScreenSpace); }

void Gfx::drawTri(const Vec2 v0, const Vec2 v1, const Vec2 v2, AsciiPixel outerC, AsciiPixel innerC, bool isScreenSpace = false)
{ drawTri(v0.x, v0.y, v1.x, v1.y, v2.x, v2.y, outerC, innerC, isScreenSpace); }

void Gfx::drawTri(const Vec2 v0, const Vec2 v1, const Vec2 v2, AsciiPixel c, bool isScreenSpace = false)
{ drawTri(v0.x, v0.y, v1.x, v1.y, v2.x, v2.y, c, c, isScreenSpace); }

void Gfx::drawQuad(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3, AsciiPixel outerC, AsciiPixel innerC, bool isScreenSpace = false)
{
    drawTri(x0, y0, x1, y1, x2, y2, innerC, innerC, isScreenSpace);
    drawTri(x0, y0, x2, y2, x3, y3, innerC, innerC, isScreenSpace);

    drawLine(x0, y0, x1, y1, outerC, isScreenSpace);
    drawLine(x1, y1, x2, y2, outerC, isScreenSpace);
    drawLine(x2, y2, x3, y3, outerC, isScreenSpace);
    drawLine(x3, y3, x0, y0, outerC, isScreenSpace);
}

void Gfx::drawQuad(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3, AsciiPixel c, bool isScreenSpace = false) 
{ drawQuad(x0, y0, x1, y1, x2, y2, x3, y3, c, c, isScreenSpace); }

void Gfx::drawQuad(const Vec2 v0, const Vec2 v1, const Vec2 v2, const Vec2 v3, AsciiPixel outerC, AsciiPixel innerC, bool isScreenSpace = false)
{ drawQuad(v0.x, v0.y, v1.x, v1.y, v2.x, v2.y, v3.x, v3.y, outerC, innerC, isScreenSpace); }

void Gfx::drawQuad(const Vec2 v0, const Vec2 v1, const Vec2 v2, const Vec2 v3, AsciiPixel c, bool isScreenSpace = false)
{ drawQuad(v0.x, v0.y, v1.x, v1.y, v2.x, v2.y, v3.x, v3.y, c, c, isScreenSpace); }
