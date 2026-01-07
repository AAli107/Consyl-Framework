#include "GameLoop.h"
#include "../../SampleLevel.h"
#include "../utils/console.h"

static const char* title = "Consyl Game";
static auto startingLevel = SampleLevel();
static int tickRate = 60; // per second
static const std::string colors[16] = { // Console 4-bit color palette (order sensitive!)
    BLACK.getHexColor(),            // Black
    DARK_RED.getHexColor(),         // Red
    DARK_GREEN.getHexColor(),       // Green
    DARK_YELLOW.getHexColor(),      // Yellow
    DARK_BLUE.getHexColor(),        // Blue
    DARK_MAGENTA.getHexColor(),     // Magenta
    DARK_CYAN.getHexColor(),        // Cyan
    LIGHT_GRAY.getHexColor(),       // White            (Light Gray)
    DARK_GRAY.getHexColor(),        // Bright Black     (Gray)
    RED.getHexColor(),              // Bright Red
    GREEN.getHexColor(),            // Bright Green
    YELLOW.getHexColor(),           // Bright Yellow
    BLUE.getHexColor(),             // Bright Blue
    MAGENTA.getHexColor(),          // Bright Magenta
    CYAN.getHexColor(),             // Bright Cyan
    WHITE.getHexColor()             // Bright White
};

int main()
{
    int r = enableANSI();
    if (r != 0) return r;
    setConsoleTitle(title);

    for (int i = 0; i < 16; ++i) setConsoleColor(i, colors[i]);

    GameLoop gl = GameLoop(&startingLevel, tickRate);
    gl.run();
    return 0;
}