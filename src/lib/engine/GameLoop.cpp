#include <iostream>
#include <chrono>

#include "GameLoop.h"
#include "Level.h"
#include "../utils/sleep.h"

GameLoop::GameLoop(Level* level) {
    openLevel(level);
}

void GameLoop::run()
{
    if (!isRunning) {
        isRunning = true;
        while (isRunning) {
            auto startTime = std::chrono::high_resolution_clock::now();
            
            if (currentLevel) {
                currentLevel->update(*this);
                // TODO: Add a fixed update `tick()` function for levels
                currentLevel->render(*this, gfx);
            }

            for (auto& kv : world.gameObjects) {
                if (!kv.second || !kv.second->enabled) continue;
                kv.second->update(*this);
                kv.second->tick(*this); // TODO: Make tick() run at fixed amount of time
                kv.second->render(*this, gfx);
            }

            gfx.render();
            if (showStats)
                std::cout << (1.0 / deltaT) << " FPS         \n" << (deltaT * 1000.0) << " ms         ";

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

double GameLoop::timeRunning() { return timeSinceStart; }

GameObject* GameLoop::spawn(std::string name, std::unique_ptr<GameObject> gameObject)
{
    std::string newName = name == "" ? "Game Object" : name;
    int n = 0;
    while (world.gameObjects.contains(newName)) {
        std::ostringstream oss;
        oss << name << ' ' << n;
        n++;
        newName = oss.str();
    }

    auto [it, _] = world.gameObjects.emplace( std::move(newName), std::move(gameObject) );

    return it->second.get();
}

GameObject *GameLoop::spawn(std::string name, std::unique_ptr<GameObject> gameObject, Vec3 position)
{
    GameObject* goPtr = spawn(name, std::move(gameObject));
    if (goPtr) goPtr->transform.position = position;
    return goPtr;
}

GameObject *GameLoop::spawn(std::string name, std::unique_ptr<GameObject> gameObject, Vec3 position, Vec3 scale)
{
    GameObject* goPtr = spawn(name, std::move(gameObject));
    if (goPtr) {
        goPtr->transform.position = position;
        goPtr->transform.scale = scale;
    }
    return goPtr;
}

GameObject *GameLoop::spawn(std::string name, std::unique_ptr<GameObject> gameObject, Transform transform)
{
    GameObject* goPtr = spawn(name, std::move(gameObject));
    if (goPtr) goPtr->transform = transform;
    return goPtr;
}

bool GameLoop::despawn(std::string name)
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
