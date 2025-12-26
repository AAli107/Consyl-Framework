#include "VecMath.h"

Vec2 project3D(Vec3 v) { return Vec2((v.x / v.z), (v.y / v.z)); }

Vec2 screenToNormalizedSpace(Vec2 v, int screenWidth, int screenHeight) { return Vec2( 2.0 * v.x / screenWidth - 1.0, 1.0 - 2.0 * v.y / screenHeight ); }

Vec2 normalizedToScreenSpace(Vec2 v, int screenWidth, int screenHeight) { return Vec2((v.x + 1.0) * 0.5 * screenWidth, (1.0 - (v.y + 1.0) * 0.5) * screenHeight); }
