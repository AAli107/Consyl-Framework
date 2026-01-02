#include "ColorTest_Level.h"
#include "../lib/engine/Keyboard.h"
#include "../lib/math/VecMath.h"

#include <cmath>

// This level holds test code for colored Ascii pixels. Main purpose of the test is to test how the colors look.
// If you want to try and test this, do the following:
//      - Go to "src/lib/engine/main.cpp" and change startingLevel variable to hold this Level's class name
//      - static auto startingLevel = SampleLevel();
//                     Change this -- ^^^^^^^^^^^


void ColorTest_Level::start(GameLoop &gl) // Runs when the level starts
{
    gl.showStats = true;
}

void ColorTest_Level::render(GameLoop &gl, Gfx &gfx) // Runs after right after update() for graphics rendering
{
    float bgCos = (cos((float)gl.timeRunning() * 1.0f) + 1) / 2;
    gfx.backgroundColor = Color(bgCos, bgCos * 0.5f, 0.0f);

    // Having a lot of differently colored Ascii pixels can slow performance
    float b = (sin((float)gl.timeRunning() * 2.0f) + 1) / 2;
    for (float r = 0; r < 50; r++)
        for (float g = 0; g < 50; g++)
            gfx.setPixel(r, g, AsciiPixel('A', Color(r / 50.0f, g / 50.0f, b)));
}
