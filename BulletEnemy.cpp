#include "BulletEnemy.h"

void BulletEnemy::update(sf::Vector2f position)
{
	_sprite.move(0, -_speed);
}
