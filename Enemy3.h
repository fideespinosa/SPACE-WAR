#pragma once
#include "Enemy.h"
#include <iostream>

class Enemy3 : public Enemy
{
public:

	int getLife();
	void setLife(int life);
	Enemy3(float x, float y) : Enemy(x, y) {

		if (!_texture.loadFromFile("img/enemy3.png")) {
			std::cout << "error en carga de textura" << std::endl;
		}
		_sprite.setTexture(_texture);
		_sprite.setPosition(x, y + _sprite.getGlobalBounds().top);
		_speed = 1;
		_life = 10;

		//Movimiento
		_stateMove = 0;
		if (!_textureMove.loadFromFile("img/moveEnemy3.png"))
		{
			std::cout << "Error al cargar naveMove" << std::endl;
		};
		_spriteMove.setTexture(_textureMove);
		_spriteMove.setPosition(x, y); //posicion inicial igual a nave
		_spriteMove.setTextureRect(sf::IntRect(0, 0, 64, 64)); // pos x , pos y, ancho (weitdh), largo (height)
	};
	
	sf::FloatRect getBounds() const;
	virtual ~Enemy3() = default;
	Enemy3() = default;
};
