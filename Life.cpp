#include "Life.h"


Life::Life()
{
	_texture.loadFromFile("img/heart.png");
	_sprite.setTexture(_texture);
	_sprite.setOrigin(std::rand() % 1023 / _sprite.getGlobalBounds().width, std::rand() % 287 / _sprite.getGlobalBounds().height);
	_velocity = 2.5;
}


void Life::update()
{
	int x = 1024, y = 573;

	for (int i = 1; i < y; i++) {
		_sprite.move(0, _velocity);
	}

}

void Life::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_sprite, states);
}

sf::FloatRect Life::getGlobalBounds() const
{
	return _sprite.getGlobalBounds();
}