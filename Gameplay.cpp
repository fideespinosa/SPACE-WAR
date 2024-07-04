#pragma once
#include <cstdlib>
#include <ctime>
#include "Gameplay.h"
#include <iostream>
#include "PauseMenu.h"
#include "ArchivoRanking.h"
#include "score.h"


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
    
    _font.loadFromFile("SPACE.ttf");
    life.setFont(_font);
    life.setCharacterSize(35);
    life.setOutlineThickness(2);
    life.setOutlineColor(sf::Color::Black);
    life.setPosition(40, 0);

    buffer2.loadFromFile("choque.mp3");
    sound.setBuffer(buffer2);
    sound.setVolume(40);

    buffer3.loadFromFile("gameOverSound.mp3");
    gameOverSound.setBuffer(buffer3);

    buffer4.loadFromFile("heartSound.mp3");
    heartEffect.setBuffer(buffer4);

    buffer5.loadFromFile("bulletImpact.wav");
    BulletImpact.setBuffer(buffer5);

    buffer6.loadFromFile("enemyDie.mp3"); 
    enemyDie.setBuffer(buffer6);

    heart.loadFromFile("img/Heart.png");
    img2.setTexture(heart);

    music.openFromFile("GPsoundtrack.wav");
    music.setVolume(20.f);

    texture.loadFromFile("img/Esc2.png");
    img.setTexture(texture);
    img.setPosition(950, -15);

    Menu.setFont(_font);
    Menu.setPosition(900, 0);
    Menu.setCharacterSize(15);
    Menu.setStyle(sf::Text::Italic);
    Menu.setFillColor(sf::Color::White);
    Menu.setOutlineThickness(2);
    Menu.setOutlineColor(sf::Color::Black);
    Menu.setString("Menu");
}

void Gameplay::checkPlayerCollisions()
{
  
    bool collisionDetected = false;
    for (auto enemyIt = _enemies.begin(); enemyIt != _enemies.end();)
    {
        if ((*enemyIt)->getBounds().intersects(_player.getBounds()))
        {
            _player.setLife(_player.getLife() - 5);
            if (_score > 0) {
                _score -= 5;
            }
            sound.play();
            enemyIt = _enemies.erase(enemyIt);
        }
        else
        {
            ++enemyIt;
        }
    }
    for (auto enemyBulletsIt = _enemyBullets.begin(); enemyBulletsIt != _enemyBullets.end();)
    {
        if (enemyBulletsIt->getBounds().intersects(_player.getBounds()))
        {
            _player.setLife(_player.getLife() - 1);
            BulletImpact.play();
            enemyBulletsIt = _enemyBullets.erase(enemyBulletsIt);
        }
        else
        {
            ++enemyBulletsIt;
        }
    }

}

void Gameplay::handleCollisions() {
    for (auto it = _playerBullets.begin(); it != _playerBullets.end();) 
    {
        bool collisionDetected = false;
        for (auto enemyIt = _enemies.begin(); enemyIt != _enemies.end();) 
        {
            if (it->getBounds().intersects((*enemyIt)->getBounds())) 
            {
                (*enemyIt)->setLife((*enemyIt)->getLife() - 1);
                if ((*enemyIt)->getLife() == 0) 
                {
                    _enemyExplosion.push_back(Explosion((*enemyIt)->getPosition(), (*enemyIt)->getType()));
                    enemyIt = _enemies.erase(enemyIt);
                    enemyDie.play();
                   
                    _score += 10;
                }
                collisionDetected = true;
                break;
            }
            else
            {
                ++enemyIt;
            }
        }
        for (auto lifeIT = _life.begin(); lifeIT != _life.end();)
        {
            if (it->getBounds().intersects(lifeIT->getBounds()))
            {
                lifeIT->setLife(lifeIT->getLife() - 1);
                if (lifeIT->getLife() == 0)
                {
                    heartEffect.play();

                    _player.setLife(_player.getLife() + 10);
                    lifeIT = _life.erase(lifeIT);
                    _score += 10;
                }
                collisionDetected = true;
                break;
            }
            else
            {
                ++lifeIT;
            }
        }

        if (collisionDetected)
        {
            it = _playerBullets.erase(it);
        }
        else
        {
            ++it;
        }

    }
}


