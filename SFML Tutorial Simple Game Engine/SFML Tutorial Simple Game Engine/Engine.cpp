#include "Engine.h"

Engine::Engine()
{
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;

    m_Window.create(VideoMode(resolution.x, resolution.y), "Simple Game Engine", Style::Fullscreen);

    // Load the background into the texture
    // Be sure to scale this image to the screen size
    m_BackgroundTexture.loadFromFile("background.jpg");
    m_BackgroundSprite.setTexture(m_BackgroundTexture);
}

void Engine::start()
{
    Clock clock;

    while (m_Window.isOpen())
    {
        Time dt = clock.restart();

        // Make a fraction from the delta time
        float dtAsSeconds = dt.asSeconds();

        input();
        update(dtAsSeconds);
        draw();
    }
}
