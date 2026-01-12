#include "PhysicsComponent.h"
#include "../engine/GameObject.h"

void PhysicsComponent::tick(GameLoop &gl)
{
    velocity *= 1 / (((doAirborneFriction ? (friction * (1 / mass)) : friction) + 1) >= 1 ? ((doAirborneFriction ? (friction * (1 / mass)) : friction) + 1) : 1);

    parent()->transform.position += velocity;
}

void PhysicsComponent::addVelocity(const Vec3 &velocity, bool ignoreMass)
{
    if (!isEnabled()) return;
    this->velocity += velocity / (ignoreMass ? 1.0 : this->mass);
}
