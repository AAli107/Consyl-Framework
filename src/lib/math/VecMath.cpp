#include "VecMath.h"

#include <cmath>

Vec2 project3D(Vec3 v) { return Vec2((v.x / v.z), (v.y / v.z)); }

Vec2 screenToNormalizedSpace(Vec2 v, int screenWidth, int screenHeight) { return Vec2( 2.0 * v.x / screenWidth - 1.0, 1.0 - 2.0 * v.y / screenHeight ); }

Vec2 normalizedToScreenSpace(Vec2 v, int screenWidth, int screenHeight) { return Vec2((v.x + 1.0) * 0.5 * screenWidth, (1.0 - (v.y + 1.0) * 0.5) * screenHeight); }

Vec3 rotate2D(Vec3 v, double angle) { double c = std::cos(angle); double s = std::sin(angle); return Vec3(c * v.x - s * v.y, s * v.x + c * v.y, v.z); }

Vec3 Cross(const Vec3 v1, const Vec3 v2) { return Vec3( v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x ); }

bool isInPolygon(const Vec2& point, const Vec2 poly[], int polyLen)
{
    if (polyLen < 3) return false;
    
    int windingN = 0;

    for (int i = 0; i < polyLen; i++)
    {
        const Vec2& currentVert = poly[i];
        const Vec2& nextVert = poly[(i + 1) % polyLen];

        double crossVal = (nextVert.x - currentVert.x) * (point.y - currentVert.y) - (nextVert.y - currentVert.y) * (point.x - currentVert.x);

        if (currentVert.y <= point.y)
        {
            if (nextVert.y > point.y && crossVal > 0)
                windingN++;
        }
        else if (nextVert.y <= point.y && crossVal < 0)
                windingN--;
    }

    return windingN != 0;
}

bool isInBox2D(const Vec2 &point, const Vec2 boxPos, const Vec2 boxDim)
{
    if (boxDim.x < 0 || boxDim.y < 0) return false;
    Vec2 boxEnd = boxPos + boxDim;
    return point.x >= boxPos.x && point.x <= boxEnd.x && point.y >= boxPos.y && point.y <= boxEnd.y; 
}

bool isBox2DIntersecting(const Vec2 box0Pos, const Vec2 box0Dim, const Vec2 box1Pos, const Vec2 box1Dim)
{
    if (box0Dim.x < 0 || box0Dim.y < 0 || box1Dim.x < 0 || box1Dim.y < 0) return false;
    Vec2 box0End = box0Pos + box0Dim;
    Vec2 box1End = box1Pos + box1Dim;
    return box0Pos.x <= box1End.x && box0End.x >= box1Pos.x && box0Pos.y <= box1End.y && box0End.y >= box1Pos.y; 
}

bool isInCircle(const Vec2 &point, const Vec2 circlePos, double circleRadius)
{ return circleRadius < 0 ? false : point.distance(circlePos) <= circleRadius; }

bool isCircleIntersecting(const Vec2 circle0Pos, double circle0Radius, const Vec2 circle1Pos, double circle1Radius)
{ return circle0Radius < 0 || circle1Radius < 0 ? false : circle0Pos.distance(circle1Pos) <= circle0Radius + circle1Radius; }

bool isInBox3D(const Vec3 &point, const Vec3 boxPos, const Vec3 boxDim)
{
    if (boxDim.x < 0 || boxDim.y < 0 || boxDim.z < 0) return false;
    Vec3 boxEnd = boxPos + boxDim;
    return point.x >= boxPos.x && point.x <= boxEnd.x && point.y >= boxPos.y && point.y <= boxEnd.y && point.z >= boxPos.z && point.z <= boxEnd.z; 
}

bool isBox3DIntersecting(const Vec3 box0Pos, const Vec3 box0Dim, const Vec3 box1Pos, const Vec3 box1Dim)
{
    if (box0Dim.x < 0 || box0Dim.y < 0 || box0Dim.z < 0 || box1Dim.x < 0 || box1Dim.y < 0 || box1Dim.z < 0) return false;
    Vec3 box0End = box0Pos + box0Dim;
    Vec3 box1End = box1Pos + box1Dim;
    return box0Pos.x <= box1End.x && box0End.x >= box1Pos.x && 
        box0Pos.y <= box1End.y && box0End.y >= box1Pos.y && 
        box0Pos.z <= box1End.z && box0End.z >= box1Pos.z; 
}

bool isInSphere(const Vec3 &point, const Vec3 spherePos, double sphereRadius)
{ return sphereRadius < 0 ? false : point.distance(spherePos) <= sphereRadius; }

bool isSphereIntersecting(const Vec3 sphere0Pos, double sphere0Radius, const Vec3 sphere1Pos, double sphere1Radius)
{ return sphere0Radius < 0 || sphere1Radius < 0 ? false : sphere0Pos.distance(sphere1Pos) <= sphere0Radius + sphere1Radius; }