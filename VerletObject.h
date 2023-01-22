#pragma once

#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>

class VerletObject {
    private: 
        // define attributes
        sf::Vector2f current_position; 
        sf::Vector2f prev_position; 
        sf::Vector2f acceleration; 
        sf::Color color;
        float radius; 
        
        // prevent default constructor being called
        VerletObject();

    public: 
        // define constructor
        VerletObject(sf::Vector2f aPosition, float aRadius, sf::Color aColor) : 
            current_position(aPosition), 
            prev_position(aPosition), 
            acceleration(sf::Vector2f(0.0, 0.0)), 
            radius(aRadius), 
            color(aColor) {};
        
        // define public methods
        sf::Vector2f get_current_position() const; 
        float get_radius() const; 
        sf::Color get_color() const;
        sf::Vector2f get_velocity(float dt) const; 
        void set_current_position(sf::Vector2f pos); 
        void set_velocity(sf::Vector2f v, float dt); 
        void add_velocity(sf::Vector2f v, float dt);
        void accelerate(sf::Vector2f a);
        void update(float dt);
};