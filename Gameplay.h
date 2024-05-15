#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "windows.h"
#include "clsPlayer.h"

class Gameplay
{
private:
    sf::Music music;
    sf::SoundBuffer buffer;
    sf::Sound sound;
    clsPlayer Spaceship;
    sf::Sprite background;
    sf::Texture backgroundGame;
    sf::Font font;
    //sf::Text;
public:

    Gameplay();

    void StartGame(sf::RenderWindow& window);

};

