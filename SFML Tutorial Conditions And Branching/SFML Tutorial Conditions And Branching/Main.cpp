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
    // Make a window that is 1000 by 700 pixels
    // And has the title "Conditions and branching demo"
    // Change the resolution if it is unsuitable for you

    int windowWidth = 1000;
    int windowHeight = 700;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Conditions and branching demo");

    // Let's make a few shapes
    // define a circle with radius = 100
    // Our new circle is called "tri"!!??!!
    sf::CircleShape tri(100);

    // A circle with 3 points
    // There is a clue in the variable name
    tri.setPointCount(3);

    // Here is another "circle"
    sf::CircleShape bumpy(100);
    bumpy.setPointCount(15);

    // Now lets have some variables for their positions (x and y)
    float triX = 0;
    float triY = 0;

    float bumpyX = windowWidth;
    float bumpyY = windowHeight;

    // Here are some variables that can never change.
    // Thet are called constants.
    // We make their names all uppercase to remind us.
    // We use the const keyword to make them constant.
    // We will see their purpose soon.
    const float LEFT = -1;
    const float RIGHT = 1;
    const float UP = -1;
    const float DOWN = 1;

    // The direction is not constant
    // tri starts with RIGHT and DOWN
    float triDirectionX = RIGHT;
    float triDirectionY = DOWN;

    // The direction is not constant
    // bumpy starts with LEFT and UP
    float bumpyDirectionX = LEFT;
    float bumpyDirectionY = UP;

    // How fast will they move
    float speed = .1;

    // This "while" loop goes round and round- perhaps forever
    // It only stops when the player closes the window
    while (window.isOpen())
    {

        // Has the player closed the game window?
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                // Someone closed the window- bye
                window.close();
        }

        // Handle the ai, physics and process updates
        // Watch out for collisions with the edge of the screen

        // First the tri shape
        if (triX > windowWidth) {
            // Triangle is near right of screen
            triDirectionX = LEFT;
        }
        else if (triX < 0) {
            // Triangle is near left of screen
            triDirectionX = RIGHT;
        }

        if (triY > windowHeight) {
            // Triangle is near bottom of screen
            triDirectionY = UP;
        }
        else if (triY < 0) {
            // Triangle is near top of screen
            triDirectionY = DOWN;
        }

        // Now for bumpy
        if (bumpyX > windowWidth) {
            // Bumpy shape is near right of screen
            bumpyDirectionX = LEFT;
        }
        else if (bumpyX < 0) {
            // Bumpy shape is near left of screen
            bumpyDirectionX = RIGHT;
        }

        if (bumpyY > windowHeight) {
            // Bumpy shape is near bottom of screen
            bumpyDirectionY = UP;
        }
        else if (bumpyY < 0) {
            // Bumpy shape is near top of screen
            bumpyDirectionY = DOWN;
        }

        // Let's move our two shapes based of the values
        // held by the appropriate ...directionX and ...directionY
        // and the speed variable
        triX = triX + speed * triDirectionX;
        triY = triY + speed * triDirectionY;

        bumpyX = bumpyX + speed * bumpyDirectionX;
        bumpyY = bumpyY + speed * bumpyDirectionY;

        // Set the position of the shapes
        tri.setPosition(triX, triY);
        bumpy.setPosition(bumpyX, bumpyY);

        // Clear everything from the last run of the while loop
        window.clear();

        // Draw our game scene
        window.draw(tri);
        window.draw(bumpy);

        // Show everything we just drew
        window.display();
    }// This is the end of the "while" loop

    return 0;
}