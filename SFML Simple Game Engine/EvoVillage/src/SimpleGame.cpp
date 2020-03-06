#include "SimpleGame.h"

SimpleGame::SimpleGame()
{
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;

    m_Window.create(VideoMode(resolution.x, resolution.y), "Simple Game Engine", Style::Default /*Style::Fullscreen*/);
}

void SimpleGame::start()
{
    Clock clock;

    m_activeScreen = std::make_shared<MainMenuScreen>();

    while (m_Window.isOpen())
    {
        Time dt = clock.restart();

        // Make a fraction from the delta time
        float deltaTime = dt.asSeconds();

        // Handle the player quitting
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            m_Window.close();
        }

        m_activeScreen->render(deltaTime, &m_Window);

        if (m_activeScreen->shouldSwitchScreen())
        {
            EScreen newScreen = m_activeScreen->getSwitchScreen();
            switch (newScreen)
            {
            case EScreen::game:
                m_activeScreen = std::make_shared<GameScreen>();
            default:
                break;
            }
        }
    }
}
