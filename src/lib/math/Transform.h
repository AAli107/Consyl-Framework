#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "VecMath.h"

struct Transform
{
    Vec3 position = VEC3_ZERO;
    Vec3 scale = VEC3_ONE;
};

#endif