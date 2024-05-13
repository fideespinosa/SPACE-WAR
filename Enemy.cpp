#include "Enemy.h"

Enemy::Enemy()
{
	_texture.loadFromFile("heart.png");
	_sprite.setTexture(_texture);
	_sprite.setOrigin(std::rand() % 1023 / _sprite.getGlobalBounds().width, std::rand() % 287 / _sprite.getGlobalBounds().height);
	//ver setOrigin.
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
