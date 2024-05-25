
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <list>"
#include "windows.h"
#include "Enemy.h"
#include "Player.h"
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
    shootTimer.restart();
}


 void Gameplay::update() 
 {

     _spaceship.update();


     for (Bullet& bullet : _bullets) {
         bullet.update();
     }

     auto it = _bullets.begin();
     while (it != _bullets.end()) {
         
         Bullet& bullet = *it;

         bullet.update();


         if (bullet.getPosition().x>1000) {
             it = _bullets.erase(it);
         }
         else {
             ++it;
         }
     }
 }

 void Gameplay::draw(sf::RenderTarget& target, sf::RenderStates states) const
 {
     target.draw(_spaceship, states);
 

     for (const Bullet& bullet : _bullets) {
         target.draw(bullet, states);
     }
 }
 
void Gameplay::shoot(sf::Vector2f position, Bullet::Direction direction)
{
    const sf::Time shootCooldown = sf::seconds(0.1f);
    if(shootTimer.getElapsedTime() >= shootCooldown) {
    _bullets.push_back(Bullet(position, direction));

    shootTimer.restart();
    }
}



