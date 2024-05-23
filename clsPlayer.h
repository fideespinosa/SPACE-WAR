#pragma once
#include <SFML/Graphics.hpp>
#include "Collisionable.h"

class clsPlayer : public sf::Drawable, public Collisionable
{
private:
	sf::Sprite _sprite;
	sf::Texture _texture;
	float _vel;
public:
	sf::Sprite getSprite() const;
	clsPlayer();
	clsPlayer(int, int); // Contructor setX() and setY()
	void upDate(); //Actualizar
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override; //Dibujar

	

protected:
	void isPress(); // Tecla Presionada
	void controlExtreme();// Controla los extremos de la pantalla
	sf::FloatRect getBounds() const override;
};

