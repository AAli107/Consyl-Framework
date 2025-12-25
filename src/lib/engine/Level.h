#ifndef LEVEL_H
#define LEVEL_H
class GameLoop;
#include "Gfx.h"
class Level {
public:
    double levelTime = 0.0;
    virtual void start(GameLoop& gl) {}
    virtual void update(GameLoop& gl) {}
    virtual void render(GameLoop& gl, Gfx& gfx) {}
    virtual void end(GameLoop& gl) {}
};

#endif