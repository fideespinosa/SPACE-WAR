#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio.hpp>

class Consumable
{
protected: //dara acceso a las clases derivadas
	sf::SoundBuffer _sonido;
	sf::Sprite _sprite;
	sf::Texture _texture;
	float _velocity;
	public:
	virtual void Respawn();
};

