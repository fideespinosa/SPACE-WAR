#pragma once
#include "Bullet.h"
class BulletEnemy : public Bullet
{
public:
	BulletEnemy(sf::Vector2f position) : Bullet(position) {
        _texture.loadFromFile("img/balaEnemigo.png");
        _sprite.setTexture(_texture);
        _sprite.setPosition(position);
        _speed = -4.0f; // Velocidad hacia abajo
	}
    void update(sf::Vector2f position);
};

