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



sf::FloatRect Enemy2::getBounds() const
{
	return _sprite.getGlobalBounds();
}

