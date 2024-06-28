
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
    sf::Sprite img, indicator, escape;
    sf::Texture background, arrow, esc;
    sf::Font font;
    sf::Text play, ranking, help, exit, options, EnterName, atras, texto, NameLimit, minimo;
    int pos;
    std::string name;


public:
    MainMenu();
    void showMenu();
    bool InserName(sf::RenderWindow& window, sf::Event Event);
    int chooseOption(int pos, sf::Sound sound, sf::RenderWindow& window, sf::Event Event);

};


