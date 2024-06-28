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
	if (!controlSprite(_sprite))
	{
		int randomMove = (std::rand() % 4) + 1;
		switch (randomMove) {
		case 1:
			_sprite.move(_speed, 0); // der
			break;
		case 2:
			_sprite.move(-_speed, 0); //izq
			break;
		case 3:
			_sprite.move(0, _speed); //abajo
			break;
		case 4:
			_sprite.move(0, _speed); // abajo
			break;
		}
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

