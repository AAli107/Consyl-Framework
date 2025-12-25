#ifndef GAMELOOP_H
#define GAMELOOP_H
#include "Gfx.h"

class Level;

class GameLoop
 {
private:
    bool isRunning = false;
    double timeSinceStart = 0.0;
    double deltaT = 0.0;
    Gfx gfx = Gfx();
    Level* currentLevel = nullptr;
public:
    bool showStats = false;
public:
    GameLoop(Level* startingLevel);
    void run();
    void stop();
    void openLevel(Level* level);
    double deltaTime();
    double timeRunning();
 }; 
#endif