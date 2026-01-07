#ifndef GAMEOBJECTTEST_LEVEL_H
#define GAMEOBJECTTEST_LEVEL_H

#include "../lib/engine/Level.h"
#include "../lib/engine/GameLoop.h"

#include <cmath>

class DummyComponent : public Component {
public:
    double speed = 2;

    void update(GameLoop& gl) override {
        parent()->transform.scale = Vec2((sin(gl.timeRunning() * speed) + 1) * 0.5,(-cos(gl.timeRunning() * speed) + 1) * 0.5);
    }
    void tick(GameLoop& gl) override {

    }
    void render(GameLoop& gl, Gfx& gfx) override {
        gfx.drawLine(parent()->transform.position, parent()->transform.position + (parent()->transform.scale * 10), 'X', true);
    }
};

class GameObjectTest_Level : public Level {
public:
    void start(GameLoop& gl) override;
    void update(GameLoop& gl) override;
    void render(GameLoop& gl, Gfx& gfx) override;
};
#endif