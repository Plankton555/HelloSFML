#pragma once
#include <SFML/Graphics.hpp>
#include "EScreen.h"
#include "Screen.h"
#include "MainMenuScreen.h"
#include "GameScreen.h"

using namespace sf;

class SimpleGame
{
private:
    RenderWindow m_Window;
    std::shared_ptr<Screen> m_activeScreen;
public:
    SimpleGame();
    void start();
};
