#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include "Gameplay.h"
#include <iostream>
#include "Life.h"

using namespace std;

int main()
{

	sf::Sprite background;
	sf::Texture backgroundGame;
	Player Spaceship;

	backgroundGame.loadFromFile("img/backgroundGamePlay.png");
	background.setTexture(backgroundGame);
	sf::RenderWindow window(sf::VideoMode(1024, 573), "Space War 2942");
	window.setFramerateLimit(60);
	Gameplay& gp = Gameplay::getInstance();
	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();

		}
		
		gp.update();
		window.clear();
		window.draw(background);
		window.draw(gp);//hasta ahora dibuj ala bala y la nave
		window.display();
	}

}
