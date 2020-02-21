// Anything after // is a comment not actual C++ code
// Comments are important and I use them to explain things
// Why not read the comments in this code

// These "include" code from the C++ library and SFML too
//#include "stdafx.h"
#include <SFML/Graphics.hpp>

// This is the main C++ program- Duh!
// It is where our game starts from
int main()
{
    // Make a window that is 800 by 600 pixels
    // And has the title "Variables Demo"
    sf::RenderWindow window(sf::VideoMode(800, 600), "Variables Demo");

    // Make three circles with 50 pixels radius
    // called circleRed, circleGreen and circleBlue
    sf::CircleShape circleRed(50);
    sf::CircleShape circleGreen(50);
    sf::CircleShape circleBlue(50);

    // Color the circles appropriately
    circleRed.setFillColor(sf::Color(255, 0, 0));
    circleGreen.setFillColor(sf::Color(0, 255, 0));
    circleBlue.setFillColor(sf::Color(0, 0, 255));

    // Here's the variables stuff
    float xGreen = 200;
    float yGreen = 200;

    float xBlue = 300;
    float yBlue = 300;

    // Hardcode position the red circle at x,y = 100, 100
    circleRed.setPosition(100, 100);

    // Set the position of the other two circles using variables
    circleGreen.setPosition(xGreen, yGreen);
    circleBlue.setPosition(xBlue, yBlue);

    // This "while" loop goes round and round- perhaps forever
    while (window.isOpen())
    {
        // The next 6 lines of code detect if the window is closed
        // And then shuts down the program
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                // Someone closed the window- bye
                window.close();
        }

        // Clear everything from the last run of the while loop
        window.clear();

        // Process stuff
        xGreen += 0.01;
        yGreen -= 0.01;

        xBlue += 0.03;
        yBlue += 0.03;

        circleGreen.setPosition(xGreen, yGreen);
        circleBlue .setPosition(xBlue, yBlue);

        // Draw our game scene here
        window.draw(circleRed);
        window.draw(circleGreen);
        window.draw(circleBlue);

        // Show everything we just drew
        window.display();
    }// This is the end of the "while" loop

    return 0;
}