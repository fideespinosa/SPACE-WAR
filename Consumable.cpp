#include "Consumable.h"
#include <stdlib.h>

void Consumable::Respawn()
{
	_sprite.setPosition(std::rand() % 1023, std::rand() % 287);
	// de esta manera siempre se seteara en el ancho de la pantalla de manera aleatoria
	// pero siempre en posicion superior
}
