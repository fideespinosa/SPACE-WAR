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
    window.clear();
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
        std::cout << ar.mostrar(i).getName() << std::endl;
    }
    showScore();
    while (exit != 1) {

       

        window.draw(img);
        window.draw(escape);
        window.draw(n1);
        window.draw(n2);
        window.draw(n3);
        window.draw(n4);
        window.draw(n5);
        window.draw(s1);
        window.draw(s2);
        window.draw(s3);
        window.draw(s4);
        window.draw(s5);
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

void RankingMenu::showScore()
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
    
    n1.setCharacterSize(30);
    n1.setOutlineThickness(2);
    n1.setOutlineColor(sf::Color::Black);
    n1.setFont(font);
    n1.setPosition(325.f, 70+ 40);

    n2.setCharacterSize(30);
    n2.setOutlineThickness(2);
    n2.setOutlineColor(sf::Color::Black);
    n2.setFont(font);
    n2.setPosition(325.f, 100 + 40);

    n3.setCharacterSize(30);
    n3.setOutlineThickness(2);
    n3.setOutlineColor(sf::Color::Black);
    n3.setFont(font);
    n3.setPosition(325.f, 130 + 40);

    n4.setCharacterSize(30);
    n4.setOutlineThickness(2);
    n4.setOutlineColor(sf::Color::Black);
    n4.setFont(font);
    n4.setPosition(325.f, 160 + 40);

    n5.setCharacterSize(30);
    n5.setOutlineThickness(2);
    n5.setOutlineColor(sf::Color::Black);
    n5.setFont(font);
    n5.setPosition(325.f, 190 + 40);

    s1.setString(std::to_string(obj[0].getPoints()));
    s2.setString(std::to_string(obj[1].getPoints()));
    s3.setString(std::to_string(obj[2].getPoints()));
    s4.setString(std::to_string(obj[3].getPoints()));
    s5.setString(std::to_string(obj[4].getPoints()));

    s1.setCharacterSize(30);
    s1.setOutlineThickness(2);
    s1.setOutlineColor(sf::Color::Black);
    s1.setFont(font);
    s1.setPosition(700, 70 + 40);

    s2.setCharacterSize(30);
    s2.setOutlineThickness(2);
    s2.setOutlineColor(sf::Color::Black);
    s2.setFont(font);
    s2.setPosition(700, 100 + 40);

    s3.setCharacterSize(30);
    s3.setOutlineThickness(2);
    s3.setOutlineColor(sf::Color::Black);
    s3.setFont(font);
    s3.setPosition(700, 130 + 40);

    s4.setCharacterSize(30);
    s4.setOutlineThickness(2);
    s4.setOutlineColor(sf::Color::Black);
    s4.setFont(font);
    s4.setPosition(700, 160 + 40);

    s5.setCharacterSize(30);
    s5.setOutlineThickness(2);
    s5.setOutlineColor(sf::Color::Black);
    s5.setFont(font);
    s5.setPosition(700, 190 + 40);

}



