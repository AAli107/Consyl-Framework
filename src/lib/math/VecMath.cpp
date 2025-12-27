#include "VecMath.h"

#include <cmath>

Vec2 project3D(Vec3 v) { return Vec2((v.x / v.z), (v.y / v.z)); }

Vec2 screenToNormalizedSpace(Vec2 v, int screenWidth, int screenHeight) { return Vec2( 2.0 * v.x / screenWidth - 1.0, 1.0 - 2.0 * v.y / screenHeight ); }

Vec2 normalizedToScreenSpace(Vec2 v, int screenWidth, int screenHeight) { return Vec2((v.x + 1.0) * 0.5 * screenWidth, (1.0 - (v.y + 1.0) * 0.5) * screenHeight); }

Vec3 rotate2D(Vec3 v, double angle) { double c = std::cos(angle); double s = std::sin(angle); return Vec3(c * v.x - s * v.y, s * v.x + c * v.y, v.z); }

Vec3 Cross(const Vec3 v1, const Vec3 v2) { return Vec3( v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x ); }

bool isInPolygon(const Vec2& v, const Vec2 poly[], int polyLen)
{
    if (polyLen < 3) return false;
    
    int windingN = 0;

    for (int i = 0; i < polyLen; i++)
    {
        const Vec2& currentVert = poly[i];
        const Vec2& nextVert = poly[(i + 1) % polyLen];

        double crossVal = (nextVert.x - currentVert.x) * (v.y - currentVert.y) - (nextVert.y - currentVert.y) * (v.x - currentVert.x);

        if (currentVert.y <= v.y)
        {
            if (nextVert.y > v.y && crossVal > 0)
                windingN++;
        }
        else if (nextVert.y <= v.y && crossVal < 0)
                windingN--;
    }

    return windingN != 0;
}

