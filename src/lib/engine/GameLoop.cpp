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
                currentLevel->render(*this, gfx);
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
    currentLevel = level;
    currentLevel->start(*this);
}

double GameLoop::deltaTime() { return deltaT; }

double GameLoop::timeRunning() { return timeSinceStart; }
