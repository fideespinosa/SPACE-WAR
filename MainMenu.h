
#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <string>
#include <iostream>
class MainMenu
{
    sf::Music music;
    sf::SoundBuffer buffer;
    sf::Sound sound;
    sf::Sprite img, indicator, escape, imgHelp, sig, teclas, space;
    sf::Texture background, arrow, esc, backgroundHelp, arrow2, fl, sc;
    sf::Font font;
    sf::Text play, ranking, help, exit, options, EnterName, atras, texto, NameLimit, minimo;
    sf::Text movimiento, choque, disparar, puntos, controles, siguiente;
    int pos;
    std::string name;


public:
    MainMenu();
    void showMenu();
    std::string InserName(sf::RenderWindow& window, sf::Event Event);
    int chooseOption(int pos, sf::Sound sound, sf::RenderWindow& window, sf::Event Event);
    void HelpMenu(sf::RenderWindow& window);

};


