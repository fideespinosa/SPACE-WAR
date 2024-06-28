#pragma once
#include "Enemy.h"
#include <iostream>

class Enemy2 : public Enemy
{
public:

	int getLife();
	void setLife(int life);
	Enemy2(float x, float y) : Enemy(x, y) {

		if (!_texture.loadFromFile("img/enemy2.png")) {
			std::cout << "error en carga de textura" << std::endl;
		}
		_sprite.setTexture(_texture);
		_sprite.setPosition(x, y + _sprite.getGlobalBounds().top);
		_speed = 3;
		_life = 5;
	};
	void update();
	void draw(sf::RenderWindow& window) override;
	sf::FloatRect getBounds() const;
	virtual ~Enemy2() = default;
	Enemy2() = default;
};

