#ifndef VECMATH_H
#define VECMATH_H

#include "Vec2.h"
#include "Vec3.h"

Vec2 project3D(Vec3 v);
Vec2 screenToNormalizedSpace(Vec2 v, int screenWidth, int screenHeight);
Vec2 normalizedToScreenSpace(Vec2 v, int screenWidth, int screenHeight);
Vec3 rotate2D(Vec3 v, double angle);
Vec3 Cross(const Vec3 v1, const Vec3 v2);
bool isInPolygon(const Vec2& v, const Vec2 poly[], int polyLen);

#endif