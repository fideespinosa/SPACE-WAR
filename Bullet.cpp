#include "Bullet.h"

Bullet::Bullet( int x, int y)
{
    speed = 0.0f;
    _texture.loadFromFile("copaBronce.png");
    _sprite.setTexture(_texture);
    //_vel = 10;
    _sprite.setPosition(x,y);
}

/*
Bullet::Bullet(sf::FloatRect startX, sf::FloatRect startY, float bulletSpeed)
{
    y = startY;
    x = startX;
    speed = bulletSpeed;
}
*/


void Bullet::upDate()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        //Mover Bala
        _sprite.move(0,-1);
    }
    
}

float Bullet::getX() const
{
    return 0.0f;
}

float Bullet::getY() const
{
    return 0.0f;
}

/*
void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    
    target.draw(_sprite, states);
}
*/

void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}