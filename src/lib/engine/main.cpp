#include "GameLoop.h"
#include "../../SampleLevel.h"

int main() 
{
    auto startingLevel = SampleLevel();
    GameLoop gl = GameLoop(&startingLevel);
    gl.run();
    return 0;
}