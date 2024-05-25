#include "Bullet.h"
#include "Player.h"

Bullet::Bullet(sf::Vector2f position, Direction direction)
{
    _texture.loadFromFile("img/bala.png");
    _sprite.setTexture(_texture);
    _direction = direction;
    setPosition(position);
}


void Bullet::update()
{
    sf::Vector2f velocity{ 8,8 };

    switch (_direction) 
    {
    case Bullet::Direction::Left:
        move(-velocity.x, 0);
        break;
    case Bullet::Direction::Right:
        move(velocity.x, 0);
        break;
    case Bullet::Direction::Up:
        move(0, velocity.y);
        break;
    case Bullet::Direction::Down:
        move(0 , -velocity.y);
        break;
    default:
        break;
    }

}

void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}





/*
Bullet::Bullet( int x, int y)
{
    speed = 0.4f;
    _texture.loadFromFile("img/bala.png");
    _sprite.setTexture(_texture);
    //_vel = 10;
    _sprite.setPosition(x,y);
}


Bullet::Bullet(float startX, float startY, float bulletSpeed){}

        //Mover Bala
        //_sprite.move(0,-1);

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