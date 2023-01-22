#include <SFML/Graphics.hpp>
#include "VerletObject.h"
#include "VerletSolver.h"
#include "Renderer.h"

int main()
{
    constexpr int window_height = 1000;
    constexpr int window_width = 800;
    constexpr int frame_rate = 60; 
    constexpr int max_objects_count = 1; 

    sf::ContextSettings settings;
    settings.antialiasingLevel = 1;
    
    sf::RenderWindow window(sf::VideoMode(window_height, window_width), "Basic Verlet Engine!");
    window.setFramerateLimit(frame_rate);

    VerletSolver solver;
    Renderer renderer{window};

    // set main attributes
    solver.set_num_substeps(8);
    solver.set_frame_rate(frame_rate);

    // add circle    
    const sf::Vector2f object_spawn_position = {500.0f, 200.0f};
    VerletObject &object = solver.add_object(object_spawn_position, 25.0, sf::Color::Blue);

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        solver.update();
        window.clear();
        renderer.render(solver);
		window.display();
    }

    return 0;
}