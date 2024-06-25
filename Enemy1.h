#pragma once
#include "Enemy.h"
#include <iostream>

class Enemy1 : public Enemy
{
public:

	int getLife();
	void setLife(int life);
	Enemy1(float x, float y) : Enemy(x, y) {
        
        if (!_texture.loadFromFile("img/enemy1.png")) {
            std::cout << "error en carga de textura" << std::endl;
        }
        _sprite.setTexture(_texture);
        _sprite.setPosition(x, y);
        _speed = 0.2f;
		_life = 5;
    };
	void update();
	void draw(sf::RenderWindow& window) override;
	sf::FloatRect getBounds() const ;
	virtual ~Enemy1() = default;
	Enemy1() = default;
};

