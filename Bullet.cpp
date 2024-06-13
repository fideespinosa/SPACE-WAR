#include "Bullet.h"

Bullet::Bullet(sf::Vector2f position) {
    _texture.loadFromFile("img/bala.png");
    _sprite.setTexture(_texture);
    _sprite.setPosition(position);
    _speed = -10.0f; // Velocidad hacia arriba
}

void Bullet::update() {
    _sprite.move(0, _speed);
}

void Bullet::draw(sf::RenderWindow& window) {
    //_texture.loadFromFile("img/bala.png");
    _sprite.setTexture(_texture);
    window.draw(_sprite);
}

sf::FloatRect Bullet::getBounds() const {
    return _sprite.getGlobalBounds();
}
