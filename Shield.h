#pragma once

#include "Consumable.h"
#include <iostream>

class Shield : public Consumable
{

public:
    Shield() : Consumable() {

        //Movimiento
        _stateMove = 0;
        if (!_texture.loadFromFile("img/shield.png"))
        {
            std::cout << "Error al cargar SHIELD" << std::endl;
        };
        _sprite.setTexture(_texture);
        _sprite.setPosition((std::rand() % 1024) + 1, 0 + _sprite.getGlobalBounds().top);
        _sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
        _life = 5;
        _speed = 3;
        _type = 1;
    }
 
};


