#pragma once

#include "../math/Transform.h"

struct Camera {
    Transform transform;

    Camera();
    Camera(Vec3 position);
    Camera(Transform transform);
};