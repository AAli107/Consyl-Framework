#include "Gfx.h"
#include <sstream>
#include <iostream>
#include <cstring>
#include <cmath>

#include "../utils/cursor.h"

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
    std::ostringstream oss;
    moveCursorTop();
    for (size_t y = 0; y < GFX_HEIGHT; y++)
    {
        for (size_t x = 0; x < GFX_WIDTH; x++)
            oss << cleanOutChar(drawBuffer[x][y]) << " ";
        oss << '\n';
    }
    memset(drawBuffer, 0, sizeof(drawBuffer));
    std::cout << oss.str();
}

void Gfx::setPixel(int x, int y, char c)
{
    if (x < 0 || x >= GFX_WIDTH || y < 0 || y >= GFX_HEIGHT) return;
    drawBuffer[x][y] = c;
}

void Gfx::setPixel(const Vec2 v, char c) { setPixel((int)v.x, (int)v.y, c); }

char Gfx::getPixel(int x, int y) const
{
    if (x < 0 || x >= GFX_WIDTH || y < 0 || y >= GFX_HEIGHT) return 0;
    return drawBuffer[x][y];
}

char Gfx::getPixel(const Vec2 v) const { return getPixel((int)v.x, (int)v.y); }

void Gfx::drawRect(int x, int y, int w, int h, char outerC, char innerC)
{
    for (size_t dy = y; dy < y+h; dy++)
    {
        for (size_t dx = x; dx < x+w; dx++)
        {
            if (dx < 0 || dx >= GFX_WIDTH || dy < 0 || dy >= GFX_HEIGHT) continue;
            char c = dx == x || dx == (x+w)-1 || dy == y || dy == (y+h)-1 ? outerC : innerC;
            setPixel(dx, dy, c);
        }
    }
}

void Gfx::drawRect(int x, int y, int w, int h, char c) { drawRect(x, y, w, h, c, c); }

void Gfx::drawRect(const Vec2 v, const Vec2 d, char outerC, char innerC) { drawRect((int)v.x, (int)v.y, (int)d.x, (int)d.y, outerC, innerC); }

void Gfx::drawRect(const Vec2 v, const Vec2 d, char c) { drawRect((int)v.x, (int)v.y, (int)d.x, (int)d.y, c, c); }

void Gfx::drawText(int x, int y, std::string str)
{
    int charX = x;
    int charY = y;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (charX < 0 || charX >= GFX_WIDTH || charY < 0 || charY >= GFX_HEIGHT) continue;

        switch (str[i])
        {
        case '\0':
            return;
        case '\n':
            charX = x-1;
            charY++;
            break;
        case '\t':
            charX += 4;
            break;
        default:
            setPixel(charX, charY, str[i]);
            charX++;
            break;
        }

    }
    
}

void Gfx::drawText(const Vec2 v, std::string str) { drawText((int)v.x, (int)v.y, str); }

void Gfx::drawLine(int x0, int y0, int x1, int y1, char c)
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

void Gfx::drawLine(const Vec2 v0, const Vec2 v1, char c) { drawLine((int)v0.x, (int)v0.y, (int)v1.x, (int)v1.y, c); }

void Gfx::drawCircle(int x, int y, int radius, char outerC, char innerC)
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

void Gfx::drawCircle(int x, int y, int radius, char c) { drawCircle(x, y, radius, c, c); }

void Gfx::drawCircle(const Vec2 v, int radius, char outerC, char innerC) { drawCircle((int)v.x, (int)v.y, radius, outerC, innerC); }

void Gfx::drawCircle(const Vec2 v, int radius, char c) { drawCircle((int)v.x, (int)v.y, radius, c, c); }