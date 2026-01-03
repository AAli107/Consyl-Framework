#ifndef COLORTEST_LEVEL_H
#define COLORTEST_LEVEL_H

#include "../lib/engine/Level.h"
#include "../lib/engine/GameLoop.h"

class ColorTest_Level : public Level {
public:
    void start(GameLoop& gl) override;
    void render(GameLoop& gl, Gfx& gfx) override;
};
#endif