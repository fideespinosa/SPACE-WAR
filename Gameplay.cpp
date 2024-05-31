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
    auto bullet_it = _bullets.begin();


    while (bullet_it != _bullets.end())
    {
        Bullet& bullet = *bullet_it;
        bullet.update();

        if (bullet.getPosition().x > 1000) {
            bullet_it = _bullets.erase(bullet_it);
        }
        else {
            ++bullet_it;
        }
    }


    spawnTimer += 0.1f;
    if (spawnTimer >= spawnTimerMax)
    {
        _enemys.push_back(Enemy(sf::Vector2f(rand() % 1022, rand() % 150), Enemy::Direction::Down));
        spawnTimer = 0;
    }
    auto enemy_it = _enemys.begin();
    while (enemy_it != _enemys.end()) {
        Enemy& _enemy = *enemy_it;
        _enemy.update();
        ++enemy_it;
    }
    enemy_it = _enemys.begin();

    while (enemy_it != _enemys.end())
    {
        Enemy& _enemy = *enemy_it;
        bool collided = false;
        bullet_it = _bullets.begin();
        while (bullet_it != _bullets.end())
        {
            Bullet& bullet = *bullet_it;
            if (_enemy.isCollision(bullet))
            {
                collided = true;
                break;
            }
            ++bullet_it;
        }
        if (collided) {
            enemy_it = _enemys.erase(enemy_it);
        }
        else {
            ++enemy_it;


        }
    }


}

 void Gameplay::draw(sf::RenderTarget& target, sf::RenderStates states) const 
 {
     target.draw(_spaceship, states);
     for (const Bullet& bullet : _bullets) {
         target.draw(bullet, states);
     }
     for (const Enemy& enemy : _enemys) {
         target.draw(enemy, states);
     }
 }
 
void Gameplay::shoot(sf::Vector2f position, Bullet::Direction direction)
{
    const sf::Time shootCooldown = sf::seconds(0.09f);
    if(shootTimer.getElapsedTime() >= shootCooldown) {
    _bullets.push_back(Bullet(position, direction));

    shootTimer.restart();
    }

}



