//Clase abstracta, funcionara como una interface para las colisiones entre diferentes objetos

#pragma once
#include <SFML/graphics.hpp>

class Collisionable {


public:
	// metodo polimorfico, para que quien lo herede lo obligamos a que lo implemente
	// En esta clase se iguala a 0, y espera que quien herede esta clase implemente getBounds()
	virtual sf::FloatRect getBounds() const = 0;
	bool isCollision(Collisionable& col) const;

};