#include <SFML/Graphics.hpp>
#include "MenuPrincipal.h"
#include <iostream>

using namespace std;

int main()
{
	MenuPrincipal _MenuPrincipal;
	
	sf::RenderWindow window(sf::VideoMode(1024, 573), "Space War 2942");
	window.setFramerateLimit(60);

	_MenuPrincipal.MostrarMenu(window);

}