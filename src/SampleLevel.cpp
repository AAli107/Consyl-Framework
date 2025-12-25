#include <cmath>
#include <sstream>

#include "SampleLevel.h"

// This has bunch of test code, so clean them up if you want to use the SampleLevel or
// you could make your own level by making a class inherit Level abstract class

void SampleLevel::start(GameLoop &gl) // Runs when the level starts
{
    gl.showStats = true;
}

void SampleLevel::update(GameLoop &gl) // Runs every frame while the level is loaded
{
    // if (gl.timeRunning() > 10) gl.stop();
}

void SampleLevel::render(GameLoop &gl, Gfx &gfx) // Runs after right after update() for graphics rendering
{
    gfx.drawRect(Vec2(5, 5), Vec2(10, 10), '#', '.');
    gfx.drawCircle(32, 20, 10, '#', '-');

    double speed = 8;
    Vec2 v(32 + cos(levelTime * speed) * 10, 20 + sin(levelTime * speed) * 10);
    gfx.drawLine(Vec2(10, 10), v, '#');
    gfx.setPixel(v, 'A');


    std::ostringstream fpsOss;
    fpsOss << (1.0 / gl.deltaTime()) << " FPS";
    gfx.drawText(Vec2(30, 40), fpsOss.str());
}

void SampleLevel::end(GameLoop &gl) // Runs when level ends
{
}
