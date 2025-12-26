#include "GameLoop.h"
#include "../../SampleLevel.h"
#include "../utils/console.h"

static const char* title = "Consyl Game";

int main() 
{
    setConsoleTitle(title);
    auto startingLevel = SampleLevel();
    GameLoop gl = GameLoop(&startingLevel);
    gl.run();
    return 0;
}