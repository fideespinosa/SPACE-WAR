
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "windows.h"
#include "Enemy.h"
#include "clsPlayer.h"
#include "Consumable.h"
#include "Gameplay.h"
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
    clsPlayer Spaceship(window.getSize().x / 2, window.getSize().y * 0.8); //X = Mitad de Pantalla ; Y = 1/3 de Pantalla aprox

   
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

        window.clear();

        //=== GAME LOOP = DIBUJOS ===

        //window.draw(_personaje);
        window.draw(background);
        window.draw(Spaceship);
       

        //=== GAME LOOP DISPPLAY FLIP ===
        window.display();

	}

	


}


