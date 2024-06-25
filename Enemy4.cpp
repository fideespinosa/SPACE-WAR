#include "Enemy4.h"
#include <iostream>

int Enemy4::getLife()
{
	return _life;
}

void Enemy4::setLife(int life)
{
	_life = life;
}

void Enemy4::update()
{
	std::srand(std::time(0));
	int randomMove = (std::rand() % 2) + 1;
	if (randomMove / 2 == 0) {
		_sprite.move(0, _speed);
	}
	else {
		_sprite.move(_speed * 2, 0);
	}
}

void Enemy4::draw(sf::RenderWindow& window)
{
	_sprite.setTexture(_texture);
	window.draw(_sprite);
}

sf::FloatRect Enemy4::getBounds() const
{
	return _sprite.getGlobalBounds();
}

