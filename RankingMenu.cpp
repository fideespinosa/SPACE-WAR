#include <string>
#include "RankingMenu.h"
#include <SFML/Graphics.hpp>
#include <SFML/audio.hpp>
#include <iostream>
#include "score.h"
#include "ArchivoRanking.h"


RankingMenu::RankingMenu()
{
    buffer.loadFromFile("seleccion.ogg");
    font.loadFromFile("space.ttf");

    Ranking.setFont(font);
    atras.setFont(font);
    datosV.setFont(font);

    Ranking.setString("RANKING GLOBAL");
    Ranking.setStyle(sf::Text::Italic);
    Ranking.setStyle(sf::Text::Underlined);
    Ranking.setPosition(325.f, 0.f);

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

    background.loadFromFile("img/backgroundRanking.jpeg");
    Tres.loadFromFile("img/copaBronce.png");
    esc.loadFromFile("img/esc.png");
    img.setTexture(background);
    tres.setTexture(Tres);
    escape.setTexture(esc);

    tres.setPosition(sf::Vector2f(100, 200));
    escape.setPosition(sf::Vector2f(5, 455));
}

void RankingMenu::show(sf::RenderWindow& window) {

    int exit = 0;
    Score _score1, _score2, _score3, _score4, _score5;
    char name1[10];
   
   /*
    std::cin >> name1;
    _score1.setName(name1);
    _score1.setPoint(0);
    _score2.setName(name1);
    _score2.setPoint(0);
    _score3.setName(name1);
    _score3.setPoint(0);
    _score4.setName(name1);
    _score4.setPoint(0);
    _score5.setName(name1);
    _score5.setPoint(0);
    ar.cargar(_score1);
    ar.cargar(_score2);
    ar.cargar(_score3);
    ar.cargar(_score4);
    ar.cargar(_score5);
    */
    ArchivoRanking ar;
    for (int i = 0; i < 5; i++) {
        std::cout << " mostrando registro  " << ar.mostrar(i).getPoints() << std::endl;
        std::cout << " mostrando registro  " << ar.mostrar(i).getName() << std::endl;
    }

    while (exit != 1) {

        window.clear();
        window.draw(img);
        window.draw(escape);
      
        window.draw(Ranking);
        window.draw(atras);


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {

            sound.play();
            //Sleep(150);
            return;
        }

       /* fopen_s(&p, "Ranking.dat", "rb");

        if (p == nullptr)
        {
            window.draw(datosV);
        } 
        */

       // fclose(p);
        window.display();
    }
    //window.close();
}

void RankingMenu::showScore(sf::RenderWindow& window)
{
    FILE* p;
    Score obj[5], aux;
    int j = 0;
    fopen_s(&p, "score.dat", "rb");

    while (fread(&aux, sizeof(Score), 1, p) == 1) {
        obj[j] = aux;
        j++;
    }
    fclose(p);
    
    n1.setString(obj[0].getName());
    n2.setString(obj[1].getName());
    n3.setString(obj[2].getName());
    n4.setString(obj[3].getName());
    n5.setString(obj[4].getName());
    
    s1.setString(std::to_string(obj[0].getPoints()));
    s2.setString(std::to_string(obj[1].getPoints()));
    s3.setString(std::to_string(obj[2].getPoints()));
    s4.setString(std::to_string(obj[3].getPoints()));
    s5.setString(std::to_string(obj[4].getPoints()));



}



