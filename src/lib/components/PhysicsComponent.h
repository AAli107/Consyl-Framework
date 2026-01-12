#ifndef PHYSICSCOMPONENT_H
#define PHYSICSCOMPONENT_H

#include "../engine/Component.h"
#include "../math/VecMath.h"

class PhysicsComponent : Component
{
public:
    Vec3 velocity = VEC3_ZERO;
    double mass = 10.0;
    double friction = 0.1;
    bool doAirborneFriction = true;
    double gravityStrength = 1.0;
    bool constrainX, constrainY, constrainZ = false; // axis constraint
private:
    Vec3 gravityVector = VEC3_DOWN;

public:
    void tick(GameLoop& gl) override;
    void addVelocity(const Vec3& velocity, bool ignoreMass = false);
};

#endif