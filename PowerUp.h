#pragma once
#include "Collisionable.h"
#include <SFML/graphics.hpp>
#include "Consumable.h"
class PowerUp : public sf::Drawable, public Collisionable, public Consumable
{

public:
	sf::Sprite _sprite;
	sf::Texture _texture;
	PowerUp();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::FloatRect getBounds() const override; //sobreescribimos el metodo de collisionable

};


