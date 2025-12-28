#include "GameObject.h"

template <std::derived_from<Component> T, typename... Args>
inline T &GameObject::addComponent(Args &&...args)
{
    auto comp = std::make_unique<T>(std::forward<Args>(args)...);
    comp->setParent(*this);
    T& ref = *comp;
    components.push_back(std::move(comp));
    return ref;
}
