#include <cmath>
#include <sstream>

#include "SampleLevel.h"

void SampleLevel::start(GameLoop &gl)
{
    gl.showStats = true;
}

void SampleLevel::update(GameLoop &gl)
{
    // if (gl.timeRunning() > 10) gl.stop();
}

void SampleLevel::render(GameLoop &gl, Gfx &gfx)
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

void SampleLevel::end(GameLoop &gl)
{
}
