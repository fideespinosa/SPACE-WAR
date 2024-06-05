#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <list>
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
    updatePlayer(); // Actualiza la nave espacial
    updateBullets(); // Actualiza las balas
    updateEnemies(); // Actualiza los enemigos
    handleCollisions(); // Maneja las colisiones
    spawnEnemies(); // Genera nuevos enemigos
}

void Gameplay::updatePlayer()
{
    _spaceship.update();
}

void Gameplay::updateBullets()
{
    for (auto& bullet : _bullets)
    {
        bullet.update();
    }
    // Elimina las balas fuera de pantalla
    _bullets.erase(std::remove_if(_bullets.begin(), _bullets.end(),
        [](const Bullet& bullet) { return bullet.getPosition().y > 1000; }),
        _bullets.end());
}

void Gameplay::updateEnemies()
{
    for (auto& enemy : _enemys)
    {
        enemy.update();
    }
}

void Gameplay::handleCollisions()
{
    auto bullet_it = _bullets.begin();
    while (bullet_it != _bullets.end())
    {
        auto& bullet = *bullet_it;
        auto enemy_it = _enemys.begin();
        while (enemy_it != _enemys.end())
        {
            auto& enemy = *enemy_it;

            // genero estos cout para validar con global bounds las posiciones de la 'caja' del sprite
            std::cout << "Bala bounds: " << bullet.getGlobalBounds().left << ", " << bullet.getGlobalBounds().top << ", " << bullet.getGlobalBounds().width << ", " << bullet.getGlobalBounds().height << std::endl;
            std::cout << "Enemigo bounds: " << enemy.getGlobalBounds().left << ", " << enemy.getGlobalBounds().top << ", " << enemy.getGlobalBounds().width << ", " << enemy.getGlobalBounds().height << std::endl;


            if (bullet.isCollision(enemy))
            {
                // Manejar la colisión aquí
                std::cout << "¡Colisión detectada!" << std::endl;

                // Eliminar la bala y el enemigo
                bullet_it = _bullets.erase(bullet_it);
                enemy_it = _enemys.erase(enemy_it);
                // Romper el bucle de enemigos ya que esta bala ya no puede colisionar con más enemigos
                break;
            }
            else
            {
                ++enemy_it;
            }
        }

        // Solo avanzar al siguiente iterador de bala si no se eliminó esta bala durante la colisión
        if (bullet_it != _bullets.end())
        {
            ++bullet_it;
        }
    }

}


void Gameplay::spawnEnemies()
{
    spawnTimer += 0.1f;
    if (spawnTimer >= spawnTimerMax)
    {
        _enemys.push_back(Enemy(sf::Vector2f(rand() % 1022, rand() % 150), Enemy::Direction::Down));
        spawnTimer = 0;
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



