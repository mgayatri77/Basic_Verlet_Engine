#include "VerletSolver.h"

const std::vector<VerletObject>& VerletSolver::get_objects() const {
    return objects;
}

void VerletSolver::set_frame_rate(int r) {
    frame_dt = 1. / r; 
}

void VerletSolver::set_num_substeps(int n) {
    num_substeps = n;
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
        obj.update(dt);
    }
}

