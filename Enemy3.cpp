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

    sf::Vector2f position = _sprite.getPosition();

    if (!controlSprite(_sprite))
    {
        int randomMove = (std::rand() % 8) + 1;
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
            _sprite.move(0, _speed * 2); // abajo
            break;
        case 5:
            _sprite.move(_speed * 1.2f, 0); // der
            break;
        case 6:
            _sprite.move(-_speed * 1.2f, 0); //izq
            break;
        case 7:
            _sprite.move(0, _speed * 1.5f); //abajo 
            break;
        case 8:
            _sprite.move(0, _speed * 2); // abajo
            break;
        }
    }
    // movimiento de energia de la nave
    if (_clockMove.getElapsedTime().asSeconds() > 0.01f)
    {
        _stateMove++;
        _spriteMove.setPosition(position.x, position.y);
        if (_stateMove < 8) {
            _spriteMove.setTextureRect(sf::IntRect(_stateMove * 128, 0, 128, 128));
        }
        _clockMove.restart();
    }
    if (_stateMove == 8)
    {
        _stateMove = 0;
    }

    // movimiento de armas de la nave
    if (_clockWeapons.getElapsedTime().asSeconds() > 0.02f)
    {
        _stateWeapons++;
        _spriteWeapons.setPosition(position.x, position.y);
        if (_stateWeapons < 35) {
            _spriteWeapons.setTextureRect(sf::IntRect(_stateWeapons * 128, 0, 128, 128));
        }
        _clockWeapons.restart();
    }
    if (_stateWeapons == 35)
    {
        _stateWeapons = 0;
    }
}

sf::FloatRect Enemy3::getBounds() const
{
	return _sprite.getGlobalBounds();
}

