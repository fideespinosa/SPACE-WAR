#include "MenuPrincipal.h"
#include "windows.h"
#include <iostream>
#include "MenuRanking.h"

MenuPrincipal::MenuPrincipal()
{
	music.openFromFile("Main Theme.wav");
    music.setVolume(10.f);

	buffer.loadFromFile("seleccion.ogg");

	font.loadFromFile("space.ttf");

	fondo.loadFromFile("fondo.png");
	flecha.loadFromFile("flecha.png");

    jugar.setFont(font);
    ranking.setFont(font);
    opciones.setFont(font);
    ayuda.setFont(font);
    salir.setFont(font);

	jugar.setString("JUGAR");
	ranking.setString("RANKING");
	opciones.setString("OPCIONES");
	ayuda.setString("AYUDA");
	salir.setString("SALIR");

    int x = 690, y = 155;

    sound.setBuffer(buffer);
}



void MenuPrincipal::MostrarMenu(sf::RenderWindow &window)
{
  

    sound.setBuffer(buffer);
    buffer.loadFromFile("Main Theme.wav");
 
    sound.setVolume(20.f);

    music.setVolume(10.f);
	music.play();

    int x = 690, y = 155, pos=1;

    jugar.setFillColor(sf::Color::White);

    fondo.loadFromFile("fondo.png");
    flecha.loadFromFile("flecha.png");
    img.setTexture(fondo);
    indicador.setTexture(flecha);



    jugar.setStyle(sf::Text::Italic);
    //jugar.setFillColor(sf::Color::Transparent);
    jugar.setOutlineThickness(1);
    jugar.setOutlineColor(sf::Color::Black);
    //jugar.setStyle(sf::Text::Underlined);
    jugar.setPosition(700.f, 150.f);
    jugar.setOutlineColor(sf::Color::Black);

    indicador.setPosition(x, y);


    ranking.setStyle(sf::Text::Italic);
    ranking.setFillColor(sf::Color::Transparent);
    ranking.setOutlineThickness(1);
    ranking.setOutlineColor(sf::Color::White);
    ranking.setPosition(678.f, 200.f);

 
    opciones.setStyle(sf::Text::Italic);
    opciones.setFillColor(sf::Color::Transparent);
    opciones.setOutlineThickness(1);
    opciones.setOutlineColor(sf::Color::White);
    opciones.setPosition(661.f, 250.f);

   
    ayuda.setStyle(sf::Text::Italic);
    ayuda.setFillColor(sf::Color::Transparent);
    ayuda.setOutlineThickness(1);
    ayuda.setOutlineColor(sf::Color::White);
    ayuda.setPosition(699.f, 300.f);

    salir.setString("SALIR");
    salir.setStyle(sf::Text::Italic);
    salir.setFillColor(sf::Color::Transparent);
    salir.setOutlineThickness(1);
    salir.setOutlineColor(sf::Color::Red);
    salir.setPosition(710.f, 350.f);


    // Game Loop
    while (window.isOpen()) {

        //ReadImput

        sf::Event event;

        while (window.pollEvent(event)) {

            //music.setPlayingOffset(sf::seconds(10));
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear();

        window.draw(img);

        window.draw(jugar);


        window.draw(ranking);
        window.draw(opciones);
        window.draw(ayuda);
        window.draw(salir);


        indicador.setPosition(x, y);
        indicador.setRotation(90.f);
        window.draw(indicador);

       
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) and pos == 1) {
            pos = 2;
            x = 670;
            y = 205;
            ranking.setFillColor(sf::Color::White);
            ranking.setOutlineColor(sf::Color::Black);
            jugar.setFillColor(sf::Color::Transparent);
            jugar.setOutlineColor(sf::Color::White);
            //opciones.setFillColor(sf::Color::Transparent);


            sound.play();
            Sleep(150);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && pos == 2) {
            pos = 1;
            x = 690;
            y = 155;
            jugar.setFillColor(sf::Color::White);
            jugar.setOutlineColor(sf::Color::Black);
            ranking.setFillColor(sf::Color::Transparent);
            ranking.setOutlineColor(sf::Color::White);

            sound.play();
            Sleep(150);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && pos == 2) {
            pos = 3;
            x = 650;
            y = 255;
            opciones.setFillColor(sf::Color::White);
            opciones.setOutlineColor(sf::Color::Black);
            ranking.setFillColor(sf::Color::Transparent);
            ranking.setOutlineColor(sf::Color::White);
            sound.play();
            Sleep(150);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && pos == 3) {
            pos = 2;
            x = 670;
            y = 205;
            ranking.setFillColor(sf::Color::White);
            ranking.setOutlineColor(sf::Color::Black);
            opciones.setFillColor(sf::Color::Transparent);
            opciones.setOutlineColor(sf::Color::White);
            sound.play();
            Sleep(150);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && pos == 3) {
            pos = 4;
            x = 690;
            y = 305;
            ayuda.setFillColor(sf::Color::White);
            opciones.setFillColor(sf::Color::Transparent);
            ayuda.setOutlineColor(sf::Color::Black);
            opciones.setOutlineColor(sf::Color::White);

            sound.play();
            Sleep(150);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && pos == 4) {
            pos = 3;
            x = 650;
            y = 255;
            ayuda.setFillColor(sf::Color::Transparent);
            ayuda.setOutlineColor(sf::Color::White);
            opciones.setFillColor(sf::Color::White);
            opciones.setOutlineColor(sf::Color::Black);

            sound.play();
            Sleep(150);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && pos == 4) {
            pos = 5;
            x = 700;
            y = 355;
            salir.setFillColor(sf::Color::Red);
            ayuda.setFillColor(sf::Color::Transparent);
            salir.setOutlineColor(sf::Color::Black);
            ayuda.setOutlineColor(sf::Color::White);
            sound.play();

            Sleep(150);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && pos == 5) {
            pos = 4;
            x = 690;
            y = 305;
            ayuda.setFillColor(sf::Color::White);
            ayuda.setOutlineColor(sf::Color::Black);

            salir.setFillColor(sf::Color::Transparent);
            salir.setOutlineColor(sf::Color::Red);
            sound.play();
            Sleep(150);
        }

        window.display();

        

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {

            if (ElegirOpcion(pos, sound, window) == 1) {
                window.close();

            };

        }

    }
    
    
}

int MenuPrincipal::ElegirOpcion(int pos, sf::Sound sound, sf::RenderWindow& window) {
     
        int salir = 0;
        switch (pos) {

        case 1: std::cout << "1";
            break;
        case 2: std::cout << "2";

            MenuRanking ranking;
            ranking.Mostrar(window);
            //sound.play();
            break;
        case 3: std::cout << "3";
            break;
        case 4: std::cout << "4";
            break;
        case 5: std::cout << "5";
            salir = 1;
            return salir;

        }
    }

