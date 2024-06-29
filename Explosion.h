#pragma once
#include <SFML\Graphics.hpp>

class Explosion
{
protected:
	sf::Texture _texture;
	sf::Sprite _sprite;
	int _stateExplosion;
	sf::Clock _clock;
public:
	Explosion(sf::Vector2f position);
	void update();
	void draw(sf::RenderWindow& window);
};