void Gameplay::spawnEnemies(float _spawnTime) { // VERIFICAR POSICION DE RESPAWN, HAY QUE CORREGIR CONTEMPLANDO GLOBALBOUDS
   
    if (_spawnCheck)
    {
        std::srand(std::time(0));
        int randomType = (std::rand() % 4) + 1; //genero numero aleatorio para utilizar un draw diferente segun typo
        //

        if (_enemySpawnClock.getElapsedTime().asSeconds() > _spawnTime) {
            float spawnX = static_cast<float>(rand() % 980 + 20); //  estaria ok
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
}

sf::Text Gameplay::showScore(int _score)
{   
    _font.loadFromFile("SPACE.ttf");
    std::string score = std::to_string(_score);
    sf::Text textScore;
    textScore.setFont(_font);
    textScore.setString(score);
    textScore.setCharacterSize(35);
    textScore.setStyle(sf::Text::Italic);
    textScore.setFillColor(sf::Color::White);
    textScore.setOutlineThickness(1);
    textScore.setOutlineColor(sf::Color::Red);
    textScore.setPosition(0, 520);
    return textScore;

}



void Gameplay::run(sf::RenderWindow& window, std::string name) {
    _score = 0;
    archivoRanking ar;
    score obj1("vacio", 0);
    score obj2("vacio", 0);
    score obj3("vacio", 0);
    score obj4("vacio", 0);
    score obj5("vacio", 0);

    ar.cargarAr(obj1);
    ar.cargarAr(obj2);
    ar.cargarAr(obj3);
    ar.cargarAr(obj4);
    ar.cargarAr(obj5);

    PauseMenu menu;
    sf::Sprite background;
    sf::Texture backgroundGame;
    _spawnCheck = true;

    backgroundGame.loadFromFile("img/backgroundGamePlay.png");
    background.setTexture(backgroundGame);
    
    music.play();
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

        for (auto& enemy1 : _enemies)
        {
            enemy1->handleInputEnemy(_enemyBullets);
        }

        for (auto& enemy : _enemies)
        {
            enemy->update();
        }

        for (auto& bullet1 : _enemyBullets) 
        {
            bullet1.update();
        }

        for (auto& enemyExplosion : _enemyExplosion)
        {
            enemyExplosion.update(enemyExplosion.getType());
        }
      
        for (auto& bullet : _playerBullets) {
            bullet.update();         
        }    
             for (auto& life : _life) {
            life.update();
        }
        sf::String lifeString = std::to_string(_player.getLife());
        //Dificultad
       
        float _seconds = _gameClock.getElapsedTime().asSeconds();
        if (_seconds >= (_minute + 1) * 60.0f)
        {
            _life.push_back(Life());
            _minute++;
            _spawnTime = _spawnTime - 0.7f;
        }

        life.setString(lifeString);
        spawnEnemies(_spawnTime);
        handleCollisions();
        checkPlayerCollisions();
        window.draw(showScore(_score));
        window.draw(Menu);
        window.draw(img2);
        window.draw(life);
        window.draw(img);
        _player.draw(window);

        // Dibujar enemigos
        for (auto it = _enemies.begin(); it != _enemies.end(); ++it) {
            (*it)->draw(window);
        }

        //dibujo explosiones
        for (auto it = _enemyExplosion.begin(); it != _enemyExplosion.end(); ++it) {
            it->draw(window);
        }

        //dibujo corazones
        for (auto it = _life.begin(); it != _life.end(); ++it) {
            it->draw(window);
        }

        // Dibujar balas
        for (auto it = _playerBullets.begin(); it != _playerBullets.end(); ++it) {
            it->draw(window);
        }
        // Dibujar balas enemigas
        for (auto it = _enemyBullets.begin(); it != _enemyBullets.end(); ++it) {
            it->draw(window);
        } 

        cleanGame();

        window.display();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            music.pause();
           
            if (menu.Pause(window)==false) {
              
                Sleep(100);
                return;
            }
            music.play();
        }
      
        if (_player.getLife() <= 0) 
        {   
           // score.setPoint(_score);
          //  score.setName(name);
            //archivoRanking file;
            _spawnCheck = false;
            _enemies.clear();
            _playerBullets.clear();
            _enemyBullets.clear();
            music.stop();
            gameOverSound.play();
            //file.CalculateFile(score);
        }

        //incluir el if de abajo con el de arriba

        if (_player.getLife() <= 0 && _clockAnimationPlayer.getElapsedTime().asSeconds() > 10)
        {
            if (gameOver(window)) {
                //empezar de vuelta
                _player.setLife(50);
                run(window,name);
            }
            else {
                //volver al menu principal
                _clockAnimationPlayer.restart();
            }
        }

       
            if (_minute >= 1) {
                std::cout << "se termino el tiempo";
                //menuGanaste();
            }
        

    }
}

