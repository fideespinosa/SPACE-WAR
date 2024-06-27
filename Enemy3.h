#pragma once
#include "Enemy.h"
#include <iostream>

class Enemy3 : public Enemy
{
public:

	int getLife();
	void setLife(int life);
	Enemy3(float x, float y) : Enemy(x, y) {

		if (!_texture.loadFromFile("img/enemy3.png")) {
			std::cout << "error en carga de textura" << std::endl;
		}
		_sprite.setTexture(_texture);
		_sprite.setPosition(x, y);
		_sprite.setRotation(180.f);
		_speed = 1;
		_life = 5;
		
	};
	void update();
	void draw(sf::RenderWindow& window) override;
	sf::FloatRect getBounds() const;
	virtual ~Enemy3() = default;
	Enemy3() = default;
};
