#include "Enemy2.h"
#include <iostream>

int Enemy2::getLife()
{
	return _life;
}

void Enemy2::setLife(int life)
{
	_life = life;
}

void Enemy2::update()
{
	std::srand(std::time(0));
	int randomMove = (std::rand() % 2) + 1;
	if (randomMove / 2 == 0) {
		_sprite.move(0, _speed);
	}
	else {
		_sprite.move(_speed, 0);
	}
}

void Enemy2::draw(sf::RenderWindow& window)
{
	_sprite.setTexture(_texture);
	window.draw(_sprite);
}

sf::FloatRect Enemy2::getBounds() const
{
	return _sprite.getGlobalBounds();
}

