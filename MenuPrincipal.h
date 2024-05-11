#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

class MenuPrincipal
{

    sf::Music music;

    sf::SoundBuffer buffer;
    
    sf::Sound sound;
   
    sf::Sprite img, indicador;
    sf::Texture fondo, flecha;
    sf::Font font;
    sf::Text jugar,ranking, ayuda, salir, opciones;

    int pos;

   

public: 

    MenuPrincipal();

    void MostrarMenu();

    //int Moverse(int pos);

    int ElegirOpcion(int pos, sf::Sound sound);
    


};

