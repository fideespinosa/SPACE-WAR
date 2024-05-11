#pragma once
#include "Collisionable.h"
#include <SFML/graphics.hpp>
#include "Consumible.h"
class PowerUp : public sf::Drawable, public Collisionable, public Consumible
{

public:
	PowerUp();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::FloatRect getBounds() const override; //sobreescribimos el metodo de collisionable

};


