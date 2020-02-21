// Anything after // is a comment not actual C++ code
// Comments are important and I use them to explain things
// Why not read the comments in this code

// These "include" code from the C++ library and SFML too
//#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "Bat.h"
#include "Ball.h"
#include <sstream>
#include <cstdlib>

using namespace sf;

// This is the main C++ program- Duh!
// It is where our game starts from
int main()
{
    int windowWidth = 1024;
    int windowHeight = 768;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Pong");

    int score = 0;
    int lives = 3;

    Bat bat(windowWidth / 2, windowHeight - 20);

    Ball ball(windowWidth / 2, 1);

    // Create a "Text" object called "message". Weird but we will learn about objects soon
    Text hud;

    // We need to choose a font
    Font font;
    // http://www.dafont.com/theme.php?cat=302
    font.loadFromFile("DS-DIGIT.TTF");
    hud.setFont(font);
    hud.setCharacterSize(75);
    hud.setFillColor(sf::Color::White);

    // This "while" loop goes round and round- perhaps forever
    while (window.isOpen())
    {
        // ====================================
        // Handle the player input!
        // ====================================
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                // Someone closed the window- bye
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            bat.moveLeft();
        }
        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            bat.moveRight();
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        // ====================================
        // Update!
        // ====================================
        // Handle ball hitting the bottom
        if (ball.getPosition().top > windowHeight)
        {
            // Reverse the ball direction
            ball.hitBottom();

            // Remove a life
            lives--;

            // Check for zero lives
            if (lives < 1)
            {
                // reset the score
                score = 0;
                // reset the lives
                lives = 3;
            }
        }

        // Handle ball hitting the top
        if (ball.getPosition().top < 0)
        {
            ball.reboundBatOrTop();

            // Add a point
            score++;
        }

        // Handle ball hitting the sides
        if (ball.getPosition().left < 0 || ball.getPosition().left + 10 > windowWidth)
        {
            ball.reboundSides();
        }

        // Handle ball hitting the bat
        if (ball.getPosition().intersects(bat.getPosition()))
        {
            // Detected a hit, reverse the ball
            ball.reboundBatOrTop();
        }

        bat.update();
        ball.update();

        // Update the HUD text
        std::stringstream ss;
        ss << "Score: " << score << "    Lives: " << lives;
        hud.setString(ss.str());


        // ====================================
        // Draw
        // ====================================

        // Clear everything from the last run of the while loop
        window.clear(Color(26, 128, 182, 255));

        window.draw(bat.getShape());
        window.draw(ball.getShape());
        window.draw(hud);

        // Show everything we just drew
        window.display();
    }// This is the end of the "while" loop

    return 0;
}