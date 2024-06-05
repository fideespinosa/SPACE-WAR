#include "PowerUp.h"


PowerUp::PowerUp()
{
	_texture.loadFromFile("img/heart.png");
	_sprite.setTexture(_texture);
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
}


void PowerUp::update()
{
}

void PowerUp::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_sprite, states);
}

sf::FloatRect PowerUp::getGlobalBounds() const
{
	return _sprite.getGlobalBounds();
}