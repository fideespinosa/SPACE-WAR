#include "Explosion.h"
#include <iostream>

Explosion::Explosion(sf::Vector2f position)
{
    if (!_texture.loadFromFile("img/Explosion.png")) {
        std::cout << "error en carga de textura" << std::endl;
    }
    _sprite.setTexture(_texture);
    _stateExplosion = 0;
    _sprite.setPosition(position.x, position.y);
    _sprite.setTextureRect(sf::IntRect(0,0,16,16)); // pos x , pos y, ancho (weitdh), largo (height)
    _sprite.setScale(4.0f, 4.0f);
}

void Explosion::update()
{
    if (_clock.getElapsedTime().asSeconds() > 0.1f)
    {
        _stateExplosion++;
        if (_stateExplosion < 8) {
            _sprite.setTextureRect(sf::IntRect(_stateExplosion *16, 0, 16, 15));
        }
        _clock.restart();
    }
}

void Explosion::draw(sf::RenderWindow& window)
{
    if (_stateExplosion < 8)
    {
        _sprite.setTexture(_texture);
        window.draw(_sprite);
    }
}

