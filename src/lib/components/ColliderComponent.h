#ifndef COLLIDER_COMPONENT_H
#define COLLIDER_COMPONENT_H

#include <vector>

#include "../engine/Component.h"
#include "../math/VecMath.h"

class ColliderComponent : public Component
{
public:
    /// @brief Offset/Position of the collider relative to the game object
    Vec3 offset = VEC3_ZERO;
    /// @brief Controls whether the collider has a solid collision or can other colliders pass through
    bool isSolidCollision = true;
    /// @brief The friction strength of the collision it makes
    double friction = 0.1;
protected:
    std::vector<ColliderComponent*> intersectingColliders;

public:
    virtual ~ColliderComponent() = default;

    /// @brief Returns whether this collider is intersecting with the provided collider
    /// @param collider 
    /// @return 
    virtual bool isIntersectingWith(const ColliderComponent& collider) const = 0;
    /// @brief Returns whether the collider is intersecting with any other collider
    /// @return 
    virtual bool isOverlapping() const { return !intersectingColliders.empty(); }
    /// @brief Returns whether the collider is intersecting with other colliders, ignoring the provided `ignoredColliders`
    /// @param ignoredColliders 
    /// @return 
    virtual bool isOverlapping(const std::vector<ColliderComponent*>& ignoredColliders) const = 0;
};

#endif