#pragma once
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "Collisionable.h"
#include <SFML/System/Clock.hpp>

class Player : public sf::Drawable, public Collisionable, public sf::Transformable
{
private:
	sf::Sprite _sprite;
	sf::Texture _texture;
	float _vel;
public:
	Player();
	void update(); //Actualizar
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override; //Dibujar
	sf::FloatRect getGlobalBounds() const override;

protected:
	void isPress(); // Tecla Presionada
	void controlExtreme();// Controla los extremos de la pantalla

};

