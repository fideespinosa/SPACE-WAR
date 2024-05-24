
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "windows.h"
#include "Enemy.h"
#include "clsPlayer.h"
#include "Consumable.h"
#include "Gameplay.h"
#include "Bullet.h"
#include <SFML/System/Clock.hpp>
#include <iostream>

//inicializamos la variable de clase en 0 para cuando programemos el 
// getinstance validemos si esta en 0 o se creo una instancia
Gameplay* Gameplay::_currentInstance = nullptr;

Gameplay& Gameplay::getInstance()
{
    if (Gameplay::_currentInstance == nullptr) {
        Gameplay::_currentInstance = new Gameplay();
   }
    return *Gameplay::_currentInstance;
}

Gameplay::Gameplay()
{
    
}


 void Gameplay::update()
 {
     //ver de modificar upDate, sintax rara
     Spaceship.upDate();
     for (Bullet& bullet : _bullets) {
         bullet.update();
     }
 }

 void Gameplay::draw(sf::RenderTarget& target, sf::RenderStates states) const
 {
 }

void Gameplay::shoot(sf::Vector2f position, Bullet::Direction direction)
{
    _bullets.push_back(Bullet(position, direction));
}



