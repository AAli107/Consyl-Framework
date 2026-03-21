#ifndef COLLIDER_COMPONENT_3D_H
#define COLLIDER_COMPONENT_3D_H

#include "ColliderComponent.h"

class ColliderComponent3D : public ColliderComponent
{
public:
    /// @brief Offset/Position of the collider relative to the game object
    Vec3 offset = VEC3_ZERO;
};

#endif