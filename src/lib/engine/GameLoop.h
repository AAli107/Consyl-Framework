#ifndef GAMELOOP_H
#define GAMELOOP_H

#include "Gfx.h"
#include "World.h"

#include <concepts>
#include <utility>

class Level;

class GameLoop
{
private:
    bool isRunning = false;
    double timeSinceStart = 0.0;
    double deltaT = 0.0;
    Gfx gfx = Gfx();
    Level* currentLevel = nullptr;
    World world{};
    double tickAccumulatedTime = 0.0;
    int tickRate;
    double tickDeltaT;
public:
    bool showStats = false;
public:
    GameLoop(Level* startingLevel, int tickRate);
    void run();
    void stop();
    void openLevel(Level* level);
    double deltaTime();
    double tickDeltaTime();
    double timeRunning();
    void setTickRate(int tickRate);
    double getTickRate();
    GameObject* spawn(std::string name, std::unique_ptr<GameObject> gameObject);
    GameObject* spawn(std::string name, std::unique_ptr<GameObject> gameObject, Vec3 position);
    GameObject* spawn(std::string name, std::unique_ptr<GameObject> gameObject, Vec3 position, Vec3 scale);
    GameObject* spawn(std::string name, std::unique_ptr<GameObject> gameObject, Transform transform);
    bool despawn(std::string name);
    GameObject* getGameObjectByName(const std::string& name);
    bool doesGameObjectExist(const std::string& name);
    std::string getNameOfGameObject(GameObject* ptr);
    size_t gameObjectCount() const;
    std::vector<GameObject*> getGameObjects() const;
};

#endif