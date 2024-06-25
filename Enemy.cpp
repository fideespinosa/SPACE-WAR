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

Enemy::Enemy(float x, float y) 
{
    _sprite.setPosition(x, y);
}

void Enemy::update() {
    _sprite.move(0, _speed);
}

void Enemy::draw(sf::RenderWindow& window) 
{
    _sprite.setTexture(_texture);
    window.draw(_sprite);
};


sf::FloatRect Enemy::getBounds() const {
    return _sprite.getGlobalBounds();
    //recomendacion - usar SF::REctangleShape 
    // cambiar return
}

Bullet Enemy::shoot() {
    return Bullet(_sprite.getPosition());
}



