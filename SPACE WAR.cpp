#include "MainMenu.h"
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

int main() 
{
    sf::RenderWindow window(sf::VideoMode(1024, 573), "Space War");
    window.setFramerateLimit(60);
    MainMenu main;
    main.showMenu(window);
}