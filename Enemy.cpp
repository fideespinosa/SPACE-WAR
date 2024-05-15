#include "Enemy.h"

Enemy::Enemy()
{
	_texture.loadFromFile("heart.png");
	_sprite.setTexture(_texture);
	_sprite.setOrigin(500, 300);
	//ver setOrigin.
}
Enemy::Enemy(int x, int y)
{
	_texture.loadFromFile("nave.png");
	_sprite.setTexture(_texture);
	//_vel = 10;
	_sprite.setPosition(x, y);
}
void Enemy::update()
{
	//ver
}

void Enemy::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_sprite, states);
}

void Enemy::respawn()
{
	_sprite.setPosition(std::rand() % 1023, std::rand() % 287);
}

sf::FloatRect Enemy::getBounds() const
{
	return sf::FloatRect();
}
