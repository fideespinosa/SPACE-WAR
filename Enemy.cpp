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
    sf::FloatRect enemyBounds = _sprite.getGlobalBounds();
    sf::Vector2f enemyCenter(_sprite.getGlobalBounds().left + _sprite.getGlobalBounds().width/2, _sprite.getPosition().y);
    return Bullet(enemyCenter, 3);
}

void Enemy::handleInputEnemy(std::list<Bullet>& bullets)
{

    int randomLuck = (std::rand() % 10) + 1;
    static sf::Clock shootClock;
    if ( shootClock.getElapsedTime().asSeconds() > 0.4f) 
    {
        std::cout << " balin enemigo " << std::endl;
        bullets.push_back(shoot());
        shootClock.restart();
    }

}

Enemy::~Enemy()
{

}




