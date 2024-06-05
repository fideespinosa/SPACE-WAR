#include "Collisionable.h"

bool Collisionable::isCollision(Collisionable& obj) const {
	return getGlobalBounds().intersects(obj.getGlobalBounds());
};