#include "Enemy.h"
#include <iostream>

Enemy::Enemy(float x, float y) {
    _texture.loadFromFile("img/enemy.png");
    _sprite.setTexture(_texture);
    _sprite.setPosition(x, y);
    _speed = 0.2f;
}

void Enemy::update() {
    _sprite.move(0, _speed);
}

void Enemy::draw(sf::RenderWindow& window) {
    _texture.loadFromFile("img/enemy.png");
    _sprite.setTexture(_texture);
    window.draw(_sprite);
}

sf::FloatRect Enemy::getBounds() const {
    return _sprite.getGlobalBounds();
}

Bullet Enemy::shoot() {
    return Bullet(_sprite.getPosition());
}
