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
	sf::Vector2f position = _sprite.getPosition();
	if (!controlSprite(_sprite)) {
		int randomMove = (std::rand() % 4) + 1;
		switch (randomMove) {
		case 1:
			_sprite.move(_speed, 0); // der
			break;
		case 2:
			_sprite.move(-_speed, 0); //izq
			break;
		case 3:
			_sprite.move(0, _speed * 2); //abajo x2
			break;
		case 4:
			_sprite.move(0, _speed); // abajo
			break;
		}
	}
	// movimiento de energia de la nave
	if (_clockMove.getElapsedTime().asSeconds() > 0.01f)
	{
		_stateMove++;
		_spriteMove.setPosition(position.x, position.y);
		if (_stateMove < 8) {
			_spriteMove.setTextureRect(sf::IntRect(_stateMove * 64, 0, 64, 64));
		}
		_clockMove.restart();
	}
	if (_stateMove == 8)
	{
		_stateMove = 0;
	}

}

sf::FloatRect Enemy1::getBounds() const
{
	return _sprite.getGlobalBounds();
}

