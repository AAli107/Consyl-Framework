#include "PlayerTest_Level.h"
#include "../lib/engine/Keyboard.h"
#include "../lib/math/VecMath.h"

#include <sstream>

// This level holds test code for Player movement. Main purpose of the test is to test out Vector calculations.
// If you want to try and test this, do the following:
//      - Go to "src/lib/engine/main.cpp" and change startingLevel variable to hold this Level's class name
//      - static auto startingLevel = SampleLevel();
//                     Change this -- ^^^^^^^^^^^

Vec2 pos = Vec2(50, 10);
Vec2 vel = VEC2_ZERO;
double friction = 10;
double walkSpeed = 1;
double sprintSpeed = 2;

void PlayerTest_Level::start(GameLoop &gl) // Runs when the level starts
{
    gl.showStats = true;
}

void PlayerTest_Level::update(GameLoop &gl) // Runs every frame while the level is loaded
{
    if (isKeyDown(Key::ESCAPE)) { gl.stop(); return; }

    // Get direction that player is moving through inputs
    Vec2 dir = Vec2();
    if (isKeyDown(Key::W)) dir.y--;
    if (isKeyDown(Key::A)) dir.x--;
    if (isKeyDown(Key::S)) dir.y++;
    if (isKeyDown(Key::D)) dir.x++;
    dir = dir.normalized();
    
    double moveSpeed = (isKeyDown(Key::L_SHIFT) ? sprintSpeed : walkSpeed);
    
    vel += dir * gl.deltaTime() * moveSpeed;

    pos += vel;

    vel *= (1 - (gl.deltaTime() * friction));
}

void PlayerTest_Level::render(GameLoop &gl, Gfx &gfx) // Runs after right after update() for graphics rendering
{
    gfx.setPixel(pos, 'X');
    gfx.setPixel(pos-Vec2(1,0), 'X');
    gfx.setPixel(pos+Vec2(1,0), 'X');
    gfx.setPixel(pos-Vec2(0,1), 'X');
    gfx.setPixel(pos+Vec2(0,1), 'X');

    std::ostringstream oss = std::ostringstream();
    oss << "Position: " << (std::string)pos << '\n' <<
           "Velocity: " << (std::string)vel << '\n';
    gfx.drawText(VEC2_ZERO, oss.str(), true);
}
