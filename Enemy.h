#pragma once
#include <SFML/Graphics.hpp>
#include "Collisionable.h"

// investigar vector de enemigos, para poder hacer varios respawn.

class Enemy : public sf::Drawable, public Collisionable
{
	sf::Sprite _sprite;
	sf::Texture _texture;
public:
	Enemy();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
	void respawn();
	sf::FloatRect getBounds() const override;
};

