#ifndef COMPONENT_H
#define COMPONENT_H

class GameObject;
class GameLoop;
class Gfx;

class Component {
private:
    bool enabled = true;
    GameObject* parentGO;
public:
    virtual ~Component() = default;

    bool isEnabled() const noexcept { return enabled; }
    void setEnabled(bool value) noexcept { enabled = value; }
    GameObject* parent() noexcept { return parentGO; }
    void setParent(GameObject& parent) noexcept { parentGO = &parent; }

    virtual void update(GameLoop& gl) {}
    virtual void tick(GameLoop& gl) {}
    virtual void render(GameLoop& gl, Gfx& gfx) {}
};

#endif