#pragma once
#include <SFML\Graphics.hpp>

class Collisionable {

public:
    virtual sf::FloatRect getBounds() const = 0;
    virtual void draw(sf::RenderWindow& window) = 0;

};


