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
	sf::Clock _clockMove;
	int _stateMove = 0, _life, _speed;
	public:   
	int getLife();
    void setLife(int life);
	void update();
	void draw(sf::RenderWindow& window);
	bool controlSprite(sf::Sprite& _sprite);
	Consumable() {};
	sf::FloatRect getBounds() const;
};

