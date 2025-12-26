#include "GameLoop.h"
#include "../../SampleLevel.h"
#include "../utils/console.h"

static const char* title = "Consyl Game";
static auto startingLevel = SampleLevel();

int main() 
{
    setConsoleTitle(title);
    GameLoop gl = GameLoop(&startingLevel);
    gl.run();
    return 0;
}