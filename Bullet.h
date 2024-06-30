#pragma once
#include <SFML/Graphics.hpp>
#include "Collisionable.h"

class Bullet : public Collisionable {
protected:
    sf::Sprite _sprite;
    sf::Texture _texture;
    float _speed;

public:
    Bullet(sf::Vector2f position);
    virtual void update();
    void draw(sf::RenderWindow& window) override;
    sf::FloatRect getBounds() const override;
};


