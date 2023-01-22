#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "VerletSolver.h"
#include "VerletObject.h"

class Renderer {
    private: 
        sf::RenderTarget& target;
    public: 
        Renderer(sf::RenderTarget& aTarget): target(aTarget) {};
        void render(const VerletSolver& objects);
};