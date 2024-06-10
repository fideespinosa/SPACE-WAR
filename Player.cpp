#include "Player.h"

Player::Player() {
    _texture.loadFromFile("img/nave.png");
    _sprite.setTexture(_texture);
    _sprite.setPosition(400, 500); // Posici�n inicial en la parte inferior de la pantalla
    _speed = 0.7f;
}

void Player::handleInput(std::list<Bullet>& bullets) {
    // agrego x2 en la velocidad de mov izq y der
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        _sprite.move(-_speed*2, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        _sprite.move(_speed*2, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        _sprite.move(0, -_speed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        _sprite.move(0, _speed);
    }

    // Limitar movimiento del jugador dentro de los l�mites de la pantalla
    sf::Vector2f position = _sprite.getPosition();
    if (position.x < 0) {
        _sprite.setPosition(0, position.y);
    }
    if (position.x > 1024 - _sprite.getGlobalBounds().width) {
        _sprite.setPosition(1024 - _sprite.getGlobalBounds().width, position.y);
    }
    if (position.y < 300) { //  300 piso de Y
        _sprite.setPosition(position.x, 300);
    }
    if (position.y > 573 - _sprite.getGlobalBounds().height) { // 573 tope
        _sprite.setPosition(position.x, 573 - _sprite.getGlobalBounds().height);
    }


    // Disparo al presionar la barra espaciadora
    static sf::Clock shootClock;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && shootClock.getElapsedTime().asSeconds() > 0.5f) {
        bullets.push_back(shoot());
        shootClock.restart();
    }
}


void Player::update() {
    // Actualizar l�gica del jugador si es necesario
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(_sprite);
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