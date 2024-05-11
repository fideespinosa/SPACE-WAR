#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio.hpp>

class Consumible
{
protected: //dara acceso a las clases derivadas
	sf::SoundBuffer _sonido;
	sf::Sprite _sprite;
	sf::Texture _texture;
	public:
	virtual void Respawn();
};

