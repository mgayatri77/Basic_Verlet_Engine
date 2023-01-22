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
        const sf::Vector2f GRAVITATIONAL_CONSTANT = {0.0f, 98.1f};

    public: 
        VerletSolver() : t(0.), frame_dt(0.), num_substeps(0.) {};
        VerletSolver(float r, int n) : t(0.), frame_dt(1. / r), num_substeps(n) {};
        const std::vector<VerletObject>& get_objects() const;
        void set_frame_rate(int r); 
        void set_num_substeps(int n);
        VerletObject& add_object(sf::Vector2f pos, float radius, sf::Color color); 
        void update();
    
    private: 
        void update_objects(float dt);
};