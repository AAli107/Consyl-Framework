#ifndef SPHERE_COLLIDER_H
#define SPHERE_COLLIDER_H

#include "ColliderComponent3D.h"

class SphereCollider : public ColliderComponent3D
{
public:
    double radius = 0.5;

protected:
    Vec3 CalculateMTV(const ColliderComponent3D& otherCollider) const override;
    bool isIntersectingWith(const ColliderComponent& collider) const override;
    bool isOverlapping(const std::vector<ColliderComponent*>& ignoredColliders) const override;
};

#endif