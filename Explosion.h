#pragma once
#include <SFML\Graphics.hpp>

class Explosion
{
protected:
	sf::Texture _texture;
	sf::Sprite _sprite;
	int _stateExplosion;
	sf::Clock _clock;
	int _typeExplosion;
public:
	Explosion(sf::Vector2f position, int _type);
	void update(int _type);
	void draw(sf::RenderWindow& window);
	int getType();
};

