#include <cmath>
#include "VerletObject.h"

[[nodiscard]]
sf::Vector2f VerletObject::get_velocity(float dt) {
    return (current_position - prev_position) / dt;     
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

void VerletObject::update_object(float dt) {
    // save displacement
    const sf::Vector2f displacement = current_position - prev_position; 

    // update positions according to Verlet integration
    prev_position = current_position; 
    current_position += displacement + acceleration * dt * dt;

    // reset acceleration
    acceleration = {0.0, 0.0};
}