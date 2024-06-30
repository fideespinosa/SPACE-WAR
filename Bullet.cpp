#include "Bullet.h"
#include <iostream>

Bullet::Bullet(sf::Vector2f position) {
    _stateMove = 0;
    if (!_texture.loadFromFile("img/bala.png"))
    {
        std::cout << "error en carga de textura Bala" << std::endl;
    };
    _sprite.setPosition(position.x - 10, position.y -10);
    _sprite.setTextureRect(sf::IntRect(0,0, 9, 12));
    _speed = -10.0f; // Velocidad hacia arriba
    _sprite.setScale(2.0f, 2.0f);
}



void Bullet::update()
{
    std::cout << "sale la bala personaje " << std::endl;
    _sprite.move(0, _speed);
    //Animacion de la bala
    if (_clockMove.getElapsedTime().asSeconds() > 0.5f)
    {
        _stateMove++;
        if (_stateMove < 8) {
            _sprite.setTextureRect(sf::IntRect(_stateMove * 9, 0, 9, 12));
        }
        _clockMove.restart();
    }
    if (_stateMove == 8)
    {
        _stateMove = 0;
    }
}

void Bullet::draw(sf::RenderWindow& window) 
{
    _sprite.setTexture(_texture);
    window.draw(_sprite);
}

sf::FloatRect Bullet::getBounds() const {
    return _sprite.getGlobalBounds();
}
