#include "VerletSolver.h"

void VerletSolver::set_frame_rate(int r) {
    frame_dt = 1. / r; 
}

void VerletSolver::set_num_substeps(int n) {
    num_substeps = n;
}

void VerletSolver::add_object(VerletObject& obj) {
    objects.push_back(obj);
}

void VerletSolver::update() {
    t += frame_dt; 
    
}