void Gameplay::drawLife(sf::RenderWindow& window, int life)
{
    
}

bool Gameplay::gameOver(sf::RenderWindow& window)
{
    int pos = 1;
    bool state = true;
    sf::Text yes, no, again;
    sf::Sprite fondo, gameOver;
    sf::Texture pic, pic2;
    sf::Font _font;
    _font.loadFromFile("SPACE.ttf");
    pic.loadFromFile("img/gameOver2.png");
    fondo.setTexture(pic);
    pic2.loadFromFile("img/gameOver.png");
    gameOver.setTexture(pic2);
    gameOver.setPosition(280, 30);

    yes.setFont(_font);
    yes.setStyle(sf::Text::Italic);
    yes.setOutlineThickness(2);
    yes.setOutlineColor(sf::Color::Black);
    yes.setFillColor(sf::Color::White);
    yes.setString("YES");
    yes.setPosition(370, 380);
    yes.setCharacterSize(20);


    no.setFont(_font);
    no.setStyle(sf::Text::Italic);
    no.setOutlineThickness(1);
    no.setOutlineColor(sf::Color::White);
    no.setFillColor(sf::Color::Transparent);
    no.setString("NO");
    no.setPosition(600, 380);
    no.setCharacterSize(20);

    again.setFont(_font);
    again.setStyle(sf::Text::Italic);
    again.setCharacterSize(25);
    again.setOutlineThickness(2);
    again.setOutlineColor(sf::Color::Black);
    again.setFillColor(sf::Color::White);
    again.setString("Play again?");
    again.setPosition(400, 280);
    again.setStyle(sf::Text::Underlined);

    while (state) {


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) and pos == 1) {
            pos = 2;

            no.setOutlineThickness(2);
            no.setOutlineColor(sf::Color::Black);
            no.setFillColor(sf::Color::White);
            yes.setOutlineThickness(1);
            yes.setOutlineColor(sf::Color::White);
            yes.setFillColor(sf::Color::Transparent);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) and pos == 2) {
            pos = 1;
           
            yes.setOutlineThickness(2);
            yes.setOutlineColor(sf::Color::Black);
            yes.setFillColor(sf::Color::White);
            no.setOutlineThickness(1);
            no.setOutlineColor(sf::Color::White);
            no.setFillColor(sf::Color::Transparent);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {

            switch (pos)
            {
            case 1:
                return true; //continua el juego
                break;
            case 2:
                return false;
                break;
            default:
                break;
            }
        }
        window.draw(fondo);
        window.draw(gameOver);
        window.draw(yes);
        window.draw(no);
        window.draw(again);
        window.display();
    }


}

void Gameplay::cleanGame() {

    _enemies.remove_if([](const std::unique_ptr<Enemy>& enemy) {
        return enemy->getPosition().y > 574;
        });

    _playerBullets.remove_if([](const Bullet& bullet) {       
        return bullet.getPosition().y < 0;
        });

    _enemyBullets.remove_if([](const BulletEnemy& bullet) {
        return bullet.getPosition().y > 574;
        });

    _life.remove_if([](const Life& life) {
        return life.getPosition().y > 574;
        });

    _enemyExplosion.remove_if([](const Explosion& explosion) {
        return explosion.getState() < 0;
        });
}

