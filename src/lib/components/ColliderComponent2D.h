#ifndef COLLIDER_COMPONENT_2D_H
#define COLLIDER_COMPONENT_2D_H

#include "ColliderComponent.h"

class ColliderComponent2D : public ColliderComponent
{
public:
    /// @brief Offset/Position of the collider relative to the game object
    Vec2 offset = VEC2_ZERO;
};

#endif