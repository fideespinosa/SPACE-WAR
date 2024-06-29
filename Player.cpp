#include "Player.h"
#include <iostream>


void Player::setLife(int life)
{
    _life = life;
}

int Player::getLife()
{
    return _life;
}
Player::Player() {
    _texture.loadFromFile("img/naveTest.png");
    _sprite.setTexture(_texture);
    _sprite.setPosition(400, 500); // Posición inicial en la parte inferior de la pantalla
    _speed = 4;
    _stateMove = 0;
    if (!_textureMove.loadFromFile("img/naveMove.png"))
    {
        std::cout << "Error al cargar naveMove" << std::endl;
    };
    _spriteMove.setTexture(_textureMove);
    _spriteMove.setPosition(400, 500); //posicion inicial igual a nave
    _spriteMove.setTextureRect(sf::IntRect(400, 500, 64, 64)); // pos x , pos y, ancho (weitdh), largo (height)
    buffer.loadFromFile("bulletSound.mp3");
    sound.setBuffer(buffer);

    _stateDead = 0;
    if (!_textureDead.loadFromFile("img/dead.png"))
    {
        std::cout << "Error al cargar dead" << std::endl;
    };
    _spriteDead.setTexture(_textureDead);
    _spriteDead.setTextureRect(sf::IntRect(0, 0, 64, 64)); // pos x , pos y, ancho (weitdh), largo (height)

}

void Player::handleInput(std::list<Bullet>& bullets) {

    sf::Vector2f position = _sprite.getPosition();

    if (getLife() > 0) {
        // agrego x2 en la velocidad de mov izq y der
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            _sprite.move(-_speed * 2, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            _sprite.move(_speed * 2, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            _sprite.move(0, -_speed);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            _sprite.move(0, _speed);
        }

        // Limitar movimiento del jugador dentro de los límites de la pantalla
        if (position.x < 0) {
            _sprite.setPosition(0, position.y);
        }
        if (position.x > 1024 - _sprite.getGlobalBounds().width) {
            _sprite.setPosition(1024 - _sprite.getGlobalBounds().width, position.y);
        }
        if (position.y < 50) { //  100 piso de Y
            _sprite.setPosition(position.x, 50);
        }
        if (position.y > 573 - _sprite.getGlobalBounds().height) { // 573 tope
            _sprite.setPosition(position.x, 573 - _sprite.getGlobalBounds().height);
        }

        // Disparo al presionar la barra espaciadora
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && shootClock.getElapsedTime().asSeconds() > 0.2f)
        {
            sound.play();
            bullets.push_back(shoot());
            shootClock.restart();
        }

        // movimiento de energia de la nave
        if (_clockMove.getElapsedTime().asSeconds() > 0.01f)
        {
            _stateMove++;
            _spriteMove.setPosition(position.x, position.y);
            if (_stateMove < 8) {
                _spriteMove.setTextureRect(sf::IntRect(_stateMove * 64, 0, 64, 64));
            }
            _clockMove.restart();
        }
        if (_stateMove == 8)
        {
            _stateMove = 0;
        }
    }
    // check dead
    if (getLife() <= 0)
    {
        if (_clockDead.getElapsedTime().asSeconds() > 0.25f)
        {
            _stateDead++;
            _spriteDead.setPosition(position.x, position.y);
            if (_stateDead < 16) {
                _spriteDead.setTextureRect(sf::IntRect(_stateDead * 64, 0, 64, 64));
            }
            _spriteDead.setScale(2.0f, 2.0f);
            _clockDead.restart();
        }
    }

}


void Player::update() 
{

}

void Player::draw(sf::RenderWindow& window) {
    if (getLife() > 0)
    {
        _spriteMove.setTexture(_textureMove);
        _sprite.setTexture(_texture);
        window.draw(_sprite);
        window.draw(_spriteMove);
    }
    else
    {
        _spriteDead.setTexture(_textureDead);
        window.draw(_spriteDead);
    }
}

sf::FloatRect Player::getBounds() const {
    return _sprite.getGlobalBounds();
}

sf::Vector2f Player::getPosition() const {
    return _sprite.getPosition();
}

Bullet Player::shoot() {
    sf::FloatRect playerBounds = _sprite.getGlobalBounds();
    sf::Vector2f playerCenter(_sprite.getPosition().x + playerBounds.width / 2, _sprite.getPosition().y);
    return Bullet(playerCenter);
}