#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

class MainMenu
{

    sf::Music music;

    sf::SoundBuffer buffer;
    
    sf::Sound sound;
   
    sf::Sprite img, indicator;
    sf::Texture background, arrow;
    sf::Font font;
    sf::Text play,ranking, help, exit, options;

    int pos;

   

public: 

    MainMenu();

    void showMenu(sf::RenderWindow &window);

    //int Moverse(int pos);

    int chooseOption(int pos, sf::Sound sound, sf::RenderWindow &window);
    


};

