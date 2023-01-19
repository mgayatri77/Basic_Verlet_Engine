#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "VerletObject.h"

class VerletSolver {
    private: 
        float t; 
        float frame_dt;
        int num_substeps;  
        std::vector<VerletObject> objects;  
        sf::Vector2f gravity;   

    public: 
        VerletSolver() : t(0.), frame_dt(0.), num_substeps(0.) {};
        VerletSolver(float r, int n) : t(0.), frame_dt(1. / r), num_substeps(n) {};
        void set_frame_rate(int r); 
        void set_num_substeps(int n);
        void add_object(VerletObject& obj); 
};