
#include "MainMenu.h"
#include "windows.h"
#include <iostream>
#include "RankingMenu.h"
#include "Gameplay.h"
#include <string>

MainMenu::MainMenu()
{
    music.openFromFile("Main Theme.wav");
    music.setVolume(10.f);

    buffer.loadFromFile("seleccion.ogg");

    font.loadFromFile("space.ttf");

    background.loadFromFile("img/background.png");
    arrow.loadFromFile("img/arrow.png");

    play.setFont(font);
    ranking.setFont(font);
    options.setFont(font);
    help.setFont(font);
    exit.setFont(font);
    minimo.setFont(font);

    play.setString("Play");
    ranking.setString("RANKING");
    options.setString("options");
    help.setString("Help");
    exit.setString("Exit");

    play.setFillColor(sf::Color::White);

    background.loadFromFile("img/background.png");
    arrow.loadFromFile("img/arrow.png");
    img.setTexture(background);
    indicator.setTexture(arrow);

    play.setStyle(sf::Text::Italic);
    play.setOutlineThickness(1);
    play.setOutlineColor(sf::Color::Black);
    play.setPosition(700.f, 150.f);

    ranking.setStyle(sf::Text::Italic);
    ranking.setFillColor(sf::Color::Transparent);
    ranking.setOutlineThickness(1);
    ranking.setOutlineColor(sf::Color::White);
    ranking.setPosition(678.f, 200.f);

    /*minimo.setString("Debe tener un minimo de 1 caracter");
    minimo.setStyle(sf::Text::Italic);
    minimo.setOutlineColor(sf::Color::White);
    minimo.setOutlineThickness(1);
    minimo.setOutlineColor(sf::Color::White);
    minimo.setPosition(600, 300);*/

    options.setStyle(sf::Text::Italic);
    options.setFillColor(sf::Color::Transparent);
    options.setOutlineThickness(1);
    options.setOutlineColor(sf::Color::White);
    options.setPosition(661.f, 250.f);

    help.setStyle(sf::Text::Italic);
    help.setFillColor(sf::Color::Transparent);
    help.setOutlineThickness(1);
    help.setOutlineColor(sf::Color::White);
    help.setPosition(699.f, 300.f);

    exit.setString("exit");
    exit.setStyle(sf::Text::Italic);
    exit.setFillColor(sf::Color::Transparent);
    exit.setOutlineThickness(1);
    exit.setOutlineColor(sf::Color::Red);
    exit.setPosition(710.f, 350.f);

    NameLimit.setCharacterSize(14);
    NameLimit.setFont(font);
    NameLimit.setString("Ha alcanzado el limite de caracteres");
    NameLimit.setStyle(sf::Text::Italic);
    NameLimit.setOutlineThickness(2);
    NameLimit.setOutlineColor(sf::Color::Black);
    NameLimit.setFillColor(sf::Color::Red);
    NameLimit.setPosition(550.f, 300.f);

    EnterName.setCharacterSize(20);
    EnterName.setFont(font);
    EnterName.setString("Ingrese su nombre:");
    EnterName.setStyle(sf::Text::Italic);
    EnterName.setOutlineThickness(1);
    EnterName.setOutlineColor(sf::Color::Black);
    EnterName.setPosition(600.f, 200.f);

    texto.setCharacterSize(15);
    texto.setFont(font);
    texto.setStyle(sf::Text::Italic);
    texto.setFillColor(sf::Color::White);
    texto.setOutlineThickness(2);
    texto.setOutlineColor(sf::Color::Black);
    //text.setPosition()

    esc.loadFromFile("img/esc.png");
    escape.setTexture(esc);
    escape.setPosition(sf::Vector2f(5, 455));

    atras.setFont(font);
    atras.setString("ATRAS");
    atras.setStyle(sf::Text::Italic);
    atras.setFillColor(sf::Color::White);
    atras.setOutlineThickness(1);
    atras.setOutlineColor(sf::Color::Black);
    atras.setPosition(115.f, 515.f);

    int x = 690, y = 155;

    sound.setBuffer(buffer);
}



