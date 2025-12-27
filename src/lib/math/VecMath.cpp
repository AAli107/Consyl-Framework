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

bool isInBox2D(const Vec2 &v, const Vec2 boxPos, const Vec2 boxDim)
{ return v.x >= boxPos.x && v.x <= boxDim.x && v.y >= boxPos.y && v.y <= boxDim.y; }

bool isBox2DIntersecting(const Vec2 box0Pos, const Vec2 box0Dim, const Vec2 box1Pos, const Vec2 box1Dim)
{ return box0Pos.x <= box1Dim.x && box0Dim.x >= box1Pos.x && box0Pos.y <= box1Dim.y && box0Dim.y >= box1Pos.y; }

bool isInCircle(const Vec2 &v, const Vec2 circlePos, double circleRadius)
{
    return false;
}

bool isCircleIntersecting(const Vec2 circle0Pos, double circle0Radius, const Vec2 circle1Pos, double circle1Radius)
{
    return false;
}

bool isInBox3D(const Vec3 &v, const Vec3 boxPos, const Vec3 dimension)
{
    return false;
}

bool isBox3DIntersecting(const Vec3 box0Pos, const Vec3 box0Dim, const Vec3 box1Pos, const Vec3 box1Dim)
{
    return false;
}

bool isInSphere(const Vec3 &v, const Vec3 spherePos, double sphereRadius)
{
    return false;
}

bool isSphereIntersecting(const Vec3 sphere0Pos, double sphere0Radius, const Vec3 sphere1Pos, double sphere1Radius)
{
    return false;
}
