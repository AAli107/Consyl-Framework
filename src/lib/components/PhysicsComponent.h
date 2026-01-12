#ifndef PHYSICSCOMPONENT_H
#define PHYSICSCOMPONENT_H

#include "../engine/Component.h"
#include "../math/VecMath.h"

class PhysicsComponent : Component
{
public:
    /// @brief Controls the direction and speed that the game object moves in over time.
    Vec3 velocity = VEC3_ZERO;
    /// @brief Describes how heavy or how resistant the game object is to change in velocity.
    double mass = 10.0;
    /// @brief The higher the value, the faster the game object slows down.
    double friction = 0.1;
    /// @brief When true, the friction behaves like the game objedct is airborne, otherwise the friction behaves like it is on the ground.
    bool doAirborneFriction = true;
    /// @brief Controls how the strength of gravity.
    double gravityStrength = 1.0;
    /// @brief Boolean value that constains a specific axis.
    bool constrainX, constrainY, constrainZ = false;
    /// @brief Controls direction of gravity
    Vec3 gravityVector = VEC3_DOWN;

public:
    void tick(GameLoop& gl) override;
    /// @brief Increases velocity by the amount given, and will be dampened by mass if ignoreMass is false
    /// @param velocity 
    /// @param ignoreMass 
    void addVelocity(const Vec3& velocity, bool ignoreMass = false);
};

#endif