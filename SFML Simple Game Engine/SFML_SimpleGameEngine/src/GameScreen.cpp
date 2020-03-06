#include "GameScreen.h"

GameScreen::GameScreen()
{
    // Load the background into the texture
    // Be sure to scale this image to the screen size
    m_BackgroundTexture.loadFromFile("assets/background.jpg");
    m_BackgroundSprite.setTexture(m_BackgroundTexture);
}

void GameScreen::render(float dt, RenderWindow* rw)
{
    input();
    update(dt);
    draw(rw);
}

void GameScreen::input()
{
    if (Keyboard::isKeyPressed(Keyboard::A))
    {
        m_Bob.moveLeft();
    }
    else
    {
        m_Bob.stopLeft();
    }

    if (Keyboard::isKeyPressed(Keyboard::D))
    {
        m_Bob.moveRight();
    }
    else
    {
        m_Bob.stopRight();
    }
}

void GameScreen::update(float dt)
{
    m_Bob.update(dt);
}

void GameScreen::draw(RenderWindow* rw)
{
    rw->clear(Color::White);

    rw->draw(m_BackgroundSprite);
    rw->draw(m_Bob.getSprite());

    rw->display();
}

void GameScreen::dispose()
{
}

bool GameScreen::shouldSwitchScreen()
{
	return false;
}

EScreen GameScreen::getSwitchScreen()
{
	return EScreen::game;
}
