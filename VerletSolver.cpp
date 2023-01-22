#include "VerletSolver.h"

const std::vector<VerletObject>& VerletSolver::get_objects() const {
    return objects;
}

const sf::Vector3f VerletSolver::get_constraint() const {
    return {constraint_center.x, constraint_center.y, constraint_radius};
}

void VerletSolver::set_frame_rate(int r) {
    frame_dt = 1. / r; 
}

void VerletSolver::set_num_substeps(int n) {
    num_substeps = n;
}

void VerletSolver::set_constraint(sf::Vector2f center, float radius) {
    constraint_center = center; 
    constraint_radius = radius; 
}

VerletObject& VerletSolver::add_object(sf::Vector2f pos, float radius, sf::Color color) {
    return objects.emplace_back(pos, radius, color);
}

void VerletSolver::update() {
    t += frame_dt;
    for (int i = 0; i < num_substeps; ++i) {
        update_objects(frame_dt / num_substeps);
    }
}

void VerletSolver::update_objects(float dt) {
    for (auto& obj : objects) {
        obj.accelerate(GRAVITATIONAL_CONSTANT);
        apply_constraint(obj); 
        obj.update(dt);
    }
}

void VerletSolver::apply_constraint(VerletObject& obj) {
    const sf::Vector2f v = constraint_center - obj.get_current_position();
    const float dist = sqrt(v.x * v.x + v.y * v.y);
    if (dist > (constraint_radius - obj.get_radius())) {
        const sf::Vector2f n = v / dist;
        obj.set_current_position(constraint_center - n * (constraint_radius - obj.get_radius()));
    }
}
