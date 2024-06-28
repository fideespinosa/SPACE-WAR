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

void Enemy3::update()
{
	if (!controlSprite(_sprite))
	{
		int randomMove = (std::rand() % 4) + 1;
		switch (randomMove) {
		case 1:
			_sprite.move(_speed, 0); // der
			break;
		case 2:
			_sprite.move(-_speed * 2, 0); //izq
			break;
		case 3:
			_sprite.move(0, _speed * 2); //abajo x2
			break;
		case 4:
			_sprite.move(0, _speed * 2); // abajo
			break;
		}
	}
}

void Enemy3::draw(sf::RenderWindow& window)
{
	_sprite.setTexture(_texture);
	window.draw(_sprite);
}

sf::FloatRect Enemy3::getBounds() const
{
	return _sprite.getGlobalBounds();
}

