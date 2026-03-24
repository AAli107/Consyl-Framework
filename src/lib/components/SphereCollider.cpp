#include "SphereCollider.h"

Vec3 SphereCollider::CalculateMTV(const ColliderComponent3D &otherCollider) const
{
    return Vec3();
}

bool SphereCollider::isIntersectingWith(const ColliderComponent &collider) const
{
    return false;
}

bool SphereCollider::isOverlapping(const std::vector<ColliderComponent *> &ignoredColliders) const
{
    return false;
}
