#include "Enemy.h"
#include <iostream>

sf::Vector2f Enemy::getPosition() const
{
      return _sprite.getPosition();   
}

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

BulletEnemy Enemy::shoot() {
    sf::FloatRect enemyBounds = _sprite.getGlobalBounds();
    sf::Vector2f enemyCenter(_sprite.getGlobalBounds().left + _sprite.getGlobalBounds().width/2, _sprite.getPosition().y);
    return BulletEnemy(enemyCenter);
}

void Enemy::handleInputEnemy(std::list<BulletEnemy>& bullets)
{

    int randomLuck = (std::rand() % 10) + 1;
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

bool Enemy::controlSprite(sf::Sprite& _sprite)
{
    sf::Vector2f position = _sprite.getPosition();
    sf::FloatRect bounds = _sprite.getGlobalBounds();

    if (bounds.left <= 0) {
        _sprite.setPosition(0, position.y); 
        _sprite.move(_speed, 0); 
    }
    else if (bounds.left + bounds.width >= 1024) {
        _sprite.setPosition(1024 - bounds.width, position.y); 
        _sprite.move(-_speed, 0); 
    }
    else {
        return false;
    }

    return true;
}






