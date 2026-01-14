#include "PhysicsComponent.h"
#include "../engine/GameObject.h"

void PhysicsComponent::tick(GameLoop &gl)
{
    const Vec3 constaintVec = Vec3(constrainX ? 0 : 1, constrainY ? 0 : 1, constrainZ ? 0 : 1);

    // gravity (all objects move towards the direction of gravity, which the gravity source would likely be your Mo-)
    Vec3 gForce = gravityVector.normalized() * gravityStrength * constaintVec;
    if (gForce != VEC3_ZERO)
        velocity += gForce;
    
    // Friction calculation
    velocity *= (1 / (((doAirborneFriction ? (friction * (1 / mass)) : friction) + 1) >= 1 ? ((doAirborneFriction ? (friction * (1 / mass)) : friction) + 1) : 1)) * constaintVec;
    
    // Apply velocity
    if (velocity != VEC3_ZERO)
        parent()->transform.position += velocity * constaintVec;
}

void PhysicsComponent::addVelocity(const Vec3 &velocity, bool ignoreMass)
{
    if (!isEnabled()) return;
    this->velocity += velocity / (ignoreMass ? 1.0 : this->mass);
}
