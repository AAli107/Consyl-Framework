#include "PhysicsTest_Level.h"
#include "../lib/engine/Keyboard.h"
#include "../lib/math/VecMath.h"
#include "../lib/components/PhysicsComponent.h"

#include <sstream>

// This level holds test code for Physics. Main purpose of the test is to test out the Physics
// If you want to try and test this, do the following:
//      - Go to "src/lib/engine/main.cpp" and change startingLevel variable to hold this Level's class name
//      - static auto startingLevel = SampleLevel();
//                     Change this -- ^^^^^^^^^^^

bool hasPressedSpace = false;

void PhysicsTest_Level::start(GameLoop &gl) // Runs when the level starts
{
    gl.showStats = true;
    auto playerObj = gl.spawnObject("Player");
    PhysicsComponent& physicsComponent = playerObj->addComponent<PhysicsComponent>();
    physicsComponent.gravityStrength = 0.0;
    auto attractObj = gl.spawnObject("Attracting Object", Vec3(10, 10, 0));
    PhysicsComponent& attractPhys = attractObj->addComponent<PhysicsComponent>();
    attractPhys.friction = 0.0;
    attractPhys.velocity = Vec3(0.9,-1,0).normalized() * 0.9;
}

void PhysicsTest_Level::update(GameLoop &gl) // Runs every frame while the level is loaded
{
    if (isKeyDown(Key::ESCAPE)) { gl.stop(); return; }
    if (isKeyDown(Key::R)) { gl.openLevel<PhysicsTest_Level>(); return; }

    auto playerObj = gl.getGameObjectByName("Player");
    auto physicsComponent = playerObj->getComponent<PhysicsComponent>();
    auto attractObj = gl.getGameObjectByName("Attracting Object");
    auto attractPhys = attractObj->getComponent<PhysicsComponent>();

    // Get direction that player is moving through inputs
    Vec2 dir = Vec2();
    if (isKeyDown(Key::W)) dir.y++;
    if (isKeyDown(Key::A)) dir.x--;
    if (isKeyDown(Key::S)) dir.y--;
    if (isKeyDown(Key::D)) dir.x++;
    dir = dir.normalized();
    
    double moveSpeed = (isKeyDown(Key::L_SHIFT) ? 2 : 1);
    
    physicsComponent->velocity += dir * gl.deltaTime() * moveSpeed;

    if (isKeyDown(Key::SPACE)) {
        if (!hasPressedSpace)
            physicsComponent->addVelocity(VEC3_UP * 0.5, isKeyDown(Key::L_CTRL));
        hasPressedSpace = true;
    } else {
        hasPressedSpace = false;
    }
}

void PhysicsTest_Level::tick(GameLoop &gl)
{
    auto playerObj = gl.getGameObjectByName("Player");
    auto attractObj = gl.getGameObjectByName("Attracting Object");

    auto attractPhys = attractObj->getComponent<PhysicsComponent>();
    
    double dist = attractObj->transform.position.distance(playerObj->transform.position);
    attractPhys->gravityStrength = 10 / (dist * dist);
    attractPhys->gravityVector = (playerObj->transform.position - attractObj->transform.position).normalized();
}

void PhysicsTest_Level::render(GameLoop &gl, Gfx &gfx) // Runs after right after update() for graphics rendering
{
    auto playerObj = gl.getGameObjectByName("Player");
    auto physicsComponent = playerObj->getComponent<PhysicsComponent>();
    auto attractObj = gl.getGameObjectByName("Attracting Object");
    auto attractPhys = attractObj->getComponent<PhysicsComponent>();

    gfx.drawCircle(playerObj->transform.position * Vec3(1, -1, 1), playerObj->transform.scale.length() * 3, AsciiPixel('P', "#ffff00"), false);
    gfx.drawCircle(attractObj->transform.position * Vec3(1, -1, 1), attractObj->transform.scale.length() * 1.25, AsciiPixel('A', "#0099ff"), false);

    std::ostringstream oss = std::ostringstream();
    oss << "Position: " << (std::string)playerObj->transform.position << '\n' <<
           "Velocity: " << (std::string)physicsComponent->velocity << '\n';
    gfx.drawText(VEC2_ZERO, oss.str(), true);
}
