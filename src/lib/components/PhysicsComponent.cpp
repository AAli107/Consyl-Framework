#include "PhysicsComponent.h"

void PhysicsComponent::addVelocity(const Vec3 &velocity, bool ignoreMass)
{
    if (!isEnabled()) return;
    this->velocity += velocity / (ignoreMass ? 1.0 : this->mass);
}
