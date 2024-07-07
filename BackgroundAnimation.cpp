#include "BackgroundAnimation.h"
#include <iostream>

BackgroundAnimation::BackgroundAnimation()
{
	_stateAnimation = 0;

    if (!_texture[0].loadFromFile("img/background/background1.png")){std::cout << "Error al cargar textura fondo" << std::endl;};
    if (!_texture[1].loadFromFile("img/background/background2.png")) { std::cout << "Error al cargar textura fondo" << std::endl; };
    if (!_texture[2].loadFromFile("img/background/background3.png")) { std::cout << "Error al cargar textura fondo" << std::endl; };
    if (!_texture[3].loadFromFile("img/background/background4.png")) { std::cout << "Error al cargar textura fondo" << std::endl; };
    if (!_texture[4].loadFromFile("img/background/background5.png")) { std::cout << "Error al cargar textura fondo" << std::endl; };
    if (!_texture[5].loadFromFile("img/background/background6.png")) { std::cout << "Error al cargar textura fondo" << std::endl; };
    if (!_texture[6].loadFromFile("img/background/background7.png")) { std::cout << "Error al cargar textura fondo" << std::endl; };
    if (!_texture[7].loadFromFile("img/background/background8.png")) { std::cout << "Error al cargar textura fondo" << std::endl; };
    if (!_texture[8].loadFromFile("img/background/background9.png")) { std::cout << "Error al cargar textura fondo" << std::endl; };
    if (!_texture[9].loadFromFile("img/background/background10.png")) { std::cout << "Error al cargar textura fondo" << std::endl;};

    _sprite[0].setTexture(_texture[0]);
    _sprite[1].setTexture(_texture[1]);
    _sprite[2].setTexture(_texture[2]);
    _sprite[3].setTexture(_texture[3]);
    _sprite[4].setTexture(_texture[4]);
    _sprite[5].setTexture(_texture[5]);
    _sprite[6].setTexture(_texture[6]);
    _sprite[7].setTexture(_texture[7]);
    _sprite[8].setTexture(_texture[8]);
    _sprite[9].setTexture(_texture[9]);

    _sprite[0].setTextureRect(sf::IntRect(0, 0, 1024, 573));
    _sprite[1].setTextureRect(sf::IntRect(0, 0, 1024, 573));
    _sprite[2].setTextureRect(sf::IntRect(0, 0, 1024, 573));
    _sprite[3].setTextureRect(sf::IntRect(0, 0, 1024, 573));
    _sprite[4].setTextureRect(sf::IntRect(0, 0, 1024, 573));
    _sprite[5].setTextureRect(sf::IntRect(0, 0, 1024, 573));
    _sprite[6].setTextureRect(sf::IntRect(0, 0, 1024, 573));
    _sprite[7].setTextureRect(sf::IntRect(0, 0, 1024, 573));
    _sprite[8].setTextureRect(sf::IntRect(0, 0, 1024, 573));
    _sprite[9].setTextureRect(sf::IntRect(0, 0, 1024, 573));



}

void BackgroundAnimation::update()
{
    int x = 0;
    if (_clock.getElapsedTime().asSeconds() > 0.5f)
    {
        _stateAnimation++;
        for (x = 0; x < 10; x++)
        {
            if (_stateAnimation < 9) {
                _sprite[x].setTextureRect(sf::IntRect(_stateAnimation * 573, 0, 1024, 573));
            }
            _clock.restart();
        }

        if(_stateAnimation == 9)
        {
            _stateAnimation = 0;
        }
    }
}

void BackgroundAnimation::draw(sf::RenderWindow& window)
{
    int x;
    for (x = 0; x < 10; x++)
    {
        _sprite[x].setTexture(_texture[x]);
        window.draw(_sprite[x]);
    }

}
