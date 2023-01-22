#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "VerletObject.h"

class VerletSolver {
        
    public: 
        VerletSolver() : t(0.), frame_dt(0.), num_substeps(0.) {};
        VerletSolver(float r, int n) : t(0.), frame_dt(1. / r), num_substeps(n) {};
        const std::vector<VerletObject>& get_objects() const;
        const sf::Vector3f get_constraint() const;
        void set_frame_rate(int r); 
        void set_num_substeps(int n);
        void set_constraint(sf::Vector2f center, float radius); 
        VerletObject& add_object(sf::Vector2f pos, float radius, sf::Color color); 
        void update();
    
    private: 
        float t; 
        float frame_dt;
        int num_substeps;  
        std::vector<VerletObject> objects;  
        sf::Vector2f constraint_center;
        float constraint_radius  = 100.0f;
        const sf::Vector2f GRAVITATIONAL_CONSTANT = {0.0f, 98.1f};
    
        void update_objects(float dt);
        void apply_constraint(VerletObject& obj);
};