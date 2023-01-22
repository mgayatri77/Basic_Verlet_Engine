#include "Renderer.h"

void Renderer::render(const VerletSolver& solver) {
    const sf::Vector3f constraint = solver.get_constraint();
    sf::CircleShape constraint_background{constraint.z};
    constraint_background.setOrigin(constraint.z, constraint.z);
    constraint_background.setFillColor(sf::Color::Yellow);
    constraint_background.setPosition(constraint.x, constraint.y);
    constraint_background.setPointCount(128);
    target.draw(constraint_background);

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