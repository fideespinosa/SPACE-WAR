#include "Enemy.h"
#include <iostream>

int Enemy::getType()
{
    return _type;
}

int Enemy::getLife()
{
    return _life;
}

void Enemy::setLife(int life)
{
    _life = life;
}

Enemy::Enemy(float x, float y, int type) {

    switch (type) {
    case 1:
        _type = type;
        _sprite.setPosition(x, y);
        _speed = 0.2f;
        _life = 10;
        break;
    case 2:
        _type = type;
        _sprite.setPosition(x, y);
        _speed = 0.3f;
        _life = 1;
        break;
    case 3:
        _type = type;
        _sprite.setPosition(x, y);
        _speed = 1;
        _life = 2;
        break;
    case 4:
        _type = type;
        _sprite.setPosition(x, y);
        _speed = 0.5f;
        _life = 1;
        break;
    default:
        std::cout << "Error en load / Enemy" << std::endl;

    };
}

void Enemy::update() {
    _sprite.move(0, _speed);
}

void Enemy::draw(sf::RenderWindow& window) 
{

    switch (getType()) {

    case 1:
        _texture.loadFromFile("img/enemy1.png");
        _sprite.setTexture(_texture);
        break;
    case 2:
        _texture.loadFromFile("img/enemy2.png");
        _sprite.setTexture(_texture);
        window.draw(_sprite);
        break;
    case 3:
        _texture.loadFromFile("img/enemy3.png");
        _sprite.setTexture(_texture);
        break;
    case 4:
        _texture.loadFromFile("img/enemy4.png");
        _sprite.setTexture(_texture);
        break;


    }

    window.draw(_sprite);
};


sf::FloatRect Enemy::getBounds() const {
    return _sprite.getGlobalBounds();
}

Bullet Enemy::shoot() {
    return Bullet(_sprite.getPosition());
}
