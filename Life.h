#pragma once
#include "Collisionable.h"
#include <SFML/graphics.hpp>
#include "Consumable.h"
class Life : public sf::Drawable, public Collisionable, public Consumable
{
	
public:
	Life();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::FloatRect getGlobalBounds() const override; //sobreescribimos el metodo de collisionable
	
};

