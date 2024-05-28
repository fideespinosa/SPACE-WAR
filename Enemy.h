#pragma once
#include <SFML/Graphics.hpp>
#include "Collisionable.h"

// investigar vector de enemigos, para poder hacer varios respawn.

class Enemy : public sf::Drawable, public Collisionable, public sf::Transformable
{
	sf::Sprite _sprite;
	sf::Texture _texture;
public:
	enum class Direction {
		Left = 0,
		Right = 1,
		Up = 2,
		Down = 3
	};
	Enemy(sf::Vector2f position, Direction direction);
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
	void respawn();
	sf::FloatRect getBounds() const override;
private:
	Direction _direction;
	sf::Vector2f _velocity;
};

