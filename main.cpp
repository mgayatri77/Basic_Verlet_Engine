#include <SFML/Graphics.hpp>
#include "VerletObject.h"

int main()
{
    constexpr int window_height = 1000;
    constexpr int window_width = 800;
    constexpr int frame_rate = 60; 

    sf::RenderWindow window(sf::VideoMode(window_height, window_width), "Basic Verlet Engine!");
    window.setFramerateLimit(frame_rate);

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}