#include "GameLoop.h"
#include "../../SampleLevel.h"
#include "../utils/console.h"

static const char* title = "Consyl Game";
static int tickRate = 60; // per second

int main() 
{
    int r = enableANSI();
    if (r != 0) return r;
    setConsoleTitle(title);
    GameLoop gl = GameLoop::create<SampleLevel>(tickRate);
    gl.run();
    return 0;
}