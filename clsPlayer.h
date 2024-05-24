#pragma once
#include <SFML/Graphics.hpp>
#include "Collisionable.h"
#include "Gameplay.h"
#include <SFML/System/Clock.hpp>

class clsPlayer : public sf::Drawable, public Collisionable, public sf::Transformable
{
private:
	sf::Sprite _sprite;
	sf::Texture _texture;
	float _vel;
	sf::Clock shootTimer;
	sf::Time shootCooldown = sf::seconds(0.1f); //tiempo de enfriamiento entre disparos
	//std::vector<Bullet> bullets;
public:
	sf::Sprite getSprite() const;
	clsPlayer();
	clsPlayer(int, int); // Contructor setX() and setY()
	
	void upDate(); //Actualizar
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override; //Dibujar
	//Bullet shoot(clsPlayer spaceship, Bullet bullet);

protected:
	void isPress(); // Tecla Presionada
	void controlExtreme();// Controla los extremos de la pantalla
	sf::FloatRect getBounds() const override;
};

