#include "PhysicsComponent.h"
#include "../engine/GameObject.h"

void PhysicsComponent::tick(GameLoop &gl)
{
    Vec3 gForce = gravityVector * gravityStrength;
    if (gForce != VEC3_ZERO)
        velocity += gForce;
    
    velocity *= 1 / (((doAirborneFriction ? (friction * (1 / mass)) : friction) + 1) >= 1 ? ((doAirborneFriction ? (friction * (1 / mass)) : friction) + 1) : 1);
    
    if (velocity != VEC3_ZERO)
        parent()->transform.position += velocity;
}

void PhysicsComponent::addVelocity(const Vec3 &velocity, bool ignoreMass)
{
    if (!isEnabled()) return;
    this->velocity += velocity / (ignoreMass ? 1.0 : this->mass);
}
