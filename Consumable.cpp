#include "Consumable.h"
#include <stdlib.h>

void Consumable::Respawn()
{
	std::srand((unsigned)std::time(0));
	_sprite.setPosition(std::rand() % 1023 + _sprite.getGlobalBounds().width, std::rand() % 287 + _sprite.getGlobalBounds().height);
	// de esta manera siempre se seteara en el ancho de la pantalla de manera aleatoria
	// pero siempre en posicion superior
}
