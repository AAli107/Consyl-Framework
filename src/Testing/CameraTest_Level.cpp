#include "CameraTest_Level.h"
#include "../lib/engine/Keyboard.h"
#include "../lib/math/VecMath.h"

#include <sstream>

// This level holds test code for the camera system. Main purpose of the test is to test out the camera wtih graphics rendering.
// If you want to try and test this, do the following:
//      - Go to "src/lib/engine/main.cpp" and change startingLevel variable to hold this Level's class name
//      - static auto startingLevel = SampleLevel();
//                     Change this -- ^^^^^^^^^^^

void CameraTest_Level::start(GameLoop &gl) // Runs when the level starts
{
    gl.showStats = true;
}

void CameraTest_Level::update(GameLoop &gl) // Runs every frame while the level is loaded
{
    if (isKeyDown(Key::ESCAPE)) { gl.stop(); return; }

    Vec2 dir = Vec2();
    if (isKeyDown(Key::W)) dir.y--;
    if (isKeyDown(Key::A)) dir.x--;
    if (isKeyDown(Key::S)) dir.y++;
    if (isKeyDown(Key::D)) dir.x++;
    dir = dir.normalized();
    
    double moveSpeed = (isKeyDown(Key::L_SHIFT) ? 20 : 10);

    Camera& currCam = gl.getCamera();
    currCam.transform.position += dir * gl.deltaTime() * moveSpeed;
}

void CameraTest_Level::render(GameLoop &gl, Gfx &gfx) // Runs after right after update() for graphics rendering
{
    gfx.drawRect(0, 0, 10, 10, 'A', ' ', false);
    gfx.drawText(-10, -10, "Hello World!", false);
    gfx.drawLine(-15, 15, -10, 20, '-', false);
    gfx.drawCircle(15, -15, 6, '+', '-', false);
    
    std::ostringstream oss = std::ostringstream();
    oss << "Position: " << (std::string)gfx.currentCamera.transform.position;
    gfx.drawText(VEC2_ZERO, oss.str(), true);
}
