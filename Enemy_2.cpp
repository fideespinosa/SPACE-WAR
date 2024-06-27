#include "Enemy_2.h"

Enemy Enemy_2::getEnemy()
{
	_texture.loadFromFile("img/enemy3.png");
	_sprite.setTexture(_texture);
	return Enemy(200,200,1);
}
