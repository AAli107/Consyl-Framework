#include "GameLoop.h"
#include "../../SampleLevel.h"
#include "../utils/console.h"

static const char* title = "Consyl Game";
static auto startingLevel = SampleLevel();
static int tickRate = 60; // per second

int main() 
{
    setConsoleTitle(title);
    GameLoop gl = GameLoop(&startingLevel, tickRate);
    gl.run();
    return 0;
}