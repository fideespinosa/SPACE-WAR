#pragma once

#include "Consumable.h"
#include <iostream>

class Life : public Consumable
{
public:
	Life() : Consumable() {

        //Movimiento
        _stateMove = 0;
        if (!_texture.loadFromFile("img/moveEnemy1.png"))
        {
            std::cout << "Error al cargar naveMove" << std::endl;
        };
        _sprite.setTexture(_texture);
        _sprite.setPosition((std::rand() % 1024) + 1, 0 + _sprite.getGlobalBounds().top);
        _sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
        _life = 5;
        _speed = 5;
        _sprite.setScale(2.0f, 2.0f);
	}
};

