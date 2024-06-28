#pragma once
#include <SFML/Graphics.hpp>
#include "Collisionable.h"

class Bullet : public Collisionable {
private:
    sf::Sprite _sprite;
    sf::Texture _texture;
    float _speed;
    int _direction;

public:
    Bullet(sf::Vector2f position, int type);
    Bullet(sf::Vector2f position);
    void update();
    void draw(sf::RenderWindow& window) override;
    sf::FloatRect getBounds() const override;
};


