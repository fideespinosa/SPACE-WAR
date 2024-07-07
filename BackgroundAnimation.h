#pragma once
#include <SFML\Graphics.hpp>

class BackgroundAnimation
{

protected:
	sf::Texture _texture[10];
	sf::Sprite _sprite[10];
	int _stateAnimation;
	sf::Clock _clock;
public:
	BackgroundAnimation();
	void update();
	void draw(sf::RenderWindow& window);
};

