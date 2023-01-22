#include "Renderer.h"

void Renderer::render(const VerletSolver& solver) {
    sf::CircleShape curr_object{1.0f};
    curr_object.setPointCount(32);
    curr_object.setOrigin(1.0f, 1.0f);
    
    for (const auto& obj: solver.get_objects()) {
        curr_object.setPosition(obj.get_current_position());
        curr_object.setScale(obj.get_radius(), obj.get_radius());
        curr_object.setFillColor(obj.get_color());
        target.draw(curr_object); 
    }
}