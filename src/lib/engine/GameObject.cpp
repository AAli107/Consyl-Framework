#include "GameObject.h"

void GameObject::update(GameLoop &gl)
{
    for (auto& c : components)
        if (c && c->isEnabled())
            c->update(gl);
}

void GameObject::tick(GameLoop &gl)
{
    for (auto& c : components)
        if (c && c->isEnabled())
            c->tick(gl);
}

void GameObject::render(GameLoop &gl, Gfx &gfx)
{
    for (auto& c : components)
        if (c && c->isEnabled())
            c->render(gl, gfx);
}
