#pragma once
#include <cstdlib>
#include <ctime>
#include "Gameplay.h"
#include <iostream>


//inicializamos la variable de clase en 0 para cuando programemos el 
// getinstance validemos si esta en 0 o se creo una instancia
Gameplay* Gameplay::_currentInstance = nullptr;

/*
bool Gameplay::checkSuperpotition(Enemy& enemy, std::list<Enemy>& _enemies)
{
    for (auto& enemy : _enemies) {
        if (enemy->getBounds().intersects(_enemies->getBounds()) {

        }
    }
}
*/

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
            if (it->getBounds().intersects((*enemyIt)->getBounds())) {
                (*enemyIt)->setLife((*enemyIt)->getLife() - 1);
                if ((*enemyIt)->getLife() == 0) {
                    enemyIt = _enemies.erase(enemyIt);
                    _score += 10;
                }
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
        }
        else {
            ++it;
        }
    }
}

void Gameplay::spawnEnemies() { // VERIFICAR POSICION DE RESPAWN, HAY QUE CORREGIR CONTEMPLANDO GLOBALBOUDS
    std::srand(std::time(0)); 
    int randomType = (std::rand() % 4) + 1; //genero numero aleatorio para utilizar un draw diferente segun typo
    //
    
    if (_enemySpawnClock.getElapsedTime().asSeconds() > 2) {
        float spawnX = static_cast<float>(rand() % (800 - 50)); // verificar ancho en getBounds de enemigo
        switch (randomType) {
        case 1:
            _enemies.push_back(std::make_unique<Enemy1>(spawnX, 0));
            break;
        case 2:
            _enemies.push_back(std::make_unique<Enemy2>(spawnX, 0));
            break;
        case 3:
            _enemies.push_back(std::make_unique<Enemy3>(spawnX, 0));
            break;
        case 4:
            _enemies.push_back(std::make_unique<Enemy4>(spawnX, 0));
            break;
        }

        _enemySpawnClock.restart();
    }
}

sf::Text Gameplay::showScore(int _score)
{   
    _font.loadFromFile("SPACE.ttf");
    std::string score = std::to_string(_score);
    sf::Text textScore;
    textScore.setFont(_font);
    textScore.setString(score);
    textScore.setCharacterSize(40);
    textScore.setStyle(sf::Text::Italic);
    textScore.setFillColor(sf::Color::White);
    textScore.setOutlineThickness(1);
    textScore.setOutlineColor(sf::Color::Red);
    textScore.setPosition(750, 25);
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
            enemy->update();
        }

        for (auto& bullet : _playerBullets) {
            bullet.update();
        }

        spawnEnemies();
        handleCollisions();
        window.draw(showScore(_score));
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
            (*it)->draw(window);
        }

        // Dibujar balas
        for (auto it = _playerBullets.begin(); it != _playerBullets.end(); ++it) {
            it->draw(window);
        }
        window.display();
    }
}

void Gameplay::drawLife(sf::RenderWindow& window, int life)
{
    
}



