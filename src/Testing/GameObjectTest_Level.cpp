#include "GameObjectTest_Level.h"
#include "../lib/engine/Keyboard.h"
#include "../lib/math/VecMath.h"

#include <sstream>

// This level holds test code for GameObjects and Components. Main purpose of the test is to test out if Adding, removing, getting GameObjects works.
// If you want to try and test this, do the following:
//      - Go to "src/lib/engine/main.cpp" and change startingLevel variable to hold this Level's class name
//      - static auto startingLevel = SampleLevel();
//                     Change this -- ^^^^^^^^^^^

void GameObjectTest_Level::start(GameLoop &gl) // Runs when the level starts
{
    gl.showStats = true;
    GameObject* g1 = gl.spawn("Game Object 1", std::make_unique<GameObject>(), Vec3(10, 23));
    g1->addComponent<DummyComponent>();
    gl.spawn("Game Object 2", std::make_unique<GameObject>(), Vec3(23, 10));
    GameObject* g3 = gl.spawn("Game Object 3", std::make_unique<GameObject>(), Vec3(40, 9));
    g3->transform.scale = Vec2(0.5, 1.8);
}

void GameObjectTest_Level::update(GameLoop &gl) // Runs every frame while the level is loaded
{
    if (isKeyDown(Key::DELETE))
        gl.despawn("Game Object 2");

    if (isKeyDown(Key::ENTER) && !gl.doesGameObjectExist("Game Object 2")) {
        gl.spawn("Game Object 2", std::make_unique<GameObject>(), Vec3(23, 10));
    }
}

void GameObjectTest_Level::render(GameLoop &gl, Gfx &gfx) // Runs after right after update() for graphics rendering
{
    auto gameObjects = gl.getGameObjects();

    for (auto& go : gameObjects)
        gfx.drawRect(go->transform.position, go->transform.scale * 10, '#', ' ');

    auto gameObj2 = gl.getGameObjectByName("Game Object 2");
    if (gameObj2)
        gfx.drawText(gameObj2->transform.position + Vec3(2, 2), gl.getNameOfGameObject(gameObj2));

    std::ostringstream oss;
    oss << "Game object count: " << gl.gameObjectCount();
    gfx.drawText(0,0, oss.str());
}
