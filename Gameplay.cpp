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
    // Actualiza el estado de la nave espacial
    _spaceship.update();

    // Inicializa un iterador al comienzo de la lista de balas
    auto bullet_it = _bullets.begin();
    // Inicializa un iterador al comienzo de la lista de enemigos
    auto enemy_it = _enemys.begin();

    // Itera sobre cada bala en la lista
    while (bullet_it != _bullets.end())
    {
        // Obtiene una referencia a la bala actual
        Bullet& bullet = *bullet_it;
        // Actualiza el estado de la bala
        bullet.update();

        // Si la bala ha salido de la pantalla (posición x > 1000), la elimina de la lista
        if (bullet.getPosition().x > 1000 ) {
            bullet_it = _bullets.erase(bullet_it);
        }
        else {
                ++bullet_it;
        }
    }

    // Incrementa el temporizador de aparición de enemigos
    spawnTimer += 0.1f;

    // Si el temporizador ha alcanzado el máximo, crea un nuevo enemigo y lo añade a la lista
    if (spawnTimer >= spawnTimerMax)
    {
        _enemys.push_back(Enemy(sf::Vector2f(rand() % 1022, rand() % 150), Enemy::Direction::Down));
        // Reinicia el temporizador de aparición de enemigos
        spawnTimer = 0;
    }

    // Itera sobre cada enemigo en la lista y actualiza su estado
    while (enemy_it != _enemys.end()) {
        Enemy& _enemy = *enemy_it;
        _enemy.update();
        ++enemy_it;
    }

    // Reinicializa el iterador al comienzo de la lista de enemigos
    enemy_it = _enemys.begin();
    // Itera sobre cada enemigo en la lista
    while (enemy_it != _enemys.end())
    {
        // Obtiene una referencia al enemigo actual
        Enemy& _enemy = *enemy_it;

        // Itera sobre cada bala en la lista
        bullet_it = _bullets.begin();
        while (bullet_it != _bullets.end())
        {
            // Obtiene una referencia a la bala actual
            Bullet& bullet = *bullet_it;

            // Comprueba si la bala ha colisionado con el enemigo
            if (bullet.isCollision(_enemy)) {
                // Si hay una colisión, imprime un mensaje en la consola
                std::cout << "¡Colisión detectada!" << std::endl;

                // Elimina la bala y pasa a la siguiente
                bullet_it = _bullets.erase(bullet_it);
            }
            else {
                // Si no hay colisión, pasa a la siguiente bala
                ++bullet_it;
            }
        }

        // Pasa al siguiente enemigo
        ++enemy_it;
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



