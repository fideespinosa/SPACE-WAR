
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

 Gameplay::Gameplay() {
	//music.openFromFile("");
	music.setVolume(10.f);

	//buffer.loadFromFile("seleccion.ogg");

	font.loadFromFile("space.ttf");

	backgroundGame.loadFromFile("backgroundGamePlay.png");
	//arrow.loadFromFile("arrow.png");
    background.setTexture(backgroundGame);
}

void Gameplay::StartGame(sf::RenderWindow& window)
{
    int salir = 0;
    Enemy enemy(700, 500);
    clsPlayer Spaceship(window.getSize().x / 2, window.getSize().y * 0.8); //X = Mitad de Pantalla ; Y = 1/3 de Pantalla aprox
    Bullet balin(700,300);

    // Vector para "almacenar" las balas
    std::vector<Bullet> bullets;

    // Temporizador para controlar la cadencia de disparo
    sf::Clock shootTimer;
    const sf::Time shootCooldown = sf::seconds(0.1f); // Tiempo de enfriamiento entre disparos
   
	while (salir !=1) {
      
        // === Perifericos de entradas ===
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Disparar la bala desde la posición del jugador si pasó suficiente tiempo desde el último disparo
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && shootTimer.getElapsedTime() >= shootCooldown) {
            // Obtener la posición de la nave
            //////sf::Vector2f playerPosition = Spaceship.getPosition();
            // Ajustar la posición de la bala para que esté por encima de la nave
            float bulletSpawnOffset = 130.0f; // Ajusta la posicion de la bala respecto a la nave
            ////////sf::Vector2f bulletPosition(playerPosition.x, playerPosition.y - bulletSpawnOffset);
            ///////Bullet bullet(bulletPosition.x, bulletPosition.y, 4.f);
            // Agregar la bala al vector
           ///// bullets.push_back(bullet);
            // Reiniciar el temporizador
            shootTimer.restart();
        }
        /*
        // Actualizar todas las balas
        for (auto& bullet : bullets) {
            bullet.update();
        }
        */

        //==== GAME LOOP _ UPDATE ===
        Spaceship.upDate();
        balin.upDate();

        window.clear();

        //=== GAME LOOP = DIBUJOS ===        
        window.draw(background);
        // BACKGROUND SIEMPRE INCLUIDO ANTES QUE OTRAS IMAGENES PORQUE SUPERPONE

        window.draw(Spaceship);
        window.draw(enemy);
        window.draw(balin);

        //balin.setPosition(x, y++);
        //=== GAME LOOP DISPPLAY FLIP ===
        window.display();

        if (Spaceship.isCollision(enemy)){
            enemy.respawn();
        }

	}

	


}


