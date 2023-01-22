#include <cmath>
#include "VerletObject.h"

sf::Vector2f VerletObject::get_current_position() const {
    return current_position;     
}

float VerletObject::get_radius() const {
    return radius;     
}

sf::Color VerletObject::get_color() const {
    return color;     
}

[[nodiscard]]
sf::Vector2f VerletObject::get_velocity(float dt) const {
    return (current_position - prev_position) / dt;     
}

void VerletObject::set_current_position(sf::Vector2f pos) {
    current_position = pos;
}

void VerletObject::set_velocity(sf::Vector2f v, float dt) {
    prev_position = current_position - v * dt; 
}

void VerletObject::add_velocity(sf::Vector2f v, float dt) {
    prev_position -= v * dt; 
}

void VerletObject::accelerate(sf::Vector2f a) {
    acceleration += a; 
}

void VerletObject::update(float dt) {
    // save displacement
    const sf::Vector2f displacement = current_position - prev_position; 

    // update positions according to Verlet integration
    prev_position = current_position; 
    current_position += displacement + acceleration * dt * dt;

    // reset acceleration
    acceleration = {0.0, 0.0};
}