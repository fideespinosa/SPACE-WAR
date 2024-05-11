#include "Life.h"


Life::Life()
{
	_texture.loadFromFile("heart.png");
	_sprite.setTexture(_texture);
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
}


void Life::update()
{
}

void Life::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_sprite, states);
}

sf::FloatRect Life::getBounds() const
{
	return _sprite.getGlobalBounds();
}