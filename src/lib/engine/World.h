#ifndef WORLD_H
#define WORLD_H

#include "GameObject.h"

#include <unordered_map>
#include <string>

struct World
{
    std::unordered_map<std::string, std::unique_ptr<GameObject>> gameObjects;
};

#endif