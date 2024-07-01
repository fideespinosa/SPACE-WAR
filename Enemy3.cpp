#include "Enemy3.h"
#include <iostream>

int Enemy3::getLife()
{
	return _life;
}

void Enemy3::setLife(int life)
{
	_life = life;
}


sf::FloatRect Enemy3::getBounds() const
{
	return _sprite.getGlobalBounds();
}

