#pragma once
#include "Bullet.h"
class BulletEnemy : public Bullet
{
public:
	BulletEnemy(sf::Vector2f position) : Bullet(position) {
        _texture.loadFromFile("img/balaEnemigo.png");
        _sprite.setTexture(_texture);
        _sprite.setPosition(position);
        _speed = -2.0f; // Velocidad hacia abajo
        _sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
        _sprite.setScale(2.0f, 2.0f);
        _stateMove = 0;
	}
    void update() override;
    void draw(sf::RenderWindow& window) override;
};

