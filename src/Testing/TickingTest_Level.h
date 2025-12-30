#ifndef TICKINGTEST_LEVEL_H
#define TICKINGTEST_LEVEL_H

#include "../lib/engine/Level.h"
#include "../lib/engine/GameLoop.h"

#include <cmath>

class TickingComponent : public Component {
public:
    int ticksAlive = 0;

    void tick(GameLoop& gl) override {
        ticksAlive++;
    }
};

class TickingTest_Level : public Level {
public:
    void start(GameLoop& gl) override;
    void tick(GameLoop& gl) override;
    void render(GameLoop& gl, Gfx& gfx) override;
};
#endif