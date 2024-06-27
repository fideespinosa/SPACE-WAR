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
	int randomMove = (std::rand() % 4) + 1;
	switch (randomMove) {
	case 1:
		_sprite.move(0, _speed);
		break;
	case 2:
		_sprite.move(_speed * -1, 3);
		break;
	case 3:
		_sprite.move(0, _speed * 2);
		break;
	case 4:
		_sprite.move(0, _speed);
		_sprite.move(_speed,0);
		break;
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

