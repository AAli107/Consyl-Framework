#ifndef LEVEL1_H
#define LEVEL1_H

#include "lib/engine/Level.h"
#include "lib/engine/GameLoop.h"

class SampleLevel : public Level {
public:
    void start(GameLoop& gl) override;
    void update(GameLoop& gl) override;
    void render(GameLoop& gl, Gfx& gfx) override;
    void end(GameLoop& gl) override;
};
#endif