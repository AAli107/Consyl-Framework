#ifndef VECMATH_H
#define VECMATH_H

#include "Vec2.h"
#include "Vec3.h"

static const Vec3 VEC3_ZERO     (0, 0, 0);
static const Vec3 VEC3_ONE      (1, 1, 1);
static const Vec3 VEC3_RIGHT    (1, 0, 0);
static const Vec3 VEC3_LEFT     (-1, 0, 0);
static const Vec3 VEC3_UP       (0, 1, 0);
static const Vec3 VEC3_DOWN     (0, -1, 0);
static const Vec3 VEC3_FORWARD  (0, 0, 1);
static const Vec3 VEC3_BACKWARD (0, 0, -1);

static const Vec2 VEC2_ZERO     (0, 0);
static const Vec2 VEC2_ONE      (1, 1);
static const Vec2 VEC2_RIGHT    (1, 0);
static const Vec2 VEC2_LEFT     (-1, 0);
static const Vec2 VEC2_UP       (0, 1);
static const Vec2 VEC2_DOWN     (0, -1);

Vec2 project3D(Vec3 v);
Vec2 screenToNormalizedSpace(Vec2 v, int screenWidth, int screenHeight);
Vec2 normalizedToScreenSpace(Vec2 v, int screenWidth, int screenHeight);
Vec3 rotate2D(Vec3 v, double angle);
Vec3 Cross(const Vec3 v1, const Vec3 v2);
bool isInPolygon(const Vec2& v, const Vec2 poly[], int polyLen);

#endif