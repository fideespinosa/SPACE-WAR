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

sf::FloatRect Enemy4::getBounds() const
{
	return _sprite.getGlobalBounds();
}

