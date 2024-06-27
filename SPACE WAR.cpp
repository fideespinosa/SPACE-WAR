#include "MainMenu.h"
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

int main() 
{
    MainMenu main;
  
    main.showMenu();
}

    /*
        // Crear la ventana
        sf::RenderWindow window(sf::VideoMode(800, 600), "Texto en pantalla");

        // Cargar una fuente
        sf::Font font;
        if (!font.loadFromFile("space.ttf"))
        {
            return -1;
        }

        // Crear el objeto de texto
        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(24); // Tamaño del texto
        text.setFillColor(sf::Color::White); // Color del texto

        std::string inputText;

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();

                if (event.type == sf::Event::TextEntered)
                {
                    // Manejar la entrada de texto
                    if (event.text.unicode == 8) // Manejar retroceso (Backspace)
                    {
                        if (!inputText.empty())
                        {
                            inputText.pop_back();
                        }
                    }
                    else if (event.text.unicode < 128) // Asegurarse de que sea un caracter imprimible
                    {
                        inputText += static_cast<char>(event.text.unicode);
                    }
                }
            }

            // Actualizar el texto
            text.setString(inputText);

            // Limpiar la ventana
            window.clear();

            // Dibujar el texto
            window.draw(text);

            // Mostrar la ventana
            window.display();
        }

        return 0;
    }

*/