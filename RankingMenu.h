#pragma once
#include <SFML/Graphics.hpp>
#include <SFML\Audio.hpp>
#include <iostream>
#include "ArchivoRanking.h"

class RankingMenu
{

private:
	sf::Sprite img, uno, dos, tres, escape;
	sf::Texture background, Uno, Dos, Tres, esc;
	sf::Font font;
	sf::Sound sound;
	sf::SoundBuffer buffer;
	sf::Text Ranking, atras, datosV, n1,n2,n3,n4,n5, s1,s2,s3,s4,s5;
public: 
	RankingMenu();
	void show(sf::RenderWindow& window);
	void showScore(sf::RenderWindow& window);
};

