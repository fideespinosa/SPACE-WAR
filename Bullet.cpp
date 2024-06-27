#include "Bullet.h"

Bullet::Bullet(sf::Vector2f position, int type)
{
    _texture.loadFromFile("img/balaEnemigo.png");
    _sprite.setTexture(_texture);
    _sprite.setPosition(position);
    _speed = -5.0f; // Velocidad hacia arriba
    _direction = 1;
}

Bullet::Bullet(sf::Vector2f position) {
    _texture.loadFromFile("img/bala.png");
    _sprite.setTexture(_texture);
    _sprite.setPosition(position);
    _speed = -10.0f; // Velocidad hacia arriba
    _direction = 0;
}



void Bullet::update() {
    if (_direction == 0) { _sprite.move(0, _speed); }
    else
    {
        _sprite.move(0, -_speed);
    }

}

void Bullet::draw(sf::RenderWindow& window) {
    //_texture.loadFromFile("img/bala.png");
    _sprite.setTexture(_texture);
    window.draw(_sprite);
}

sf::FloatRect Bullet::getBounds() const {
    return _sprite.getGlobalBounds();
}
