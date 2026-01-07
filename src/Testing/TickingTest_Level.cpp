#include "TickingTest_Level.h"
#include "../lib/engine/Keyboard.h"
#include "../lib/math/VecMath.h"

#include <sstream>

// This level holds test code ticking system. Main purpose of the test is to test out if game loop ticks run properly or not.
// If you want to try and test this, do the following:
//      - Go to "src/lib/engine/main.cpp" and change startingLevel variable to hold this Level's class name
//      - static auto startingLevel = SampleLevel();
//                     Change this -- ^^^^^^^^^^^

double tickTimeRunning = 0;

void TickingTest_Level::start(GameLoop &gl) // Runs when the level starts
{
    gl.showStats = true;
    GameObject* g1 = gl.spawnObject("Game Object 1", Vec3(32, 23));
    g1->addComponent<TickingComponent>();
}

void TickingTest_Level::tick(GameLoop &gl) // Runs fixed number of times per second while this level is loaded
{
    if (auto gameObj1 = gl.getGameObjectByName("Game Object 1")) {
        gameObj1->transform.position.y = 24 + sin(tickTimeRunning * 12) * 6;
    }
    tickTimeRunning += gl.tickDeltaTime();
}

void TickingTest_Level::render(GameLoop &gl, Gfx &gfx) // Runs after right after update() for graphics rendering
{
    if (auto gameObj1 = gl.getGameObjectByName("Game Object 1")) {
        if (auto tickingComp = gameObj1->getComponent<TickingComponent>()) {
            std::ostringstream oss;
            oss << "Ticks Alive: " << tickingComp->ticksAlive;
            gfx.drawText(gameObj1->transform.position + Vec3(2, 2), oss.str(), true);
        }
    }
    std::ostringstream oss;
    oss << "Tick Rate: " << gl.getTickRate() << "\nTick Delta: " << gl.tickDeltaTime();
    gfx.drawText(0,0, oss.str(), true);
}
