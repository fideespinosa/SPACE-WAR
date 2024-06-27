#include "Enemy1.h"
#include <iostream>

int Enemy1::getLife()
{
	return _life;
}

void Enemy1::setLife(int life)
{
	_life = life;
}


void Enemy1::update()
{
	std::srand(std::time(0));
	int randomMove = (std::rand() % 2) + 1;
	if (randomMove / 2 == 0) {
		_sprite.move(0, _speed);
	}
	else {
		_sprite.move(_speed * 2, -_speed);
	}
}

void Enemy1::draw(sf::RenderWindow& window)
{
	_sprite.setTexture(_texture);
	window.draw(_sprite);
}

sf::FloatRect Enemy1::getBounds() const
{
	return _sprite.getGlobalBounds();
}

