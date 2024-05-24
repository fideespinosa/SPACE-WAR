#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include <iostream>
#include "Life.h"

using namespace std;

int main()
{
	MainMenu mainMenu;
	
	sf::Sprite background;
	sf::Texture backgroundGame;
	backgroundGame.loadFromFile("img/backgroundGamePlay.png");
	background.setTexture(backgroundGame);

	sf::RenderWindow window(sf::VideoMode(1024, 573), "Space War 2942");
	window.setFramerateLimit(60);

	mainMenu.showMenu(window);

}
