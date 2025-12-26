#ifndef VECMATH_H
#define VECMATH_H

#include "Vec2.h"
#include "Vec3.h"

Vec2 project3D(Vec3 v);
Vec2 screenToNormalizedSpace(Vec2 v, int screenWidth, int screenHeight);
Vec2 normalizedToScreenSpace(Vec2 v, int screenWidth, int screenHeight);

#endif