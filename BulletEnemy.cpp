#include "BulletEnemy.h"

void BulletEnemy::update()
{
	_sprite.move(0, -_speed);

    if (_clockMove.getElapsedTime().asSeconds() > 0.1f)
    {
        _stateMove++;
        if (_stateMove < 16) {
            _sprite.setTextureRect(sf::IntRect(_stateMove * 16, 0, 16, 16));
        }
        _clockMove.restart();
    }
    if (_stateMove == 16)
    {
        _stateMove = 0;
    }
}


void BulletEnemy::draw(sf::RenderWindow& window)
{
    _sprite.setTexture(_texture);
    window.draw(_sprite);
}