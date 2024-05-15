#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "windows.h"
#include "clsPlayer.h"
#include "Enemy.h"

class Gameplay
{
private:
    sf::Music music;
    sf::SoundBuffer buffer;
    sf::Sound sound;
    clsPlayer Spaceship;
    Enemy enemy;
    sf::Sprite background;
    sf::Texture backgroundGame;
    sf::Font font;
    //sf::Text;
public:

    Gameplay();

    void StartGame(sf::RenderWindow& window);

};

