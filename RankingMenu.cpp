
#include "RankingMenu.h"
#include <SFML/Graphics.hpp>
#include <SFML/audio.hpp>
#include <iostream>



void RankingMenu::show(sf::RenderWindow& window) {
    int exit = 0;
    FILE* p;

    sf::SoundBuffer buffer;
    buffer.loadFromFile("seleccion.ogg");
    sf::Sound sound;
    sound.setBuffer(buffer);

    sf::Sprite img, uno, dos, tres, escape;
    sf::Texture background, Uno, Dos, Tres, esc;
    sf::Font font;
    font.loadFromFile("space.ttf");
    sf::Text Ranking, atras, datosV;



    Ranking.setFont(font);
    atras.setFont(font);
    datosV.setFont(font);

    Ranking.setString("RANKING GLOBAL");
    Ranking.setStyle(sf::Text::Italic);
    Ranking.setStyle(sf::Text::Underlined);
    Ranking.setPosition(325.f, 0.f);

    atras.setString("ATRAS");
    atras.setStyle(sf::Text::Italic);
    atras.setFillColor(sf::Color::White);
    atras.setOutlineThickness(1);
    atras.setOutlineColor(sf::Color::Black);
    //atras.setStyle(sf::Text::Underlined);
    atras.setPosition(115.f, 515.f);

    datosV.setString("NO SE ENCUENTRAN DATOS REGISTRADOS");
    //datosV.setStyle(sf::Text::;
    datosV.setCharacterSize(16);
    datosV.setFillColor(sf::Color::Red);
    // datosV.setOutlineThickness(4);
     //datosV.setOutlineColor(sf::Color::Black);
    datosV.setStyle(sf::Text::Style::Bold);
    datosV.setPosition(226.f, 150.f);

    while (exit != 1) {

        background.loadFromFile("backgroundRanking.jpeg");
        Tres.loadFromFile("copaBronce.png");
        esc.loadFromFile("esc.png");
        img.setTexture(background);
        tres.setTexture(Tres);
        escape.setTexture(esc);
        escape.setTexture(esc);

        tres.setPosition(sf::Vector2f(100, 200));
        escape.setPosition(sf::Vector2f(5, 455));

        window.clear();

        window.draw(img);

        window.draw(tres);

        window.draw(escape);

        window.draw(Ranking);
        window.draw(atras);


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {

            sound.play();
            //Sleep(150);
            return;
        }

        /* p = fopen("Ranking.dat", "rb");

        if (p == nullptr)
        {
            window.draw(datosV);


        } */


        //fclose(p);
        window.display();
    }
    //window.close();
}



