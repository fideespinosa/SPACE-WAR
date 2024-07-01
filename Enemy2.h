#pragma once
#include "Enemy.h"
#include <iostream>

class Enemy2 : public Enemy
{
public:

	int getLife();
	void setLife(int life);
	Enemy2(float x, float y) : Enemy(x, y) {

		if (!_texture.loadFromFile("img/enemy2.png")) {
			std::cout << "error en carga de textura" << std::endl;
		}
		_sprite.setTexture(_texture);
		_sprite.setPosition(x, y + _sprite.getGlobalBounds().top);
		_speed = 2;
		_life = 5;

		//Movimiento
		_stateMove = 0;
		if (!_textureMove.loadFromFile("img/moveEnemy2.png"))
		{
			std::cout << "Error al cargar naveMove" << std::endl;
		};
		_spriteMove.setTexture(_textureMove);
		_spriteMove.setPosition(x, y); //posicion inicial igual a nave
		_spriteMove.setTextureRect(sf::IntRect(0, 0, 64, 64)); // pos x , pos y, ancho (weitdh), largo (height)
	};

	sf::FloatRect getBounds() const;
	virtual ~Enemy2() = default;
	Enemy2() = default;
};

