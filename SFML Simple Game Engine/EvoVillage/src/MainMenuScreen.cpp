#include "MainMenuScreen.h"
#include <iostream>

MainMenuScreen::MainMenuScreen()
{
    m_font.loadFromFile("fonts/28 Days Later.ttf");
    m_menuText.setFont(m_font);
    m_menuText.setString("Press ENTER to start");
    m_menuText.setCharacterSize(60);
    sf::FloatRect bounds = m_menuText.getLocalBounds();
    m_menuText.setOrigin(bounds.width / 2, bounds.height / 2);
}

void MainMenuScreen::render(float dt, RenderWindow* rw)
{
    input();
    update(dt);
    draw(rw);
}

void MainMenuScreen::input()
{
    if (Keyboard::isKeyPressed(Keyboard::Enter))
    {
        m_switchScreen = EScreen::game;
    }
}

void MainMenuScreen::update(float dt)
{
}

void MainMenuScreen::draw(RenderWindow* rw)
{
    rw->clear(Color(100, 100, 200));

    m_menuText.setPosition(rw->getSize().x / 2, rw->getSize().y / 2);
    rw->draw(m_menuText);

    rw->display();
}

void MainMenuScreen::dispose()
{
}

bool MainMenuScreen::shouldSwitchScreen()
{
    return m_switchScreen != EScreen::mainmenu;
}

EScreen MainMenuScreen::getSwitchScreen()
{
    return m_switchScreen;
}
