#include "Consumable.h"
#include <stdlib.h>



void Consumable::update()
{
    sf::Vector2f position = _sprite.getPosition();
    // movimiento de energia del corazon

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
    if (_clockMove.getElapsedTime().asSeconds() > 0.03f)
    {
        _stateMove++;
        _sprite.setPosition(position.x, position.y);
        if (_stateMove < 5) {
            _sprite.setTextureRect(sf::IntRect(_stateMove * 16, 0, 16, 16));
        }
        _clockMove.restart();
    }
    if (_stateMove == 5)
    {
        _stateMove = 0;
    }
}

void Consumable::draw(sf::RenderWindow& window)
{
    _sprite.setTexture(_texture);
    window.draw(_sprite);
}

bool Consumable::controlSprite(sf::Sprite& _sprite)
{
    sf::Vector2f position = _sprite.getPosition();
    sf::FloatRect bounds = _sprite.getGlobalBounds();

    if (bounds.left <= 0) {
        _sprite.move(_speed * 1.5f, 0);
    }
    else if (bounds.left + bounds.width >= 1024) {
        _sprite.move(-_speed * 1.5f, 0);
    }
    else {
        return false;
    }

    return true;
}
