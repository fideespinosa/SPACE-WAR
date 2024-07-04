#pragma once
#include <SFML/Graphics.hpp>
#include "Collisionable.h"

class Bullet : public Collisionable {
protected:
    sf::Sprite _sprite;
    sf::Texture _texture;
    float _speed;
    int _stateMove;
    sf::Clock _clockMove;

public: 
    Bullet(sf::Vector2f position);
    virtual void update();
    virtual void draw(sf::RenderWindow& window) override;
    sf::FloatRect getBounds() const override;
    sf::Vector2f getPosition() const;
};


