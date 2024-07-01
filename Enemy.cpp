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

}

void Enemy::update() 
{
    sf::Vector2f position = _sprite.getPosition();

    if (!controlSprite(_sprite))
    {
        int randomMove = (std::rand() % 8) + 1;
        switch (randomMove) {
        case 1:
            _sprite.move(_speed, 0); // der
            break;
        case 2:
            _sprite.move(-_speed, 0); //izq
            break;
        case 3:
            _sprite.move(0, _speed); //abajo
            break;
        case 4:
            _sprite.move(0, _speed * 2); // abajo
            break;
        case 5:
            _sprite.move(_speed * 1.2f, 0); // der
            break;
        case 6:
            _sprite.move(-_speed * 1.2f, 0); //izq
            break;
        case 7:
            _sprite.move(0, _speed * 1.5f); //abajo 
            break;
        case 8:
            _sprite.move(0, _speed * 2); // abajo
            break;
        }
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

void Enemy::draw(sf::RenderWindow& window) 
{
    _spriteMove.setTexture(_textureMove);
    _sprite.setTexture(_texture);
    window.draw(_sprite);
    window.draw(_spriteMove);
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
        _sprite.move(_speed*1.5f, 0); 
    }
    else if (bounds.left + bounds.width >= 1024) {
        _sprite.move(-_speed*1.5f, 0);
    }
    else {
        return false;
    }

    return true;
}






