#include "Explosion.h"
#include <iostream>

Explosion::Explosion(sf::Vector2f position, int _type)
{

    switch (_type) {

    case 1:
        if (!_texture.loadFromFile("img/explosion/enemy1destruction.png")) {
            std::cout << "error en carga de textura" << std::endl;
        }
        _sprite.setTexture(_texture);
        _sprite.setPosition(position.x, position.y);
        _sprite.setTextureRect(sf::IntRect(576, 0, 64, 64)); // pos x , pos y, ancho (weitdh), largo (height)
        _stateExplosion = 10;
        _typeExplosion = 2;
        break;

    case 2:
        if (!_texture.loadFromFile("img/explosion/enemy2destruction.png")) {
            std::cout << "error en carga de textura" << std::endl;
        }
        _sprite.setTexture(_texture);
        _sprite.setPosition(position.x, position.y);
        _sprite.setTextureRect(sf::IntRect(512, 0, 64, 64)); // pos x , pos y, ancho (weitdh), largo (height)
        _stateExplosion = 9;
        _typeExplosion = 2;
        break;
    case 3:
        if (!_texture.loadFromFile("img/explosion/enemy3destruction.png")) {
            std::cout << "error en carga de textura" << std::endl;
        }
        _sprite.setTexture(_texture);
        _stateExplosion = 0;
        _sprite.setPosition(position.x, position.y);
        _sprite.setTextureRect(sf::IntRect(1408, 0, 128, 128)); // pos x , pos y, ancho (weitdh), largo (height)
        _stateExplosion = 12;
        _typeExplosion = 3;

        break;
    case 4:
        if (!_texture.loadFromFile("img/explosion/enemy4destruction.png")) {
            std::cout << "error en carga de textura" << std::endl;
        }
        _sprite.setTexture(_texture);
        //_sprite.setRotation(180);
        _sprite.setPosition(position.x, position.y);
        _sprite.setTextureRect(sf::IntRect(448, 0, 64, 64));
        _stateExplosion = 8;
        _typeExplosion = 4;
        break;
    case 5:
        if (!_texture.loadFromFile("img/explosion/animationDesc.png")) {
            std::cout << "error en carga de textura" << std::endl;
        }
        _sprite.setTexture(_texture);
        _stateExplosion = 0;
        _sprite.setPosition(position.x, position.y);
        _sprite.setTextureRect(sf::IntRect(0, 0, 128, 128)); // pos x , pos y, ancho (weitdh), largo (height)
        _typeExplosion = 5;

        break;
    default:
        std::cout << "Error" << std::endl;

    }
}

void Explosion::update(int _type)
{

    switch (_type) {
        
    case 1:
        if (_clock.getElapsedTime().asSeconds() > 0.1f)
        {
            _stateExplosion--;
            if (_stateExplosion >0) {
                _sprite.setTextureRect(sf::IntRect(_stateExplosion * 64, 0, 64, 64));
            }
            _clock.restart();
        }
        
        break;

    case 2:
        if (_clock.getElapsedTime().asSeconds() > 0.1f)
        {
            _stateExplosion--;
            if (_stateExplosion > 0) {
                _sprite.setTextureRect(sf::IntRect(_stateExplosion * 64, 0, 64, 64));
            }
            _clock.restart();
        }
        
        break;

    case 3:
        if (_clock.getElapsedTime().asSeconds() > 0.1f)
        {
            _stateExplosion--;
            if (_stateExplosion > 0) {
                _sprite.setTextureRect(sf::IntRect(_stateExplosion * 128, 0, 128, 128));
            }
            _clock.restart();
        }
        
        break;

    case 4:
        if (_clock.getElapsedTime().asSeconds() > 0.1f)
        {
            _stateExplosion--;
            if (_stateExplosion > 0) {
                _sprite.setTextureRect(sf::IntRect(_stateExplosion * 64, 0, 64, 64));
            }
            _clock.restart();

        }
        break;

    case 5:
        if (_clock.getElapsedTime().asSeconds() > 0.1f)
        {
            _stateExplosion++;
            if (_stateExplosion < 12) {
               
                _sprite.setTextureRect(sf::IntRect(_stateExplosion * 128, 0, 128, 128));
            }

            _clock.restart();
        }
        if (_stateExplosion == 12) {
            _stateExplosion = 0;
        }
        break;
    }
}

void Explosion::draw(sf::RenderWindow& window)
{
        if (_stateExplosion > 0) {
            _sprite.setTexture(_texture);
            window.draw(_sprite);
        }
        else if(getType()==5)
        {
            _sprite.setTexture(_texture);
            window.draw(_sprite);
        }
}

int Explosion::getType()
{
    return _typeExplosion;
}

int Explosion::getState() const
{
    return _stateExplosion;
}

