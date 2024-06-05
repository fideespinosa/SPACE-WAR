//Clase abstracta, funcionara como una interface para las colisiones entre diferentes objetos
//Para hacer la colision, todos los involucrados deben heredar ser collisionable,
// y se debe llamar a isCollision desde el objeto pasandole como dato el otro objeto a chequear su collision.
// personaje.isCollision(powerUp) <---- ejemplo.

#pragma once
#include <SFML/graphics.hpp>

class Collisionable {
public:
	// metodo polimorfico, para que quien lo herede lo obligamos a que lo implemente
	// En esta clase se iguala a 0, y espera que quien herede esta clase implemente getBounds()
	virtual sf::FloatRect getGlobalBounds() const = 0;
	bool isCollision(Collisionable& col) const;
};