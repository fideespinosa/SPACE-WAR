#include "Consumible.h"
#include <stdlib.h>

void Consumible::Respawn()
{
	_sprite.setPosition(std::rand() % 1024 - _sprite.getGlobalBounds().width, 0);
	// de esta manera siempre se seteara en el ancho de la pantalla de manera aleatoria
	// pero siempre en posicion superior
}
