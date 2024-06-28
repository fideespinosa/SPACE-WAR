#pragma once
#include <SFML/Graphics.hpp>
#include "windows.h"
class PauseMenu
{

private:
	sf::Text resume, exit, pause;
	sf::Font _font;
	sf::Sprite img, indicator;
	sf::Texture background, arrow;

public:
	PauseMenu();
	bool Pause(sf::RenderWindow& window);
};