void MainMenu::showMenu() {

    sf::RenderWindow window(sf::VideoMode(1024, 573), "Space War");
    window.setFramerateLimit(60);


    sound.setBuffer(buffer);
    buffer.loadFromFile("Main Theme.wav");

    sound.setVolume(20.f);

    music.setVolume(10.f);
    music.play();

    int x = 690, y = 155, pos = 1;
    indicator.setPosition(x, y);
    // Game Loop
    while (window.isOpen()) {

        //ReadImput

        sf::Event Event;

        while (window.pollEvent(Event)) {

            //music.setPlayingOffset(sf::seconds(10));
            if (Event.type == sf::Event::Closed)
                window.close();
        }


        window.clear();

        window.draw(img);

        window.draw(play);


        window.draw(ranking);
        window.draw(options);
        window.draw(help);
        window.draw(exit);


        indicator.setPosition(x, y);
        indicator.setRotation(90.f);
        window.draw(indicator);


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) and pos == 1) {
            pos = 2;
            x = 670;
            y = 205;
            ranking.setFillColor(sf::Color::White);
            ranking.setOutlineColor(sf::Color::Black);
            play.setFillColor(sf::Color::Transparent);
            play.setOutlineColor(sf::Color::White);
            //options.setFillColor(sf::Color::Transparent);


            sound.play();
            Sleep(150);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && pos == 2) {
            pos = 1;
            x = 690;
            y = 155;
            play.setFillColor(sf::Color::White);
            play.setOutlineColor(sf::Color::Black);
            ranking.setFillColor(sf::Color::Transparent);
            ranking.setOutlineColor(sf::Color::White);

            sound.play();
            Sleep(150);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && pos == 2) {
            pos = 3;
            x = 650;
            y = 255;
            options.setFillColor(sf::Color::White);
            options.setOutlineColor(sf::Color::Black);
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
            options.setFillColor(sf::Color::Transparent);
            options.setOutlineColor(sf::Color::White);
            sound.play();
            Sleep(150);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && pos == 3) {
            pos = 4;
            x = 690;
            y = 305;
            help.setFillColor(sf::Color::White);
            options.setFillColor(sf::Color::Transparent);
            help.setOutlineColor(sf::Color::Black);
            options.setOutlineColor(sf::Color::White);

            sound.play();
            Sleep(150);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && pos == 4) {
            pos = 3;
            x = 650;
            y = 255;
            help.setFillColor(sf::Color::Transparent);
            help.setOutlineColor(sf::Color::White);
            options.setFillColor(sf::Color::White);
            options.setOutlineColor(sf::Color::Black);

            sound.play();
            Sleep(150);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && pos == 4) {
            pos = 5;
            x = 700;
            y = 355;
            exit.setFillColor(sf::Color::Red);
            help.setFillColor(sf::Color::Transparent);
            exit.setOutlineColor(sf::Color::Black);
            help.setOutlineColor(sf::Color::White);
            sound.play();

            Sleep(150);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && pos == 5) {
            pos = 4;
            x = 690;
            y = 305;
            help.setFillColor(sf::Color::White);
            help.setOutlineColor(sf::Color::Black);

            exit.setFillColor(sf::Color::Transparent);
            exit.setOutlineColor(sf::Color::Red);
            sound.play();
            Sleep(150);
        }

        window.display();



        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {

            if (chooseOption(pos, sound, window, Event) == 1) {
                window.close();

            };

        }

    }


}

std::string MainMenu::InserName(sf::RenderWindow& window, sf::Event Event)
{
    int cont = 0;
    const int maxLength = 10;
    sf::FloatRect textBounds;
   

    Sleep(200);



    while (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) == false) {

        textBounds = texto.getLocalBounds();
        sf::RectangleShape background(sf::Vector2f(textBounds.width+20, textBounds.height+20));
        background.setFillColor(sf::Color(0, 0, 0, 350));
        background.setPosition((800 - textBounds.width) / 2, (600 - textBounds.height) / 2);
        texto.setPosition(background.getPosition());

        background.setPosition(650, 250);  
        texto.setPosition(650, 250);  

        if (Event.type == sf::Event::Closed)
            window.close();
        window.pollEvent(Event);

        if (Event.type == sf::Event::TextEntered)
        {
            Sleep(100);
            
            // Manejar la entrada de texto
            if (Event.text.unicode == 8) // Manejar retroceso (Backspace)
            {
                if (!name.empty())
                {
                   
                    name.pop_back();
                }
            }
            else if (Event.text.unicode < 128 and name.length() <= maxLength) // Asegurarse de que sea un caracter imprimible y ver el limite
            {
                name += static_cast<char>(Event.text.unicode);
                
            }
            texto.setString(name);
           
           

        }

        window.draw(img);
        window.draw(escape);
        window.draw(atras);
        window.draw(EnterName);
        if (name.length() > maxLength) {
            
            window.draw(NameLimit);
          
        }
    
        window.draw(background);
        window.draw(texto);
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            return name;
        }
        
        window.display();
    }
    std::string estado = "false";
    return estado;
    std::cout << "salio";
}

int MainMenu::chooseOption(int pos, sf::Sound sound, sf::RenderWindow& window, sf::Event Event) {
    RankingMenu ranking;
    std::string p;
    Gameplay gameplay;
    int exit = 0;
    switch (pos) {

    case 1: std::cout << "1";
        p = InserName(window, Event);
        if (p == "false") { std::cout << "falseeee"; }
        if (p!="false") {
            music.stop();
            gameplay.run(window, p);
            music.play();
        };

        break;
    case 2: std::cout << "2";
        ranking.show(window);
        //sound.play();
        break;
    case 3: std::cout << "3";
        break;
    case 4: std::cout << "4";
        HelpMenu(window);
        break;
    case 5: std::cout << "5";
        exit = 1;
        return exit;

    }
}

void MainMenu::HelpMenu(sf::RenderWindow& window)
{
    while(window.isOpen()){
    backgroundHelp.loadFromFile("img/backgroundHelp.jpg");
    imgHelp.setTexture(backgroundHelp);


    window.clear();
    window.draw(imgHelp);
    window.display();
    }
}
