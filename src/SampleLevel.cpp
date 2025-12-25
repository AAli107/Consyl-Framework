#include <cmath>
#include <sstream>

#include "SampleLevel.h"
#include "lib/engine/Keyboard.h"

// This has bunch of test code, so clean them up if you want to use the SampleLevel or
// you could make your own level by making a class inherit Level abstract class

std::string keyboardStr = "";

void SampleLevel::start(GameLoop &gl) // Runs when the level starts
{
    gl.showStats = true;
}

void SampleLevel::update(GameLoop &gl) // Runs every frame while the level is loaded
{
    // if (isKeyDown(Key::ESCAPE))
    //     gl.stop();

    if (isKeyDown(Key::A)) keyboardStr = "A";
    if (isKeyDown(Key::B)) keyboardStr = "B";
    if (isKeyDown(Key::C)) keyboardStr = "C";
    if (isKeyDown(Key::D)) keyboardStr = "D";
    if (isKeyDown(Key::E)) keyboardStr = "E";
    if (isKeyDown(Key::F)) keyboardStr = "F";
    if (isKeyDown(Key::G)) keyboardStr = "G";
    if (isKeyDown(Key::H)) keyboardStr = "H";
    if (isKeyDown(Key::I)) keyboardStr = "I";
    if (isKeyDown(Key::J)) keyboardStr = "J";
    if (isKeyDown(Key::K)) keyboardStr = "K";
    if (isKeyDown(Key::L)) keyboardStr = "L";
    if (isKeyDown(Key::M)) keyboardStr = "M";
    if (isKeyDown(Key::N)) keyboardStr = "N";
    if (isKeyDown(Key::O)) keyboardStr = "O";
    if (isKeyDown(Key::P)) keyboardStr = "P";
    if (isKeyDown(Key::Q)) keyboardStr = "Q";
    if (isKeyDown(Key::R)) keyboardStr = "R";
    if (isKeyDown(Key::S)) keyboardStr = "S";
    if (isKeyDown(Key::T)) keyboardStr = "T";
    if (isKeyDown(Key::U)) keyboardStr = "U";
    if (isKeyDown(Key::V)) keyboardStr = "V";
    if (isKeyDown(Key::Q)) keyboardStr = "Q";
    if (isKeyDown(Key::R)) keyboardStr = "R";
    if (isKeyDown(Key::R)) keyboardStr = "R";
    if (isKeyDown(Key::S)) keyboardStr = "S";
    if (isKeyDown(Key::T)) keyboardStr = "T";
    if (isKeyDown(Key::U)) keyboardStr = "U";
    if (isKeyDown(Key::V)) keyboardStr = "V";
    if (isKeyDown(Key::W)) keyboardStr = "W";
    if (isKeyDown(Key::X)) keyboardStr = "X";
    if (isKeyDown(Key::Y)) keyboardStr = "Y";
    if (isKeyDown(Key::Z)) keyboardStr = "Z";
    if (isKeyDown(Key::DIGIT_0)) keyboardStr = "DIGIT_0";
    if (isKeyDown(Key::DIGIT_1)) keyboardStr = "DIGIT_1";
    if (isKeyDown(Key::DIGIT_2)) keyboardStr = "DIGIT_2";
    if (isKeyDown(Key::DIGIT_3)) keyboardStr = "DIGIT_3";
    if (isKeyDown(Key::DIGIT_4)) keyboardStr = "DIGIT_4";
    if (isKeyDown(Key::DIGIT_5)) keyboardStr = "DIGIT_5";
    if (isKeyDown(Key::DIGIT_6)) keyboardStr = "DIGIT_6";
    if (isKeyDown(Key::DIGIT_7)) keyboardStr = "DIGIT_7";
    if (isKeyDown(Key::DIGIT_8)) keyboardStr = "DIGIT_8";
    if (isKeyDown(Key::DIGIT_9)) keyboardStr = "DIGIT_9";
    if (isKeyDown(Key::UP)) keyboardStr = "UP";
    if (isKeyDown(Key::DOWN)) keyboardStr = "DOWN";
    if (isKeyDown(Key::LEFT)) keyboardStr = "LEFT";
    if (isKeyDown(Key::RIGHT)) keyboardStr = "RIGHT";
    if (isKeyDown(Key::L_SHIFT)) keyboardStr = "L_SHIFT";
    if (isKeyDown(Key::R_SHIFT)) keyboardStr = "R_SHIFT";
    if (isKeyDown(Key::L_CTRL)) keyboardStr = "L_CTRL";
    if (isKeyDown(Key::R_CTRL)) keyboardStr = "R_CTRL";
    if (isKeyDown(Key::L_ALT)) keyboardStr = "L_ALT";
    if (isKeyDown(Key::R_ALT)) keyboardStr = "R_ALT";
    if (isKeyDown(Key::SPACE)) keyboardStr = "SPACE";
    if (isKeyDown(Key::ENTER)) keyboardStr = "ENTER";
    if (isKeyDown(Key::ESCAPE)) keyboardStr = "ESCAPE";
    if (isKeyDown(Key::TAB)) keyboardStr = "TAB";
    if (isKeyDown(Key::BACKSPACE)) keyboardStr = "BACKSPACE";
    if (isKeyDown(Key::F1)) keyboardStr = "F1";
    if (isKeyDown(Key::F2)) keyboardStr = "F2";
    if (isKeyDown(Key::F3)) keyboardStr = "F3";
    if (isKeyDown(Key::F4)) keyboardStr = "F4";
    if (isKeyDown(Key::F5)) keyboardStr = "F5";
    if (isKeyDown(Key::F6)) keyboardStr = "F6";
    if (isKeyDown(Key::F7)) keyboardStr = "F7";
    if (isKeyDown(Key::F8)) keyboardStr = "F8";
    if (isKeyDown(Key::F9)) keyboardStr = "F9";
    if (isKeyDown(Key::F10)) keyboardStr = "F10";
    if (isKeyDown(Key::F11)) keyboardStr = "F11";
    if (isKeyDown(Key::F12)) keyboardStr = "F12";
    if (isKeyDown(Key::NUM_0)) keyboardStr = "NUM_0";
    if (isKeyDown(Key::NUM_1)) keyboardStr = "NUM_1";
    if (isKeyDown(Key::NUM_2)) keyboardStr = "NUM_2";
    if (isKeyDown(Key::NUM_3)) keyboardStr = "NUM_3";
    if (isKeyDown(Key::NUM_4)) keyboardStr = "NUM_4";
    if (isKeyDown(Key::NUM_5)) keyboardStr = "NUM_5";
    if (isKeyDown(Key::NUM_6)) keyboardStr = "NUM_6";
    if (isKeyDown(Key::NUM_7)) keyboardStr = "NUM_7";
    if (isKeyDown(Key::NUM_8)) keyboardStr = "NUM_8";
    if (isKeyDown(Key::NUM_9)) keyboardStr = "NUM_9";
    if (isKeyDown(Key::NUM_ADD)) keyboardStr = "NUM_ADD";
    if (isKeyDown(Key::NUM_SUBTRACT)) keyboardStr = "NUM_SUBTRACT";
    if (isKeyDown(Key::NUM_MULTIPLY)) keyboardStr = "NUM_MULTIPLY";
    if (isKeyDown(Key::NUM_DIVIDE)) keyboardStr = "NUM_DIVIDE";
    if (isKeyDown(Key::MINUS)) keyboardStr = "MINUS";
    if (isKeyDown(Key::EQUAL)) keyboardStr = "EQUAL";
    if (isKeyDown(Key::L_BRACKET)) keyboardStr = "L_BRACKET";
    if (isKeyDown(Key::R_BRACKET)) keyboardStr = "R_BRACKET";
    if (isKeyDown(Key::BACKSLASH)) keyboardStr = "BACKSLASH";
    if (isKeyDown(Key::SEMICOLON)) keyboardStr = "SEMICOLON";
    if (isKeyDown(Key::APOSTROPHE)) keyboardStr = "APOSTROPHE";
    if (isKeyDown(Key::GRAVE)) keyboardStr = "GRAVE";
    if (isKeyDown(Key::COMMA)) keyboardStr = "COMMA";
    if (isKeyDown(Key::PERIOD)) keyboardStr = "PERIOD";
    if (isKeyDown(Key::SLASH)) keyboardStr = "SLASH";
}

void SampleLevel::render(GameLoop &gl, Gfx &gfx) // Runs after right after update() for graphics rendering
{
    gfx.drawText(Vec2(0,0), keyboardStr);

    gfx.drawRect(Vec2(5, 5), Vec2(10, 10), '#', '.');
    gfx.drawCircle(32, 20, 10, '#', '-');

    double speed = 8;
    Vec2 v(32 + cos(levelTime * speed) * 10, 20 + sin(levelTime * speed) * 10);
    gfx.drawLine(Vec2(10, 10), v, '#');
    gfx.setPixel(v, 'A');

    std::ostringstream fpsOss;
    fpsOss << (1.0 / gl.deltaTime()) << " FPS";
    gfx.drawText(Vec2(30, 40), fpsOss.str());
}

void SampleLevel::end(GameLoop &gl) // Runs when level ends
{
}
