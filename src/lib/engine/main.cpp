#include "GameLoop.h"
#include "../../SampleLevel.h"
#include "../utils/console.h"

static const char* title = "Consyl Game";
static auto startingLevel = SampleLevel();
static int tickRate = 60; // per second

int main() 
{
    int r = enableANSI();
    if (r != 0) return r;
    setConsoleTitle(title);
    GameLoop gl = GameLoop(&startingLevel, tickRate);
    gl.run();
    return 0;
}