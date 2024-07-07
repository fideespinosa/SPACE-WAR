#pragma once

#include "Consumable.h"
#include <iostream>

class Life : public Consumable
{
public:
	Life() : Consumable() {

        //Movimiento
        _stateMove = 0;
        if (!_texture.loadFromFile("img/heart2.png"))
        {
            std::cout << "Error al cargar HEART" << std::endl;
        };
        _sprite.setTexture(_texture);
        _sprite.setPosition((std::rand() % 1024) + 1, 0 + _sprite.getGlobalBounds().top);
        _sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
        _life = 5;
        _speed = 2;
        _sprite.setScale(3.0f, 3.0f);
        _type = 0;
	}
};

