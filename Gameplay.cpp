#pragma once
#include "Gameplay.h"
#include <iostream>


//inicializamos la variable de clase en 0 para cuando programemos el 
// getinstance validemos si esta en 0 o se creo una instancia
Gameplay* Gameplay::_currentInstance = nullptr;


Gameplay& Gameplay::getInstance()
{
    if (Gameplay::_currentInstance == nullptr) {
        Gameplay::_currentInstance = new Gameplay();
    }
    return *Gameplay::_currentInstance;
}

Gameplay::Gameplay() {
    // Inicializar jugador y listas de enemigos y balas
}

void Gameplay::handleCollisions() {
    for (auto it = _playerBullets.begin(); it != _playerBullets.end();) {
        bool collisionDetected = false;
        for (auto enemyIt = _enemies.begin(); enemyIt != _enemies.end();) {
            if (it->getBounds().intersects(enemyIt->getBounds())) {
                enemyIt = _enemies.erase(enemyIt);
                std::cout << "Collision detected" << std::endl;
                collisionDetected = true;
                break;
            }
            else {
                ++enemyIt;
            }
        }
        if (collisionDetected) {
            it = _playerBullets.erase(it);
            _score += 10;
        }
        else {
            ++it;
        }
    }
}

void Gameplay::spawnEnemies() { // VERIFICAR POSICION DE RESPAWN, HAY QUE CORREGIR CONTEMPLANDO GLOBALBOUDS
    if (_enemySpawnClock.getElapsedTime().asSeconds() > 2) {
        float spawnX = static_cast<float>(rand() % (800 - 50)); // Suponiendo que el ancho del enemigo es 50
        _enemies.push_back(Enemy(spawnX, 0));
        _enemySpawnClock.restart();
    }
}

sf::Text Gameplay::showScore(int _score)
{   
    sf::Font _font;
    _font.loadFromFile("SPACE.ttf");
    std::string score = std::to_string(_score);
    sf::Text textScore;
    textScore.setFont(_font);
    textScore.setString(score);
    textScore.setCharacterSize(40);
    textScore.setStyle(sf::Text::Regular);
    textScore.setFillColor(sf::Color::White);
    textScore.setOutlineThickness(1);
    textScore.setOutlineColor(sf::Color::White);
    textScore.setPosition(500, 300);
    return textScore;

}

void Gameplay::run(sf::RenderWindow& window) {
    _score = 0;
    sf::Sprite background;
    sf::Texture backgroundGame;

    backgroundGame.loadFromFile("img/backgroundGamePlay.png");
    background.setTexture(backgroundGame);
    

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        window.draw(background);
        
        _player.handleInput(_playerBullets);
        _player.update();

        for (auto& enemy : _enemies) {
            enemy.update();
        }

        for (auto& bullet : _playerBullets) {
            bullet.update();
        }

        spawnEnemies();
        handleCollisions();
        //sf::Text _text(showScore(_score));
        //window.draw(_text);
        //window.clear();
        _player.draw(window);
        

        /*
        auto enemy_it = _enemies.begin();
        while (enemy_it != _enemies.end())
        {
            auto& enemy = *enemy_it;
            enemy.draw(window);
            ++enemy_it;
        }

        auto bullet_it = _playerBullets.begin();
        while (bullet_it != _playerBullets.end())
        {
            auto& bullet = *bullet_it;
            bullet.draw(window);
            ++bullet_it;
        }*/

        // Dibujar enemigos
        for (auto it = _enemies.begin(); it != _enemies.end(); ++it) {
            it->draw(window);
        }

        // Dibujar balas
        for (auto it = _playerBullets.begin(); it != _playerBullets.end(); ++it) {
            it->draw(window);
        }
        window.display();
    }
}



