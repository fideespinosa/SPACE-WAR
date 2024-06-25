#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

class MainMenu
{
    sf::Music music;
    sf::SoundBuffer buffer;
    sf::Sound sound;
    sf::Sprite img, indicator, escape;
    sf::Texture background, arrow,esc;
    sf::Font font;
    sf::Text play,ranking, help, exit, options, EnterName, atras;
    int pos;
 

public: 
    MainMenu();
    void showMenu();
    bool InserName(sf::RenderWindow& window);
    int chooseOption(int pos, sf::Sound sound, sf::RenderWindow &window);

};

