#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "../math/VecMath.h"
#include "../math/Transform.h"
#include "Component.h"

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
    template <std::derived_from<Component> T> T* getComponent() noexcept;
};

template <std::derived_from<Component> T, typename... Args>
T &GameObject::addComponent(Args &&...args)
{
    auto comp = std::make_unique<T>(std::forward<Args>(args)...);
    comp->setParent(*this);
    T& ref = *comp;
    components.push_back(std::move(comp));
    return ref;
}

template <std::derived_from<Component> T>
T* GameObject::getComponent() noexcept
{
    for (const auto& c : components)
        if (auto* ptr = dynamic_cast<T*>(c.get()))
            return ptr;
    return nullptr;
}

#endif