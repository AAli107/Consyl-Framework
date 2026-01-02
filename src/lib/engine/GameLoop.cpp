#include <iostream>
#include <chrono>
#include <assert.h>

#include "GameLoop.h"
#include "Level.h"
#include "../utils/sleep.h"

GameLoop::GameLoop(Level* level, int tickRate) {
    assert(tickRate > 0);
    openLevel(level);
    setTickRate(tickRate);
}

void GameLoop::run()
{
    if (!isRunning) {
        isRunning = true;
        while (isRunning) {
            auto startTime = std::chrono::high_resolution_clock::now();
            
            // Per frame update phase
            if (currentLevel) currentLevel->update(*this);
            for (auto& kv : world.gameObjects) {
                if (!kv.second || !kv.second->enabled) continue;
                kv.second->update(*this);
            }
            
            // tick update phase (runs fixed number of times per second)
            tickAccumulatedTime += deltaT;
            while (tickAccumulatedTime >= tickDeltaT)
            {
                if (currentLevel) currentLevel->tick(*this);
                for (auto& kv : world.gameObjects) {
                    if (!kv.second || !kv.second->enabled) continue;
                    kv.second->tick(*this);
                }    
                tickAccumulatedTime -= tickDeltaT;
            }
            
            // Rendering phase
            if (currentLevel) currentLevel->render(*this, gfx);
            for (auto& kv : world.gameObjects) {
                if (!kv.second || !kv.second->enabled) continue;
                kv.second->render(*this, gfx);
            }
            gfx.render();
            if (showStats)
                std::cout << (1.0 / deltaT) << " FPS         \n" << (deltaT * 1000.0) << " ms          ";

            sleep_us(1);
            deltaT = std::chrono::duration_cast<std::chrono::nanoseconds>(
                    std::chrono::high_resolution_clock::now() - startTime
                ).count() / 1000000000.0;
            if (currentLevel) currentLevel->levelTime += deltaT;
            timeSinceStart += deltaT;
        }
        if (currentLevel) currentLevel->end(*this);
    }
}

void GameLoop::stop() { isRunning = false; }

void GameLoop::openLevel(Level* level)
{
    if (!level) return;
    if (currentLevel)
        currentLevel->end(*this);
    world = {};
    currentLevel = level;
    currentLevel->start(*this);
}

double GameLoop::deltaTime() { return deltaT; }

double GameLoop::tickDeltaTime() { return tickDeltaT; }

double GameLoop::timeRunning() { return timeSinceStart; }

void GameLoop::setTickRate(int tickRate)
{
    if (tickRate <= 0) return;
    this->tickRate = tickRate;
    tickDeltaT = 1.0 / static_cast<double>(tickRate);
}

double GameLoop::getTickRate() { return tickRate; }

GameObject* GameLoop::spawnObject(std::string name)
{
    std::string baseName = name.empty() ? "Game Object" : name;
    std::string newName  = baseName;
    int n = 0;
    while (world.gameObjects.contains(newName)) {
        std::ostringstream oss;
        oss << baseName << ' ' << n++;
        newName = oss.str();
    }

    auto [it, _] = world.gameObjects.emplace( std::move(newName), std::make_unique<GameObject>(GameObject()) );

    return it->second.get();
}

GameObject *GameLoop::spawnObject(std::string name, Vec3 position)
{
    GameObject* goPtr = spawnObject(name);
    if (goPtr) goPtr->transform.position = position;
    return goPtr;
}

GameObject *GameLoop::spawnObject(std::string name, Vec3 position, Vec3 scale)
{
    GameObject* goPtr = spawnObject(name);
    if (goPtr) {
        goPtr->transform.position = position;
        goPtr->transform.scale = scale;
    }
    return goPtr;
}

GameObject *GameLoop::spawnObject(std::string name, Transform transform)
{
    GameObject* goPtr = spawnObject(name);
    if (goPtr) goPtr->transform = transform;
    return goPtr;
}

bool GameLoop::despawnObject(std::string name)
{
    if (name == "") return false;
    return world.gameObjects.erase(name) > 0;
}

GameObject* GameLoop::getGameObjectByName(const std::string& name)
{
    if (name == "") return nullptr;

    auto it = world.gameObjects.find(name);
    if (it != world.gameObjects.end())
        return it->second.get();
    return nullptr;
}

bool GameLoop::doesGameObjectExist(const std::string& name)
{
    if (name == "") return false;
    return world.gameObjects.contains(name);
}

std::string GameLoop::getNameOfGameObject(GameObject *ptr)
{
    for (auto& p : world.gameObjects) {
        if (p.second.get() == ptr)
            return p.first;
    }
    return "";
}

size_t GameLoop::gameObjectCount() const
{ 
    return world.gameObjects.size();
}

std::vector<GameObject*> GameLoop::getGameObjects() const
{
    std::vector<GameObject*> result;
    result.reserve(world.gameObjects.size());

    for (const auto& [key, obj] : world.gameObjects)
        result.push_back(obj.get());

    return result;
}

void GameLoop::setBackgroundColor(const Color c)
{
    gfx.backgroundColor = c;
}
