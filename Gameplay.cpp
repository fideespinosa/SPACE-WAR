
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "windows.h"
#include "Enemy.h"
#include "clsPlayer.h"
#include "Consumable.h"
#include "Gameplay.h"
#include "Bullet.h"
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
   
	while (salir !=1) {
      
        // === Perifericos de entradas ===
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

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


