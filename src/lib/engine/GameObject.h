#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "../math/VecMath.h"
#include "../math/Transform.h"
#include <vector>
#include <concepts>
#include <memory>

class Component;

class GameObject {
private:
    bool enabled = true;
    std::vector<std::unique_ptr<Component>> components;
public:
    Transform transform;

    bool isEnabled() const noexcept { return enabled; }
    void setEnabled(bool value) noexcept { enabled = value; }
    template <std::derived_from<Component> T, typename... Args> T& addComponent(Args&&... args);
    template <std::derived_from<Component> T> T& getComponent();
    template <std::derived_from<Component> T> bool tryGetComponent(T& component);
};

#endif