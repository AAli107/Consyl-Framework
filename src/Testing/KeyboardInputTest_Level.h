#ifndef KEYBOARDINPUTTEST_LEVEL_H
#define KEYBOARDINPUTTEST_LEVEL_H

#include "../lib/engine/Level.h"
#include "../lib/engine/GameLoop.h"

class KeyboardInputTest_Level : public Level {
public:
    void start(GameLoop& gl) override;
    void update(GameLoop& gl) override;
    void render(GameLoop& gl, Gfx& gfx) override;
};
#endif